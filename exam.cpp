#include "exam.h"
#include "ui_exam.h"
#include <string>
#include "examcreation.h"
#include "teacherlogin.h"
Exam::Exam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Exam)
{
    ui->setupUi(this);
}

Exam::~Exam()
{
    delete ui;
}

void Exam::on_pushButton_clicked()
{
    int speedValue = ui->spinBox->value();
    QString s = QString::number(speedValue);
    ui->label->setText(s);
    this->close();
    ExamCreation *E=new ExamCreation;
    E->show();
}

void Exam::on_pushButton_2_clicked()
{
    TeacherLogin *TL=new TeacherLogin;
    this->close();
    TL->show();
}
