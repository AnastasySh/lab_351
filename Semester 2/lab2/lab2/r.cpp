#include "r.h"

myTcpServer::myTcpServer(QObject *parent)
    : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &myTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333) && server_status == 0) {
        qDebug() << "server isn't work";
    }
    else {
        server_status = 1;
        qDebug() << "server is work";
    }
}

myTcpServer::~myTcpServer()
{
    server_status = 0;
}

void myTcpServer::slotNewConnection()
{
    if (server_status == 1)
    {
        mTcpSocket = mTcpServer->nextPendingConnection();

        mTcpSocket->write("hello!\r\n");

        connect(mTcpSocket, &QTcpSocket::readyRead, this, &myTcpServer::slotServerRead);

        connect(mTcpSocket, &QTcpSocket::disconnected, this, &myTcpServer::slotClientDisconnected);
    }
}


void myTcpServer::slotServerRead() {
    QByteArray;
    while (mTcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = mTcpSocket->readAll();
        char str = *array.data();
        str += 1;
        mTcpSocket->write(QByteArray::fromStdString((std::string)&str));
    }

}
void myTcpServer::slotClientDisconnected() {

    if (server_status == 1) {

        mTcpSocket->close();
        mTcpServer->close();

        qDebug() << QString::fromUtf8("сервер остановлен");

        server_status = 0;
    }
}
