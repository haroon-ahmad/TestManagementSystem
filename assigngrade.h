#ifndef ASSIGNGRADE_H
#define ASSIGNGRADE_H

#include <QWidget>

namespace Ui {
class AssignGrade;
}

class AssignGrade : public QWidget
{
    Q_OBJECT

public:
    explicit AssignGrade(QWidget *parent = 0);
    int marks;
    ~AssignGrade();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AssignGrade *ui;
};

#endif // ASSIGNGRADE_H
