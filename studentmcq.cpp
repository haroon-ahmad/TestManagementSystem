#include "studentmcq.h"
#include "ui_studentmcq.h"

studentMCQ::studentMCQ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentMCQ)
{
    ui->setupUi(this);
}

studentMCQ::~studentMCQ()
{
    delete ui;
}
