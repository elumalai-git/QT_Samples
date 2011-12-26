#include <QtGui/QApplication>
#include "sender.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Sender w;

    w.timer();


    return a.exec();
}
