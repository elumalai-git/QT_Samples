#ifndef RECEIVER_H
#define RECEIVER_H

#include <QWidget>
#include <QDebug>

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);

private slots:
    void sltReceiver();

};

#endif // RECEIVER_H
