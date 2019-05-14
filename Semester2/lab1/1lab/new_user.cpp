#include "new_user.h"
#include "ui_new_user.h"
#include "qDebug"
#include <QMessageBox>
#include <QString>

new_user::new_user(QWidget *parent, QTcpSocket *ClientSock) :
    QDialog(parent),
    ui(new Ui::new_user)
{
    ui->setupUi(this);
    ClientSocket = ClientSock;
   // emit createDyn();
}

new_user::~new_user()
{
    delete ui;
}

/*
    qDebug()<<"accepted";
    QString log = ui->loginEdit->text(); считывание строки из поля
    QString pass = ui->passwordEdit->text();
    QString status = ui->statusEdit->text();
    QString all = "newQuery&"+log+", "+pass+", "+status+"&login, password, status&";
    QByteArray array;
    array.append(all);
    ClientSocket->write(array);
};*/




void new_user::on_buttonBox_accepted()
{
    qDebug()<<"accepted";
    QString log = ui->loginEdit->text();
    log += '"';
    log.prepend('"');
    QString pass = ui->passwordEdit->text();
    pass += '"';
    pass.prepend('"');
    QString status = ui->statusEdit->text();
    if(status == "moder" || status == "user" || status == "manager" ) {
        pass += '"';
        pass.prepend('"');
        QString all = "newQuery&("+log+", "+pass+", "+status+")&login, password, status&";
        QByteArray array;
        array.append(all);
        ClientSocket->write(array); // вылетают лютые ошибки в этом месте
    }
    else {
    QMessageBox Msg;
    Msg.setText("Invalid status entry. repeat");
    Msg.exec();
    }
}
