#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mentalsett.h"
#include "colorsett.h"
#include "inequalitysett.h"
#include "helpwin.h"
#include "cardsett.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("BrainStorm");

     QFile styleFile(":/styles/default/default.css");

        if( styleFile.open(QFile::ReadOnly) ) {
                QString styleSheet = QLatin1String(styleFile.readAll());
            qApp->setStyleSheet(styleSheet);
        }

    sqlhelp = new StatsSqlHelper();
    sqlhelp->init();

    QPushButton *mental = this->findChild<QPushButton *>("mental");
    QPushButton *exit = this->findChild<QPushButton *>("exit");
    QPushButton *help = this->findChild<QPushButton *>("help");
    QPushButton *color = this->findChild<QPushButton *>("color");
    QPushButton *ineq = this->findChild<QPushButton *>("ineq");
    QPushButton *stats = this->findChild<QPushButton *>("stats");
    QObject::connect(mental,SIGNAL(clicked(bool)),this,SLOT(mentalClicked()));
    QObject::connect(exit,SIGNAL(clicked(bool)),this,SLOT(close()));
    QObject::connect(help,SIGNAL(clicked(bool)),this,SLOT(helpClicked()));
    QObject::connect(color,SIGNAL(clicked(bool)),this,SLOT(colorClicked()));
    QObject::connect(ineq,SIGNAL(clicked(bool)),this,SLOT(ineqClicked()));
    QObject::connect(stats,SIGNAL(clicked(bool)),this,SLOT(statsClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mentalClicked()
{
    MentalSett *sett=new MentalSett();
    sett->sqlhelp=sqlhelp;
    sett->show();
}
void MainWindow::colorClicked()
{
   ColorSett *sett=new ColorSett();
   sett->sqlhelp=sqlhelp;
   sett->show();
}
void MainWindow::ineqClicked()
{
   InequalitySett *sett=new InequalitySett();
   sett->sqlhelp=sqlhelp;
   sett->show();
}


void MainWindow::statsClicked()
{
    sqlhelp->showStats();
}


void MainWindow::helpClicked()
{
    helpwin *hw = new helpwin();
    hw->show();
}


void MainWindow::cardClicked()
{
    CardSett *cq = new CardSett();
    cq->show();
}
