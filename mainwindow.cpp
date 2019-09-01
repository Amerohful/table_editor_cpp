#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "search.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    size = 0;
    column = 3;
    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Toy" << "Price" << "Age");

    QAction *open = ui->actionOpen;
    connect(open,SIGNAL(triggered(bool)),this,SLOT(open()));
    QAction *save = ui->actionSave;
    connect(save,SIGNAL(triggered(bool)),this,SLOT(save()));
    QAction *exit = ui->actionExit;
    connect(exit,SIGNAL(triggered(bool)),this,SLOT(close()));
    QAction *search = ui->actionSearch;
    connect(search,SIGNAL(triggered(bool)),this,SLOT(searc()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// вызываем окно поиска
void MainWindow::searc()
{
    save();
    Search *s = new Search();
    s->show();
}

// заполнение таблицы из формы
void MainWindow::on_pushButton_clicked()
{
    Dialog *add = new Dialog(this);
    add->show();

    connect(add,SIGNAL(addToy(QString)),this,SLOT(getToy(QString)));
    connect(add,SIGNAL(addPrice(QString)),this,SLOT(getPrice(QString)));
    connect(add,SIGNAL(addAge(QString)),this,SLOT(getAge(QString)));
}
// добавляем название игрушки
void MainWindow::getToy(const QString &toy)
{
    ui->tableWidget->setRowCount(++size);
    ui->tableWidget->setItem(size - 1, 0, new QTableWidgetItem(toy));
}
// добавляем цену игрушки
void MainWindow::getPrice(const QString &price)
{
    ui->tableWidget->setItem(size - 1, 1, new QTableWidgetItem(price));
}
// добавляем возраст
void MainWindow::getAge(const QString &age)
{
    ui->tableWidget->setItem(size - 1, 2, new QTableWidgetItem(age));
}

// удаляем выбранную строку
void MainWindow::on_pushButton_3_clicked()
{
    if(ui->tableWidget->rowCount() <= 1)
        ui->tableWidget->setRowCount(0);
    else
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    size--;
}

// записываем изменения
void MainWindow::on_pushButton_2_clicked()
{
    Dialog *add = new Dialog(this);
    add->show();

    connect(add,SIGNAL(addToy(QString)),this,SLOT(changeToy(QString)));
    connect(add,SIGNAL(addPrice(QString)),this,SLOT(changePrice(QString)));
    connect(add,SIGNAL(addAge(QString)),this,SLOT(changeAge(QString)));
}
// изменяем название игрушки
void MainWindow::changeToy(const QString &toy)
{
    ui->tableWidget->setItem(ui->tableWidget->currentRow(), 0, new QTableWidgetItem(toy));
}
// изменяем цену игрушки
void MainWindow::changePrice(const QString &price)
{
    ui->tableWidget->setItem(ui->tableWidget->currentRow(), 1, new QTableWidgetItem(price));
}
// изменяем возраст
void MainWindow::changeAge(const QString &age)
{
    ui->tableWidget->setItem(ui->tableWidget->currentRow(), 2, new QTableWidgetItem(age));
}

// открываем файл
void MainWindow::open()
{
    QFile mFile("/home/amerohful/build-practis_5-Desktop-Debug/toys.dat");

    if (!mFile.open(QFile::ReadOnly | QFile::Text))
        qDebug() << "Error. You shell not path!!";

    QTextStream stream(&mFile);

    QString buffer = stream.readAll();

    QStringList list = buffer.split(" ");
    for (int i = 0, row = 0; i < list.size() - 1; row++, i += 3)
    {
        ui->tableWidget->setRowCount(++size);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(list.at(i)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(list.at(i + 1)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(list.at(i + 2)));
    }
    mFile.flush();
    mFile.close();
}

// сохраняем файл
void MainWindow::save()
{
    QFile mFile("/home/amerohful/build-practis_5-Desktop-Debug/toys.dat");

    if (!mFile.open(QFile::WriteOnly | QFile::Text))
        qDebug() << "Error. You shell not path!!";

    QTextStream stream(&mFile);

    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
        for (int col = 0; col < ui->tableWidget->columnCount(); col++)
        {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            stream << item->text() << " ";
        }
    }
    mFile.close();
}
