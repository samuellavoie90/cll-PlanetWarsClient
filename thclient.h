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

signals:
    void NewTime(QByteArray);

protected:
    void run();

public slots:


};

#endif // THCLIENT_H
