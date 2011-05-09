#include "clientmaingame.h"
#include "ui_clientmaingame.h"

ClientMainGame::ClientMainGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientMainGame)
{
    ui->setupUi(this);

    // TEST GUILLAUME
}

ClientMainGame::~ClientMainGame()
{
    delete ui;
}
