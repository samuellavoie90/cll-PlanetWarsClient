#ifndef CLIENTMAINGAME_H
#define CLIENTMAINGAME_H

#include <QMainWindow>
//ConnectToHost
#include "ship.h"
#include "planet.h"
#include "magicrect.h"
#include "thclient.h"
#include "paquet.h"
#include <qmath.h>
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
    QList<int> ShipsToRemove; //Variable membre pour empecher de la cree 30 fois par seconde, pour plus de performance.
    MagicRect MRE;
    thClient *TC;
    QRect WindowRes;
    int PlayerID;
    void TickALL(int tick);
    QTimer *Timer;
    QImage background;
    bool MousePressed;
    int m_TotalPlayers;
    void mousePressEvent(QMouseEvent * Stuff);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
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
     void repaint();



private slots:
     void OnTimerTick();
     void on_pushButton_3_clicked();
     void on_pushButton_clicked();
     void on_pushButton_4_clicked();
};

#endif // CLIENTMAINGAME_H
