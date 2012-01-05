#ifndef JAVASCRIPT_H
#define JAVASCRIPT_H

#include <QtGui/QWidget>
#include <QtWebKit>
#include <QtDebug>

class JavaScript : public QWebView
{
    Q_OBJECT

public:
    JavaScript(QWidget *parent = 0);
    ~JavaScript();
signals:
    void sigAnother();
    void sigSuccess(QVariant);
    void sigtimer();
public slots:
//    QString cppsayHello(QVariantMap);
    QString cppGetObjectName();
};

#endif // JAVASCRIPT_H
