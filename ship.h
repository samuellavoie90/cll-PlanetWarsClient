#ifndef SHIP_H
#define SHIP_H

#include <QObject>
#include <QtGui>
//#include "planet.h"
class Ship : public QObject
{
    Q_OBJECT
public:
    explicit Ship(QObject *parent = 0);
    bool shipLaunched;
    int TickstoLauch;
    QPoint StartLocation;
    QPoint Destination;
    int Attackvalue;
    int shipspeed;
    QRect Location;
    void ShipTick(int TickCount);
    void ShipDraw();
//    bool CheckShipToPlanetCollision(Planet SomePlanet);
    static bool CheckShipToShipCollision(Ship ship1, Ship ship2);
//une variable de texture
signals:

public slots:



};

#endif // SHIP_H
