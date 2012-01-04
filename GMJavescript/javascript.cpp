#include "javascript.h"

JavaScript::JavaScript(QWidget *parent)
    : QWebView(parent)
{
    startTimer(3000);
    QWebFrame *frame = this->page()->mainFrame();
    frame->addToJavaScriptWindowObject("gmint",this);
}

JavaScript::~JavaScript()
{

}

QString JavaScript::cppsayHello(QVariantMap data) {
    emit sigSuccess(QVariant(data).value<QVariantMap>());
    return ("Hello");
}

void JavaScript::timerEvent(QTimerEvent *) {
    qDebug()<<"Inside TimerEvent";

    emit sigtimer();
}

