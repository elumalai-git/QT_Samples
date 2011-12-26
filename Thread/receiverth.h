#ifndef RECEIVERTH_H
#define RECEIVERTH_H
#include <QThread>
//#include <QObject>

class ReceiverTh : public QThread
{
    Q_OBJECT
public:
    explicit ReceiverTh(QThread *parent = 0);

protected:
    void run();

signals:

public slots:
    void ThCounter();

};

#endif // RECEIVERTH_H
