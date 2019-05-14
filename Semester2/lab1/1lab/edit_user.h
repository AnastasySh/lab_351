#ifndef EDIT_USER_H
#define EDIT_USER_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class edit_user;
}

class edit_user : public QDialog
{
    Q_OBJECT

public:
    explicit edit_user(QWidget *parent = nullptr, QTcpSocket *ClientSock = nullptr);
    ~edit_user();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::edit_user *ui;
    QTcpSocket *ClientSocket;
};

#endif // EDIT_USER_H
