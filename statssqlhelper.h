#ifndef STATSSQLHELPER_H
#define STATSSQLHELPER_H

#include <QWidget>
#include <QApplication>
#include <statssqlhelper.h>
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
    int nameCol=0;
    int complCol=0;
    int resCol=0;
    int idCol=0;

    int col=0;
    QTableView *view;

public slots:
    void setCol(int col);
};

#endif // STATSSQLHELPER_H
