#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class myTcpServer : public QObject
{
    Q_OBJECT

public:
    myTcpServer(QObject *parent = nullptr); // nullptr - специальная штука в С++11 для зануления указателей
    ~myTcpServer();

public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
    //void slotReadClient();

private:
    QTcpServer *mTcpServer;
    QTcpSocket *mTcpSocket;
    int server_status;
    QMap<int, QTcpSocket *> SClients;
};
