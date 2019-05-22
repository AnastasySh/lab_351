#include "new_user.h"
#include "ui_new_user.h"
#include <qDebug>
#include <QMessageBox>
#include <QString>
#include <QCryptographicHash>


new_user::new_user(QWidget *parent, QTcpSocket *ClientSock, QString name) :
    QDialog(parent),
    ui(new Ui::new_user)
{
    if (name == "registration"){
        ui->setupUi(this);
        //ui ->statusEdit -> hide();
        ui ->statusLabel -> hide();
        ClientSocket = ClientSock;
    }
    else {
        ui->setupUi(this);
        ClientSocket = ClientSock;
    }
}

new_user::~new_user()
{
    delete ui;
}

void new_user::on_buttonBox_accepted() //cделано. добавление новых записей в таблицу
{
    qDebug()<<"accepted";
    QString log = ui->loginEdit->text();
    QString pass = ui->passwordEdit->text();
    QString status = ui->statusEdit->text();
    if (status == ""){
        status = "user";
    }
    if(log.indexOf('"') != -1 || log.indexOf('*') != -1 || log.indexOf("\\") != -1
       || log.indexOf('|') != -1 || log.indexOf('/') != -1 || log.indexOf('&') != -1) {
           QMessageBox Msg;
           Msg.setText("Invalid login entry. dont use \", \\, *, |, &. repeat");
           Msg.exec();
    }
    else if(pass.indexOf('"') != -1 || pass.indexOf('*') != -1 || pass.indexOf("\\") != -1
       || pass.indexOf('|') != -1 || pass.indexOf('/') != -1 || pass.indexOf('&') != -1) {
           QMessageBox Msg;
           Msg.setText("Invalid login entry. dont use \", \\, *, |, &. repeat");
           Msg.exec();
    }
    else if(status == "moder" || status == "user" || status == "manager" ) {
        QByteArray passH = pass.toUtf8();
        qDebug() << passH;
        qDebug() <<  QCryptographicHash::hash(passH, QCryptographicHash::Sha256).toHex();
        passH = QCryptographicHash::hash(passH, QCryptographicHash::Sha256).toHex(); // почему то без toHex хэш не хэш
        while (passH.indexOf('\\') != -1){
            passH.remove(passH.indexOf('\\'), 1);
        }
        while (passH.indexOf('"') != -1){
            passH.remove(passH.indexOf('"'), 1);
        }
        while (passH.indexOf(',') != -1){
            passH.remove(passH.indexOf('"'), 1);
        }
        pass = passH;
        QString all = "newQuery&(login, password, status)&user&"+log+","+pass+","+status;
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
