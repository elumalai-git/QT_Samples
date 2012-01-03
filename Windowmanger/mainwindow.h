#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtWebKit>

namespace Ui {
    class MainWindow;
}
 class QWebView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void on_close_btn_clicked();

    void on_fc_btn_activated(QString );

    void on_launch_btn_clicked();

    void on_addurl_clicked();

private:
    Ui::MainWindow *ui;
    QWebView *m_webview;
    QWebView *m_zorder;
    QMap <QString, QWebView* > m_map;
    QString strUrlName;
};

#endif // MAINWINDOW_H
