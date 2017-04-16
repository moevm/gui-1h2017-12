#include "mentalsett.h"
#include "ui_mentalsett.h"
#include "mentalquest.h"
#include <qDebug>
MentalSett::MentalSett(QWidget *parent) :QWidget(parent),ui(new Ui::MentalSett)
{
    ui->setupUi(this);


    go= this->findChild<QPushButton *>("start");
    QPushButton *back= this->findChild<QPushButton *>("back");

    diapv = this->findChild<QLabel *>("diapv");
    diap = this->findChild<QSlider *>("diap");

    numCountv = this->findChild<QLabel *>("numCountv");
    numCount = this->findChild<QSlider *>("numCount");

    timerv = this->findChild<QLabel *>("timerv");
    timer = this->findChild<QSlider *>("timer");

    neg=this->findChild<QCheckBox *>("neg");

    negS=true;
    numsS=5;
    timerS=1000;
    diapS=100;

    QObject::connect(diap,SIGNAL(valueChanged(int)),this,SLOT(diapSet(int)));
    QObject::connect(numCount,SIGNAL(valueChanged(int)),this,SLOT(numsSet(int)));
    QObject::connect(timer,SIGNAL(valueChanged(int)),this,SLOT(timerSet(int)));
    QObject::connect(neg,SIGNAL(clicked(bool)),this,SLOT(negCheck(bool)));
    QObject::connect(go,SIGNAL(clicked(bool)),this,SLOT(goMental()));
    QObject::connect(back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

MentalSett::~MentalSett()
{
    delete ui;
}

void MentalSett::diapSet(int d)
{
    diapS=pow(10,d);
    QString s=QString::number(diapS);
    diapv->setText(s);
}


void MentalSett::numsSet(int n)
{
    numsS=n;
    QString s=QString::number(numsS);
    numCountv->setText(s);
}


void MentalSett::timerSet(int t)
{
    timerS=t*500;
    double x=(double)t/2;
    QString s=QString::number(x);
    timerv->setText(s);
}

void MentalSett::negCheck(bool ch)
{
    negS=ch;
}

void MentalSett::goMental()
{
    MentalQuest *quest=new MentalQuest();
    qDebug() << negS << " " << numsS << " " << timerS << " " << diapS;
    quest->initClock(negS,numsS,timerS,diapS);
    quest->show();
    this->close();
}
