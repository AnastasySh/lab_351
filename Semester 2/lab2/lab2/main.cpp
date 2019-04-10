#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include "r.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    myTcpServer server(33333);

    server.show();

    return app.exec();
}
