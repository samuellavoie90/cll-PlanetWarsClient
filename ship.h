#ifndef SHIP_H
#define SHIP_H

#include <QObject>
#include <QtGui>
#include "paquet.h"
class Ship
{

public:
    explicit Ship(QObject *parent = 0);
    bool shipLaunched;
    int TickstoLauch;
    QPoint StartLocation;
    QPoint Destination;
    int Attackvalue;
    int StartPlanet;
    int EndPlanet;
    int shipspeed;
    QRect Location;
    void ShipTick(int TickCount);
    void DrawShip(QPainter *);
    QImage ShipImg;
    int Player;
    void LoadImage();
    Paquet ShipToPacket();
    double XRatio;
    double YRatio;
    double XTravel;
    double YTravel;
    double HDistance;
public slots:



};

#endif // SHIP_H
