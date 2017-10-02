#ifndef STUDENTEE_H
#define STUDENTEE_H

#include <QWidget>

namespace Ui {
class StudentEE;
}

class StudentEE : public QWidget
{
    Q_OBJECT

public:
    explicit StudentEE(QWidget *parent = 0);
    ~StudentEE();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::StudentEE *ui;
};

#endif // STUDENTEE_H
