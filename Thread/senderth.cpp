#include "senderth.h"
#include <QDebug>

Sender::Sender(QObject *parent)
    : QObject(parent)
{
    i = 0;
    startTimer(200);
    obj_recvth = new ReceiverTh();
    obj_recvth->start();


}

Sender::~Sender()
{

}

void Sender::start()
{
    connect(this,SIGNAL(sigsender()),obj_recvth,SLOT(ThCounter()),Qt::QueuedConnection);
}

void Sender::timerEvent(QTimerEvent *)
{
    if(i == 3)
    {
        emit sigsender();
        qDebug() << "Sender ThreadID =" << QThread::currentThreadId();
        i = 0;
    }
    i++;
}
