#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mentalsett.h"
#include "colorsett.h"
#include "inequalitysett.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *mental = this->findChild<QPushButton *>("mental");
    QPushButton *exit = this->findChild<QPushButton *>("exit");
    QPushButton *help = this->findChild<QPushButton *>("help");
    QPushButton *color = this->findChild<QPushButton *>("color");
    QPushButton *ineq = this->findChild<QPushButton *>("ineq");

    QObject::connect(mental,SIGNAL(clicked(bool)),this,SLOT(mentalClicked()));
    QObject::connect(exit,SIGNAL(clicked(bool)),this,SLOT(close()));
    QObject::connect(help,SIGNAL(clicked(bool)),this,SLOT());
    QObject::connect(color,SIGNAL(clicked(bool)),this,SLOT(colorClicked()));
    QObject::connect(ineq,SIGNAL(clicked(bool)),this,SLOT(ineqClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mentalClicked()
{
    MentalSett *sett=new MentalSett();
    sett->show();
}
void MainWindow::colorClicked()
{
   ColorSett *col=new ColorSett();
   col->show();
}
void MainWindow::ineqClicked()
{
   InequalitySett *ineq=new InequalitySett();
   ineq->show();
}
