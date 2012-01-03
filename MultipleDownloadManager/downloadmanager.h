#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

//#include "cdownload.h"
#include "cdownload.h"

#include <QMainWindow>
#include <QtNetwork>
#include <QDebug>
#include <QtGui>


namespace Ui {
class Downloadmanager;
}

class Downloadmanager : public QMainWindow
{
    Q_OBJECT

public:
    explicit Downloadmanager(QWidget *parent = 0);
    ~Downloadmanager();
signals:
    void trailprocress();

private slots:

    void downloadFile();
    void startRequest(QUrl &url);
    void StoreFile();
    void downloadFinished();

    void on_quitbutton_clicked();

private:
    Ui::Downloadmanager *ui;

    QProgressBar m_progressbar;
    QMap<QProgressBar, QNetworkRequest> m_map;
    QUrl url ;

    QList<QNetworkReply *> m_currentDownloads;
    QNetworkAccessManager *m_qnam;
    QNetworkReply *m_reply;
    QNetworkRequest *m_request;
    bool b_Request;
};

#endif // DOWNLOADMANAGER_H
