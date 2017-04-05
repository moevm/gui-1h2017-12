#include "mentalquest.h"
#include "ui_mentalquest.h"

MentalQuest::MentalQuest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MentalQuest)
{
    ui->setupUi(this);
}

MentalQuest::~MentalQuest()
{
    delete ui;
}
