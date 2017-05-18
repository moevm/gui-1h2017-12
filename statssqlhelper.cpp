#include "statssqlhelper.h"
#include "ui_statssqlhelper.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QHeaderView>
StatsSqlHelper::StatsSqlHelper(QWidget *parent) : QWidget(parent),
    ui(new Ui::StatsSqlHelper)
{
    ui->setupUi(this);    
    view = this->findChild<QTableView *>("tableView");

    this->setWindowTitle(QString::fromLocal8Bit("Статистика"));
}

StatsSqlHelper::~StatsSqlHelper()
{
}

void StatsSqlHelper::init()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("BrainStorm");

      if (!m_db.open())
      {
         qDebug() << "Error: connection with database fail";
      }
      else
      {
         qDebug() << "Database: connection ok";
      }

      QSqlQuery a_query;
      // DDL query
      a_query.prepare( "CREATE TABLE IF NOT EXISTS stats (id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, quest_name VARCHAR(30), complexity VARCHAR(10), result VARCHAR(10))" );

      if( !a_query.exec() )
          qDebug() << a_query.lastError();
      else
          qDebug() << "Table created!";
}

void StatsSqlHelper::deleteStats(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM stats WHERE id = (:id)");
    query.bindValue(":id", id);
    bool b = query.exec();

    if(!b) qDebug() << "remove error: " << query.lastError();
}

void StatsSqlHelper::addStats(QString questname, int complexity, int result)
{
    QSqlQuery a_query;
    QString str_insert = "INSERT INTO stats(quest_name, complexity, result) "
                "VALUES ('%1', '%2', '%3');";

    QString c = QString::number(complexity)+"%";
    QString r = QString::number(result)+"%";

    str_insert = str_insert.arg(questname)
            .arg(c)
            .arg(r);

    bool b = a_query.exec(str_insert);

    if(!b) qDebug() << "Insert err";
}


void StatsSqlHelper::selectAll()
{
    QSqlQuery a_query;
    if (!a_query.exec("SELECT * FROM stats"))
    {
          qDebug() << "Даже селект не получается, я пас.";
          return;
    }
    QSqlRecord rec = a_query.record();
    int nameCol=0;
    int complCol=0;
    int resCol=0;
    int idCol=0;
    int id;
    QString n,c,r;
    QString address = "";

    nameCol=rec.indexOf("quest_name");
    complCol=rec.indexOf("complexity");
    resCol=rec.indexOf("result");
    idCol=rec.indexOf("id");

    while (a_query.next())
    {
      n = a_query.value(nameCol).toString();
      c = a_query.value(complCol).toString();
      r = a_query.value(resCol).toString();
      id = a_query.value(idCol).toInt();

      qDebug() << id << " " << n << " "  << c << " " << r;
    }
}

void StatsSqlHelper::showStats()
{
    model=new QSqlTableModel(this,m_db);
    model->setTable("stats");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);


    view->setModel(model);
    //view->
    view->hideColumn(0);

    view->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    this->show();
}
