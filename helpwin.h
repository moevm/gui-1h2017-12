#ifndef HELPWIN_H
#define HELPWIN_H

#include <QWidget>

namespace Ui {
class helpwin;
}

class helpwin : public QWidget
{
    Q_OBJECT

public:
    explicit helpwin(QWidget *parent = 0);
    ~helpwin();

private:
    Ui::helpwin *ui;
};

#endif // HELPWIN_H
