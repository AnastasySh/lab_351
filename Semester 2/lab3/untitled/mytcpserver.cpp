#include "mytcpserver.h"
#include <QDebug>
#include <QString>
#include <QFile>
#include <QCoreApplication>
#include <string>
#include <db.h>

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

myTcpServer::~myTcpServer() //деструктор сервера
{
    server_status = 0;
}

void myTcpServer::slotNewConnection() // подключение нового слота
{
    if (server_status == 1)
    {
        mTcpSocket = mTcpServer->nextPendingConnection();

        mTcpSocket->write("you're not welcome\r\n");

        connect(mTcpSocket, &QTcpSocket::readyRead, this, &myTcpServer::slotServerRead);

        connect(mTcpSocket, &QTcpSocket::disconnected, this, &myTcpServer::slotClientDisconnected);
    }
}


void myTcpServer::slotServerRead() {

    /*чтение со слота в массив*/

            if (mTcpSocket ->bytesAvailable () >0)
                {/*если не авторизировались - авторизируемся один раз. и все.*/
            QByteArray array = mTcpSocket->readAll();
            qDebug() << array;

            std::string message, name_of_func, login, password;
            array.toStdString();
            message = array.toStdString();
            qDebug() << QString::fromStdString(message);
            //ищем название функции  // пробел как разделитель в строке
            int pos = message.find("&");
            // он нашел где первый &.
            name_of_func = message.substr(0,pos);
            qDebug() << QString::fromStdString(name_of_func);
            message.erase(0,pos); // обрезка
            pos = message.find("&");
           login = message.substr(0,pos);
           qDebug() << QString::fromStdString(login);
            message.erase(0,pos+1);
            pos = message.find("&");
           password = message.substr(0,pos);
           password.erase(password.length()-2, 2);
           qDebug() << QString::fromStdString(password);
            message.erase(0,pos+1);
           qDebug() << authorize(login, password);
   // проблемы. позиция -1.


           // mTcpSocket->write(authorize(login, password));
     }


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
