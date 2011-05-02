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
void Planet::initialize(int Owner, int Quadrant, Planet *PlanetArray, int PlanetCount)
{
    int i =0;
Player=Owner;
bool Collision = false;
PopulationGrowth = PlanetSize;
int sizex = 512;
int sizey = 384;
QPoint temp;
int tempsize;
if(Quadrant!=1)
{
    int sizex = 512;
    int sizey = 384;
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

}while(Collision);

}
void Planet::MirrorPlanet(Planet SomePlanet,int Quadrant)
{
    int placex = 1024;
    int placey = 768;
    int team = 2;
    if(Quadrant!=1)
    {
        if(Quadrant=2)
        {
            int placex = 512;
            int placey = 384;
            team=2;
        }
        if(Quadrant=3)
        {
            int placex = 512;
            int placey = 384;
            team=3;
        }
        if(Quadrant=4)
        {
            int placex = 512;
            int placey = 384;
            team = 4;
        }
    }
    Location = QRect(QPoint(placex-SomePlanet.Location.x(),placey-SomePlanet.Location.y()),QSize(SomePlanet.Location.size()));
    SomePlanet.Player=team;
    SomePlanet.PopulationGrowth = PopulationGrowth;
    SomePlanet.Population = Population;

}
bool Planet::CheckPlanetToPlanetCollision(Planet planet2)
{
  return Location.intersects(planet2.Location);
}
