#ifndef CDOWNLOAD_H
#define CDOWNLOAD_H

#include <QtGui>
#include <QWidget>

class cDownload : public QWidget
{
    Q_OBJECT
public:
    explicit cDownload(QWidget *parent = 0);

signals:

public slots:
    void updateprogrssbar(qint64,qint64);
private:
    QProgressBar *m_progressbar;

};

#endif // CDOWNLOAD_H
