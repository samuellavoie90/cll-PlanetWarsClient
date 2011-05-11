#ifndef CLIENTMAINGAME_H
#define CLIENTMAINGAME_H

#include <QMainWindow>
//ConnectToHost
#include "ship.h"
#include "planet.h"
#include "magicrect.h"
#include "thclient.h"
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
    MagicRect MRE;
    thClient *TC;
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::ClientMainGame *ui;
    QPainter *myQP;

public slots:
       void Getmessage(QByteArray message);
signals:
    void SendInfo(QByteArray);
     void NewTime(QByteArray);


};

#endif // CLIENTMAINGAME_H
