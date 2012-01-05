#include "javascript.h"
#include "interface.h"
#include <QtDebug>

JavaScript::JavaScript(QWidget *parent)
    : QWebView(parent)
{
    QWebFrame *frame = this->page()->mainFrame();
    frame->addToJavaScriptWindowObject("gmint",this);
}

JavaScript::~JavaScript()
{

}

QString JavaScript::cppGetObjectName() {
    qDebug("Inside Getobject");
    Interface *pinterface = new Interface(this);
    return pinterface->objectName();
}

