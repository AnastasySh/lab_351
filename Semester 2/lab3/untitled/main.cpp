#include <QCoreApplication>
#include "mytcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    myTcpServer server;

    // создание объекта сервер

    return a.exec();
}
