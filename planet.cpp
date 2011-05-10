#include "planet.h"

Planet::Planet()
{
    //QPoint Location;
    //int Population;
    //int Player;
   // int PopulationGrowth;
   // bool Focus;
}
void Planet::initialize(int Owner, int Quadrant, Planet PlanetArray[], int PlanetCount)
{
    int i =0;
Player=Owner;
bool Collision = false;
//PopulationGrowth = PlanetSize;
int sizex = 512;
int sizey = 384;
QPoint temp;
int tempsize;
if(Quadrant!=1)
{
    sizex = 256;
    sizey = 192;
}
else
{

}
do    
{
    Collision = false;
    temp = QPoint(qrand()%sizex,qrand()%sizey);
    tempsize = 15+qrand()%50;
    Location=QRect(temp,QSize(tempsize,tempsize));

    while(i<PlanetCount)
    {
        if(CheckPlanetToPlanetCollision(PlanetArray[i]))
        {
            Collision = true;
        }

        i++;
    }
    PlanetNumber=i;

}while(Collision);
Population= PopulationGrowth;
Focus = false;

}
void Planet::MirrorPlanet(Planet SomePlanet,int Quadrant, int PlanetCount)
{
    int placex = 1024;
    int placey = 768;
    Player=2;
    if(Quadrant!=1)
    {
        if(Quadrant==2)
        {
            placex = 1024;
            placey = SomePlanet.Location.y()*2;
             Player=2;

        }
        else
        if(Quadrant==3)
        {
            placex = SomePlanet.Location.x()*2;
            placey = 768;
             Player=3;

        }
        else
        if(Quadrant==4)
        {
            placex = 1024;
            placey = 768;
             Player=4;

        }
    }
    if(SomePlanet.Player == 5)
    {
        Player=5;
    }
    Location = QRect(QPoint(placex-SomePlanet.Location.x(),placey-SomePlanet.Location.y()),QSize(SomePlanet.Location.size()));
    Player=SomePlanet.Player;
    PopulationGrowth=PopulationGrowth;
    Population =SomePlanet.Population;
    PlanetNumber = SomePlanet.PlanetNumber+PlanetCount;
    Focus = false;

}
bool Planet::CheckPlanetToPlanetCollision(Planet planet2)
{
  return Location.intersects(planet2.Location);
}
void Planet::PlanetTick(int tickAmmount)
{

}
Ship Planet::CreateShip(Planet Destination)
{

}
void Planet::DrawPlanet(QPainter *QP)
{


}

bool Ship::CheckShipToPlanetCollision(Ship SomeShip, Planet SomePlanet)
{
return SomeShip.Location.intersects(SomePlanet.Location);
}
