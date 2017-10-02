#include "course.h"
#include "ui_course.h"
#include "exam.h"
#include "questionbank.h"
#include "teacherlogin.h"
#include "checkexam.h"
#include "reporting.h"
Course::Course(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Course)
{
    ui->setupUi(this);
}

Course::~Course()
{
    delete ui;
}
void Course::setcID(int c)
{
    cID=c;
}
int Course::getcID()
{
    return cID;
}
void Course::on_pushButton_2_clicked()
{
    this->close();
    Exam *E=new Exam;
    E->show();
}

void Course::on_pushButton_clicked()
{
    /*this->close();
    QuestionBank *qb=new QuestionBank();
    qb->setcID(cID);
    qb->show();*/
    this->hide();
    QuestionBank *qb=new QuestionBank;
    qb->setcID(cID);
    qb->show();
}

void Course::on_back_clicked()
{
    TeacherLogin *TL=new TeacherLogin;
    this->close();
    TL->show();

}

void Course::on_pushButton_3_clicked()
{
    CheckExam *c=new CheckExam;
    this->close();
    c->show();
}

void Course::on_pushButton_4_clicked()
{
    Reporting *R=new Reporting;
    this->close();
    R->show();
}
