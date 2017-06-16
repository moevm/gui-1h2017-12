#include "cardsett.h"
#include "ui_cardsett.h"
#include <cardquest.h>

CardSett::CardSett(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardSett)
{
    ui->setupUi(this);
}

CardSett::~CardSett()
{
    delete ui;
}

void CardSett::maxSet(int d)
{
    max=d;
    QString s=QString::number(max);
    ui->colorsv->setText(s );
}

void CardSett::gamesSet(int n)
{
    games=n;
    QString s=QString::number(games);
    ui->gamesv->setText(s);
}

void CardSett::goCard()
{
    CardQuest *cq = new CardQuest();
    cq->init(games,max);
    cq->show();
    this->close();
}
