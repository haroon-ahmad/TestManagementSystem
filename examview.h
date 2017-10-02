#ifndef EXAMVIEW_H
#define EXAMVIEW_H

#include <QWidget>

namespace Ui {
class ExamView;
}

class ExamView : public QWidget
{
    Q_OBJECT

public:
    explicit ExamView(QWidget *parent = 0);
    ~ExamView();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ExamView *ui;
};

#endif // EXAMVIEW_H
