#include "db.h"
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>

bool open_db (QString name){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // открытие или создание файла БД. передача cтроки- идентификатора БД
    db.setDatabaseName(name); // название ДБ
    if(!db.open()) {   // открытие БД, проверка
        qDebug()<<db.lastError().text();
        qDebug()<< "not open";
        }
    else {
        qDebug()<< "open";
    }
}
QString authorize(std::string login, std::string password) // БД открывается.
{
    open_db("Test");
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
    query.prepare("SELECT * FROM 'user' WHERE login ==(:log) AND password ==(:pass)");
    query.bindValue(":pas","password");
    query.bindValue(":log","login");
   qDebug()<<query.exec() << "exec2";
   // где то в нижних строчках ошибки. запрос к базе проходит.
   QString status;
   if (query.at()) { // пролетаем этот цикл
           QSqlRecord rec = query.record();
            status = query.value(rec.indexOf("status")).toString();//.toInt();
   }
   /*if () // тут нужно сделать проверку на данные с запроса
   {
      qDebug() << "error authorization";
   }
   else {
       qDebug() << "authorization";
   }
   qDebug() << status;*/
   // db.close();
   qDebug() << status;
    return "moder";
}


