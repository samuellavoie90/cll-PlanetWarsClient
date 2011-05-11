#include "thclient.h"

thClient::thClient(QObject *parent) :
    QThread(parent)
{
}

void thClient::run()
{
    QTcpSocket sockClient;
    QByteArray baReception;
    sockClient.connectToHost(m_IP, 32564);
    if (sockClient.waitForConnected(1000))
    {
        while(sockClient.waitForReadyRead(2000))
        {
            baReception = sockClient.readAll();
            emit NewTime(baReception);
            baReception.clear();
        }
        sockClient.disconnectFromHost();
        sockClient.close();
    }
}
