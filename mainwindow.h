#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void getToy(const QString &toy);
    void getPrice(const QString &price);
    void getAge(const QString &age);

    void changeToy(const QString &toy);
    void changePrice(const QString &price);
    void changeAge(const QString &age);

    void open();
    void save();
    void searc();

private:
    Ui::MainWindow *ui;
    int size;
    int column;
};

#endif // MAINWINDOW_H
