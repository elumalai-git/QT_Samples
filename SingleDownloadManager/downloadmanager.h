#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QMainWindow>
#include <QtGui>
#include <QtNetwork>


namespace Ui {
    class DownloadManager;
}

class DownloadManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit DownloadManager(QWidget *parent = 0);
    ~DownloadManager();
    void start();
    void startRequest(QNetworkRequest & url);

private slots:

    void enableDownloadButton();
    void downloadFile();
    void downloadFinished();
    void WriteFile();
    void cancelDownload();
    void pauseDownload();

    void DataProgress(qint64 ibytesRead,qint64 itotalBytes);
    void sslErrors(QNetworkReply*,const QList<QSslError> &sslError);

//    void on_networkdisablebtn_clicked();
//    void on_networkenablebtn_clicked();
    void on_quitbutton_clicked();

private:
    Ui::DownloadManager *ui;

    qint64 iDownloadSizeAtPause;
    bool b_Request;

    QFile *m_file;
    QList<QNetworkReply *> m_currentDownloads;

    QNetworkAccessManager m_qnam;
    QNetworkReply *m_reply;
    QNetworkRequest m_request;



};

#endif // DOWNLOADMANAGER_H
