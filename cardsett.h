#ifndef CARDSETT_H
#define CARDSETT_H

#include <QWidget>

namespace Ui {
class CardSett;
}

class CardSett : public QWidget
{
    Q_OBJECT

public:
    explicit CardSett(QWidget *parent = 0);
    ~CardSett();

private:
    Ui::CardSett *ui;

    int games=5;
    int max=10;

private slots:
    void goCard();
    void maxSet(int d);
    void gamesSet(int n);
};

#endif // CARDSETT_H
