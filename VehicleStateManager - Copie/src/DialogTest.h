#ifndef DIALOGTEST_H
#define DIALOGTEST_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class DialogTest;
}

class DialogTest : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTest(QWidget *parent = nullptr);
    ~DialogTest();

private slots:
    void Enddiagclicked();

private:
    Ui::DialogTest *ui;
    QStandardItemModel * Model= nullptr;
};

#endif // DIALOGTEST_H
