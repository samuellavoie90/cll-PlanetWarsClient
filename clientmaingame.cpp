#include "clientmaingame.h"
#include "ui_clientmaingame.h"

ClientMainGame::ClientMainGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientMainGame)
{
    ui->setupUi(this);
}

ClientMainGame::~ClientMainGame()
{
    delete ui;
}
