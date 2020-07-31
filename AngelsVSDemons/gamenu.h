#ifndef GAMENU_H
#define GAMENU_H

#include <QDialog>
#include <QDesktopWidget>
namespace Ui {
class GAMenu;
}

class GAMenu : public QDialog
{
    Q_OBJECT

public:
    explicit GAMenu(QWidget *parent = nullptr);
    ~GAMenu();

private:
    Ui::GAMenu *ui;
};

#endif // GAMENU_H
