#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtGui>
#include <QObject>

class Interface : public QObject
{
    Q_OBJECT
public:
    explicit Interface(QObject *parent = 0);
    QVariantMap m_data;
signals:
    void sigSuccess(QVariant);
    void sigFailure();
public slots:
    void GetAge(QVariantMap data);
    void timerEvent(QTimerEvent *);
};

#endif // INTERFACE_H
