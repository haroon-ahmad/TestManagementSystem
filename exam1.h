#ifndef EXAM1_H
#define EXAM1_H

#include <QDialog>
#include<string>

using namespace std;

namespace Ui {
class Exam1;
}

class Exam1 : public QDialog
{
    Q_OBJECT

public:
    explicit Exam1(QWidget *parent = 0);
    void setCourse(string L);
    string getCourse();
    void setRoll(int R);
    int getRoll();
    ~Exam1();

private slots:
    void on_mcq_clicked();

    void on_fillin_clicked();

    void on_pushButton_clicked();

    void on_cancel_clicked();

private:
    Ui::Exam1 *ui;
    string course;
    int Roll;
};

#endif // EXAM_H
