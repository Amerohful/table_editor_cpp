#include "search.h"
#include "ui_search.h"
#include <QFile>
#include <QDir>
#include <QDebug>

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);

    size = 0;
    column = 3;
    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Toy" << "Price" << "Age");

    connect(ui->cancel,SIGNAL(clicked(bool)),this,SLOT(close()));
}

Search::~Search()
{
    delete ui;
}

// вывод товаров с ценой отличающейся не более чем на 1000
void Search::on_max_price_clicked()
{
    size = 0;
    ui->tableWidget->setRowCount(size);
    QFile mFile("/home/amerohful/build-practis_5-Desktop-Debug/toys.dat");
    if (!mFile.open(QFile::ReadOnly | QFile::Text)) qDebug() << "Error. You shell not path!!";
    QTextStream stream(&mFile);
    QString buffer = stream.readAll();
    QStringList list = buffer.split(" ");
    vector<vector<QString> > matrix((list.size() / 3), vector<QString>(3));
    for (int i = 0, j = 0; i < list.size() - 1; j++, i += 3)
    {
        matrix[j][0] = list.at(i);
        matrix[j][1] = list.at(i + 1);
        matrix[j][2] = list.at(i + 2);
    }
    mFile.flush();
    mFile.close();

    int max = matrix.at(0).at(1).toInt();
    size = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix.at(i).at(1).toInt() >= max)
            max = matrix.at(i).at(1).toInt();
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix.at(i).at(1).toInt() > max - 1000)
        {
            ui->tableWidget->setRowCount(++size);
            ui->tableWidget->setItem(size - 1, 0, new QTableWidgetItem(matrix.at(i).at(0)));
            ui->tableWidget->setItem(size - 1, 1, new QTableWidgetItem(matrix.at(i).at(1)));
            ui->tableWidget->setItem(size - 1, 2, new QTableWidgetItem(matrix.at(i).at(2)));
        }
    }
}

// поиск по имени
void Search::on_name_clicked()
{
    size = 0;
    ui->tableWidget->setRowCount(size);
    QFile mFile("/home/amerohful/build-practis_5-Desktop-Debug/toys.dat");
    if (!mFile.open(QFile::ReadOnly | QFile::Text)) qDebug() << "Error. You shell not path!!";
    QTextStream stream(&mFile);
    QString buffer = stream.readAll();
    QStringList list = buffer.split(" ");
    vector<vector<QString> > matrix((list.size() / 3), vector<QString>(3));
    for (int i = 0, j = 0; i < list.size() - 1; j++, i += 3)
    {
        matrix[j][0] = list.at(i);
        matrix[j][1] = list.at(i + 1);
        matrix[j][2] = list.at(i + 2);
    }
    mFile.flush();
    mFile.close();
    QString name = ui->lineName->text();
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix.at(i).at(0) == name)
        {
            ui->tableWidget->setRowCount(++size);
            ui->tableWidget->setItem(size - 1, 0, new QTableWidgetItem(matrix.at(i).at(0)));
            ui->tableWidget->setItem(size - 1, 1, new QTableWidgetItem(matrix.at(i).at(1)));
            ui->tableWidget->setItem(size - 1, 2, new QTableWidgetItem(matrix.at(i).at(2)));
        }
    }
}

// поиск по первой букве
void Search::on_letter_clicked()
{
    size = 0;
    ui->tableWidget->setRowCount(size);
    QFile mFile("/home/amerohful/build-practis_5-Desktop-Debug/toys.dat");
    if (!mFile.open(QFile::ReadOnly | QFile::Text)) qDebug() << "Error. You shell not path!!";
    QTextStream stream(&mFile);
    QString buffer = stream.readAll();
    QStringList list = buffer.split(" ");
    vector<vector<QString> > matrix((list.size() / 3), vector<QString>(3));
    for (int i = 0, j = 0; i < list.size() - 1; j++, i += 3)
    {
        matrix[j][0] = list.at(i);
        matrix[j][1] = list.at(i + 1);
        matrix[j][2] = list.at(i + 2);
    }
    mFile.flush();
    mFile.close();
    QString name = ui->lineLetter->text();
    for (int i = 0; i < matrix.size(); i++)
    {
        QString s = matrix.at(i).at(0);
        if (blablabla(s, name))
        {
            ui->tableWidget->setRowCount(++size);
            ui->tableWidget->setItem(size - 1, 0, new QTableWidgetItem(matrix.at(i).at(0)));
            ui->tableWidget->setItem(size - 1, 1, new QTableWidgetItem(matrix.at(i).at(1)));
            ui->tableWidget->setItem(size - 1, 2, new QTableWidgetItem(matrix.at(i).at(2)));
        }
    }
}

bool Search::blablabla(QString &str, QString &let)
{
    bool a = false;
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == let[0] && str[i + 1] == let[1])
        {
            a = true;
            return a;
        }
    }

}

// вывод всех товаров с возрастом больше указанного
void Search::on_years_clicked()
{
    size = 0;
    ui->tableWidget->setRowCount(size);
    QFile mFile("/home/amerohful/build-practis_5-Desktop-Debug/toys.dat");
    if (!mFile.open(QFile::ReadOnly | QFile::Text)) qDebug() << "Error. You shell not path!!";
    QTextStream stream(&mFile);
    QString buffer = stream.readAll();
    QStringList list = buffer.split(" ");
    vector<vector<QString> > matrix((list.size() / 3), vector<QString>(3));
    for (int i = 0, j = 0; i < list.size() - 1; j++, i += 3)
    {
        matrix[j][0] = list.at(i);
        matrix[j][1] = list.at(i + 1);
        matrix[j][2] = list.at(i + 2);
    }
    mFile.flush();
    mFile.close();
    int age = ui->lineYears->text().toInt();
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix.at(i).at(2).toInt() >= age)
        {
            ui->tableWidget->setRowCount(++size);
            ui->tableWidget->setItem(size - 1, 0, new QTableWidgetItem(matrix.at(i).at(0)));
            ui->tableWidget->setItem(size - 1, 1, new QTableWidgetItem(matrix.at(i).at(1)));
            ui->tableWidget->setItem(size - 1, 2, new QTableWidgetItem(matrix.at(i).at(2)));
        }
    }
}
