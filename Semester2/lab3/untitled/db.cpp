#include "db.h"
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
QString authorize(std::string login, std::string password)
{
    //password
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // открытие или создание файла БД. передача троки- идентификатора БД
    db.setDatabaseName("Test"); // название ДБ
    db.open();
    if(!db.open()) // проверка открытия
        qDebug()<<db.lastError().text();
    QSqlQuery query(db); // создание объекта для работы с БД
   // query.exec("SELECT * FROM 'User'");


    query.prepare("SELECT status FROM 'user' WHERE login == (:login) AND password == (:password)");
    query.bindValue(":password","password");
    query.bindValue(":login","login");
   query.exec();
   qDebug() << query.first();
    // выдает -1

// где то в нижних строчках ошибки
QSqlRecord rec = query.record(); // вроде как это отвечает за записи
QString status = query.value(rec.indexOf("status")).toString();

 /*  if () // тут нужно сделать проверку на данные с запроса
   {
      qDebug() << "error authorization";
   }
   else {
       qDebug() << "authorization";
   }*/
   qDebug() << status;
 return status;
}
