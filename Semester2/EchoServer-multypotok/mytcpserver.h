#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSqlDatabase>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();
    void send_to_client(QString message, QTcpSocket* clientSocket);
    void send_to_client (QByteArray message, QTcpSocket* clientSocket);



private:
    QTcpServer *tcpServer;
    int server_status;
    QMap<int,QTcpSocket *> SClients;
    QSqlDatabase db;

};



#endif // MYTCPSERVER_H
