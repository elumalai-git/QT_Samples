/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Dec 27 16:19:18 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QComboBox *fc_btn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *urledit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *load_btn;
    QPushButton *load_new;
    QPushButton *close_btn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 8000);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 20, 781, 27));
        fc_btn = new QComboBox(centralWidget);
        fc_btn->setObjectName(QString::fromUtf8("fc_btn"));
        fc_btn->setGeometry(QRect(870, 20, 97, 27));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 70, 851, 64));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        urledit = new QLineEdit(widget);
        urledit->setObjectName(QString::fromUtf8("urledit"));

        horizontalLayout->addWidget(urledit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        load_btn = new QPushButton(widget);
        load_btn->setObjectName(QString::fromUtf8("load_btn"));

        verticalLayout_2->addWidget(load_btn);

        load_new = new QPushButton(widget);
        load_new->setObjectName(QString::fromUtf8("load_new"));

        verticalLayout_2->addWidget(load_new);


        horizontalLayout->addLayout(verticalLayout_2);

        close_btn = new QPushButton(centralWidget);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));
        close_btn->setGeometry(QRect(940, 120, 41, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "http://www.google.com", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "http://www.yahoo.com", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "http://www.gmail.com", 0, QApplication::UnicodeUTF8)
        );
        fc_btn->clear();
        fc_btn->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "SetFG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "SetBG", 0, QApplication::UnicodeUTF8)
        );
        urledit->setText(QApplication::translate("MainWindow", "http://", 0, QApplication::UnicodeUTF8));
        load_btn->setText(QApplication::translate("MainWindow", "load(samepage)", 0, QApplication::UnicodeUTF8));
        load_new->setText(QApplication::translate("MainWindow", "load(newtab)", 0, QApplication::UnicodeUTF8));
        close_btn->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
