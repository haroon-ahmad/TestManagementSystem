#ifndef EXAM_H
#define EXAM_H

#include <QWidget>

namespace Ui {
class Exam;
}

class Exam : public QWidget
{
    Q_OBJECT

public:
    explicit Exam(QWidget *parent = 0);
    ~Exam();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Exam *ui;
};

#endif // EXAM_H
