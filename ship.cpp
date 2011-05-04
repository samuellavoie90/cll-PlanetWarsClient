#include "ship.h"

Ship::Ship(QObject *parent) :
    QObject(parent)
{
    shipLaunched = false;
    /*
    bool shipLaunched;
    int TickstoLauch;
    QPoint StartLocation;
    QPoint Destination;
    int Attackvalue;
    int shipspeed;
    QRect Location
    */
}
void Ship::ShipTick(int TickCount)
{
    if(shipLaunched)
    {
        double PercentX;


    }
    else
    {
        TickstoLauch-=TickCount;
        if(TickstoLauch == 0)
        {
            shipLaunched = true;
        }
    }


}

void Ship::ShipDraw()
{

}
/*bool Ship::CheckShipToPlanetCollision(Planet SomePlanet)
{
    return Location.intersects(SomePlanet.Location);

}*/
bool Ship::CheckShipToShipCollision(Ship ship1, Ship ship2)
{
    return ship1.Location.intersects(ship2.Location);
}
