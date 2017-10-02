#ifndef STUDENTFILLIN_H
#define STUDENTFILLIN_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class studentFillin;
}

class studentFillin : public QDialog
{
    Q_OBJECT

public:
    explicit studentFillin(QWidget *parent = 0);
    ~studentFillin();

private:
    Ui::studentFillin *ui;
};

#endif // STUDENTFILLIN_H
