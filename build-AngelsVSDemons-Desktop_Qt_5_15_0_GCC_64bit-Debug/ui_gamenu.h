/********************************************************************************
** Form generated from reading UI file 'gamenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMENU_H
#define UI_GAMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_GAMenu
{
public:
    QPlainTextEdit *screen;

    void setupUi(QDialog *GAMenu)
    {
        if (GAMenu->objectName().isEmpty())
            GAMenu->setObjectName(QString::fromUtf8("GAMenu"));
        GAMenu->resize(1414, 938);
        screen = new QPlainTextEdit(GAMenu);
        screen->setObjectName(QString::fromUtf8("screen"));
        screen->setGeometry(QRect(320, 220, 831, 531));

        retranslateUi(GAMenu);

        QMetaObject::connectSlotsByName(GAMenu);
    } // setupUi

    void retranslateUi(QDialog *GAMenu)
    {
        GAMenu->setWindowTitle(QCoreApplication::translate("GAMenu", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GAMenu: public Ui_GAMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMENU_H
