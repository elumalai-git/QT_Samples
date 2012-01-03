#include "downloadmanager.h"

#include "ui_downloadmanager.h"

Downloadmanager::Downloadmanager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Downloadmanager)
{
    ui->setupUi(this);

    connect(ui->downloadbtn, SIGNAL(clicked()), this, SLOT(downloadFile()));

}

Downloadmanager::~Downloadmanager()
{
    delete ui;
}

void Downloadmanager::downloadFile() {


    url = ui->urlbtn->currentText();

    b_Request = false;
    startRequest(url);
}
void Downloadmanager::startRequest(QUrl &url) {

    m_qnam = new QNetworkAccessManager;
    m_request = new QNetworkRequest(url);
    m_reply = m_qnam->get(*m_request);
    cDownload *cdownload = new cDownload(this);


    connect(m_reply,SIGNAL(finished()),this,SLOT(downloadFinished()));

    connect(m_reply, SIGNAL(downloadProgress(qint64,qint64)),
            cdownload, SLOT(updateprogrssbar(qint64,qint64)));
}
void Downloadmanager::WriteFile()
{
    if (m_reply->error()) {
        fprintf(stderr, "Download of %s failed: %s\n",
                url.toEncoded().constData(),
                qPrintable(m_reply->errorString()));

    }
    else
    {
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
        if (m_file)
        {
            m_file->write(m_reply->readAll());
            m_file->flush();
            m_file->close();
            delete m_file;
            m_file = 0;
        }
    }

}

void Downloadmanager::downloadFinished()
{
    qDebug("Downloadfinished");
    WriteFile();
}

