#ifndef MENTALSETT_H
#define MENTALSETT_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QCheckBox>
#include <QPushButton>
#include <QString>

namespace Ui {
class MentalSett;
}

class MentalSett : public QWidget
{
    Q_OBJECT

public:
    explicit MentalSett(QWidget *parent = 0);
    ~MentalSett();


public slots:
    void negCheck(bool ch);
    void timerSet(int t);
    void diapSet(int d);
    void numsSet(int n);
    void goMental();

private:
    Ui::MentalSett *ui;
    QPushButton *go;
    QLabel *diapv;
    QSlider *diap;
    QLabel *numCountv;
    QSlider *numCount;
    QLabel *timerv;
    QSlider *timer ;
    QCheckBox *neg;

    bool negS; // Негативные числа ?
    int timerS; // Период чисел
    int diapS; // Диапазон чисел
    int numsS;// Количество чисел
};

#endif // MENTALSETT_H
