#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <vector>
#include <algorithm>

using namespace std;

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();

private slots:
    void on_max_price_clicked();
    void on_name_clicked();
    void on_letter_clicked();
    void on_years_clicked();

    bool blablabla(QString &str, QString &let);

private:
    Ui::Search *ui;
    int size;
    int column;
};

#endif // SEARCH_H
