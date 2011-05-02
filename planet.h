#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QPoint>
class Planet : public QObject
{
    Q_OBJECT
public:
    explicit Planet(QObject *parent = 0);
    QPoint Location;
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
    bool CheckPlanetToPlanetCollision(Planet planet1, Planet planet2);

};

#endif // PLANET_H
