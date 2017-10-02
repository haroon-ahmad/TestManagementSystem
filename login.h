#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase myDB;
    void connClose()
    {
        myDB.close();
        myDB.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
        myDB = QSqlDatabase::addDatabase("QSQLITE");
        myDB.setDatabaseName("C:/Users/Haroon/Desktop/Phase3/MyDB");
        if(!myDB.open()){
            return false;
        }
        else{
            return true;
        }
    }

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::Login *ui;
    int type = 0;
};

#endif // LOGIN_H
