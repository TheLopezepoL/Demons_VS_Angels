#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x = true;
    //PALETTES------------------------------------------------------------------
    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    //BACKGROUND----------------------------------------------------------------
    QString path = "/home/rev/Documents/GitHub/Demons_VS_Angels/ImagenesGUI";
    resize(QDesktopWidget().availableGeometry(this).size() * 0.80);
    QPixmap bgnd(path + "/warzone.jpeg");
    bgnd = bgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bgnd);
    this->setPalette(palette);
    //BOTON START----------------------------------------------------------------
    QPixmap button1(path +"/start.png");
    QIcon start(button1);
    ui->Start->setIcon(start);
    ui->Start->setIconSize(button1.size());
    //BOTON Birth----------------------------------------------------------------
    QPixmap button2( path +"/birth.png");
    QIcon birth(button2);
    ui->Birth->setIcon(birth);
    ui->Birth->setIconSize(button2.size());
    //BOTON SIN GENERATOR----------------------------------------------------------------
    QPixmap button3( path +"/sinG.png");
    QIcon  sinG(button3);
    ui->SinGenerator->setIcon(sinG);
    ui->SinGenerator->setIconSize(button3.size());
    //BOTON SIN GENERATOR----------------------------------------------------------------
    QPixmap button4( path +"/gaG.png");
    QIcon  gaG(button4);
    ui->GAGenerator->setIcon(gaG);
    ui->GAGenerator->setIconSize(button4.size());
    //BOTON GA MENU----------------------------------------------------------------
    QPixmap button5( path +"/gaMenu.png");
    QIcon  gaM(button5);
    ui->GAMenu->setIcon(gaM);
    ui->GAMenu->setIconSize(button5.size());
    //BOTON SIN MENU----------------------------------------------------------------
    QPixmap button6( path +"/sinConsult.png");
    QIcon  sinM(button6);
    ui->SinMenu->setIcon(sinM);
    ui->SinMenu->setIconSize(button6.size());
    //BOTON SALVATION----------------------------------------------------------------
    QPixmap button7( path +"/salvationB.png");
    QIcon  salvation(button7);
    ui->Salvation->setIcon(salvation);
    ui->Salvation->setIconSize(button6.size());
    //BOTON DAMNNATION----------------------------------------------------------------
    QPixmap button8( path +"/condenacionB.png");
    QIcon  condenacion(button8);
    ui->Damnation->setIcon(condenacion);
    ui->Damnation->setIconSize(button6.size());
    //BOTON ABB----------------------------------------------------------------
    QPixmap button9( path +"/abb.png");
    QIcon  abb(button9);
    ui->ABB->setIcon(abb);
    ui->ABB->setIconSize(button6.size());
    ui->ABB->setCheckable(true);
    //BOTON hell----------------------------------------------------------------
    QPixmap button10( path +"/hell.png");
    QIcon  hell(button10);
    ui->Hell->setIcon(hell);
    ui->Hell->setIconSize(button6.size());
    //BOTON Winner----------------------------------------------------------------
    QPixmap button11( path +"/winner.png");
    QIcon  heaven(button11);
    ui->SetWInner->setIcon(heaven);
    ui->SetWInner->setIconSize(button6.size());
    ui->SetWInner->setCheckable(true);
    //TEXT BOX----------------------------------------------------------------
    ui->textEdit->setReadOnly(true);
    //BOTON Maps----------------------------------------------------------------
    QPixmap button12( path +"/mapSins.png");
    QIcon  map(button12);
    ui->Maps->setIcon(map);
    ui->Maps->setIconSize(button6.size());
    ui->Maps->setCheckable(true);
    //BOTON Maps----------------------------------------------------------------
    QPixmap button13( path +"/mapGA.png");
    QIcon  mapGA(button13);
    ui->Maps2->setIcon(mapGA);
    ui->Maps2->setIconSize(button6.size());
    ui->Maps2->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//CREAR MUNDO
void MainWindow::on_Start_clicked()
{
    this->mundo = new World();
    this->mundo->preStart("/home/rev/Documents/GitHub/Demons_VS_Angels");
    x = false;
}
//NACIMIENTO
void MainWindow::on_Birth_clicked()
{
    QString textEditText = ui->cant->toPlainText();
    int x = QString::toInt(textEditText);
    this->mundo->birth(1000);
    ui->textEdit->setText(mundo->binnacle);
}
//GENERA PECADOS
void MainWindow::on_SinGenerator_clicked()
{
    this->mundo->sinGenerator();
    //this->mundo->imprimirHumanos();
}
//GENERA BUENAS ACCIONES
void MainWindow::on_GAGenerator_clicked()
{
    this->mundo->blessGenerator();
    //this->mundo->imprimirHumanos();
}
//VER MAPA
void MainWindow::on_Maps_clicked(bool checked)
{
    if(!x){
        if (checked){
            Map *mapWindow = new Map(this);
            mapWindow->showMaps(mundo->getMapa(true));
            mapWindow->show();
            ui->textEdit->clear();
            ui->textEdit->setText(mundo->cantPecadosCont);
        }
        else {
            ui->textEdit->clear();
            mundo->cantPecadosCont = "";
        }
    }

}
//MAPA GA
void MainWindow::on_Maps2_clicked(bool checked)
{
    if(!x){
        if (checked){
            Map *mapWindow = new Map(this);
            mapWindow->showMaps(mundo->getMapa(false));
            mapWindow->show();
            ui->textEdit->clear();
            ui->textEdit->setText(mundo->cantGA);
        }
        else {
            ui->textEdit->clear();
            mundo->cantGA = "";
        }
    }
}

void MainWindow::on_SinMenu_clicked()
{
    SinMenu *sinMenu = new SinMenu(this);
    sinMenu->mundo = mundo;
    sinMenu->show();
}

void MainWindow::on_GAMenu_clicked()
{
    GAMenu *gaMenu = new GAMenu(this);
    gaMenu->show();
}

void MainWindow::on_ABB_clicked(bool checked)
{
    if(!x){
        if (checked){
            ui->textEdit->clear();
            mundo->abb->preOrden(mundo->abb->root,0);
            ui->textEdit->setText(mundo->tree);
        }
        else {
            ui->textEdit->clear();
        }
    }
}



void MainWindow::on_SetWInner_clicked(bool checked)
{
    if(!x){
        if (checked){
            ui->textEdit->clear();
           QString msg = mundo->setWinner();
            ui->textEdit->setText(msg);
        }
        else {
            ui->textEdit->clear();
        }
    }
}
