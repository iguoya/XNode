#include "monitorservice.h"

MonitorService::MonitorService(QObject *parent)
    : QObject{parent}
{
    server.bind(QHostAddress::Any, 8888);
    connect(&server, &QUdpSocket::readyRead, this, &MonitorService::readRead);
}


void MonitorService::send(QString cmd, QString ip, ushort port)
{
    client.writeDatagram(cmd.toUtf8(), QHostAddress(ip), port);
}

void MonitorService::readRead()
{
    QByteArray result;
    result.resize(server.bytesAvailable());
    server.readDatagram(result.data(),result.size());
    resultReady(QString(result));
//    ui->lineEdit->setText(arr);
}
