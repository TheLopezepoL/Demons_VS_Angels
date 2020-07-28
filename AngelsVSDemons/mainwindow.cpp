#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //PALETTES------------------------------------------------------------------
    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    //BACKGROUND----------------------------------------------------------------
    resize(QDesktopWidget().availableGeometry(this).size() * 0.80);
    QPixmap bgnd("/home/rev/Documents/GitHub/Demons_VS_Angels/ImagenesGUI/warzone.jpeg");
    bgnd = bgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bgnd);
    this->setPalette(palette);




}

MainWindow::~MainWindow()
{
    delete ui;
}

