#include <QtGui/QApplication>
#include "downloadmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Downloadmanager w;
//    w.start();
    w.show();

    return a.exec();
}
