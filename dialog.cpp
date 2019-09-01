#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()),SLOT(okClicked()));
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()),SLOT(close()));
}

void Dialog::okClicked()
{
    emit addToy(ui->lineEdit->text());
    emit addPrice(ui->lineEdit_2->text());
    emit addAge(ui->lineEdit_3->text());
    close();
}

Dialog::~Dialog()
{
    delete ui;
}
