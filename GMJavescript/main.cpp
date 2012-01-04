#include <QtGui/QApplication>
#include "javascript.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JavaScript w;
//    w.load(QUrl("file:///home/elumalai/Downloads/qtwebkittrainingexampleattachedeom/test.html"));
    w.load(QUrl("file:://home/elumalai/Documents/test.html"));
    w.show();

    return a.exec();
}
