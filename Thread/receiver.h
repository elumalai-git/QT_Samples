#ifndef RECEIVERTH_H
#define RECEIVERTH_H

#include <QObject>

class ReceiverTh : public QObject
{
    Q_OBJECT
public:
    explicit ReceiverTh(QObject *parent = 0);

public slots:
    void ThCounter();

};

#endif // RECEIVERTH_H
