#include "studentlogin.h"
#include "ui_studentlogin.h"
#include"login.h"
#include "course.h"
#include"exam1.h"
#include "studentee.h"
#include<iostream>
#include<sstream>
#include<string>


using namespace std;

studentlogin::studentlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentlogin)
{
    ui->setupUi(this);
    Login conn;

    QSqlQueryModel *modal1=new QSqlQueryModel();
    QSqlQuery *qry1=new QSqlQuery(conn.myDB);
    qry1->prepare("select CourseName from Course join Exam on Exam.CourseID=Course.CourseID ");
    qry1->exec();
    modal1->setQuery(*qry1);
    ui->examView->setModel(modal1);
}

void studentlogin::setRoll(int R){
    RollNo = R;
    stringstream ss0;
    ss0<<RollNo;
    string str0=ss0.str();
    QString  myQS= QString::QString(str0.c_str());
    ui->rollNo->setText(myQS);
    QString user = ui->rollNo->text();

    string a = user.toStdString();

    Login conn;

    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery(conn.myDB);
    //qry->prepare("select CourseName, Grade from Course join Reporting.CourseID=Course.CourseID where StudentID='" + QString::QString(a.c_str()) + "'");
    qry->exec("SELECT CourseName, Grade FROM Course join Reporting on Course.CourseID = Reporting.CourseID WHERE StudentID='"+QString::QString(a.c_str())+"'");
    modal->setQuery(*qry);
    ui->CourseView->setModel(modal);

}

int studentlogin::getRoll(){
    return RollNo;
}

studentlogin::~studentlogin(){
    delete ui;
}

void studentlogin::on_logout_clicked(){
    this->close();
    Login *M = new Login;
    M->show();
}

void studentlogin::on_examView_doubleClicked(const QModelIndex &index){
    int row = index.row();
    QString name = index.sibling(row, 0).data().toString();
    string a = name.toStdString();

    /*this->close();
    Exam1 sL;
    sL.setRoll(RollNo);
    sL.setCourse(a);
    sL.setModal(true);
    sL.exec();*/
    this->close();
    StudentEE *ss=new StudentEE;
    ss->show();
}

