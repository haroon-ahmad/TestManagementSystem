#ifndef COURSE_H
#define COURSE_H

#include <QWidget>

namespace Ui {
class Course;
}

class Course : public QWidget
{
    Q_OBJECT

public:
    explicit Course(QWidget *parent = 0);
    int getcID();
    void setcID(int c);
    ~Course();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_back_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Course *ui;
    int cID;
};

#endif // COURSE_H
