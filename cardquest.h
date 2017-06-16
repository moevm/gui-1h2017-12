#ifndef CARDQUEST_H
#define CARDQUEST_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include "statssqlhelper.h"

namespace Ui {
class CardQuest;
}

class CardQuest : public QWidget
{
    Q_OBJECT

public:
    explicit CardQuest(QWidget *parent = 0);
    StatsSqlHelper *sqlhelp;
    void init(int games,int max);
    ~CardQuest();

private:
    Ui::CardQuest *ui;
    QLabel *answ;
    QSpinBox *ansBox;
    QLabel *res;
    float comp=0;
    int num=0;
    int max;
    int cur=0;
    int games;
    int sum=0;

private slots:
    void yes();

};

#endif // CARDQUEST_H
