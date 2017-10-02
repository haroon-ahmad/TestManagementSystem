#include "questionbank.h"
#include "ui_questionbank.h"
#include "login.h"
#include "teacherlogin.h"
#include<string>
#include<sstream>
#include <iostream>
using namespace std;

QuestionBank::QuestionBank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionBank)
{
    ui->setupUi(this);
    //TeacherLogin TL;
    Login conn;//=new Login;
    stringstream ss0;
    ss0<<cID;
    string str0=ss0.str();
    QString  myQS= QString::QString(str0.c_str());

    string a = myQS.toStdString();
    QSqlQueryModel *modal=new QSqlQueryModel();
    //conn->connOpen();
    QSqlQuery *qry=new QSqlQuery(conn.myDB);
    //qry->prepare("select QuesionBankTypes.QuestionID,QuesionBankTypes.QuesionText,QuesionBankTypes.Answer from QuesionBankTypes join QuestionBank on QuesionBankTypes.QBankID = QuestionBank.QBankID where QuestionBank.CourseID='"+QString::QString(a.c_str())+"'");
    qry->prepare("select QuesionBankTypes.QuestionID,QuesionBankTypes.QuesionText,QuesionBankTypes.Answer from QuesionBankTypes join QuestionBank on QuesionBankTypes.QBankID = QuestionBank.QBankID where QuestionBank.CourseID=105");
    qry->exec();
    modal->setQuery(*qry);
    ui->questions->setModel(modal);
    //conn->connClose();
}

QuestionBank::~QuestionBank()
{
    delete ui;
}
void QuestionBank::setcID(int c)
{
    cID=c;
}
int QuestionBank::getcID()
{
    return cID;
}

void QuestionBank::on_Fillintheblanks_clicked()
{
    type=1;
}

void QuestionBank::on_Mcq_clicked()
{
    type=2;
}

void QuestionBank::on_Descriptive_clicked()
{
    type=3;
}

void QuestionBank::on_Programming_clicked()
{
    type=4;
}

void QuestionBank::on_Puzzles_clicked()
{
    type=5;
}

void QuestionBank::on_pushButton_clicked()
{
    Login conn;
    QString statement,answer,option1,option2,option3,option4;
    statement=ui->questiontext->text();
    answer=ui->Answer->text();
    option1=ui->option1->text();
    option2=ui->option2->text();
    option3=ui->option3->text();
    option4=ui->option4->text();
    int qbid=5;
    int qid=19;
    int t=type;
    ui->label_4->setText(option1);
    stringstream ss0;
    ss0<<qbid;
    string str0=ss0.str();
    stringstream ss1;
    ss1<<qid;
    string str1=ss1.str();
    stringstream ss2;
    ss2<<t;
    string str2=ss2.str();

    QSqlQuery qry;
    qry.prepare("insert into QuesionBankTypes (QBankID,QuestionID,QuestionType,QuesionText,Answer,Option1,Option2,Option3,Option4) values('"+QString::QString(str0.c_str())+"','"+QString::QString(str1.c_str())+"','"+QString::QString(str2.c_str())+"','"+statement+"','"+answer+"','"+option1+"','"+option2+"','"+option3+"','"+option4+"')");
    //qry.prepare("insert into QuestionBankTypes (QBankID) values (1)");
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
        ui->label_4->setText("safa");
    }
}


void QuestionBank::on_questions_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
   QString name = index.sibling(row, 1).data().toString();
   int qid =index.sibling(row,0).data().toInt();
   stringstream ss0;
   ss0<<qid;
   string str0=ss0.str();
   QSqlQuery qry;
   qry.prepare("delete from QuesionBankTypes where QuestionId='"+QString::QString(str0.c_str())+"'");
   if(qry.exec())
   {
       //ui->label_4->setText("done");
       while(qry.next()){
           //this->close();
           //conn.close();
       }
//        conn.close();
   }
}

void QuestionBank::on_pushButton_2_clicked()
{
    TeacherLogin *TL=new TeacherLogin;
    this->close();
    TL->show();
}
