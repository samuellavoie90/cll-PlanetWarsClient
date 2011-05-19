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
PlanetNumber=PlanetArray.length();
if(Quadrant!=1)
{
    sizex = 480;
    sizey = 350;
}

LoadImage();
do    
{
    if(Player!=1)
    {

        temp = QPoint(qrand()%sizex,qrand()%sizey);
        PopulationGrowth = 20+qrand()%50;
    }

    else
    {

        temp = QPoint(qrand()%(sizex),qrand()%(sizey));
        PopulationGrowth = 30+qrand()%30;
    }
    tempsize = PopulationGrowth;
    Location=QRect(temp,QSize(tempsize,tempsize));
    GenerationRect = QRect(QPoint(temp.x()-Location.width()/2,temp.y()-Location.height()/2),QSize(Location.width()*2,Location.height()*2));
    i=0;
    Collision = false;
    while(i<PlanetArray.length())
    {     
        if(CheckPlanetToPlanetCollision(PlanetArray[i]))
        {
            Collision = true;
            i= PlanetArray.length();
        }
        i++;

    }


}while(Collision);
Population= PopulationGrowth;
PFocus = false;

}
void Planet::MirrorPlanet(Planet SomePlanet,int Quadrant, int PlanetCount)
{
    TickTillLastPop=100;
    int placex = 1024;
    int placey = 768;
    Player = 5;
    if(Quadrant!=1)
    {
        if(Quadrant==2)
        {            
            if(SomePlanet.Player==1)
            {
                Player=2;
            }
            placex = 1100;
            placey = SomePlanet.Location.y()*2;

        }
        else
        if(Quadrant==3)
        {
            if(SomePlanet.Player==1)
            {
                Player=3;
            }
            placex = SomePlanet.Location.x()*2;
            placey = 900;


        }
        else
        if(Quadrant==4)
        {
            if(SomePlanet.Player==1)
            {                
                Player=4;
            }
            placex = 1100;
            placey = 900;
        }
    }
    else
    {
        //1 Quadrant means its a 1v1 game, so generate for player 2
        if(SomePlanet.Player==1)
        {
            Player=2;
        }
    }


    Location = QRect(QPoint(placex-SomePlanet.Location.x(),placey-SomePlanet.Location.y()),QSize(SomePlanet.Location.size()));
    PopulationGrowth=SomePlanet.PopulationGrowth;
    Population =SomePlanet.Population;
    PlanetNumber = SomePlanet.PlanetNumber+PlanetCount;
    PFocus = false;
    LoadImage();

}
bool Planet::CheckPlanetToPlanetCollision(Planet planet2)
{
    QRect temp = QRect(QPoint(0,0),QSize(1100,1000));
    if(GenerationRect.intersects(planet2.GenerationRect))
    {
        return true;
    }
    else
    {
    if(GenerationRect.intersects(temp))
    {
        return false;
    }
    else
    {
        return true;
    }
    }

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
Someship.shipspeed = 2;
Someship.Location = QRect(Location.x()+Location.width()/2,Location.y()+Location.height()/2,20,20);
Someship.Player = Player;
Someship.StartPlanet = PlanetNumber;
Someship.EndPlanet = Destination.PlanetNumber;
Someship.LoadImage();

return Someship;
}
void Planet::DrawPlanet(QPainter *QP)
{
QColor tempColor = QColor();
tempColor.setRgb(0,255,0,255);
QPen temppen;
temppen = QPen(tempColor);
QP->setPen(temppen);
if(PFocus)
{
    QP->drawEllipse(QPoint(Location.x()+Location.width()/2,Location.y()+Location.height()/2),Location.width()-5,Location.height()-5);
}
QP->drawImage(Location,PlanetImg);
tempColor.setRgb(255,255,255,255);
temppen = QPen(tempColor);
QP->setPen(temppen);
QP->drawText(QPoint(Location.x()+Location.width()/2-7,Location.y()+Location.height()/2),QString::number(Population,10)); //Set back to population
}

bool Planet::CheckShipToPlanetCollision(Ship SomeShip, Planet *SomePlanet)
{
    if(SomeShip.Location.intersects(SomePlanet->Location)&&SomeShip.StartPlanet!=SomePlanet->PlanetNumber)
    {
        if(SomeShip.Player=SomePlanet->Player)
        {
            SomePlanet->Population += SomeShip.Attackvalue;
        }
        else
        {
            SomePlanet->PFocus = false;
            SomePlanet->Population -= SomeShip.Attackvalue;
            if(SomePlanet->Population<0)
            {
                SomePlanet->Population = 0-SomePlanet->Population*2;
                SomePlanet->Player = SomeShip.Player;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
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
     PlanetNumber = W[7];
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
     PlanetImg.load("PGG.png",0);
     }
     else
     if(Player ==4)
     {
     PlanetImg.load("PY.png",0);
     }

         if(Player ==5)
         {
             PlanetImg.load("PG.png",0);
         }

 }

 Ship Planet::PaquetToShip(Paquet p, QList<Planet> Planets)
 {
    Ship Someship;
     Someship.shipLaunched = false;
     Someship.TickstoLauch = 10;
     for(int i =0;i<Planets.length();i++)
     {
         if(p.m_Player ==Planets[i].Player&&p.m_Data[0] == Planets[i].PlanetNumber)
         {
             Someship.StartLocation = QPoint(Planets[i].Location.x(),Planets[i].Location.y());
             Someship.StartPlanet = Planets[i].PlanetNumber;
             Someship.Attackvalue = Planets[i].Population / 2;
             Planets[i].Population = Planets[i].Population / 2;
             Someship.Location = QRect(Planets[i].Location.x()+Planets[i].Location.width()/2,Planets[i].Location.y()+Planets[i].Location.height()/2,20,20);
             Someship.Player = Planets[i].Player;
         }
         else
         {
         if(p.m_Data[1] == Planets[i].PlanetNumber)
         {
              Someship.Destination = QPoint(Planets[i].Location.x(),Planets[i].Location.y());
              Someship.EndPlanet = Planets[i].PlanetNumber;
         }
         }

     }
     Someship.shipspeed = 2;
     Someship.LoadImage();
     return Someship;
 }
