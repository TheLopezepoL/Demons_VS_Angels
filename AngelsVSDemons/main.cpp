#include "mainwindow.h"

#include <QApplication>
#include <QRandomGenerator>
#include "filemanager.h"
#include "world.h"
#include "triarbol.h"
#include "SmtpMime"
int main(int argc, char *argv[])
{
    //"/home/thelopezepol/Escritorio/C++/ED S1 2020/Demons_VS_Angels"
    //"/home/rev/Documents/GitHub/Demons_VS_Angels"



    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}















