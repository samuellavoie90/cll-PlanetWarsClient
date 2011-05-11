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
  void MagicRect::Draw(QPainter *QP)
  {
      QP->drawRect(GetRectangle());
  }
  void MagicRect::CheckPlanetsWithin(QList<Planet> Planets)
  {
      QRect temp = GetRectangle();
      for(int i =0;i<Planets.length();i++)
      {
          Planets[i].PFocus= temp.intersects(Planets[i].Location);
      }

  }
