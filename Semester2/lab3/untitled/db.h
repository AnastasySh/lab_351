#ifndef DB_H
#define DB_H
#include <QString>
bool open_db(QString name);
QString authorize(std::string login, std::string password);

#endif // DB_H
