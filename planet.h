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
    //populationGrowth va etre utiliser pour determiner la grandeur de la planete.
    //une variable de texture
   //int planettype;
    bool Focus;
signals:

public slots:
    void initialize(int Player, int Quadrant, Planet *PlanetArray,int PlanetCount);
    void MirrorPlanet(Planet SomePlanet,int Quadrant);

};

#endif // PLANET_H
