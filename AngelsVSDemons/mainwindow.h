#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "world.h"
#include "map.h"
#include "sinmenu.h"
#include "gamenu.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool x;

public:
    World *mundo;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Start_clicked();

    void on_Birth_clicked();

    void on_SinGenerator_clicked();

    void on_GAGenerator_clicked();

    void on_Maps_clicked(bool checked);

    void on_SinMenu_clicked();

    void on_GAMenu_clicked();

    void on_ABB_clicked(bool checked);

    void on_Maps2_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
