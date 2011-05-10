#include "clientmaingame.h"
#include "ui_clientmaingame.h"

ClientMainGame::ClientMainGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientMainGame)
{
    ui->setupUi(this);
    myQP = new QPainter();
}

ClientMainGame::~ClientMainGame()
{
    delete ui;
}
void ClientMainGame::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    myQP->begin(this);

    myQP->end();
}
