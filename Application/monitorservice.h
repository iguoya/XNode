#ifndef MONITORSERVICE_H
#define MONITORSERVICE_H

#include <QObject>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>

class MonitorService : public QObject
{
    Q_OBJECT
public:
    explicit MonitorService(QObject *parent = nullptr);
    void send(QString cmd, QString ip = "127.0.0.1", ushort port = 10000);

signals:
    void resultReady(QString result);

public slots:

    void readRead();

private:
    QUdpSocket client;
    QUdpSocket server;
};



#endif // MONITORSERVICE_H
