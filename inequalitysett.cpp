#include "inequalitysett.h"
#include "ui_inequalitysett.h"
#include "inequalityquest.h"

InequalitySett::InequalitySett(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InequalitySett)
{
    ui->setupUi(this);

    this->setWindowTitle(QString::fromLocal8Bit("Неравенства"));

    go= this->findChild<QPushButton *>("start");
    QPushButton *back= this->findChild<QPushButton *>("back");

    gamesv = this->findChild<QLabel *>("gamesv");
    games = this->findChild<QSlider *>("games");

    compv = this->findChild<QLabel *>("compv");
    comp = this->findChild<QSlider *>("comp");

    timev = this->findChild<QLabel *>("timev");
    time = this->findChild<QSlider *>("time");

    neg=this->findChild<QCheckBox *>("neg");

    negS=true;
    gamesS=5;
    compS=5;
    timeS=10000;

    maxcomp = comp->maximum();
    maxgames = games->maximum();
    maxtimeS = time->maximum()*1000;

    QObject::connect(games,SIGNAL(valueChanged(int)),this,SLOT(gamesSet(int)));
    QObject::connect(comp,SIGNAL(valueChanged(int)),this,SLOT(compSet(int)));
    QObject::connect(time,SIGNAL(valueChanged(int)),this,SLOT(timeSet(int)));


    QObject::connect(neg,SIGNAL(clicked(bool)),this,SLOT(negCheck(bool)));
    QObject::connect(go,SIGNAL(clicked(bool)),this,SLOT(goIneq()));
    QObject::connect(back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

InequalitySett::~InequalitySett()
{
    delete ui;
}

void InequalitySett::negCheck(bool ch)
{
    negS=ch;
}

void InequalitySett::gamesSet(int d)
{
    gamesS=d;
    QString s=QString::number(d);
    gamesv->setText(s);
}

void InequalitySett::compSet(int t)
{
    compS=t;
    QString s=QString::number(t);
    compv->setText(s);
}

void InequalitySett::timeSet(int n)
{
    timeS=n*1000;
    QString s=QString::number(n);
    timev->setText(s);
}

void InequalitySett::goIneq()
{
    InequalityQuest *ineq = new InequalityQuest();
    int ne;
    if(negS) ne=1;
    else ne=0;
    float comp=compS/maxcomp+(1-timeS/maxtimeS)+gamesS/maxgames+ne;
    comp=(int)comp*25;
    ineq->init(negS,compS,timeS,gamesS,comp);
    ineq->sqlhelp=sqlhelp;
    ineq->show();
    this->close();
}
