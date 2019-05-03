#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer *tcpServer;
    int server_status;
    QMap<int,QTcpSocket *> SClients;
    void send_to_client(QString message, QTcpSocket* clientSocket);
};



#endif // MYTCPSERVER_H
