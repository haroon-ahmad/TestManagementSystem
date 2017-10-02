#include "studentee.h"
#include "ui_studentee.h"
#include "login.h"
#include "teacherlogin.h"
#include "studentlogin.h"
StudentEE::StudentEE(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentEE)
{
    ui->setupUi(this);
    Login conn;//=new Login;
    QSqlQueryModel *modal=new QSqlQueryModel();
    //conn->connOpen();
    QSqlQuery *qry=new QSqlQuery(conn.myDB);
    qry->prepare("select QuesionText,Option1,Option2,Option3,Option4 from ExamQuestions join QuesionBankTypes on ExamQuestions.QuestionID=QuesionBankTypes.QuestionID");
    qry->exec();
    modal->setQuery(*qry);
    ui->examquestions->setModel(modal);
}

StudentEE::~StudentEE()
{
    delete ui;
}

void StudentEE::on_tableView_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    QString question = index.sibling(row, 0).data().toString();
    ui->question1->setText(question);
    QString o1 = index.sibling(row, 1).data().toString();
     ui->opt1->setText(o1);
     QString o2 = index.sibling(row, 2).data().toString();
      ui->opt2->setText(o2);
      QString o3 = index.sibling(row, 3).data().toString();
       ui->opt3->setText(o3);
       QString o4 = index.sibling(row, 4).data().toString();
        ui->opt4->setText(o4);





}

void StudentEE::on_pushButton_clicked()
{
    //QString ans=ui->answ->text().toStdString();

}


void StudentEE::on_pushButton_2_clicked()
{
    studentlogin *ss=new studentlogin;
    this->close();
    ss->show();

}
