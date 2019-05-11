#include "party_work.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Party_work w;
    w.show();

    return a.exec();
}
