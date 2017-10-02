#include "login.h"
#include "ui_login.h"
#include"teacherlogin.h"
#include"studentlogin.h"
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login(){
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString user, pass;
    user = ui->user->text();
    pass = ui->pass->text();

    string a = user.toStdString();

    if(!connOpen()){
        qDebug()<<"Failed to Connect to Database";
        return;
    }
    QSqlQuery qry;
    qry.prepare("select * from Teacher where T_ID='" + QString::QString(a.c_str()) + "' and Password= '"+pass+"'");

    if(type == 1){
        if(qry.exec()){

            while(qry.next())
            {
                int u=qry.value("T_ID").toInt();
                a.resize(4);
                int u1=stoi(a.c_str());
                this->close();
                TeacherLogin TL;
                TL.setRoll(u1);
                TL.setModal(true);
                TL.exec();
            }
        }
    }
    else if(type == 2){
        if(qry.exec("select * from Student where RollNo='"+ QString::QString(a.c_str()) +"' and Password='"+pass+"'")){
            while(qry.next())
            {
                a.resize(4);
                int u=stoi(a.c_str());
                this->close();
                studentlogin sL;
                sL.setRoll(u);
                sL.setModal(true);
                sL.exec();
            }
        }
    }
}

void Login::on_radioButton_clicked()
{
    type = 1;
}

void Login::on_radioButton_2_clicked()
{
    type = 2;
}
