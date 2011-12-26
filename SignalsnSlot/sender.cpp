#include "sender.h"
#include "ui_sender.h"

Sender::Sender(QObject *parent) :
    QObject(parent)
{
    i = 1;
    obj_recv = new Receiver;
    startTimer(200);
}

Sender::~Sender()
{
    delete obj_recv;
}


void Sender::timer()
{

    connect(this,SIGNAL(sigSender()),obj_recv,SLOT(sltReceiver()),Qt::QueuedConnection);

}
void Sender::timerEvent(QTimerEvent *)
{


    if(i == 3)
    {
        emit sigSender();
        i = 0;
    }
    i++;

}


