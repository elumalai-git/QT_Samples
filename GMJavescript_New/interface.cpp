#include "interface.h"

Interface::Interface(QObject *parent) :
    QObject(parent)
{
    setObjectName("js"+QString::number(rand()));
}

void Interface::GetAge(QVariantMap data) {
    qDebug("Inside GetName");
    m_data = data;
    startTimer(3000);
}

void Interface::timerEvent(QTimerEvent *event) {
    qDebug()<<"TimerID"<<event->timerId();
    emit sigSuccess(QVariant(m_data).value<QVariantMap>());
    killTimer(event->timerId());
    deleteLater();
}
