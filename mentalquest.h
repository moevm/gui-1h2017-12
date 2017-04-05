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


    public slots:
        void timeStop();
        void result();

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
    ~Clock();

signals:
   void stop();

public slots:
    void slotUpdateDateTime();



    private:
        QTimer* ptimer;
        int nums;
        int cur;
};

#endif // MENTALQUEST_H
