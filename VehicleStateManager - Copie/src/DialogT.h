#ifndef DIALOGT_H
#define DIALOGT_H

#include <QDialog>

namespace Ui {
class DialogT;
}

class DialogT : public QDialog
{
    Q_OBJECT

public:
    explicit DialogT(QWidget *parent = nullptr);
    ~DialogT();

public slots:
   void onconnectBtnclicked();
    /*void onWIFIBtnclicked();*/

private slots:
    void onGSMBtn2clicked();

    void onWIFIBtn2clicked();

    void on_comboBoxSEC_currentTextChanged(const QString &arg1);

private:
    Ui::DialogT *ui;

};

#endif // DIALOGT_H
