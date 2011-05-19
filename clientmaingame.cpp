#include "clientmaingame.h"
#include "ui_clientmaingame.h"

ClientMainGame::ClientMainGame(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::ClientMainGame)
{
    ui->setupUi(this);
    background.load("bg.jpg",0);
    myQP = new QPainter();
    TC = new thClient();
    connect(TC, SIGNAL(NewTime(QByteArray)),this,SLOT(Getmessage(QByteArray)));
    connect (this,SIGNAL(SendInfo(QByteArray)),TC,SLOT(WriteBA(QByteArray)));
    Timer = new QTimer(parent);
    Timer->setInterval(42);
    connect(Timer,SIGNAL(timeout()),this,SLOT(OnTimerTick()));
    MousePressed = false;
    WindowRes = this->geometry();
    PlayerID = 1;


}

ClientMainGame::~ClientMainGame()
{
    delete TC->m_sockClient;
    delete TC;
    delete Timer;
    delete ui;
}
void ClientMainGame::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    myQP->begin(this);
    myQP->setRenderHint(QPainter::Antialiasing,true);
    myQP->drawImage(QRect(QPoint(0,0),QSize(1200,1000)),background);
    for(int i =0;i<Planets.length();i++)
    {
        Planets[i].DrawPlanet(myQP);
    }
    for(int i =0;i<Ships.length();i++)
    {
        Ships[i].DrawShip(myQP);
    }
    if(MousePressed)
    {
        MRE.Draw(myQP);
    }

    myQP->end();

}
void ClientMainGame::mousePressEvent(QMouseEvent * Stuff)
{
    if(Stuff->button()==Qt::LeftButton)
    {
        MRE.TopLeft=QPoint(Stuff->pos());
        MRE.BotRight=QPoint(Stuff->pos());
        MousePressed=true;
    }
    if(Stuff->button() == Qt::RightButton)
    {
        QRect cursor = QRect(Stuff->pos(),QSize(1,1));
        Ship temp;
        int AttackedPlanetNumber = 0;
        Paquet temp2;
        for(int  i = 0;i<Planets.length();i++)
        {
            if(cursor.intersects(Planets[i].Location))
            {
                AttackedPlanetNumber = i;
                break;
            }
        }
        for(int i=0;i<Planets.length();i++)
        {
            if(Planets[i].PFocus  && AttackedPlanetNumber!=i)
            {
                temp =Planets[i].CreateShip(Planets[AttackedPlanetNumber]);
                temp2 = temp.ShipToPacket();
                emit SendInfo(temp2.ToByteArray());
            }
        }
    }
}
void ClientMainGame::mouseReleaseEvent(QMouseEvent * Stuff)
{
    if(Stuff->button()==Qt::LeftButton)
    {
        MousePressed = false;
        QRect temp = QRect(MRE.GetRectangle());
        for(int i =0;i<Planets.length();i++)
        {
            if(Planets[i].Player==PlayerID)
            {
                Planets[i].PFocus= temp.intersects(Planets[i].Location);
            }
            else
            {
                Planets[i].PFocus=false;
            }
        }
    }


}
void ClientMainGame::mouseMoveEvent(QMouseEvent * Stuff)
{
    if(MousePressed)
    {
        MRE.BotRight=QPoint(Stuff->pos());
    }
}

void ClientMainGame::TickALL(int tick)
{
    for(int i =0;i<Planets.length();i++)
    {
        Planets[i].PlanetTick(tick);

    }
    for(int k =Ships.length()-1;k>=0;k--)
    {
        if(Planets[0].CheckShipToPlanetCollision(Ships[k],&Planets[Ships[k].EndPlanet]))
        {
            Ships.removeAt(k);
        }

    }
    for(int i =0;i<Ships.length();i++)
    {
        Ships[i].ShipTick(tick);
    }
}

