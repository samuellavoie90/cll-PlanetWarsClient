#include "planet.h"

Planet::Planet(QObject *parent) :
    QObject(parent)
{
    //QPoint Location;
    //int Population;
    //int Player;
   // int PopulationGrowth;
   // bool Focus;
}
void Planet::initialize(int Owner, int Quadrant, Planet *PlanetArray, int PlanetCount, int PlanetSize)
{
    int i =0;
Player=Owner;
bool Collision = false;
PopulationGrowth = PlanetSize;
int sizex = 512;
int sizey = 384;
if(Quadrant!=1)
{
    int sizex = 512;
    int sizey = 384;
}

do
{
    Collision = false;
Location=QPoint(qrand()%sizex,qrand()%sizey);
while(i<PlanetCount)
{
    if(CheckPlanetToPlanetCollision(PlanetArray[i]))
    {
        Collision = true;
    }
           // qrand();
    i++;
}

}while(Collision);

}
void Planet::MirrorPlanet(Planet SomePlanet,int Quadrant)
{

}
bool CheckPlanetToPlanetCollision(Planet planet2)
{

}
