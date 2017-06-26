#include "cardquest.h"
#include "ui_cardquest.h"

CardQuest::CardQuest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardQuest)
{
    ui->setupUi(this);

    answ = this->findChild<QLabel *>("answ");
    ansBox  = this->findChild<QSpinBox*>("ansBox");

    ui->result->setVisible(false);

}


CardQuest::~CardQuest()
{
    delete ui;
}


void CardQuest::yes()
{
    if(num==ui->spinBox->value())
    {
        sum++;
        QString s=QString::fromLocal8Bit("Результат: ")+QString::number(sum);
        ui->res->setText(s);
    }
    cur++;
    if(cur>=games)
    {
        ui->openGLWidget->hide();
        ui->label->hide();
        ui->spinBox->hide();
        ui->res->hide();
        ui->yes->hide();

        ui->result->setVisible(true);

        double b =(double) (100*sum)/games;

        ui->result->setText(QString::fromLocal8Bit("Ваш реузльтат:  ")+QString::number((int)b)+"%");

        this->sqlhelp->addStats(QString::fromLocal8Bit("Карточки Абакус"),comp*100,b);
    }
    num = qrand()%max;
    ui->openGLWidget->setNum(num);
}

void  CardQuest::init(int games, int max)
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    this->games=games;
    this->max=max;

    this->comp = (float)(float(this->games)/20 + float(this->max)/199);

    num = qrand()%max;
    ui->openGLWidget->setNum(num);
}
