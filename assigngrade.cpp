#include "assigngrade.h"
#include "ui_assigngrade.h"
#include "teacherlogin.h"

AssignGrade::AssignGrade(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AssignGrade)
{
    ui->setupUi(this);
    QString s = QString::number(10);
    ui->label_4->setText(s);
}

AssignGrade::~AssignGrade()
{
    delete ui;
}

void AssignGrade::on_pushButton_clicked()
{
    QString grade=ui->lineEdit->text();
    QSqlQuery qry;
    qry.prepare("insert into Grading (TeacherID,StudentID,ExamID,Grade) values(4005,4065,1,'"+grade+"')");
    qry.exec();
    qry.prepare("update Reporting set Grade='"+grade+"' where StudentID=4065");
    qry.exec();
    TeacherLogin *TL=new TeacherLogin;
    this->close();
    TL->show();
}
