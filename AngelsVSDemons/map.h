#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include <QLabel>
#include "mainwindow.h"
namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    //LABELS
    QLabel *lblASIA;
    QLabel *lblAFRICA;
    QLabel *lblAMERICA;
    QLabel *lblEUROPA;
    QLabel *lblOCEANIA;
    QLabel *titulo;
    explicit Map(QWidget *parent = nullptr);
    ~Map();
    void showMaps(QStringList list);


private:
    Ui::Map *ui;
};

#endif // MAP_H
