#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QtGui>
#include "ship.h"
#include "paquet.h"
class Planet
{
    //Q_OBJECT
public:
    explicit Planet();
    QRect Location;
    int Population;
    int PlanetNumber;
    int Player;
    int PopulationGrowth;
    bool PFocus;
    int TickTillLastPop;
    QImage PlanetImg;
    //populationGrowth va etre utiliser pour determiner la grandeur de la planete.
    //une variable de texture
   //int planettype;

    Ship CreateShip(Planet Destination);

    Ship shipFromByteArray(int Data[]);
   void initialize(int Owner, int Quadrant,Planet PlanetArray[], int PlanetCount);
    void MirrorPlanet(Planet SomePlanet,int Quadrant,int PlanetCount);
    bool CheckPlanetToPlanetCollision(Planet planet2);
    void DrawPlanet(QPainter *);
    void PlanetTick(int tickAmmount);
   bool CheckShipToPlanetCollision(Ship SomeShip, Planet SomePlanet);
   void initializeFromint(int W[]);
private:
    void LoadImage();
signals:

public slots:


};

#endif // PLANET_H

