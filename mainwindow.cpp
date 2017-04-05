#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mentalquest.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *mental = this->findChild<QPushButton *>("mental");
    QPushButton *exit = this->findChild<QPushButton *>("exit");
    QPushButton *help = this->findChild<QPushButton *>("help");

    QObject::connect(mental,SIGNAL(clicked(bool)),this,SLOT(mentalClicked()));
    QObject::connect(exit,SIGNAL(clicked(bool)),this,SLOT(close()));
    QObject::connect(help,SIGNAL(clicked(bool)),this,SLOT());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mentalClicked()
{
    MentalQuest *quest=new MentalQuest();
    quest->show();
}
