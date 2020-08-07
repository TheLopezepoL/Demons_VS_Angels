#ifndef GAMENU_H
#define GAMENU_H
#include "world.h"
#include <QDialog>
#include <QDesktopWidget>
namespace Ui {
class GAMenu;
}

class GAMenu : public QDialog
{
    Q_OBJECT
    bool x;
public:
    World *mundo;
    explicit GAMenu(QWidget *parent = nullptr);
    ~GAMenu();

private slots:
    void on_top10_clicked(bool checked);

    void on_top5_clicked(bool checked);

    void on_familyState_clicked(bool checked);

    void on_hLS_clicked(bool checked);

    void on_CFS_clicked(bool checked);

    void on_familyStats_clicked(bool checked);


private:
    Ui::GAMenu *ui;
};

#endif // GAMENU_H
