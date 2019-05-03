#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QTextStream>


MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
       connect(tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
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
        QTcpSocket* clientSocket=tcpServer->nextPendingConnection();
        int idusersocs=clientSocket->socketDescriptor();
        SClients[idusersocs]=clientSocket;
        connect(SClients[idusersocs],SIGNAL(readyRead()),this, SLOT(slotServerRead()));
         connect(SClients[idusersocs],SIGNAL(disconected()),this, SLOT(slotClientDisconnected()));
    }
}

void MyTcpServer::slotServerRead()
{
 QTcpSocket* clientSocket = (QTcpSocket*)sender();
 int idusersocs=clientSocket->socketDescriptor();
 QTextStream os(clientSocket);
 qDebug()<<os.readAll();

}

void MyTcpServer::slotClientDisconnected()
{

}


