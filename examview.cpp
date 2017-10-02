#include "examview.h"
#include "ui_examview.h"
#include "login.h"
#include "teacherlogin.h"
ExamView::ExamView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExamView)
{
    ui->setupUi(this);
    Login conn;//=new Login;
    QSqlQueryModel *modal=new QSqlQueryModel();
    //conn->connOpen();
    QSqlQuery *qry=new QSqlQuery(conn.myDB);
    qry->prepare("select QuesionText from ExamQuestions join QuesionBankTypes on ExamQuestions.QuestionID=QuesionBankTypes.QuestionID");
    qry->exec();
    modal->setQuery(*qry);
    ui->lala->setModel(modal);
}

ExamView::~ExamView()
{
    delete ui;
}

void ExamView::on_pushButton_clicked()
{

}

void ExamView::on_pushButton_2_clicked()
{
    TeacherLogin *TL=new TeacherLogin;
    this->close();
    TL->show();
}
