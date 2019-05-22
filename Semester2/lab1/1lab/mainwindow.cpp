#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moder.h"
#include <fstream>
#include <qfile.h>
#include <qdebug.h>
#include<qstring.h>
#include <QCryptographicHash>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QCoreApplication>
#include <QTextStream>
#include <QByteArray>
#include <QMessageBox>
#include "new_user.h"

// инициализация сокета в конструкторе

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ClientSocket = new QTcpSocket (this);
    ClientSocket -> connectToHost("127.0.0.1", 33333);
    connect(ClientSocket,SIGNAL( connected() ),this,SLOT( slot_connected() ) );
    connect(ClientSocket,SIGNAL(readyRead()),this,SLOT(slot_read()));
    QString log = ui->lineLog->text();
    QString pass = ui->linePass->text();
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
   qDebug() << passH;
   QString all ="auth&" + log +"&" + passH + "&";
   qDebug() <<all;
   send_to_server(all);
}

void MainWindow::slot_connected()
{
    QMessageBox Msg;
    Msg.setText("Connected!");
    Msg.exec();

};
void MainWindow::slot_read()
{
    while(ClientSocket -> bytesAvailable()>0){
        QByteArray array;
        array = ClientSocket -> readAll();
        QList <QByteArray> all = array.split('&');
        if (all[0] == "authAnswer"){
            if(all[1] == "moder"){
                ui ->reg -> hide();
                moder *M = new moder(this, ClientSocket, all[1]);
                M ->show();
                //this -> hide();
            }
            else if (all[1] == "manager") {
                ui ->reg -> hide();
                moder *M = new moder(this, ClientSocket, all[1]);
                M ->show();
            }
            else if (all[1] == "user") {
                ui ->reg -> hide();
                moder *M = new moder (this, ClientSocket, all[1]);
                M ->show();
            }
            else if ( all [1] == "errorAuth") {

                QMessageBox Msg;
                Msg.setText("error Authorization. Please, try again");
                Msg.exec();

            }
        }
        else if (all[0] == "selectAllAnswer" ) {
            emit readyReadfromMainWindow(array);

        }
        else if (all[0] == "selectAnswer" ) {
            emit readyReadfromMainWindow(array);

        }
  }

 //int idusersocs=ClientSocket->socketDescriptor();

};
void MainWindow::send_to_server (QString message)
{
QByteArray array;
array.append(message);
ClientSocket->write(array);// то что мы отправляем. в виде Qstring
};
void MainWindow::disconnected()
{

};

void MainWindow::on_reg_clicked()
{
    ClientSocket = new QTcpSocket (this);
    ClientSocket -> connectToHost("127.0.0.1", 33333);
    new_user *W = new new_user(nullptr, ClientSocket, "registration");
    W -> show();


}
