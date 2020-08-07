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
    QLabel *Title;
    QTextEdit *id;
    QLabel *IDSig;
    QTextEdit *Pais;
    QLabel *pais;
    QLabel *secondName;
    QTextEdit *sencondN;
    QPushButton *familyState;
    QPushButton *hLS;
    QPushButton *CFS;

    void setupUi(QDialog *SinMenu)
    {
        if (SinMenu->objectName().isEmpty())
            SinMenu->setObjectName(QString::fromUtf8("SinMenu"));
        SinMenu->resize(1547, 942);
        SinMenu->setModal(false);
        TOP10 = new QPushButton(SinMenu);
        TOP10->setObjectName(QString::fromUtf8("TOP10"));
        TOP10->setGeometry(QRect(150, 660, 181, 91));
        TOP10->setFlat(true);
        SCREEN = new QTextEdit(SinMenu);
        SCREEN->setObjectName(QString::fromUtf8("SCREEN"));
        SCREEN->setGeometry(QRect(530, 100, 941, 621));
        TOP5 = new QPushButton(SinMenu);
        TOP5->setObjectName(QString::fromUtf8("TOP5"));
        TOP5->setGeometry(QRect(150, 760, 181, 91));
        TOP5->setFlat(true);
        Title = new QLabel(SinMenu);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setGeometry(QRect(120, 50, 381, 181));
        Title->setPixmap(QPixmap(QString::fromUtf8("../ImagenesGUI/hellT.png")));
        id = new QTextEdit(SinMenu);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(140, 240, 221, 31));
        IDSig = new QLabel(SinMenu);
        IDSig->setObjectName(QString::fromUtf8("IDSig"));
        IDSig->setGeometry(QRect(70, 240, 67, 17));
        QPalette palette;
        QBrush brush(QColor(238, 238, 236, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(246, 246, 245, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(119, 119, 118, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(159, 159, 157, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush5);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        IDSig->setPalette(palette);
        Pais = new QTextEdit(SinMenu);
        Pais->setObjectName(QString::fromUtf8("Pais"));
        Pais->setGeometry(QRect(140, 280, 221, 31));
        pais = new QLabel(SinMenu);
        pais->setObjectName(QString::fromUtf8("pais"));
        pais->setGeometry(QRect(60, 290, 67, 17));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush8(QColor(127, 127, 127, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush8);
        QBrush brush9(QColor(170, 170, 170, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        pais->setPalette(palette1);
        pais->setAutoFillBackground(false);
        pais->setTextFormat(Qt::PlainText);
        secondName = new QLabel(SinMenu);
        secondName->setObjectName(QString::fromUtf8("secondName"));
        secondName->setGeometry(QRect(60, 340, 67, 17));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        secondName->setPalette(palette2);
        sencondN = new QTextEdit(SinMenu);
        sencondN->setObjectName(QString::fromUtf8("sencondN"));
        sencondN->setGeometry(QRect(140, 330, 221, 31));
        familyState = new QPushButton(SinMenu);
        familyState->setObjectName(QString::fromUtf8("familyState"));
        familyState->setGeometry(QRect(130, 384, 231, 51));
        hLS = new QPushButton(SinMenu);
        hLS->setObjectName(QString::fromUtf8("hLS"));
        hLS->setGeometry(QRect(130, 450, 231, 51));
        CFS = new QPushButton(SinMenu);
        CFS->setObjectName(QString::fromUtf8("CFS"));
        CFS->setGeometry(QRect(130, 510, 231, 51));

        retranslateUi(SinMenu);

        QMetaObject::connectSlotsByName(SinMenu);
    } // setupUi

    void retranslateUi(QDialog *SinMenu)
    {
        SinMenu->setWindowTitle(QCoreApplication::translate("SinMenu", "Dialog", nullptr));
        TOP10->setText(QString());
        TOP5->setText(QString());
        Title->setText(QString());
        IDSig->setText(QCoreApplication::translate("SinMenu", "ID:", nullptr));
        pais->setText(QCoreApplication::translate("SinMenu", "Country:", nullptr));
        secondName->setText(QCoreApplication::translate("SinMenu", "Second N.", nullptr));
        familyState->setText(QCoreApplication::translate("SinMenu", "Family State", nullptr));
        hLS->setText(QCoreApplication::translate("SinMenu", "Highest to Lower Sinners", nullptr));
        CFS->setText(QCoreApplication::translate("SinMenu", "Country/Family", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SinMenu: public Ui_SinMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINMENU_H
