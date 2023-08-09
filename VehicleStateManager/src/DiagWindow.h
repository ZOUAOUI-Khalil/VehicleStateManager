#ifndef DIAGWINDOW_H
#define DIAGWINDOW_H
#include <QMqttClient>
#include <QDialog>
#include <QStandardItemModel>
#include <TypesAndDefines.h>


namespace Ui {
class DiagWindow;
}
/*!
 * \brief The DiagWindow class this is a class hello
 */

class DiagWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DiagWindow(QWidget *parent = nullptr, int SerialNumber =0, QMap<long,TGURMsg>* CurrentData = nullptr, QMqttClient* i_PtrClient = nullptr);
    ~DiagWindow();


private:
    QMqttClient* m_Client=nullptr;
    //TGURMsg Msg;
    int m_SerialNumber = -1;
    QMap<long,TGURMsg>* m_CurrentData = nullptr;
    TGURMsg Message;
    Ui::DiagWindow *ui;
    QStandardItemModel * Model= nullptr;
    /*TGURMsg* Msg=nullptr;*/

    void updateValues();


public slots:
    void Updatecurrentdata(int serialnumber);
private slots:
    void CroixRouge();
    void Enddiagclicked();
    //void  SetItems ();


};

#endif // DIAGWINDOW_H
