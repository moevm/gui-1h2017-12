#include "mentalquest.h"
#include "ui_mentalquest.h"

MentalQuest::MentalQuest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MentalQuest)
{
    ui->setupUi(this);

    QPushButton *exit= this->findChild<QPushButton *>("exit");

    QObject::connect(exit,SIGNAL(clicked(bool)),this,SLOT(close()));
}

MentalQuest::~MentalQuest()
{
    delete ui;
}
