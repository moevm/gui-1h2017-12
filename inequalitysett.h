#ifndef INEQUALITYSETT_H
#define INEQUALITYSETT_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>

namespace Ui {
class InequalitySett;
}

class InequalitySett : public QWidget
{
    Q_OBJECT

public:
    explicit InequalitySett(QWidget *parent = 0);
    ~InequalitySett();


public slots:
    void negCheck(bool ch);
    void compSet(int t);
    void gamesSet(int d);
    void timeSet(int n);
    void goIneq();

private:
    Ui::InequalitySett *ui;
    QPushButton *go;
    QLabel *compv;
    QSlider *comp;
    QLabel *gamesv;
    QSlider *games;
    QLabel *timev;
    QSlider *time ;
    QCheckBox *neg;

    bool negS; // Негативные числа ?
    int compS; // Сложность выражений
    int timeS; // Время попытки
    int gamesS;// Количество игр
};

#endif // INEQUALITYSETT_H
