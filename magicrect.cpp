#include "magicrect.h"

MagicRect::MagicRect()
{
}
QRect MagicRect::GetRectangle()
{
    QRect temp;
    if(TopLeft.y()>BotRight.y())
    {
          temp=QRect(BotRight,TopLeft);
    }
    else
    {
            temp=QRect(TopLeft,BotRight);
    }
    return temp;
}
  void MagicRect::Draw(QPainter *QP)
  {
      QP->drawRect(GetRectangle());
  }
  void MagicRect::CheckPlanetsWithin(QList<Planet> Planets, int PlayerID)
  {
      QRect temp = GetRectangle();
      for(int i =0;i<Planets.length();i++)
      {
          if(Planets[i].Player==PlayerID)
          {
            Planets[i].PFocus= temp.intersects(Planets[i].Location);
          }
          else
          {
              Planets[i].PFocus=false;
          }
      }

  }
