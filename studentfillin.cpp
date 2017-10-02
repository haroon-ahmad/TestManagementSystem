#include "studentfillin.h"
#include "ui_studentfillin.h"

studentFillin::studentFillin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentFillin)
{
    ui->setupUi(this);
}

studentFillin::~studentFillin()
{
    delete ui;
}
