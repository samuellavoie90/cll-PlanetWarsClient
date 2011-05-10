#ifndef CLIENTMAINGAME_H
#define CLIENTMAINGAME_H

#include <QMainWindow>
//ConnectToHost
#include "ship.h"
#include "planet.h"

namespace Ui {
    class ClientMainGame;
}

class ClientMainGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientMainGame(QWidget *parent = 0);
    ~ClientMainGame();
    QList<Planet> Planets;
    QList<Ship> Ships;
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::ClientMainGame *ui;
    QPainter *myQP;
};

#endif // CLIENTMAINGAME_H
