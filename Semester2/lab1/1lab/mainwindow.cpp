#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QBitArray>
#include <QMessageBox>




// инициализация сокета в конструкторе

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


ClientSocket = new QTcpSocket (this); // инициализация сокета
ClientSocket -> connectToHost("127.0.0.1", 33333); // сокет подключается к порту.

connect(ClientSocket,SIGNAL(connected()),this,SLOT(slot_connected()));
connect(ClientSocket,SIGNAL(readyRead()),this,SLOT(slot_read()));// вызываем

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //обработка формы подготовка сообщения к отправке
{

   QString log = ui->lineLog->text(); /*считывание строки из поля*/
   QString pass = ui->linePass->text();
   QByteArray passH = pass.toUtf8();// хэшируем пароль алгоритмом sha256. передаваться он будет только в таком виде.
  qDebug() << passH;
  qDebug() <<  QCryptographicHash::hash(passH, QCryptographicHash::Sha256).toHex();
  //passH = QCryptographicHash::hash(passH, QCryptographicHash::Sha256).toHex(); // почему то без toHex хэш не хэш
  qDebug() << passH;
  // в идеале здесь сразу должна быть функция, которая клеит qarraу добавляя auth, и отправляет серверу.
   QString all ="auth&" + log +"&" + passH + "&";
   qDebug() <<all;
   send_to_server(all);

// далее нужно переделать все в QByteArray
}

void MainWindow::slot_connected()
{
    QMessageBox Msg;
    Msg.setText("Connected!");
    Msg.exec();

};
void MainWindow::slot_read()
{
    while(ClientSocket -> bytesAvailable()>0) // пока хоть что-то считывается
    {
    QByteArray array;
    array = ClientSocket -> readAll();
    qDebug() << array;
    std::string message;
    message = array.toStdString();
    qDebug() << QString::fromStdString(message);

    QMessageBox msg2;
    msg2.setText(QString::fromStdString(message));

  }

 int idusersocs=ClientSocket->socketDescriptor();
 QTextStream os(ClientSocket);
 qDebug()<<os.readAll();
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


