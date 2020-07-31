#include "sinmenu.h"
#include "ui_sinmenu.h"
#include <QDesktopWidget>
SinMenu::SinMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SinMenu)
{
    ui->setupUi(this);
    x = false;
    //PALETTES------------------------------------------------------------------
    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    //BACKGROUND----------------------------------------------------------------
    QString path = "/home/rev/Documents/GitHub/Demons_VS_Angels/ImagenesGUI";
    resize(QDesktopWidget().availableGeometry(this).size() * 0.80);
    QPixmap bgnd(path + "/hell.jpeg");
    bgnd = bgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bgnd);
    this->setPalette(palette);
    //BOTON TOP 10----------------------------------------------------------------
    QPixmap button1(path +"/top10.png");
    QIcon start(button1);
    ui->TOP10->setIcon(start);
    ui->TOP10->setIconSize(button1.size());
    ui->TOP10->setCheckable(true);
    //TEXT BOX----------------------------------------------------------------
    ui->SCREEN->setReadOnly(true);
    //BOTON TOP 10----------------------------------------------------------------
    QPixmap button2(path +"/top5.png");
    QIcon top5(button2);
    ui->TOP5->setIcon(top5);
    ui->TOP5->setIconSize(button2.size());
    ui->TOP5->setCheckable(true);
}

SinMenu::~SinMenu()
{
    delete ui;
}


void SinMenu::on_TOP10_clicked(bool checked)
{
    if(!x){
        if (checked){
            QString msg = "PAISES CON MAS PECADOS: " +  mundo->printTops(mundo->top10Sins());
            ui->SCREEN->setText(msg);
        }
        else {
            ui->SCREEN->clear();
        }
    }
}

void SinMenu::on_TOP5_clicked(bool checked)
{
    if(!x){
        if (checked){
            QString msg = "PAISES CON MENOS PECADOS: " +  mundo->printTops(mundo->top5LessSins());
            ui->SCREEN->setText(msg);
        }
        else {
            ui->SCREEN->clear();
        }
    }
}
