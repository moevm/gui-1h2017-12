#ifndef COLORSETT_H
#define COLORSETT_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QPushButton>

namespace Ui {
class ColorSett;
}

class ColorSett : public QWidget
{
    Q_OBJECT

public:
    explicit ColorSett(QWidget *parent = 0);
    ~ColorSett();

public slots:
    void colorsSet(int d);
    void gamesSet(int n);
    void goColor();
private:
    Ui::ColorSett *ui;
    QPushButton *go;
    QLabel *colorsv;
    QLabel *gamesv;
    int colors;
    int games;
};

#endif // COLORSETT_H
