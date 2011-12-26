#include <QtGui/QApplication>
#include "senderth.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Sender w;
    w.start();
    return a.exec();
}
