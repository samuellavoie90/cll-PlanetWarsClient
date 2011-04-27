#include <QtGui/QApplication>
#include "clientmaingame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientMainGame w;
    w.show();

    return a.exec();
}
