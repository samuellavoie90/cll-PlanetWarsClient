#include "magicrect.h"

MagicRect::MagicRect()
{
}
QRect MagicRect::GetRectangle()
{
    QRect temp;
    if(TopLeft.y()>BotRight.y())
    {
        if(TopLeft.x()>BotRight.x())
        {
            temp=QRect(BotRight,TopLeft);
        }
        else
        {
            temp=QRect(TopLeft.x(),BotRight.y(),TopLeft.x()-BotRight.x(),BotRight.y()-TopLeft.y());
        }
    }
    else
    {
        if(TopLeft.x()>BotRight.x())
        {
            temp=QRect(BotRight.x(),TopLeft.y(),BotRight.x()-TopLeft.x(),TopLeft.y()-BotRight.y());
        }
        else
        {
            temp=QRect(TopLeft,BotRight);
        }

    }
    return temp;
}
