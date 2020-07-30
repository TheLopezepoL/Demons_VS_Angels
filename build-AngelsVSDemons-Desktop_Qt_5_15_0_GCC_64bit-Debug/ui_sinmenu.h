/********************************************************************************
** Form generated from reading UI file 'sinmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINMENU_H
#define UI_SINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SinMenu
{
public:
    QPushButton *TOP10;
    QTextEdit *SCREEN;
    QPushButton *TOP5;
    QLabel *label;

    void setupUi(QDialog *SinMenu)
    {
        if (SinMenu->objectName().isEmpty())
            SinMenu->setObjectName(QString::fromUtf8("SinMenu"));
        SinMenu->resize(1547, 942);
        SinMenu->setModal(false);
        TOP10 = new QPushButton(SinMenu);
        TOP10->setObjectName(QString::fromUtf8("TOP10"));
        TOP10->setGeometry(QRect(170, 480, 181, 91));
        TOP10->setFlat(true);
        SCREEN = new QTextEdit(SinMenu);
        SCREEN->setObjectName(QString::fromUtf8("SCREEN"));
        SCREEN->setGeometry(QRect(530, 100, 941, 621));
        TOP5 = new QPushButton(SinMenu);
        TOP5->setObjectName(QString::fromUtf8("TOP5"));
        TOP5->setGeometry(QRect(170, 580, 181, 91));
        TOP5->setFlat(true);
        label = new QLabel(SinMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 50, 381, 181));
        label->setPixmap(QPixmap(QString::fromUtf8("../ImagenesGUI/hellT.png")));

        retranslateUi(SinMenu);

        QMetaObject::connectSlotsByName(SinMenu);
    } // setupUi

    void retranslateUi(QDialog *SinMenu)
    {
        SinMenu->setWindowTitle(QCoreApplication::translate("SinMenu", "Dialog", nullptr));
        TOP10->setText(QString());
        TOP5->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SinMenu: public Ui_SinMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINMENU_H
