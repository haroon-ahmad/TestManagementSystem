#ifndef STUDENTLOGIN_H
#define STUDENTLOGIN_H

#include <QDialog>

namespace Ui {
class studentlogin;
}

class studentlogin : public QDialog
{
    Q_OBJECT

public:
    explicit studentlogin(QWidget *parent = 0);
    void setRoll(int R);
    int getRoll();
    ~studentlogin();

private slots:
    void on_logout_clicked();


    void on_examView_doubleClicked(const QModelIndex &index);

private:
    Ui::studentlogin *ui;
    int RollNo;

};

#endif // STUDENTLOGIN_H
