#ifndef SINMENU_H
#define SINMENU_H

#include <QDialog>
#include "world.h"
namespace Ui {
class SinMenu;
}

class SinMenu : public QDialog
{
    Q_OBJECT
    bool x;

public:
    World *mundo;
    explicit SinMenu(QWidget *parent = nullptr);
    ~SinMenu();

private slots:
    void on_TOP10_clicked(bool checked);

    void on_TOP5_clicked(bool checked);

    void on_familyState_clicked(bool checked);

    void on_hLS_clicked(bool checked);

    void on_CFS_clicked(bool checked);


private:
    Ui::SinMenu *ui;
};

#endif // SINMENU_H
