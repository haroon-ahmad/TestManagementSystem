#ifndef REPORTING_H
#define REPORTING_H

#include <QWidget>

namespace Ui {
class Reporting;
}

class Reporting : public QWidget
{
    Q_OBJECT

public:
    explicit Reporting(QWidget *parent = 0);
    ~Reporting();

private:
    Ui::Reporting *ui;
};

#endif // REPORTING_H
