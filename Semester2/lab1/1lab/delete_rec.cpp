#include "delete_rec.h"
#include "ui_delete_rec.h"

delete_rec::delete_rec(QWidget *parent, QTcpSocket *ClientSock) :
    QDialog(parent),
    ui(new Ui::delete_rec)

{
    ui->setupUi(this);
    ClientSocket = ClientSock;
}

delete_rec::~delete_rec()
{
    delete ui;
}

void delete_rec::on_buttonBox_accepted()
{
    QString message = "yeeeees";
    QByteArray array;
    array.append(message);
    ClientSocket->write(array);
}
