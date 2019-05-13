#ifndef DB_H
#define DB_H
#include <QString>
bool openDB(QString name);
QString authorize(QByteArray login, QByteArray password);
QByteArray selectAll(QByteArray login, QByteArray password);
QString select(QByteArray login, QByteArray password, QByteArray condition);
QString newQuery(QByteArray what, QByteArray whatExactly, QByteArray where);
#endif // DB_H
