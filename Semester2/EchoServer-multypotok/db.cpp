#include "db.h"
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QList>
#include <QByteArray>

bool openDB(QString name, QSqlDatabase& db){

    if(!db.open()) {
        qDebug()<<db.lastError().text();
        qDebug()<< "not open";
        return false;
    }
    else {
        qDebug()<< "open";
        return true;
    }
}
QString authorize(QString login, QString password, QSqlDatabase& db){

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Test");
    openDB("Test",db);
    QSqlQuery query(db);
    query.prepare("SELECT * FROM user WHERE login = :log AND password = :pass" );
    QString log = login;
    QString pass = password; // если не будет этих строк - все не заработает
    query.bindValue(":pass", pass);
    query.bindValue(":log", log);
    query.exec();
    QString status;
    query.next();
    QSqlRecord rec = query.record();
    status = "authAnswer&";
    status += query.value(rec.indexOf("status")).toString();
    qDebug() << status;
    if (status == "authAnswer&")
    {
        qDebug() << "error authorization";
        status = "authAnswer&errorAuth";
    }
    else {
       qDebug() << "authorization";
    }
    db.close();
    return status;
}
QByteArray selectAll(QByteArray what, QByteArray where, QSqlDatabase& db){

    openDB("Test",db);
    QSqlQuery query(db);
    int n;
    QByteArray all = "";
    QList <QByteArray> nameOfColumns = what.split(', ');
    query.prepare("pragma table_info(user)");
    query.exec();
    QSqlRecord rec = query.record();
    while(query.next()){
        all += query.value(rec.indexOf("name")).toString();
        all += "&";
        n++;
    }
    query.clear();
    query.prepare("SELECT "+what+" FROM "+where);
    /*qDebug()<<what<<"\t"<<where<<"\n";
    QString whatt = (QString)what;
    QString wherre = (QString)where;
    query.bindValue(":what", whatt);
    query.bindValue(":where", wherre);*/
    query.exec();
    rec = query.record();
    qDebug() << all;
    while(query.next()){ //пролетает весь цикл
        all += query.value(rec.indexOf("login")).toString();
        all += "&";
        all += query.value(rec.indexOf("password")).toString();
        all += "&";
        all += query.value(rec.indexOf("status")).toString();
        all += "&";
    }
    all.prepend('&');
    all.prepend(n+'0');
    all.prepend("selectAllAnswer&");
    qDebug() << QString::fromStdString(all.toStdString());
    db.close();
    return all;
}
QString select(QByteArray what, QByteArray where, QByteArray condition, QSqlDatabase& db){

    openDB("Test",db);
    QSqlQuery query(db);
    int n;
    QByteArray all = "";
    query.prepare("pragma table_info(user)");
    query.exec();
    QSqlRecord rec = query.record();
    while(query.next()){
        all += query.value(rec.indexOf("name")).toString();
        all += "&";
        n++;
    }
    query.clear();
    query.prepare("SELECT " + what+ "FROM "+where+" "+condition);
    /*QString whatt = what;
    QString wherre = where;
    QString cond = condition;
    query.bindValue(":what", what);
    query.bindValue(":where", where);
    query.bindValue(":where", cond);*/
    query.exec();
    rec = query.record();
    qDebug() << all;
    while(query.next()){
        all += query.value(rec.indexOf("login")).toString();
        all += "&";
        all += query.value(rec.indexOf("password")).toString();
        all += "&";
        all += query.value(rec.indexOf("status")).toString();
        all += "&";
    }
    all.prepend('&');
    all.prepend(n+'0');
    all.prepend("selectAnswer");
    qDebug() << QString::fromStdString(all.toStdString());
    db.close();
    return all;
}
QString newQuery(QByteArray what, QByteArray where, QByteArray whatExactly,QSqlDatabase& db){

    openDB("Test",db);
    QSqlQuery query(db);
    QList <QByteArray> all = whatExactly.split(',');
    qDebug() << "INSERT INTO "+where+" "+what+" VALUES "+whatExactly;
    query.prepare("INSERT INTO "+where+" "+what+" VALUES (:one, :two, :three)");
    query.bindValue(":one",all[0]);
    query.bindValue(":two",all[1]);
    query.bindValue(":three",all[2]);
    query.exec();
    db.close();
    return selectAll("*",where, db);

}
