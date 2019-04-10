#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <qfile.h>
#include <qdebug.h>
#include<qstring.h>
#include <QCryptographicHash>
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
   QString log = ui->lineLog->text(); /*считывание строки из поля*/
   QString pass = ui->linePass->text();
   QByteArray passH = pass.toUtf8();// хэшируем пароль алгоритмом sha256. передаваться он будет только в таком виде.
  qDebug() << passH;
  qDebug() <<  QCryptographicHash::hash(passH, QCryptographicHash::Sha256).toHex();
  passH = QCryptographicHash::hash(passH, QCryptographicHash::Sha256).toHex(); // почему то без toHex хэш не хэш
  qDebug() << passH;
  // в идеале здесь сразу должна быть функция, которая клеит qarraу добавляя auth, и отправляет серверу.
   QString all ="auth&" + log +"&" + passH;
   QByteArray allout = 0;
   qDebug() <<allout;
   allout +=all;
   qDebug() << allout;
// далее нужно переделать все в QByteArray


}

