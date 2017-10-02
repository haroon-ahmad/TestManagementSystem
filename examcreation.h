#ifndef EXAMCREATION_H
#define EXAMCREATION_H

#include <QWidget>

namespace Ui {
class ExamCreation;
}

class ExamCreation : public QWidget
{
    Q_OBJECT
public:
int index;
public:
    explicit ExamCreation(QWidget *parent = 0);
    ~ExamCreation();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ExamCreation *ui;
};

#endif // EXAMCREATION_H
