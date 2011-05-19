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

