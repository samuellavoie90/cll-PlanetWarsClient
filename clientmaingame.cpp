#include "clientmaingame.h"
#include "ui_clientmaingame.h"

ClientMainGame::ClientMainGame(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::ClientMainGame)
{
    ui->setupUi(this);
    myQP = new QPainter();
    TC = new thClient();
    connect(TC, SIGNAL(NewTime(QByteArray)),this,SLOT(Getmessage(QByteArray)));
    connect (this,SIGNAL(SendInfo(QByteArray)),TC,SLOT(WriteBA(QByteArray)));
    Timer = new QTimer(parent);
    Timer->setInterval(40);
    connect(Timer,SIGNAL(timeout()),this,SLOT(OnTimerTick()));

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
    for(int i =0;i<Planets.length();i++)
    {
        Planets[i].DrawPlanet(myQP);
    }
    for(int i =0;i<Ships.length();i++)
    {
        Ships[i].DrawShip(myQP);
    }
    MRE.Draw(myQP);

    myQP->end();

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
    Paquet *ss;
    ss->FromByteArray(message);
    switch (ss->m_Message)
    {
    case 1:
        TickALL(ss->m_Data[0]);
        break;
    case 2:
        Planet temp;
        temp.initializeFromint(ss->m_Data);
        break;
    }

}
//emit SendInfo(message);


void ClientMainGame::on_pushButton_2_clicked()
{
    qsrand(QTime::currentTime().msec());
    int random = 6+qrand()%15;
     Planet temp;
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
         Planets.append(temp);
     }
     ui->frame->setVisible(false);
     Timer->start();

}
void ClientMainGame::OnTimerTick()
{
repaint();
}

void ClientMainGame::on_pushButton_3_clicked()
{
    Planets.clear();
    qsrand(QTime::currentTime().msec());
    int random = 8+qrand()%6;
     Planet temp;
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
         Planets.append(temp);
     }
     ui->frame->setVisible(false);
     Timer->start();

}
