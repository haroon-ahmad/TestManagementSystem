#include "teacherlogin.h"
#include "ui_teacherlogin.h"
#include"login.h"
#include "course.h"
#include "questionbank.h"
#include<sstream>
#include <string>
using namespace std;
TeacherLogin::TeacherLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherLogin){
    ui->setupUi(this);
}

TeacherLogin::~TeacherLogin(){
    delete ui;
}
int TeacherLogin::getRoll()
{
    return RollNo;
}
void TeacherLogin::setRoll(int R)
{
    RollNo=R;
}

void TeacherLogin::on_pushButton_clicked(){
    this->close();
    Login *M = new Login;
    M->show();
}
int TeacherLogin::getCourseID()
{
    return CourseID;
}

void TeacherLogin::setCourseID(int c)
{
    CourseID=c;
}


void TeacherLogin::on_viewcourses_clicked()
{
    stringstream ss0;
    ss0<<getRoll();
    string str0=ss0.str();
    QString  myQS= QString::QString(str0.c_str());

    string a = myQS.toStdString();
    Login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();
   // conn->connOpen();
    QSqlQuery *qry=new QSqlQuery(conn.myDB);
    qry->prepare("select CourseName,Teaches.CourseID from Teaches join Course on Teaches.CourseID=Course.CourseID where TeacherID='"+QString::QString(a.c_str())+"' ");
    qry->exec();
     //this->setCourseID(qry.value("CourseID").toInt());
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
 //   conn->connClose();
}

void TeacherLogin::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();
   int cid = index.sibling(row, 0).data().toInt();
    CourseID=cid;

    /*this->hide();
    Course *C = new Course;
    C->setcID(cid);
    C->show();*/
    this->hide();
    Course *C=new Course;
    C->setcID(CourseID);
    C->show();
}
