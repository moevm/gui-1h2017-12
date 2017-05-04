#ifndef INEQUALITYQUEST_H
#define INEQUALITYQUEST_H

#include <QWidget>
#include <QLabel>
#include <QPalette>
#include <QPushButton>
#include <statssqlhelper.h>
#include <QTimer>

namespace Ui {
class InequalityQuest;
}

class InequalityQuest : public QWidget
{
    Q_OBJECT

public:
    explicit InequalityQuest(QWidget *parent = 0);
    void init(bool neg,int comp,int time,int games,int compZ);
    void slotUpdateDateTime();
    StatsSqlHelper *sqlhelp;
    ~InequalityQuest();

private slots:
    void low();
    void eq();
    void more();
    void game();

private:
    Ui::InequalityQuest *ui;
    QLabel *left;
    QLabel *right;
    QLabel *res;
    int comp;
    QPushButton *moreB;
    QPushButton *lowB;
    QPushButton *eqB;
    QTimer* ptimer;


    int sum; // Текущий результат
    int games; // Количество игр
    int cur; // Текущий номер попытки

    bool negS; // Негативные числа ?
    int compS; // Сложность выражений
    int timeS; // Время попытки

    float leftC;
    float rightC;

    float labelEvaq(QLabel *l,int comp);
};

#endif // INEQUALITYQUEST_H
