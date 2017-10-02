#ifndef QUESTIONBANK_H
#define QUESTIONBANK_H

#include <QWidget>

namespace Ui {
class QuestionBank;
}

class QuestionBank : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionBank(QWidget *parent = 0);
    int getcID();
    void setcID(int c);
    ~QuestionBank();

private slots:
    void on_Fillintheblanks_clicked();

    void on_Mcq_clicked();

    void on_Descriptive_clicked();

    void on_Programming_clicked();

    void on_Puzzles_clicked();

    void on_pushButton_clicked();


    void on_questions_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::QuestionBank *ui;
    int type;
    int cID;
};

#endif // QUESTIONBANK_H
