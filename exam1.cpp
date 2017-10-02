#include "exam1.h"
#include"studentlogin.h"
#include "ui_exam1.h"
#include"studentmcq.h"
#include"studentnormal.h"
#include"studentfillin.h"
#include"login.h"
#include<string>
#include<iostream>

using namespace std;

Exam1::Exam1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exam1)
{
    ui->setupUi(this);

}

void Exam1::setCourse(string L){
    course = L;
    QString  myQS= QString::QString(course.c_str());
    ui->label->setText(myQS);


}

string Exam1::getCourse(){
    return course;
}

Exam1::~Exam1()
{
    delete ui;
}

void Exam1::on_mcq_clicked()
{
    this->close();
    studentMCQ SM;
    SM.setModal(true);
    SM.exec();
}

void Exam1::on_fillin_clicked()
{
    this->close();
    studentFillin SM;
    SM.setModal(true);
    SM.exec();
}

void Exam1::on_pushButton_clicked()
{
    Login conn;
    QSqlQuery *qry1 = new QSqlQuery(conn.myDB);
    qry1->prepare("SELECT CourseID FROM Course WHERE CourseName = '"+QString::QString(course.c_str())+"'");
    int id = 0;
    if(qry1->exec())
    {
        while(qry1->next())
        {
            id = qry1->value(0).toInt();
        }
    }
    this->close();
    studentNormal SM;
    SM.setCourseID(id);
    SM.setModal(true);
    SM.exec();
}

void Exam1::on_cancel_clicked()
{
    this->close();
    studentlogin sL;
    sL.setRoll(Roll);
    sL.setModal(true);
    sL.exec();
}
void Exam1::setRoll(int R){
    Roll = R;
}

int Exam1::getRoll(){
    return Roll;
}
