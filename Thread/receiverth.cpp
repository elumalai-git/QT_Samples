#include "receiverth.h"
#include<QDebug>
#include<QThread>

ReceiverTh::ReceiverTh(QObject *parent) :
    QObject(parent)
{

}

void ReceiverTh::ThCounter()
{
    static int icounter = 0;
    qDebug() << "Receiver ThreadID =" << QThread::currentThreadId();
    qDebug()<<"Thread counter value"<<icounter;
    icounter++;

}
