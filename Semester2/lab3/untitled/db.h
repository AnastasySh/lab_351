#ifndef DB_H
#define DB_H
#include <QString>
bool open_db(QString name);
QString authorize(QString login, QString password);
QString db_select(QString login, QString password);
QString db_select(std::string login, std::string password, std::string condition);
#endif // DB_H
