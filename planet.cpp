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

if(Owner==1)
{
    PlanetImg.load("PB.png",0);
}
else
{
    if(Owner ==2)
    {
        PlanetImg.load("PR.png",0);
    }
    else
    {
        PlanetImg.load("PG.png",0);
    }
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
Population= PopulationGrowth;//A checker pour des erreur en debug plustard
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
            if(SomePlanet.Player==1)
            {
                PlanetImg.load("PR.png",0);
                Player=2;
            }
            placex = 1024;
            placey = SomePlanet.Location.y()*2;
             Player=2;

        }
        else
        if(Quadrant==3)
        {
            if(SomePlanet.Player==1)
            {
                PlanetImg.load("PR.png",0);//change for other color later
                Player=3;
            }
            placex = SomePlanet.Location.x()*2;
            placey = 768;


        }
        else
        if(Quadrant==4)
        {
            if(SomePlanet.Player==1)
            {
                PlanetImg.load("PR.png",0);
                Player=4;
            }
            placex = 1024;
            placey = 768;
        }
    }
    else
    {
        //1 Quadrant means its a 1v1 game, so generate for player 2
        if(SomePlanet.Player==1)
        {
            PlanetImg.load("PR.png",0);
            Player=2;
        }
    }

    if(SomePlanet.Player == 5)
    {
        Player=5;
        PlanetImg.load("PG.png",0);
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
Ship Someship;
Someship.shipLaunched = false;
Someship.TickstoLauch = 10;
Someship.StartLocation = QPoint(Location.x(),Location.y());
Someship.Destination = QPoint(Destination.Location.x(),Destination.Location.y());
Someship.Attackvalue = Population / 2;
Population = Population /2;
Someship.shipspeed = 2;
Someship.Location = QRect(Location.x()+Location.width()/2,Location.y()+Location.height()/2,20,20);
if(Player ==1)
{
    Someship.ShipImg.load("MB.png",0);
}
else
{
    if(Player ==2)
    {
        Someship.ShipImg.load("MR.png",0);
    }
    else
    {
        if(Player ==3)
        {
            Someship.ShipImg.load("MR.png",0);//Change Color
        }
        else
        {
            if(Player ==4)
            {
                Someship.ShipImg.load("MR.png",0);
            }
        }

    }
}

return Someship;
}
void Planet::DrawPlanet(QPainter *QP)
{


}

bool Planet::CheckShipToPlanetCollision(Ship SomeShip, Planet SomePlanet)
{
return SomeShip.Location.intersects(SomePlanet.Location);
}
