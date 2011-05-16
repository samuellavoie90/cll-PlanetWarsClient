#include "thclient.h"

thClient::thClient(QObject * parent) :
    QThread(parent)
{
        m_sockClient = new QTcpSocket();
        connect(m_sockClient,SIGNAL(readyRead()),this,SLOT(ReadyToRead()));


}

void thClient::run()
{
   /* QByteArray baReception;

        while(m_sockClient.waitForReadyRead(1000))
        {
            baReception = m_sockClient.readAll();
            emit NewTime(baReception);
            baReception.clear();
        }
        m_sockClient.disconnectFromHost();
        m_sockClient.close();
    }*/
}
void thClient::ReadyToRead()
{
    baReception = *new QByteArray();
    while(m_sockClient->bytesAvailable())
    {
        baReception = m_sockClient->read(124);
        emit NewTime(baReception);
    }
}
void thClient::DisconnectFromServer()
{
    m_sockClient->disconnectFromHost();
    m_sockClient->close();
}
bool thClient::ConnectToHost()
{
    m_sockClient->connectToHost(m_IP, 35994);
    if (m_sockClient->waitForConnected(3000))
    {

        return true;
    }
    else
    {
        return false;
    }
}
void thClient::WriteBA(QByteArray ba)
{
m_sockClient->write(ba);
}
