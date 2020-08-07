/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *title;
    QPushButton *Start;
    QPushButton *Birth;
    QPushButton *SinGenerator;
    QPushButton *GAGenerator;
    QPushButton *SinMenu;
    QPushButton *GAMenu;
    QPushButton *Salvation;
    QPushButton *Damnation;
    QTextEdit *textEdit;
    QPushButton *ABB;
    QPushButton *Hell;
    QPushButton *SetWInner;
    QPushButton *Maps;
    QPushButton *Maps2;
    QTextEdit *cant;
    QPushButton *Heaven;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(2002, 1176);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(150, 0, 1301, 141));
        title->setPixmap(QPixmap(QString::fromUtf8("../ImagenesGUI/title.png")));
        Start = new QPushButton(centralwidget);
        Start->setObjectName(QString::fromUtf8("Start"));
        Start->setGeometry(QRect(130, 710, 201, 81));
        Start->setAutoFillBackground(false);
        Start->setAutoDefault(false);
        Start->setFlat(true);
        Birth = new QPushButton(centralwidget);
        Birth->setObjectName(QString::fromUtf8("Birth"));
        Birth->setGeometry(QRect(100, 220, 241, 131));
        Birth->setFlat(true);
        SinGenerator = new QPushButton(centralwidget);
        SinGenerator->setObjectName(QString::fromUtf8("SinGenerator"));
        SinGenerator->setGeometry(QRect(60, 410, 351, 71));
        SinGenerator->setFlat(true);
        GAGenerator = new QPushButton(centralwidget);
        GAGenerator->setObjectName(QString::fromUtf8("GAGenerator"));
        GAGenerator->setGeometry(QRect(60, 510, 351, 121));
        GAGenerator->setFlat(true);
        SinMenu = new QPushButton(centralwidget);
        SinMenu->setObjectName(QString::fromUtf8("SinMenu"));
        SinMenu->setGeometry(QRect(480, 140, 301, 71));
        SinMenu->setFlat(true);
        GAMenu = new QPushButton(centralwidget);
        GAMenu->setObjectName(QString::fromUtf8("GAMenu"));
        GAMenu->setGeometry(QRect(820, 140, 301, 71));
        GAMenu->setFlat(true);
        Salvation = new QPushButton(centralwidget);
        Salvation->setObjectName(QString::fromUtf8("Salvation"));
        Salvation->setGeometry(QRect(1270, 140, 271, 71));
        Salvation->setFlat(true);
        Damnation = new QPushButton(centralwidget);
        Damnation->setObjectName(QString::fromUtf8("Damnation"));
        Damnation->setGeometry(QRect(1270, 220, 271, 71));
        Damnation->setFlat(true);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(430, 240, 821, 601));
        ABB = new QPushButton(centralwidget);
        ABB->setObjectName(QString::fromUtf8("ABB"));
        ABB->setGeometry(QRect(1280, 740, 241, 101));
        ABB->setFlat(true);
        Hell = new QPushButton(centralwidget);
        Hell->setObjectName(QString::fromUtf8("Hell"));
        Hell->setGeometry(QRect(1260, 410, 111, 81));
        Hell->setFlat(true);
        SetWInner = new QPushButton(centralwidget);
        SetWInner->setObjectName(QString::fromUtf8("SetWInner"));
        SetWInner->setGeometry(QRect(1290, 300, 231, 91));
        SetWInner->setFlat(true);
        Maps = new QPushButton(centralwidget);
        Maps->setObjectName(QString::fromUtf8("Maps"));
        Maps->setGeometry(QRect(1280, 530, 241, 81));
        Maps->setFlat(true);
        Maps2 = new QPushButton(centralwidget);
        Maps2->setObjectName(QString::fromUtf8("Maps2"));
        Maps2->setGeometry(QRect(1280, 630, 241, 81));
        Maps2->setFlat(true);
        cant = new QTextEdit(centralwidget);
        cant->setObjectName(QString::fromUtf8("cant"));
        cant->setGeometry(QRect(140, 140, 161, 70));
        Heaven = new QPushButton(centralwidget);
        Heaven->setObjectName(QString::fromUtf8("Heaven"));
        Heaven->setGeometry(QRect(1400, 410, 131, 81));
        Heaven->setFlat(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 2002, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Start->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        title->setText(QString());
        Start->setText(QString());
        Birth->setText(QString());
        SinGenerator->setText(QString());
        GAGenerator->setText(QString());
        SinMenu->setText(QString());
        GAMenu->setText(QString());
        Salvation->setText(QString());
        Damnation->setText(QString());
        ABB->setText(QString());
        Hell->setText(QString());
        SetWInner->setText(QString());
        Maps->setText(QString());
        Maps2->setText(QString());
        Heaven->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
