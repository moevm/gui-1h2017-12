#ifndef COLORQUEST_H
#define COLORQUEST_H

#include <QWidget>
#include <QLabel>
#include <QPalette>
#include <QPushButton>

namespace Ui {
class ColorQuest;
}

class ColorQuest : public QWidget
{
    Q_OBJECT

public:
    explicit ColorQuest(QWidget *parent = 0);
    void game();
    void init(int colors,int games);
    ~ColorQuest();

public slots:
    void yes();
    void no();
private:
    Ui::ColorQuest *ui;
    QLabel *left;
    QLabel *right;
    QLabel *res;
    QPushButton *yesb;
    QPushButton *nob;
    int s1;
    int c1;
    int s2;
    int c2;
    int sum; // Текущий результат
    int colors; // Количество используемых цветов
    int games; // Сумарное количество попыток
    int cur; // Текущий номер попытки

    void labelColor(QLabel *l,int x);
    void labelText(QLabel *l,int x);
};

#endif // COLORQUEST_H
