#include "colorquest.h"
#include "ui_colorquest.h"

ColorQuest::ColorQuest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorQuest)
{
    ui->setupUi(this);

    this->setWindowTitle(QString::fromLocal8Bit("Уследи за цветом"));

    sum=0;
    cur=0;

    left = this->findChild<QLabel *>("left");
    right = this->findChild<QLabel *>("right");
    res = this->findChild<QLabel *>("res");


    QPushButton *exit = this->findChild<QPushButton *>("exit");
    yesb = this->findChild<QPushButton *>("yes");
    nob = this->findChild<QPushButton *>("no");


    QObject::connect(yesb,SIGNAL(clicked(bool)),this,SLOT(yes()));
    QObject::connect(nob,SIGNAL(clicked(bool)),this,SLOT(no()));
    QObject::connect(exit,SIGNAL(clicked(bool)),this,SLOT(close()));

}

ColorQuest::~ColorQuest()
{
    delete ui;
}

void ColorQuest::init(int colors, int games,int comp)
{
    this->colors=colors;
    this->games=games;
    this->comp=comp;
    game();
}

void ColorQuest::game()
{
    s1=qrand() % colors;
    c1=qrand() % colors;
    s2=qrand() % colors;
    c2=qrand() % colors;

    int p=qrand()%100;
    if(p<45) s1=c2;

    labelColor(left,c1);
    labelText(left,s1);

    labelColor(right,c2);
    labelText(right,s2);
}

void ColorQuest::labelColor(QLabel *l, int x)
{
    switch(x)
    {
      case 0:
        l->setStyleSheet("color: rgb(255, 0, 0)");
        break;

      case 1:
        l->setStyleSheet("color: rgb(0, 255, 0)");
        break;

      case 2:
        l->setStyleSheet("color: rgb(0, 0, 255)");
        break;

      case 3:
        l->setStyleSheet("color: rgb(0, 0, 0)");
      break;

      case 4:
        l->setStyleSheet("color: rgb(230, 215, 5)");
      break;
    }
}

void ColorQuest::labelText(QLabel *l, int x)
{
    switch(x)
    {
      case 0:
        l->setText(QString::fromLocal8Bit("Красный"));
        break;

      case 1:
        l->setText(QString::fromLocal8Bit("Зеленый"));
        break;

      case 2:
        l->setText(QString::fromLocal8Bit("Синий"));
        break;

      case 3:
        l->setText(QString::fromLocal8Bit("Черный"));
      break;

      case 4:
        l->setText(QString::fromLocal8Bit("Желтый"));
      break;
    }
}

void ColorQuest::yes()
{
    if(s1==c2)
    {
        sum++;
        QString s=QString::number(sum);
        res->setText(s);
    }
    cur++;
    if(cur>=games)
    {

        labelColor(left,3);
        labelColor(right,3);
        left->setText(QString::fromLocal8Bit("Ваш реузльтат:"));
        double b=(double) (100*sum)/games;

        this->sqlhelp->addStats(QString::fromLocal8Bit("Уследи за цветом"),comp,b);

        QString r=QString::number((int)b)+"%";
        right->setText(r);
        yesb->setEnabled(false);
        yesb->setVisible(false);
        nob->setEnabled(false);
        nob->setVisible(false);
    }
    else game();
}

void ColorQuest::no()
{
    if(s1!=c2)
    {
        sum++;
        QString s=QString::number(sum);
        res->setText(s);
    }
    cur++;
    if(cur>=games)
    {
        labelColor(left,3);
        labelColor(right,3);
        left->setText(QString::fromLocal8Bit("Ваш реузльтат:"));
        double b=(double) (100*sum)/games;

        this->sqlhelp->addStats(QString::fromLocal8Bit("Уследи за цветом"),comp,b);

        QString r=QString::number(b)+"%";
        right->setText(r);
        yesb->setEnabled(false);
        yesb->setVisible(false);
        nob->setEnabled(false);
        nob->setVisible(false);
    }
    else game();
}
