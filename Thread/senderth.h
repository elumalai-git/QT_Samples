#ifndef SENDERTH_H
#define SENDERTH_H

#include <QtGui/QWidget>
#include"receiverth.h"

class Sender : public QObject
{
    Q_OBJECT
    int i;
    ReceiverTh *obj_recvth;

public:
    Sender(QObject *parent = 0);
    void start();
    ~Sender();
signals:
    void sigsender();
protected:
    void timerEvent(QTimerEvent *);
};

#endif // SENDERTH_H
