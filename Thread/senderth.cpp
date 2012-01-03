#include "senderth.h"
#include <QDebug>
#include <QEventLoop>

Sender::Sender(QObject *parent)
    : QObject(parent)
{
    startTimer(200);
}

Sender::~Sender()
{

}
void Sender::run()
{
    QEventLoop loop;
    loop.exec();

}

void Sender::timerEvent(QTimerEvent *)
{
    static int i = 0;
    i++;
    if(i == 3)
    {
        emit sigsender();
        qDebug() << "Sender ThreadID =" << QThread::currentThreadId();
        i = 0;
    }

}
