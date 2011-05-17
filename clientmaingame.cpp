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
    Timer->setInterval(40);
    connect(Timer,SIGNAL(timeout()),this,SLOT(OnTimerTick()));
    MousePressed = false;
    WindowRes = this->geometry();


}

ClientMainGame::~ClientMainGame()
{
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
        MousePressed=true;
    }
}
void ClientMainGame::mouseReleaseEvent(QMouseEvent * Stuff)
{
    if(Stuff->button()==Qt::LeftButton)
    {
        MousePressed = false;
        MRE.CheckPlanetsWithin(Planets,PlayerID);
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
    Ship temp2;
    switch (ss->m_Message)
    {
    case 1:
        TickALL(ss->m_Data[0]);
        break;
    case 2:        
        temp.initializeFromint(ss->m_Data);
        Planets.append(temp);
        break;
    case 3:
        temp2=temp.PaquetToShip(*ss,Planets);
        Ships.append(temp2);
        break;
     case 4:
        PlayerID=ss->m_Player;
        break;
    }
    Timer->start();

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
    for(int i =0;i<random;i++)
    {
        if(i==1)
        {
            temp.initialize(1,1,Planets);
        }
        else
        {
            temp.initialize(5,1,Planets);
        }
        Planets.append(temp);


    }
    for(int i = 0;i<random;i++)
    {
        temp.MirrorPlanet(Planets[i],2,Planets.length());
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
