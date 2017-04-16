#include "mentalquest.h"
#include "ui_mentalquest.h"
#include <QDebug>

MentalQuest::MentalQuest(QWidget *parent) : QWidget(parent)
{
    this->ui=new Ui::MentalQuest;
    ui->setupUi(this);

    ansbut = this->findChild<QPushButton *>("ansbut");
    QPushButton *exit= this->findChild<QPushButton *>("exit");
    anslabel = this->findChild<QLabel *>("anslabel");
    answer = this->findChild<QTextEdit *>("answer");

    clock=this->findChild<Clock *>("clock");

    QObject::connect(clock,SIGNAL(stop()),this,SLOT(timeStop()));
    QObject::connect(ansbut,SIGNAL(clicked(bool)),this,SLOT(result()));
    QObject::connect(exit,SIGNAL(clicked(bool)),this,SLOT(exit()));

    ansbut->setVisible(false);
    anslabel->setVisible(false);
    answer->setVisible(false);
}

MentalQuest::~MentalQuest()
{
    delete ui;
}

void MentalQuest::initClock(bool neg, int count, int time, int diap)
{
    clock->setNeg(neg);
    clock->setTimer(time);
    clock->setDiap(diap);
    clock->setNumCount(count);
    clock->ptimer->start(time-1);
}

void MentalQuest::timeStop()
{
    ansbut->setVisible(true);
    anslabel->setVisible(true);
    answer->setVisible(true);
    ansbut->setEnabled(true);
    anslabel->setEnabled(true);
    answer->setEnabled(true);
    clock->setVisible(false);

}

void MentalQuest::exit()
{
    clock->ptimer->stop();
    this->close();
    clock->~Clock();
    this->~MentalQuest();
}

void MentalQuest::result()
{
    QString result=answer->toPlainText();

    ansbut->setVisible(false);
    anslabel->setVisible(false);
    answer->setVisible(false);
    ansbut->setEnabled(false);
    anslabel->setEnabled(false);
    answer->setEnabled(false);

    QFont font = clock->font();
        font.setPointSize(40);
    clock->setFont(font);
    QString ans=QString::number(clock->sum);
    if(clock->sum==result.toInt()) clock->setText("<CENTER>Succses</CENTER>");
    else clock->setText("<CENTER> Incorrect: " + ans + "</CENTER>");

    clock->setVisible(true);
}

Clock::Clock(QWidget* parent) : QLabel(parent)
{
    negp=20;
    sum=0;
    cur=0;
    ptimer = new QTimer(this);
    QObject::connect(ptimer,SIGNAL(timeout()),this,SLOT(slotUpdateDateTime()));
}


void Clock::slotUpdateDateTime()
{
    cur++;
    int p=qrand() % 100;
    int rand=qrand() % diap;
    if(cur>1)//Для всех чисел после 1го
    {
        while(rand==last) // Совпадение 2х чисел подряд
            rand=qrand() % diap;
    }
    last=rand; //Запомнили предыдущее число
    if((neg)&&(p<negp)) rand=-rand; //С вероятностью отрицаем число
        qDebug() << rand;
    sum=sum+rand;
    QString str = QString::number(rand);
    setText("<CENTER>" + str + "</CENTER>");
    if(cur==nums+1)
    {
        sum=sum-rand;
        ptimer->stop();
        emit stop();
    }
}


Clock::~Clock()
{

}

void Clock::setNeg(bool neg)
{
    this->neg=neg;
}
void Clock::setNumCount(int count)
{
    this->nums=count;
}
void Clock::setDiap(int diap)
{
    this->diap=diap;
}

void Clock::setTimer(int time)
{
    this->timer=time;
}
