#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

signals:
    void addToy(const QString &str);
    void addPrice(const QString &str2);
    void addAge(const QString &str3);


private slots:
    void okClicked();
};

#endif // DIALOG_H
