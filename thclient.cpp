#include "thclient.h"

thClient::thClient(QObject *parent) :
    QThread(parent)
{
    connect(sockClient,SIGNAL(ReadyRead()),this,SLOT(ReadytoRead()));
}

void thClient::run()
{
   /* QByteArray baReception;

        while(sockClient.waitForReadyRead(1000))
        {
            baReception = sockClient.readAll();
            emit NewTime(baReception);
            baReception.clear();
        }
        sockClient.disconnectFromHost();
        sockClient.close();
    }*/
}
void thClient::ReadyToRead()
{
    QByteArray baReception;
    while(sockClient->bytesAvailable())
    {
    baReception = sockClient->read(124);
    emit NewTime(baReception);
    }
}
void thClient::DisconnectFromServer()
{
    sockClient->disconnectFromHost();
    sockClient->close();
}
bool thClient::ConnectToHost()
{
    sockClient->connectToHost(m_IP, 32564);
    if (sockClient->waitForConnected(3000))
    {
        return true;
    }
    else
    {
        return false;
    }
}
