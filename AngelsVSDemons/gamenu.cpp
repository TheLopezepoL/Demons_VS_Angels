#include "gamenu.h"
#include "ui_gamenu.h"

GAMenu::GAMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GAMenu)
{
    ui->setupUi(this);
    //PALETTES------------------------------------------------------------------
    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    //BACKGROUND----------------------------------------------------------------
    QString path = "/home/rev/Documents/GitHub/Demons_VS_Angels/ImagenesGUI";
    resize(QDesktopWidget().availableGeometry(this).size() * 0.80);
    QPixmap bgnd(path + "/heaven.jpeg");
    bgnd = bgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bgnd);
    this->setPalette(palette);
}

GAMenu::~GAMenu()
{
    delete ui;
}
