#include "receiverth.h"
#include<QDebug>
#include <QEventLoop>

ReceiverTh::ReceiverTh(QThread *parent) :
    QThread(parent)
{
    moveToThread(this);
}


void ReceiverTh::run()
{
    QEventLoop ev_loop;
    ev_loop.exec();

}

void ReceiverTh::ThCounter()
{
    static int counter = 0;
    qDebug() << "Receiver ThreadID =" << currentThreadId();
    qDebug()<<"Thread counter value"<<counter;
    counter++;

}
