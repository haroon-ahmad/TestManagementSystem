#ifndef STUDENTNORMAL_H
#define STUDENTNORMAL_H

#include <QDialog>
#include<string>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

using namespace std;

namespace Ui {
class studentNormal;
}

class studentNormal : public QDialog
{
    Q_OBJECT

public:
    explicit studentNormal(QWidget *parent = 0);
    void setCourseID(int c);
    int getCourseID();
    void regulator(int qbid);
    void loopQuestions();
    ~studentNormal();

private slots:
    void on_submit_clicked();

private:
    Ui::studentNormal *ui;
    int iterator;
    int courseID;
    int qbid;
    string** answer;
    int size;
    int qid;
    bool boolean;
};

#endif // STUDENTNORMAL_H
