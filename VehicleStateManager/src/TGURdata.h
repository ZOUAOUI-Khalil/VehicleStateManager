#ifndef TGURDATA_H
#define TGURDATA_H

#include <QDialog>
#include <QMqttClient>
#include <TypesAndDefines.h>
#include <Windows.h>
#include <wlanapi.h>
namespace Ui {
class TGURdata;
}

class TGURdata : public QDialog
{
    Q_OBJECT

public:
    explicit TGURdata(QWidget *parent = nullptr, QMqttClient* i_PtrClient = nullptr,Configuration* Config=nullptr);
    ~TGURdata();
    

public slots:
   void onconnectBtnclicked();
    void saveinivalues(const QString &path,const QString &groupename,const QString &Name,const QString &Value);
    QString readinivalues(const QString &path,const QString &groupename,const QString &Name);
    QString GetSSID() ;


    /*void onWIFIBtnclicked();*/

private slots:

    void onGSMBtn2clicked();

    void onWIFIBtn2clicked();

    void onComboBoxSECCurrentTextChanged(const QString &arg1);

private:
    QMqttClient* m_Client=nullptr;
    Configuration* m_Config=nullptr;
    Ui::TGURdata* ui;

    bool m_FilledComboBoxes = false;



    // QDialog interface
    void SaveConfiguration();
    void SaveConfigurationwifi();
    void SaveConfigurationInINI();
    void SaveConfigurationInINIWIFI();
    void ReadconfigurationINI();
    void ReadconfigurationINIWIFI();
public slots:
    void reject();
};

#endif // TGURDATA_H
