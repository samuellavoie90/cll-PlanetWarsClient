#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QtGui>
class Planet : public QObject
{
    Q_OBJECT
public:
    explicit Planet(QObject *parent = 0);
    QRect Location;
    int Population;
    int Player;
    int PopulationGrowth;
    bool Focus;
    //populationGrowth va etre utiliser pour determiner la grandeur de la planete.
    //une variable de texture
   //int planettype;

signals:

public slots:
    void initialize(int Owner, int Quadrant, Planet *PlanetArray,int PlanetCount);
    void MirrorPlanet(Planet SomePlanet,int Quadrant);
    bool CheckPlanetToPlanetCollision(Planet planet2);
    void DrawPlanet(); //to be completed later
    void PlanetTick(int tickAmmount);

};

#endif // PLANET_H
