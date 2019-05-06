#include "db.h"
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>


QString authorize(std::string login, std::string password) // БД открывается.
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // открытие или создание файла БД. передача cтроки- идентификатора БД
    db.setDatabaseName("Test"); // название ДБ
    if(!db.open()) {   // открытие БД, проверка
        qDebug()<<db.lastError().text();
        qDebug()<< "not open";
        }
    else {
        qDebug()<< "open";
    }
    QSqlQuery query(db); // создание объекта для работы с БД
    query.prepare("SELECT * FROM user WHERE login = :log AND password = :pass");
    QString log = QString::fromStdString(login);
    QString pass = QString::fromStdString(password);
    query.bindValue(":pass", pass);
    query.bindValue(":log", log);
    query.exec();
   //qDebug()<<query.exec() << "exec2";
   // где то в нижних строчках ошибки. запрос к базе проходит.
   QString status;
   query.next();
   QSqlRecord rec = query.record();
   status = query.value(rec.indexOf("status")).toString();//.toInt()
   qDebug() << status;
   if (status == "") // тут нужно сделать проверку на данные с запроса
   {
      qDebug() << "error authorization";
   }
   else {
       qDebug() << "authorization";
   }
   return status;
}

QString db_select(std::string login, std::string password){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Test");
    if(!db.open()) {
        qDebug()<<db.lastError().text();
        qDebug()<< "not open";
    }
    else {
        qDebug()<< "open";
    }
    QSqlQuery query(db);
    query.prepare("SELECT (:what) FROM (:where)");
};
QString db_select(std::string login, std::string password, std::string condition){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Test");
    if(!db.open()) {
        qDebug()<<db.lastError().text();
        qDebug()<< "not open";
    }
    else {
        qDebug()<< "open";
    }
    QSqlQuery query(db);
    query.prepare("SELECT (:what) FROM (:where) (:condition)" );
};
