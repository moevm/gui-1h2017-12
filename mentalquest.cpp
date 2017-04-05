#include "mentalquest.h"
#include "ui_mentalquest.h"
#include <QDebug>

MentalQuest::MentalQuest(QWidget *parent) :
    QWidget(parent)
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
    QObject::connect(exit,SIGNAL(clicked(bool)),this,SLOT(close()));

    ansbut->setVisible(false);
    anslabel->setVisible(false);
    answer->setVisible(false);
}

MentalQuest::~MentalQuest()
{
    delete ui;
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

    if(clock->sum==result.toInt()) clock->setText("<CENTER>Succses</CENTER>");
    else clock->setText("<CENTER> Incorrect: " + result + "</CENTER>");

    clock->setVisible(true);
}

Clock::Clock(QWidget* parent) : QLabel(parent)
{
    nums=5;
    sum=0;
    cur=0;
    ptimer = new QTimer(this);
    QObject::connect(ptimer,SIGNAL(timeout()),this,SLOT(slotUpdateDateTime()));
    ptimer->start(1000);
}


void Clock::slotUpdateDateTime()
{
    cur++;
    int rand=qrand() % 20;
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
