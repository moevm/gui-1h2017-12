#ifndef MENTALQUEST_H
#define MENTALQUEST_H

#include <QWidget>

namespace Ui {
class MentalQuest;
}

class MentalQuest : public QWidget
{
    Q_OBJECT

public:
    explicit MentalQuest(QWidget *parent = 0);
    ~MentalQuest();

private:
    Ui::MentalQuest *ui;
};

#endif // MENTALQUEST_H
