#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QtGui>
#include "ship.h"

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
    bool Focus;
    //populationGrowth va etre utiliser pour determiner la grandeur de la planete.
    //une variable de texture
   //int planettype;

    Ship CreateShip(Planet Destination);
    void initialize(int Owner, int Quadrant, Planet *PlanetArray,int PlanetCount);
    void MirrorPlanet(Planet SomePlanet,int Quadrant,int PlanetCount);
    bool CheckPlanetToPlanetCollision(Planet planet2);
    void DrawPlanet(); //to be completed later
    void PlanetTick(int tickAmmount);
signals:

public slots:


};

#endif // PLANET_H
