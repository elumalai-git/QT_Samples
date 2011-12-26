/********************************************************************************
** Form generated from reading UI file 'sender.ui'
**
** Created: Mon Dec 26 17:44:47 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDER_H
#define UI_SENDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sender
{
public:

    void setupUi(QWidget *Sender)
    {
        if (Sender->objectName().isEmpty())
            Sender->setObjectName(QString::fromUtf8("Sender"));
        Sender->resize(400, 300);

        retranslateUi(Sender);

        QMetaObject::connectSlotsByName(Sender);
    } // setupUi

    void retranslateUi(QWidget *Sender)
    {
        Sender->setWindowTitle(QApplication::translate("Sender", "Sender", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sender: public Ui_Sender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDER_H
