#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QFile>
#include <string>
#include <db.h>

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(slotNewConnection()));
       if (!tcpServer->listen(QHostAddress::Any, 33333) && server_status==0) {
           qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(tcpServer->errorString());
       } else {
           server_status=1;
           qDebug() << QString::fromUtf8("Server run!");
       }
}

void MyTcpServer::slotNewConnection()
{
    if(server_status==1){
        qDebug() << QString::fromUtf8("new client");
        QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
        int idusersocs = clientSocket->socketDescriptor();
        SClients[idusersocs]=clientSocket;
        connect(SClients[idusersocs],SIGNAL(readyRead()),this,SLOT(slotServerRead()));
        //connect(SClients[idusersocs],SIGNAL(disconected()),this,SLOT(slotClientDisconnected())); потом реализовать дисконект
    }
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    int idusersocs=clientSocket->socketDescriptor();
    QTextStream os(clientSocket);
        if (clientSocket ->bytesAvailable () >0) {
            QByteArray array = clientSocket ->readAll();
            qDebug() << "array is" + array;
            QList <QByteArray> all = array.split('&');
            qDebug() << "name func is " +  all[0]; // это он вывел
                if (all[0] == "auth") {
                    send_to_client(authorize(all[1], all[2]), clientSocket);
                }
                else if (all[0] == "selectAll") {
                    send_to_client(selectAll(all[1], all[2]), clientSocket);
                }
                else if (all[0] == "select") {
                    send_to_client(select(all[1], all[2], all [3]), clientSocket);
                }
                else if (all[0] == "newQuery") {

                    send_to_client(newQuery(all[1], all[2], all [3]), clientSocket);

                }
        }
}

void MyTcpServer::send_to_client (QString message, QTcpSocket* clientSocket)
{
QByteArray array;
array.append(message);
clientSocket->write(array);
};

void MyTcpServer::send_to_client (QByteArray message, QTcpSocket* clientSocket)
{
clientSocket->write(message);
};

void MyTcpServer::slotClientDisconnected()
{

}


