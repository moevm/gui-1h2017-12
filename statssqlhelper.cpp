#include "statssqlhelper.h"
#include "ui_statssqlhelper.h"
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
      }
      else
      {
      }

      QSqlQuery a_query;
      // DDL query
      a_query.prepare( "CREATE TABLE IF NOT EXISTS stats (id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, quest_name VARCHAR(30), complexity VARCHAR(10), result VARCHAR(10))" );

      if( !a_query.exec() ){}

      this->selectAll();

}

void StatsSqlHelper::deleteStats(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM stats WHERE id = (:id)");
    query.bindValue(":id", id);
    bool b = query.exec();

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

}


void StatsSqlHelper::selectAll()
{
    QSqlQuery a_query;
    if (!a_query.exec("SELECT * FROM stats"))
    {
          return;
    }
    QSqlRecord rec = a_query.record();
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
    }
}

void StatsSqlHelper::showStats()
{
    model=new QSqlTableModel(this,m_db);
    model->setTable("stats");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setHeaderData(1,Qt::Horizontal, QString::fromLocal8Bit("Название задания"));
    model->setHeaderData(2,Qt::Horizontal, QString::fromLocal8Bit("Сложность"));
    model->setHeaderData(3,Qt::Horizontal, QString::fromLocal8Bit("Результат"));

    QSortFilterProxyModel *sort_filter = new QSortFilterProxyModel(this);
    sort_filter->setSourceModel(model);

    sort_filter->sort(this->col,Qt::SortOrder::DescendingOrder);

    view->setModel(sort_filter);

    view->hideColumn(0);

    QHeaderView *h = view->horizontalHeader();

    h->setSectionResizeMode(1, QHeaderView::Stretch);

    view->setHorizontalHeader(h);

    this->show();
}

void StatsSqlHelper::setCol(int col)
{
    this->col=col+1;
    this->showStats();
}

void StatsSqlHelper::SlotDel()
{
  int row;
  QItemSelectionModel    *selectModel;
  QModelIndexList         indexes;
  QModelIndex             index;

    // Узнаем выделенную строку
    selectModel = view->selectionModel();
    indexes = selectModel->selectedIndexes();

    foreach(index, indexes)
    {
        QString str;
        row = index.row();
        if (!model->removeRows(row,1))
        {
            str = model->lastError().text();
            break;
        }
        else
        {
            view->setRowHidden(row, true);
        }
    }

    this->update();

}
