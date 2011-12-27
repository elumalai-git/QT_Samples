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
    void init();
private slots:
    void on_load_btn_clicked();

    void on_close_btn_clicked();

    void on_fc_btn_activated(QString );

    void on_comboBox_activated(QString );

    void on_load_new_clicked();

private:
    Ui::MainWindow *ui;
    QWebView *webview;
};

#endif // MAINWINDOW_H
