#ifndef TEACHERLOGIN_H
#define TEACHERLOGIN_H

#include <QDialog>
#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>


namespace Ui {
class TeacherLogin;
}

class TeacherLogin : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherLogin(QWidget *parent = 0);
    void setRoll(int R);
    int getRoll();
    int getCourseID();
    void setCourseID(int c);
    ~TeacherLogin();

private slots:
    void on_pushButton_clicked();

    void on_viewcourses_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::TeacherLogin *ui;
    QSqlDatabase myDB;
    int RollNo;
    int CourseID;
};

#endif // TEACHERLOGIN_H
