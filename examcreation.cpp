#include "examcreation.h"
#include "ui_examcreation.h"
#include "login.h"
#include<iostream>
#include <sstream>
#include "examview.h"
#include "teacherlogin.h"
using namespace std;
ExamCreation::ExamCreation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExamCreation)
{
    ui->setupUi(this);
    Login conn;//=new Login;
    QSqlQueryModel *modal=new QSqlQueryModel();
    //conn->connOpen();
    QSqlQuery *qry=new QSqlQuery(conn.myDB);
    qry->prepare("select QuesionBankTypes.QuestionID,QuesionBankTypes.QuesionText,QuesionBankTypes.Answer from QuesionBankTypes join QuestionBank on QuesionBankTypes.QBankID = QuestionBank.QBankID where QuestionBank.CourseID=105");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

ExamCreation::~ExamCreation()
{
    delete ui;
}

void ExamCreation::on_tableView_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
   QString name = index.sibling(row, 1).data().toString();
   int qid =index.sibling(row,0).data().toInt();
    this->index=qid;
    ui->label_2->setText(name);
}

void ExamCreation::on_pushButton_clicked()
{
    stringstream ss0;
    ss0<<this->index;
    string str0=ss0.str();
     QSqlQuery qry;
 qry.prepare("Insert into ExamQuestions (SectionID,QuestionID) values (1,'"+QString::QString(str0.c_str())+"')");
 if(qry.exec())
 {
     //ui->label_4->setText("done");
     while(qry.next()){
         //this->close();
         //conn.close();
     }
 //        conn.close();
 }
 else
 {
     ui->label_2->setText("Could Not add");
 }
}

void ExamCreation::on_pushButton_2_clicked()
{
    this->close();
    ExamView *E=new ExamView;
    E->show();
}

void ExamCreation::on_pushButton_3_clicked()
{
    TeacherLogin *TL=new TeacherLogin;
    this->close();
    TL->show();
}
