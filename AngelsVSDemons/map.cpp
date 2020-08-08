#include "map.h"
#include "ui_map.h"
#include <QDesktopWidget>
#include <QDebug>
Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map)
{

    ui->setupUi(this);
    //PALETTES------------------------------------------------------------------
    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    //BACKGROUND----------------------------------------------------------------
    QString path = "/home/thelopezepol/Escritorio/C++/ED S1 2020/Demons_VS_Angels/ImagenesGUI/";
    resize(QDesktopWidget().availableGeometry(this).size() * 0.50);
    QPixmap bgnd(path + "/fondo.jpeg");
    bgnd = bgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bgnd);
    this->setPalette(palette);
    //MUESTRA PAIS-------------------------------------------------------------
    this->lblASIA = new QLabel(this);
    this->lblAMERICA = new QLabel(this);
    this->lblOCEANIA = new QLabel(this);
    this->lblAFRICA = new QLabel(this);
    this->lblEUROPA = new QLabel(this);
    this->titulo = new QLabel(this);


}

Map::~Map()
{
    delete ui;
}


void Map::showMaps(QStringList list){
    QString path = "/home/thelopezepol/Escritorio/C++/ED S1 2020/Demons_VS_Angels/ImagenesGUI/";
    qDebug() << list;
    //PIXMAPS
    QPixmap america(path + list[0]);
    QPixmap asia(path + list[2]);
    QPixmap africa(path + list[3]);
    QPixmap oceania(path + list[4]);
    QPixmap europa(path + list[1]);
    QPixmap title(path + "titulomundo.png");
    this->lblAMERICA->setPixmap(america);
    this->lblAMERICA->setGeometry(0,0,500,500);
    this->lblEUROPA->setPixmap(europa);
    this->lblEUROPA->setGeometry(250,40,200,200);
    this->lblASIA->setPixmap(asia);
    this->lblASIA->setGeometry(450,0,400,400);
    this->lblOCEANIA->setPixmap(oceania);
    this->lblOCEANIA->setGeometry(750,300,200,200);
    this->lblAFRICA->setPixmap(africa);
    this->lblAFRICA->setGeometry(400,270,200,200);

}
