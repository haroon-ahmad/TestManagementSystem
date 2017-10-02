#include "reporting.h"
#include "ui_reporting.h"
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

Reporting::Reporting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reporting)
{
    Login conn;
    ui->setupUi(this);
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery(conn.myDB);
    qry->prepare("select StudentID,Grade from Reporting ");
    qry->exec();
    modal->setQuery(*qry);
    ui->reporttable->setModel(modal);

}

Reporting::~Reporting()
{
    delete ui;
}
