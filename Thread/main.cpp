#include <QtGui/QApplication>
#include <QThread>
#include "senderth.h"
#include "receiverth.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread *thread = new QThread;

    Sender *sender = new Sender;

    sender->moveToThread(thread);
    ReceiverTh receiver;

    thread->start();
    QObject::connect(sender,SIGNAL(sigsender()),&receiver,SLOT(ThCounter()),Qt::QueuedConnection);

    return a.exec();
}
