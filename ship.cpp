#include "ship.h"

Ship::Ship(QObject *parent)
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
        if(TickstoLauch <= 0)
        {
            shipLaunched = true;
        }
    }


}

void Ship::DrawShip(QPainter *QP)
{
    QP->drawImage(Location,ShipImg);

    QColor tempColor = QColor();
    tempColor.setRgb(255,255,255,255);
    QPen temppen = QPen(tempColor);
    QP->setPen(temppen);
    QP->drawText(QPoint(Location.x()+Location.width()/2-4,Location.y()+Location.height()/2),QString::number(Attackvalue,10));
}
/*bool Ship::CheckShipToPlanetCollision(Planet SomePlanet)
{
    return Location.intersects(SomePlanet.Location);

}*/
bool Ship::CheckShipToShipCollision(Ship ship1, Ship ship2)
{
    return ship1.Location.intersects(ship2.Location);
}

void Ship::LoadImage()
{
    if(Player == 1)
    {
        ShipImg.load("MB.png",0);
    }
    else
        if(Player == 2)
        {
            ShipImg.load("MR.png",0);
        }
        else
            if(Player == 3)
            {
                ShipImg.load("MB.png",0);
            }
            else
                if(Player == 4)
                {
                    ShipImg.load("MB.png",0);
                }
}

