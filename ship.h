#ifndef SHIP_H
#define SHIP_H

#include <QObject>
#include <QPoint>

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
//une variable de texture
signals:

public slots:


};

#endif // SHIP_H
