#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(0,0,1000,800);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    webview = new QWebView(this);
    webview->setGeometry(0,170,1000,800);
    webview->load(QUrl("http://google.com"));
}


void MainWindow::on_close_btn_clicked()
{
    webview->close();
}

void MainWindow::on_fc_btn_activated(QString )
{
    if(ui->fc_btn->currentText() == "SetFG")
    {
        webview->raise();
    }
    else if(ui->fc_btn->currentText() == "SetBG")
    {
        webview->lower();
    }
}

void MainWindow::on_comboBox_activated(QString url_name)
{

    url_name = ui->comboBox->currentText();

    webview->load(url_name);
    webview->setFocus();
}

void MainWindow::on_load_btn_clicked()
{
    QUrl url = QUrl(ui->urledit->text());
    webview->load(url);
    webview->show();
    webview->setFocus();
}

void MainWindow::on_load_new_clicked()
{
    QWebView *webview_new = new QWebView(this);
    webview_new->setGeometry(0,200,1000,800);
    QUrl url = QUrl(ui->urledit->text());
    webview_new->load(url);
    webview_new->show();
    webview_new->setFocus();

}
