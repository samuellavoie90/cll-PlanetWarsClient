#include "planet.h"

Planet::Planet()
{
    //QPoint Location;
    //int Population;
    //int Player;
   // int PopulationGrowth;
   // bool Focus;
    TickTillLastPop=100;
}
void Planet::initialize(int Owner, int Quadrant,QList<Planet> PlanetArray)
{
    TickTillLastPop=100;
    int i =0;
Player=Owner;
bool Collision = false;
int sizex = 480;
int sizey = 770;
QPoint temp;
int tempsize;
if(Quadrant!=1)
{
    sizex = 512;
    sizey = 384;
}

LoadImage();
do    
{

    temp = QPoint(qrand()%sizex,qrand()%sizey);
    PopulationGrowth = 15+qrand()%50;
    tempsize = PopulationGrowth;
    Location=QRect(temp,QSize(tempsize,tempsize));
    GenerationRect = QRect(QPoint(temp.x()-Location.width()/2,temp.y()-Location.height()/2),QSize(Location.width()*2,Location.height()*2));
    i=0;
    while(i<PlanetArray.length())
    {     
       Collision = CheckPlanetToPlanetCollision(PlanetArray[i]);
       i++;

    }
    PlanetNumber=i;

}while(Collision);
Population= PopulationGrowth;
PFocus = false;

}
void Planet::MirrorPlanet(Planet SomePlanet,int Quadrant, int PlanetCount)
{
    TickTillLastPop=100;
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
    Location = QRect(QPoint(placex-SomePlanet.Location.x()-SomePlanet.Location.width(),placey-SomePlanet.Location.y()),QSize(SomePlanet.Location.size()));
    Player=SomePlanet.Player;
    PopulationGrowth=PopulationGrowth;
    Population =SomePlanet.Population;
    PlanetNumber = SomePlanet.PlanetNumber+PlanetCount;
    PFocus = false;

}
bool Planet::CheckPlanetToPlanetCollision(Planet planet2)
{

  return GenerationRect.intersects(planet2.GenerationRect);

}
void Planet::PlanetTick(int tickAmmount)
{
    TickTillLastPop-=tickAmmount;
    if(TickTillLastPop <= PopulationGrowth)
    {
    Population += 1;
    TickTillLastPop = 100;
    }
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
Someship.Player = Player;
Someship.LoadImage();

return Someship;
}
void Planet::DrawPlanet(QPainter *QP)
{
QP->drawImage(Location,PlanetImg);

}

bool Planet::CheckShipToPlanetCollision(Ship SomeShip, Planet SomePlanet)
{
return SomeShip.Location.intersects(SomePlanet.Location);
}
 void Planet::initializeFromint(int W[])
 {
     //QPoint Location;
     //int Population;
     //int Player;
    // int PopulationGrowth;
    // bool Focus;
     PFocus = false;
     Player = W[0];
     PopulationGrowth = W[1];
     Population = W[2];
     Location = QRect(QPoint(W[3],W[4]),QSize(W[5],W[6]));
    LoadImage();



 }
 void Planet::LoadImage()
 {
     if(Player ==1)
     {
     PlanetImg.load("PB.png",0);
     }
     else
     if(Player ==2)
     {
     PlanetImg.load("PR.png",0);
     }
     else
     if(Player ==3)
     {
     PlanetImg.load("PB.png",0);
     }
     else
     if(Player ==4)
     {
     PlanetImg.load("PB.png",0);
     }
     else
         if(Player ==5)
         {
             PlanetImg.load("PG.png",0);
         }

 }
 Ship Planet::shipFromByteArray(int Data[])
 {
     /*
     bool shipLaunched;
     int TickstoLauch;
     QPoint StartLocation;
     QPoint Destination;
     int Attackvalue;
     int shipspeed;
     QRect Location;
     void ShipTick(int TickCount);
     void DrawShip(QPainter *);
     QImage ShipImg;
     */
     Ship temp;
     temp.shipLaunched = false;
     temp.TickstoLauch = 10;
     temp.Player = Player;

     temp.StartLocation = QPoint(Data[0],Data[1]);
     temp.Destination = QPoint(Data[2],Data[3]);
     temp.Attackvalue = Population / 2;
     Population = Population /2;
     temp.shipspeed = Data[4];
     temp.Location = QRect(Location.x()+Location.width()/2,Location.y()+Location.height()/2,20,20);
     temp.LoadImage();
     return temp;
 }
