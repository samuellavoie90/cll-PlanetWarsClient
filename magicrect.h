#ifndef MAGICRECT_H
#define MAGICRECT_H
#include <QObject>
#include <QtGui>
#include "planet.h"
class MagicRect
{
public:
    MagicRect();
    QPoint TopLeft;
    QPoint BotRight;
    QRect Rectangle1;
    QRect GetRectangle();
    void Draw(QPainter *QP);

};

#endif // MAGICRECT_H
