#ifndef CHECKEXAM_H
#define CHECKEXAM_H

#include <QWidget>

namespace Ui {
class CheckExam;
}

class CheckExam : public QWidget
{
    Q_OBJECT

public:
    explicit CheckExam(QWidget *parent = 0);
    double marks;
    ~CheckExam();

private slots:
    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::CheckExam *ui;
};

#endif // CHECKEXAM_H
