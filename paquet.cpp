#include "paquet.h"

Paquet::Paquet(short Message, short Player, int Data[30])
{
    m_Message = Message;
    m_Player = Player;
    for(int i = 0; i < 30; i++)
    {
        m_Data[i] = Data[i];
    }
}

Paquet::Paquet()
{

}

QByteArray Paquet::ToByteArray()
{
    char temp;
    QByteArray unBA ("");
    temp = (char)(255 & m_Message);
    unBA[0]= temp;
    temp = (char)(m_Message >> 8);
    unBA[1]= temp;
    temp = (char)(255 & m_Player);
    unBA[2]= temp;
    temp = (char)(m_Player >> 8);
    unBA[3]= temp;
    int j = 4;
    for(int i = 0; i < 30; i++)
    {
        temp = (char)(4278190080 & m_Data[i] >> 24);
        unBA[j] = temp;
        j++;
        temp = (char)((16711680 & m_Data[i]) >> 16);
        unBA[j] = temp;
        j++;
        temp = (char)((65280 & m_Data[i]) >> 8);
        unBA[j] = temp;
        j++;
        temp = (char)(255 & m_Data[i]);
        unBA[j] = temp;
        j++;
    }
    return unBA;
}
void Paquet::FromByteArray(QByteArray unBA)
{
    m_Message = unBA[0] | (unBA[1] << 8);
    m_Player = unBA[2] | (unBA[3] << 8);
    int j = 4;
    for(int i = 0; i < 30; i++)
    {
        m_Data[i] = 0;
        for(int k = 3; k >= 0; k--)
        {
            m_Data[i] |= ((int)(((uchar)unBA[j])) << 8*k);
            j++;
        }
    }
}
