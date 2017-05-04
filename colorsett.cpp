#include "colorsett.h"
#include "ui_colorsett.h"
#include "colorquest.h"
#include <QDebug>

ColorSett::ColorSett(QWidget *parent) :QWidget(parent),ui(new Ui::ColorSett)
{

    ui->setupUi(this);

    go= this->findChild<QPushButton *>("start");
    QPushButton *back= this->findChild<QPushButton *>("back");


    colorsv = this->findChild<QLabel *>("colorsv");
    QSlider *colors = this->findChild<QSlider *>("colors");

    gamesv = this->findChild<QLabel *>("gamesv");
    QSlider *games = this->findChild<QSlider *>("games");

    maxCol=colors->maximum();
    maxGame=games->maximum();

    QObject::connect(colors,SIGNAL(valueChanged(int)),this,SLOT(colorsSet(int)));
    QObject::connect(games,SIGNAL(valueChanged(int)),this,SLOT(gamesSet(int)));

    QObject::connect(go,SIGNAL(clicked(bool)),this,SLOT(goColor()));
    QObject::connect(back,SIGNAL(clicked(bool)),this,SLOT(deleteLater()));

    this->games=5;
    this->colors=3;
}


void ColorSett::colorsSet(int d)
{
    colors=d;
    QString s=QString::number(colors);
    colorsv->setText(s);
}

void ColorSett::gamesSet(int n)
{
    games=n;
    QString s=QString::number(games);
    gamesv->setText(s);
}

void ColorSett::goColor()
{
    ColorQuest *col=new ColorQuest();
    float comp=colors/maxCol+games/maxGame;
    comp=(int)comp*50;
    col->init(colors,games,comp);
    col->sqlhelp=sqlhelp;
    col->show();
    this->close();
    this->~ColorSett();
}


ColorSett::~ColorSett()
{
    delete ui;
}
