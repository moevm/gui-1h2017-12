#include "inequalityquest.h"
#include "ui_inequalityquest.h"

InequalityQuest::InequalityQuest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InequalityQuest)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("Неравенства"));

    sum=0;
    cur=0;

    left = this->findChild<QLabel *>("left");
    right = this->findChild<QLabel *>("right");
    res = this->findChild<QLabel *>("res");


    QPushButton *exit = this->findChild<QPushButton *>("exit");
    moreB = this->findChild<QPushButton *>("more");
    lowB = this->findChild<QPushButton *>("low");
    eqB = this->findChild<QPushButton *>("eq");

    ptimer = new QTimer(this);

    QObject::connect(ptimer,SIGNAL(timeout()),this,SLOT(game()));
    QObject::connect(lowB,SIGNAL(clicked(bool)),this,SLOT(low()));
    QObject::connect(eqB,SIGNAL(clicked(bool)),this,SLOT(eq()));
    QObject::connect(moreB,SIGNAL(clicked(bool)),this,SLOT(more()));
    QObject::connect(exit,SIGNAL(clicked(bool)),this,SLOT(deleteLater()));
}

InequalityQuest::~InequalityQuest()
{
    delete ui;
}


void InequalityQuest::init(bool neg,int comp,int time,int games,int compz)
{
    this->negS=neg;
    this->compS=comp;
    this->timeS=time;
    this->games=games;
    this->comp=compz;

    ptimer->start(timeS);
    game();
}

void InequalityQuest::game()
{
    cur++;

    if(cur<=games)
    {
        int c = this->compS;
        leftC=labelEvaq(left,c);
        rightC=labelEvaq(right,c);
    }
    else
    {
        left->setText(QString::fromLocal8Bit("Ваш реузльтат:"));
        double b=(double) (100*sum)/games;

        this->sqlhelp->addStats(QString::fromLocal8Bit("Неравенства"),comp,b);
        QString r=QString::number(b)+"%";

        right->setText(r);

        lowB->setEnabled(false);
        lowB->setVisible(false);

        moreB->setEnabled(false);
        moreB->setVisible(false);

        eqB->setEnabled(false);
        eqB->setVisible(false);
    }
}

void InequalityQuest::low()
{
    if(leftC<rightC)
    {
        sum++;
        QString s=QString::number(sum);
        res->setText(s);
    }
    ptimer->stop();
    ptimer->start(timeS);
    game();
}

void InequalityQuest::eq()
{
    if(leftC==rightC)
    {
        sum++;
        QString s=QString::number(sum);
        res->setText(s);
    }
    ptimer->stop();
    ptimer->start(timeS);
    game();
}

void InequalityQuest::more()
{
    if(leftC>rightC)
    {
        sum++;
        QString s=QString::number(sum);
        res->setText(s);
    }
    ptimer->stop();
    ptimer->start(timeS);
    game();
}

float InequalityQuest::labelEvaq(QLabel *l, int comp)
{
    float result=0;
    int minO=comp/5;
    int oper;

    int p=qrand()%100;
    if(comp<2) p=0;
    oper=round(minO+((float)p/100));

    int sign;
    sign = round((comp-oper)/(oper+1));

    QString s = "";

    int st = ((long int)pow(10,sign));


    float num = st/10+qrand()%(st-st/10);
    if(negS)
    {
        p=qrand()%100;
        if(p>75) num=-num;
    }
    float num1;
    float sum=num;
    s+=QString::number(num);

    bool b=false;
    bool b1=false;
    if(oper==0) result+=num;
    for(int i=0;i<oper;i++)
    {
        st = ((long int)pow(10,sign));
        num1 = st/10+qrand()%(st-st/10);
        if(negS)
        {
            p=qrand()%100;
            if(p>75) num1=-num1;
        }
        p=qrand()%100;

        if(p<=20)
        {
            if(num1<0) b1=true;
            s+="/";
            sum=sum/num1;
            b=true;
            if(s[s.length()-2]==')') b=false;
            else s.insert(s.length()-sign-1,"(");
        }
        if((p>20)&&(p<=50))
        {
            if(num1>0) s+="+";
            result+=sum;
            sum=num1;
        }
        if((p>50)&&(p<=80))
        {
            if(num1<0) s+="+";
            else s+="-";
            result+=sum;
            sum=-num1;
        }
        if(p>80)
        {
            if(num1<0) b1=true;
            s+="x";
            sum=sum*num1;
            b=true;
            if(s[s.length()-2]==')') b=false;
            else s.insert(s.length()-sign-1,"(");
        }
        if(b1){
            s+="("+QString::number(num1)+")";
            b1=false;
        }
        else s+=QString::number(num1);
        if(b)
        {
            s+=")";
            b=false;
        }
        num=num1;
    }

    result+=sum;
    l->setText(s);
    return result;
}

bool oper(QString s,int n)
{
    return ((s[n]=='*')||(s[n]=='/')||(s[n]=='+')||(s[n]=='-'));
}
