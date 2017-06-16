#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <statssqlhelper.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void mentalClicked();
    void colorClicked();
    void ineqClicked();
    void statsClicked();
    void helpClicked();
    void cardClicked();

private:
    Ui::MainWindow *ui;
    StatsSqlHelper *sqlhelp;
};

#endif // MAINWINDOW_H
