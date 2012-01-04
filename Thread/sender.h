#ifndef SENDERTH_H
#define SENDERTH_H

#include <QtGui/QWidget>
#include <QThread>


class Sender : public QObject
{
    Q_OBJECT

public:
    Sender(QObject *parent = 0);

    ~Sender();

protected:
    void run();
    void timerEvent(QTimerEvent *);

signals:
    void sigsender();

};

#endif // SENDERTH_H