void ClientMainGame::Getmessage(QByteArray message)
{
    Paquet *ss = new Paquet();
    ss->FromByteArray(message);
    Planet temp;
    Planet temp3;
    Ship temp2;
    switch (ss->m_Message)
    {
    case 1:
        TickALL(ss->m_Data[0]);
        break;
    case 2:        
        temp.initializeFromint(ss->m_Data);
        m_TotalPlayers = ss->m_Player;
        Planets.append(temp);
        break;
    case 3:
        temp2.shipLaunched = false;
        temp2.TickstoLauch = 10;
        for(int i =0;i<Planets.length();i++)
        {
            if(ss->m_Data[0] == Planets[i].PlanetNumber)
            {
                temp = Planets[i];
                temp2.StartLocation = QPoint(Planets[i].Location.x(),Planets[i].Location.y());
                temp2.StartPlanet = Planets[i].PlanetNumber;
                temp2.Attackvalue = Planets[i].Population / 2.0;
                Planets[i].Population = qRound(Planets[i].Population / 2.0);
                temp2.Location = QRect(Planets[i].Location.x()+Planets[i].Location.width()/4,Planets[i].Location.y()+Planets[i].Location.height()/4,20,20);
                temp2.Player = ss->m_Player;
            }
            else
            {
                if(ss->m_Data[1] == Planets[i].PlanetNumber)
                {
                    temp3 = Planets[i];
                    temp2.Destination = QPoint(Planets[i].Location.x()-Planets[i].Location.width()/2,Planets[i].Location.y()-Planets[i].Location.y()/2);
                    temp2.EndPlanet = Planets[i].PlanetNumber;
                }
            }

        }
        temp2.XRatio= temp3.Location.x()+temp3.Location.width()/2.0-(temp.Location.x()+temp.Location.width()/2.0);
        temp2.YRatio = temp3.Location.y()+temp3.Location.height()/2.0-(temp.Location.y()+temp.Location.height()/2.0);
        temp2.XTravel = temp2.Location.x();
        temp2.YTravel = temp2.Location.y();
        temp2.shipspeed = 3;
        temp2.HDistance = qSqrt(qPow(temp2.XRatio, 2)+qPow(temp2.YRatio, 2));
        temp2.LoadImage();
        Ships.append(temp2);
        break;
    case 4:
        PlayerID=ss->m_Player;
        Timer->start();
        break;
    }

delete ss;
}
void ClientMainGame::OnTimerTick()
{
    update();
}
void ClientMainGame::on_pushButton_3_clicked()
{
    Planets.clear();
    qsrand(QTime::currentTime().msec());
    int random = 8+qrand()%6;
    Planet temp;
    ui->frame->setVisible(false);
    Timer->start();
    temp.initialize(1,1,Planets);
    Planets.append(temp);
    for(int i =1;i<random;i++)
    {
        temp.initialize(5,1,Planets);
        Planets.append(temp);
    }
    for(int i = 0;i<random;i++)
    {
        temp.MirrorPlanet(Planets[i],1,Planets.length());
        temp.Location.moveRight(temp.Location.x()+120);
        Planets.append(temp);
    }


}

void ClientMainGame::on_pushButton_clicked()
{
    TC->m_IP=ui->txtIPAdress->text();
    TC->ConnectToHost();
    Planets.clear();
    ui->frame->setVisible(false);
}

void ClientMainGame::on_pushButton_4_clicked()
{
    Planets.clear();
    qsrand(QTime::currentTime().msec()*QTime::currentTime().second());
    int random = 4+qrand()%2;
    Planet temp;
    ui->frame->setVisible(false);
    Timer->start();
    temp.initialize(1,2,Planets);
    Planets.append(temp);
    for(int i =1;i<random;i++)
    {
        temp.initialize(5,2,Planets);
        Planets.append(temp);
    }
    int TotalPlanetsSoFar = Planets.length();
    for(int k=3;k<6;k++)
    {
        for(int i = 0;i<random;i++)
        {
            temp.MirrorPlanet(Planets[i],k-1,TotalPlanetsSoFar);
            Planets.append(temp);
        }
    }

}
