#include "downloadmanager.h"
#include "ui_downloadmanager.h"

DownloadManager::DownloadManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DownloadManager)
{
    iDownloadSizeAtPause = 0;
    ui->setupUi(this);

}

DownloadManager::~DownloadManager()
{
    delete ui;
}

void DownloadManager::start()
{

    connect(ui->lineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableDownloadButton()));

    connect(&m_qnam, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),
                    this, SLOT(sslErrors(QNetworkReply*,QList<QSslError>)));
    connect(ui->downloadButton, SIGNAL(clicked()), this, SLOT(downloadFile()));
    connect(ui->pausebutton,SIGNAL(clicked()),this,SLOT(pauseDownload()));


}
void DownloadManager::startRequest(QNetworkRequest &req)
{


    m_reply = m_qnam.get(req);

    connect(m_reply, SIGNAL(readyRead()),
            this, SLOT(WriteFile()));
    connect(m_reply,SIGNAL(finished()),this,SLOT(downloadFinished()));
//    connect(&qnam,SIGNAL(networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility)),
//            this,SLOT(on_networkdisablebtn_clicked()));
    connect(m_reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(DataProgress(qint64,qint64)));
    m_currentDownloads.append(m_reply);
}


void DownloadManager::downloadFile()
{
    QUrl url = ui->lineEdit->text();
    QFileInfo fileInfo(url.path());

    QString fileName = fileInfo.fileName();
    if (fileName.isEmpty())
        fileName = "index.html";

    if (QFile::exists(fileName))
    {
        if (QMessageBox::question(this, tr("Download Manager"),
                                  tr("There already exists a file called %1 in "
                                     "the current directory. Overwrite?").arg(fileName),
                                  QMessageBox::Yes|QMessageBox::No, QMessageBox::No) == QMessageBox::No)
            return;

    }
        QFile::remove(fileName);
         m_file = new QFile(fileName);
         if(!m_file->open(QIODevice::WriteOnly))
         {
             QMessageBox::information(this, tr("Download Manager"),
                                      tr("Unable to save the file %1: %2.")
                                      .arg(fileName).arg(m_file->errorString()));
             delete m_file;
             m_file = 0;
             return;
         }

         ui->downloadinglabel->setText(tr("Downloading %1.").arg(fileName));

         b_Request = false;
         m_request.setUrl(url);
         startRequest(m_request);
}

void DownloadManager::pauseDownload()
{
      if(ui->pausebutton->text() == "Pause")
    {
        if(m_reply == 0)
        {
            return;
        }
        ui->pausebutton->setText("Resume");
        disconnect(m_reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(DataProgress(qint64,qint64)));
        disconnect(m_reply,SIGNAL(finished()),this,SLOT(downloadFinished()));
        m_reply->abort();
        WriteFile();
        m_reply = 0;
    }
    else if(ui->pausebutton->text() == "Resume")
    {

        ui->pausebutton->setText("Pause");
        iDownloadSizeAtPause = m_file->size();
        qDebug()<<"Downloadsize"<<iDownloadSizeAtPause / 1024;
        QByteArray rangeHeaderValue = "bytes=" + QByteArray::number(iDownloadSizeAtPause) + "-";
        m_request.setRawHeader("Range",rangeHeaderValue);

        startRequest(m_request);
    }
}

void DownloadManager::cancelDownload()
{

    b_Request= true;
    m_reply->abort();
    ui->downloadButton->setEnabled(true);
}


void DownloadManager::DataProgress(qint64 ibytesRead, qint64 ibytesTotal)
{
    if (b_Request)
        return;
    ui->progressBar1->setMaximum(ibytesTotal);
    ui->progressBar1->setValue(iDownloadSizeAtPause + ibytesRead);


    if(ibytesTotal != 0)
        qDebug()<<"Actual KBytes"<< (ibytesTotal) / 1024 ;
}

void DownloadManager::WriteFile()
{
    if (m_file)
        m_file->write(m_reply->readAll());
}

void DownloadManager::enableDownloadButton()
{
    ui->downloadButton->setEnabled(true);
}

void DownloadManager::on_quitbutton_clicked()
{
    QMainWindow::close();
}

void DownloadManager::downloadFinished()
{

    qDebug("Downloadfinished");

    ui->downloadButton->setEnabled(true);
    m_currentDownloads.removeAll(m_reply);

    m_file->flush();
    m_file->close();
    delete m_file;
    m_file = 0;

    m_reply->deleteLater();
    m_reply = 0;

}

void DownloadManager::sslErrors(QNetworkReply *,const QList<QSslError> &sslError)
{
    QString strError;

    foreach(const QSslError &error, sslError) {
        if(!strError.isEmpty())
            strError += ",";
        strError += error.errorString();
    }
    if (QMessageBox::warning(this, tr("Download Manager"),
                             tr("One or more SSL errors has occurred: %1").arg(strError),
                             QMessageBox::Ignore | QMessageBox::Abort) == QMessageBox::Ignore) {
        m_reply->ignoreSslErrors();
    }
}

//void DownloadManager::on_networkdisablebtn_clicked()
//{
//    m_qnam.setNetworkAccessible(QNetworkAccessManager::NotAccessible);
//}

//void DownloadManager::on_networkenablebtn_clicked()
//{
//    m_qnam.setNetworkAccessible(QNetworkAccessManager::Accessible);
//}

