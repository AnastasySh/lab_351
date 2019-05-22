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
     qDebug() << "QUERY IS  " + query.lastQuery();
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
    query.prepare("SELECT " +what+ "FROM "+where+" WHERE login = \""+QString::fromStdString(condition.toStdString())+"\" OR password = \""+QString::fromStdString(condition.toStdString())+
                  "\" OR status = \""+QString::fromStdString(condition.toStdString())+"\"");
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
    all.prepend("selectAnswer&");
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
    query.bindValue(":one",QString::fromStdString(all[0].toStdString()));
    query.bindValue(":two",QString::fromStdString(all[1].toStdString()));
    query.bindValue(":three",QString::fromStdString(all[2].toStdString()));
    query.exec();
    db.close();
    return selectAll("*",where, db);

}
QString update(QByteArray where, QByteArray what, QSqlDatabase& db){
   openDB("Test",db);
   QSqlQuery query(db);
    QList <QByteArray> all = what.split(',');
     query.prepare("UPDATE "+where+" SET login = \""+QString::fromStdString(all[3].toStdString())+"\", password = \""+QString::fromStdString(all[4].toStdString())+"\","
                   " status = \""+QString::fromStdString(all[5].toStdString())+"\" WHERE login = \""+QString::fromStdString(all[0].toStdString())+"\""
                                   "  AND password = \""+QString::fromStdString(all[1].toStdString())+"\" AND status = \""+QString::fromStdString(all[2].toStdString())+"\"");
     /*query.bindValue(":log",all[0]);
     query.bindValue(":pass",all[1]);
     query.bindValue(":status",all[2]);
     query.bindValue(":lastlog",all[3]);
     query.bindValue(":lastPass",all[4]);
     query.bindValue(":lastStat",all[5]);
     qDebug() << "QUERY IS  " + query.lastQuery();*/
     query.exec();
     qDebug() << query.lastQuery();
     db.close();
      return selectAll("*",where, db);
}
QString deleteRec (QByteArray where, QByteArray what, QSqlDatabase& db){
    openDB("Test",db);
    QSqlQuery query(db);
     QList <QByteArray> all = what.split(','); // вся проблема опять в кавычках
     query.prepare("DELETE FROM "+where+" WHERE login = \""+QString::fromStdString(all[0].toStdString())+"\" AND password = \""
             +QString::fromStdString(all[1].toStdString())+"\" AND status = \""+QString::fromStdString(all[2].toStdString())+"\"");
     qDebug() << "DELETE FROM "+where+" WHERE login = \""+QString::fromStdString(all[0].toStdString())+"\" AND password = \""
             +QString::fromStdString(all[1].toStdString())+"\" AND status = \""+QString::fromStdString(all[2].toStdString())+"\"";
    /*query.bindValue(":lastLog",all[0]);
     query.bindValue(":lastPass",all[1]);
     query.bindValue(":lastStat",all[2]);*/
     query.exec();
     db.close();
     return selectAll("*",where, db);
}
