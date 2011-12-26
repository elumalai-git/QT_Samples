#ifndef SENDER_H
#define SENDER_H

#include <receiver.h>
#include <QWidget>
#include <QtGui>

namespace Ui {
    class Sender;
}

class Sender : public QObject
{
    Q_OBJECT

public:
    explicit Sender(QObject * parent = 0);
    ~Sender();

    void timer();

protected:
    void timerEvent(QTimerEvent *);

signals:
    void sigSender();

private:

    Receiver *obj_recv;
    int i;

};

#endif // SENDER_H
