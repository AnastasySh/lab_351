#ifndef DB_H
#define DB_H
#include <QString>
#include <QSqlDatabase>
bool openDB(QString name);
QString authorize(QString login, QString password, QSqlDatabase& db);
QByteArray selectAll(QByteArray login, QByteArray password, QSqlDatabase& db);
QString select(QByteArray login, QByteArray password, QByteArray condition,QSqlDatabase& db);
QString newQuery(QByteArray what, QByteArray whatExactly, QByteArray where, QSqlDatabase& db);
#endif // DB_H
