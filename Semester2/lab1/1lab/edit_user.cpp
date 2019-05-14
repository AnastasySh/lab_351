#include "edit_user.h"
#include "ui_edit_user.h"

edit_user::edit_user(QWidget *parent, QTcpSocket *ClientSock) :
    QDialog(parent),
    ui(new Ui::edit_user)
{
    ui->setupUi(this);
    ClientSocket = ClientSock;
}

edit_user::~edit_user()
{
    delete ui;
}

void edit_user::on_buttonBox_accepted()
{
    QString message = "yeeeees";
    QByteArray array;
    array.append(message);
    ClientSocket->write(array);
}
