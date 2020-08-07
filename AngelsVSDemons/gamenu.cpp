#include "gamenu.h"
#include "ui_gamenu.h"

GAMenu::GAMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GAMenu)
{
    ui->setupUi(this);
    x = false;
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
    ui->screen->setReadOnly(true);
    //BOTON TOP 10----------------------------------------------------------------
    QPixmap button1(path +"/top10.png");
    QIcon button(button1);
    ui->top10->setIcon(button);
    ui->top10->setIconSize(button1.size());
    ui->top10->setCheckable(true);
    //TEXT BOX----------------------------------------------------------------
    //BOTON TOP 10----------------------------------------------------------------
    QPixmap button2(path +"/top5.png");
    QIcon top5(button2);
    ui->top5->setIcon(top5);
    ui->top5->setIconSize(button2.size());
    ui->top5->setCheckable(true);
    ui->familyState->setCheckable(true);
    ui->hLS->setCheckable(true);
    ui->CFS->setCheckable(true);

}


GAMenu::~GAMenu()
{
    delete ui;
}

void GAMenu::on_top10_clicked(bool checked)
{
    if(!x){
        if (checked){
            mundo->printCountryListGA();
            QString msg = "PAISES CON MAS BUENAS ACCIONES: " +  mundo->printTops(mundo->top10GA());
            ui->screen->setText(msg);

        }
        else {
            ui->screen->clear();
        }
    }
}

void GAMenu::on_top5_clicked(bool checked)
{
    if(!x){
        if (checked){
            QString msg = "PAISES CON MENOS BUENAS ACCIONES: " +  mundo->printTops(mundo->top5LessGA());
            ui->screen->setText(msg);
        }
        else {
            ui->screen->clear();
        }
    }
}

void GAMenu::on_familyState_clicked(bool checked)
{
    if(!x){
        if (checked){
            QString textEditText = ui->id->toPlainText();
            int var = textEditText.toInt();
            qDebug() << var;
            QString msg = "Familia-----------------------\n" + mundo->familyGoodActions(var);
            ui->screen->setText(msg);
        }
        else {
            ui->screen->clear();
        }
    }
}

void GAMenu::on_hLS_clicked(bool checked)
{
    if(!x){
        if (checked){
            QString msg = "ARCHIVO TXT CREADO!";
            mundo->printAllHumansInfo(false);
            ui->screen->setText(msg);
        }
        else {
            ui->screen->clear();
        }
    }
}

void GAMenu::on_CFS_clicked(bool checked)
{
    if(!x){
        if (checked){
             QString pais = ui->Pais->toPlainText();
            QString sName = ui->sencondN->toPlainText();

            QString msg = "Familia-----------------------\n" + mundo->searchFamily(sName,pais);
            ui->screen->setText(msg);
        }
        else {
            ui->screen->clear();
        }
    }
}
