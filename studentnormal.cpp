#include "studentnormal.h"
#include "ui_studentnormal.h"
#include"login.h"
#include<iostream>
#include<string>

using namespace std;


studentNormal::studentNormal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentNormal)
{
    ui->setupUi(this);
    iterator = 0;
    qid = 1;
    boolean = false;
    answer = NULL;
}

void studentNormal::regulator(int qbid){
    Login conn;

    string a = std::to_string(qbid);
    int type = 3;
    string a1 = std::to_string(type);

    QSqlQuery *qry1 = new QSqlQuery(conn.myDB);
    int id1 = 0;
    qry1->prepare("select QuestionID from QuesionBankTypes where QBankID = '"+QString::QString(a.c_str())+"' and QuestionType = '"+QString::QString(a1.c_str())+"'");

    if(qry1->exec()){
        while(qry1->next() && id1<=qid)
        {
            id1 = qry1->value(0).toInt();
            if(id1 > qid)
                break;
        }
        iterator++;
        if(id1 > qid){
            qid = id1;
            string a2 = to_string(qid);

            QSqlQuery *qry2 = new QSqlQuery(conn.myDB);
            qry2->prepare("select QuesionText from QuesionBankTypes where QBankID = '"+QString::QString(a.c_str())+"' and QuestionType = '"+QString::QString(a1.c_str())+"' and QuestionID = '"+QString::QString(a2.c_str())+"'");
            QString ques;
            if(qry2->exec())
            {
                while(qry2->next())
                {
                    ques = qry2->value("QuesionText").toString();
                }
            }
            ui->question->setText(ques);
        }
    }
}

void studentNormal::setCourseID(int c){
    courseID = c;
    string a = std::to_string(courseID);
    Login conn;
    QSqlQuery *qry1 = new QSqlQuery(conn.myDB);
    qry1->prepare("select QBankID from QuestionBank where CourseID = '"+QString::QString(a.c_str())+"'");
    int qbid1 = 0;
    if(qry1->exec())
    {
        while(qry1->next())
        {
            qbid1 = qry1->value(0).toInt();
        }
    }
    int type = 3;
    qbid = qbid1;
    string a2 = std::to_string(type);
    string a1 = std::to_string(qbid);
    QSqlQuery *qry2 = new QSqlQuery(conn.myDB);
    qry2->prepare("select count(QuestionID) from QuesionBankTypes where QBankID = '"+QString::QString(a1.c_str())+"'and QuestionType='"+QString::QString(a2.c_str())+"' ");
    int size1 = 0;
    if(qry2->exec())
    {
        while(qry2->next())
        {
            size1 = qry2->value(0).toInt();
        }
    }
    size = size1;
    answer = new string*[size];
    regulator(qbid);
}

int studentNormal::getCourseID(){
    return courseID;
}

studentNormal::~studentNormal()
{
    delete ui;
}

void studentNormal::loopQuestions(){
    cout<<"Now im here";
    Login conn;
    int type = 3;
    string a2 = std::to_string(type);
    string a1 = std::to_string(qbid);
    QSqlQuery *qry1 = new QSqlQuery(conn.myDB);
    int id1 = 0;

    qry1->prepare("select QuestionID from QuesionBankTypes where QBankID = '"+QString::QString(a1.c_str())+"' and QuestionType = '"+QString::QString(a2.c_str())+"'");
    if(iterator < size){
        if(qry1->exec()){
                cout<<endl<<"qid == "<<qid<<endl;
               // qry1->next();
            while(qry1->next()){
                id1 = qry1->value(0).toInt();
                cout<<endl<<"id == "<<id1<<endl;
                if(id1 > qid)
                    break;
            }
            iterator++;
            if(id1 > qid){
                qid = id1;
                string a3 = to_string(qid);

                QSqlQuery *qry2 = new QSqlQuery(conn.myDB);
                qry2->prepare("select QuesionText from QuesionBankTypes where QBankID = '"+QString::QString(a1.c_str())+"' and QuestionType = '"+QString::QString(a2.c_str())+"' and QuestionID = '"+QString::QString(a3.c_str())+"'");
                QString ques;
                if(qry2->exec())
                {
                    while(qry2->next())
                    {
                        ques = qry2->value("QuesionText").toString();
                    }
                }
                ui->question->setText(ques);
            }
        }
    }

}

void studentNormal::on_submit_clicked(){
    if(iterator<size){
        QString newA = ui->answer->text();
        string a = newA.toStdString();
        answer[iterator] = new string(a);
        loopQuestions();
        //answer[iterator] = new string(a);
        cout<<"Answer : "<<*answer[iterator]<<endl;
    }
    else{
        ui->question->clear();
        QString lel = "this part of the test is all but clear";
         ui->question->setText(lel);

    }
}
