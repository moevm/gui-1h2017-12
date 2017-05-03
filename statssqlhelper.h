#ifndef STATSSQLHELPER_H
#define STATSSQLHELPER_H

#include <QWidget>
#include <QApplication>
#include <QtSql>
#include <QTableView>

namespace Ui {
class StatsSqlHelper;
}


class StatsSqlHelper : public QWidget
{
    Q_OBJECT

public:
    explicit StatsSqlHelper(QWidget *parent = 0);
    ~StatsSqlHelper();
    void init();
    void addStats(QString questname,int complexity,int result);
    void deleteStats(int id);
    void selectAll();
    void showStats();

private:
    Ui::StatsSqlHelper *ui;
    QSqlDatabase m_db;
    QSqlTableModel *model;
    QTableView *view;
};

#endif // STATSSQLHELPER_H
