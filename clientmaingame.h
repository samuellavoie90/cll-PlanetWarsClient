#ifndef CLIENTMAINGAME_H
#define CLIENTMAINGAME_H

#include <QMainWindow>
//ConnectToHost
#include "ship.h"
#include "planet.h"
#include "magicrect.h"
#include "thclient.h"
#include "paquet.h"
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
    void TickALL(int tick);
    QTimer *Timer;
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


private slots:
     void on_pushButton_2_clicked();
     void OnTimerTick();
};

#endif // CLIENTMAINGAME_H
