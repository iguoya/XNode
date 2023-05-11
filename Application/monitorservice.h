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

signals:
private:
    QUdpSocket m_socket;
};

#endif // MONITORSERVICE_H
