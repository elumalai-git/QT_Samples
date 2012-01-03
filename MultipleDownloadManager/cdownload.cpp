#include "cdownload.h"
#include <QDebug>

cDownload::cDownload(QWidget *parent) :
    QWidget(parent)
{
    static int y = 100;
    m_progressbar = new QProgressBar(parent);
    m_progressbar->setGeometry(50,y,580,20);
    y = y + 50;
//    qDebug()<<y;
    m_progressbar->show();
}

void cDownload::updateprogrssbar(qint64 bytesRead, qint64 bytesTotal)
{

    m_progressbar->setMaximum(bytesTotal);
    m_progressbar->setValue(bytesRead);

//qDebug("Dataprogress called");
//    if(bytesTotal != 0)
//        qDebug()<<"Actual KBytes"<< (bytesTotal) / 1024 ;
}

