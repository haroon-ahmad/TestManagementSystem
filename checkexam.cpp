#include "checkexam.h"
#include "ui_checkexam.h"
#include "assigngrade.h"
#include "questionbank.h"
#include "ui_questionbank.h"
#include "login.h"
#include "teacherlogin.h"
#include<string>
#include<sstream>
#include <iostream>
using namespace std;

CheckExam::CheckExam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckExam)
{
    Login conn;
    ui->setupUi(this);
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery(conn.myDB);
    qry->prepare("select QuesionBankTypes.QuesionText,ExamExecution.QuestionID,ExamExecution.Answer from QuesionBankTypes join ExamExecution on QuesionBankTypes.QuestionID = ExamExecution.QuestionID ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    marks=0;
}

CheckExam::~CheckExam()
{
    delete ui;
}

void CheckExam::on_pushButton_clicked()
{
    AssignGrade *TL=new AssignGrade;
    TL->marks=marks;
    this->close();
    TL->show();
}

void CheckExam::on_tableView_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
   QString statement = index.sibling(row, 0).data().toString();
   ui->question->setText(statement);
   QString answer = index.sibling(row, 2).data().toString();
   ui->studentanswer->setText(answer);
}

void CheckExam::on_pushButton_2_clicked()
{
    int speedValue = ui->marks1->value();
    marks=marks+speedValue;
}
