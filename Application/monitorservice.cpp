#include "monitorservice.h"

MonitorService::MonitorService(QObject *parent)
    : QObject{parent}
{
//    m_socket = new QUdpSocket(this);
//    m_socket.bind(4321);
}

void MonitorService::command(QString cmd)
{
    m_socket.writeDatagram(cmd.toUtf8(), QHostAddress("127.0.0.1"), 10000);
}
