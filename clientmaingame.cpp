#include "clientmaingame.h"
#include "ui_clientmaingame.h"

ClientMainGame::ClientMainGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientMainGame)
{
    ui->setupUi(this);
    myQP = new QPainter();
    connect(thclient, NewTime(QByteArray),this,SLOT(Getmessage(QByteArray));
}

ClientMainGame::~ClientMainGame()
{
    delete ui;
}
void ClientMainGame::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    myQP->begin(this);
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
 void Getmessage(QByteArray message)
 {

 }
