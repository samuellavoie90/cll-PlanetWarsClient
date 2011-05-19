#ifndef THCLIENT_H
#define THCLIENT_H

#include <QThread>
#include <QtNetwork>

class thClient : public QThread
{
    Q_OBJECT
public:
    explicit thClient(QObject *parent = 0);
    QString m_IP;
    QTcpSocket *m_sockClient;
    void DisconnectFromServer();
    bool ConnectToHost();
    QByteArray baReception;
signals:
    void NewTime(QByteArray);
    void SendInfo(QByteArray);


protected:
    void run();

private slots:
void ReadyToRead();
void WriteBA(QByteArray);

};

#endif // THCLIENT_H
