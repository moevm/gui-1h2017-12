#ifndef MENTALQUEST_H
#define MENTALQUEST_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QTextEdit>
#include <QPushButton>
#include "QTime"

class Clock;

namespace Ui {
class MentalQuest;
}

class MentalQuest : public QWidget
{
    Q_OBJECT

    public:
        explicit MentalQuest(QWidget *parent = 0);
        ~MentalQuest();
        void initClock(bool neg=false,int count=5,int time=1000,int diap=100);


    public slots:
        void timeStop();
        void result();
        void exit();

    private:
        Ui::MentalQuest *ui;
        QLabel *anslabel;
        QTextEdit *answer;
        QPushButton *ansbut;
        Clock *clock;

};

class Clock : public QLabel
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = 0);
    int sum;
    void setNeg(bool neg);
    void setNumCount(int count);
    void setTimer(int time);
    void setDiap(int diap);
    ~Clock();
    QTimer* ptimer;

signals:
   void stop();

public slots:
    void slotUpdateDateTime();



    private:
        int nums;// Количество чисел
        int cur; // Текущий тик
        int last; // Предыдущее случайное число
        bool neg; // Негативные числа ?
        int timer; // Период чисел
        int diap; // Диапазон чисел
        int negp; //Вероятность негативного числа
};

#endif // MENTALQUEST_H
