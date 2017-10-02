#ifndef STUDENTMCQ_H
#define STUDENTMCQ_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class studentMCQ;
}

class studentMCQ : public QDialog
{
    Q_OBJECT

public:
    explicit studentMCQ(QWidget *parent = 0);
    ~studentMCQ();

private:
    Ui::studentMCQ *ui;
};

#endif // STUDENTMCQ_H
