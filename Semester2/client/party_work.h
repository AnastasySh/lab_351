#ifndef PARTY_WORK_H
#define PARTY_WORK_H

#include <QMainWindow>
#include <QTcpSocket>
namespace Ui {
class Party_work;
}

class Party_work : public QMainWindow
{
    Q_OBJECT

public:
    explicit Party_work(QWidget *parent = nullptr);
    ~Party_work();

private:
    Ui::Party_work *ui;
    QTcpSocket *ClientSocket;

private slots:
    void slot_connected();
    void slot_read();
    void send_to_server (QString message);
    void disconnected();
};

#endif // PARTY_WORK_H
