#ifndef DB_H
#define DB_H
#include <QString>
#include <QSqlDatabase>
bool openDB(QString name);
QString authorize(QString login, QString password, QSqlDatabase& db);
QByteArray selectAll(QByteArray what, QByteArray where, QSqlDatabase& db);
QString select(QByteArray what, QByteArray where, QByteArray condition,QSqlDatabase& db);
QString newQuery(QByteArray what, QByteArray whatExactly, QByteArray where, QSqlDatabase& db);
QString update(QByteArray where, QByteArray what,QSqlDatabase& db);
QString deleteRec (QByteArray where, QByteArray what, QSqlDatabase& db);
#endif // DB_H
