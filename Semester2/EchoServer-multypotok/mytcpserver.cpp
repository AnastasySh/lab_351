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
    /*если не авторизировались - авторизируемся один раз. и все.*/
    QByteArray array = clientSocket ->readAll();
    qDebug() << "array is" + array;
    std::string message, name_of_func, login, password;
    message = array.toStdString();
    qDebug() << "message is " + QString::fromStdString(message);
    //ищем название функции  // пробел как разделитель в строке
    int pos = message.find("&");
    // он нашел где первый &.
    name_of_func = message.substr(0,pos);
    qDebug() << "name func is " + QString::fromStdString(name_of_func); // это он вывел
    message.erase(0,pos+1); // обрезка
    pos = message.find("&");
   login = message.substr(0,pos);
   qDebug() << "login is " + QString::fromStdString(login); // это он тоже вывел
    message.erase(0,pos+1);
    pos = message.find("&");
   password = message.substr(0,pos);
  // password.erase(password.length()-2, 2);
   qDebug() << "pass is " + QString::fromStdString(password);
    message.erase(0,pos+1);

   //qDebug() << authorize(login, password);
   send_to_client("moder",clientSocket);
  }



 /*int idusersocs=clientSocket->socketDescriptor();
 QTextStream os(clientSocket);
 qDebug()<<os.readAll();*/

 }

void MyTcpServer::send_to_client (QString message, QTcpSocket* clientSocket)
{
QByteArray array;
array.append(message);
clientSocket->write(array);// то что мы отправляем. в виде Qstring
};

void MyTcpServer::slotClientDisconnected()
{

}


