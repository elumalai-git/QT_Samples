#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(0,0,1000,800);
    m_webview = new QWebView(this);
    m_webview->setGeometry(0,150,1000,800);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_fc_btn_activated(QString )
{
    strUrlName = ui->comboBox->currentText();
    m_zorder = m_map[strUrlName];

    if(ui->fc_btn->currentText() == "SetFG")
    {
        m_zorder->raise();
    }
    else if(ui->fc_btn->currentText() == "SetBG")
    {
        m_zorder->lower();
    }

}

void MainWindow::on_launch_btn_clicked()
{

    m_webview = new QWebView(this);
    m_webview->setGeometry(0,150,1000,800);

    strUrlName = ui->comboBox->currentText();

    m_map[strUrlName] = m_webview;

    QUrl url = QUrl(strUrlName);

    m_webview->load(url);

    m_webview->show();
    m_webview->setFocus();

}

void MainWindow::on_addurl_clicked()
{
    ui->comboBox->addItem(ui->urledit->text());
}

void MainWindow::on_close_btn_clicked()
{
    ui->comboBox->setItemText(ui->comboBox->currentIndex(),"");
    m_zorder->close();

}
