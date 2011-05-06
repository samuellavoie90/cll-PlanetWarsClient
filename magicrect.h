#ifndef MAGICRECT_H
#define MAGICRECT_H
#include <QObject>
#include <QtGui>
class MagicRect
{
public:
    MagicRect();
    QPoint TopLeft;
    QPoint BotRight;
    QRect Rectangle1;
    QRect GetRectangle();
    void Draw();

};

#endif // MAGICRECT_H
