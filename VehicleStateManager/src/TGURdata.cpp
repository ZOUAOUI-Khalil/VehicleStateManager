#include "TGURdata.h"
#include "ui_TGURdata.h"
#include "MainWindow.h"
#include "VAR.h"
#include <QDebug>
#include<QSettings>
#include<QString>
#include <QDir>
#include <QMessageBox>
#include <QtNetwork>
#include <QNetworkInterface>

TGURdata::TGURdata(QWidget *parent,QMqttClient* i_PtrClient, Configuration* i_ptrConfig) :
    QDialog(parent),
    m_Client(i_PtrClient),
    m_Config(i_ptrConfig),
    ui(new Ui::TGURdata)
{
    ui->setupUi(this);
    connect(ui->Connection, &QPushButton::clicked, this, &TGURdata::onconnectBtnclicked); //Connect
    connect(ui->GSMBtn_2, &QRadioButton::clicked, this, &TGURdata::onGSMBtn2clicked);   // GSM
    connect(ui->WIFIBtn_2, &QRadioButton::clicked, this, &TGURdata::onWIFIBtn2clicked); // WIFI
    connect(ui->SecurityLevel, &QComboBox::currentTextChanged, this, &TGURdata::onComboBoxSECCurrentTextChanged);

    setWindowTitle("Connexion");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint); //poue éliminer le point d'interrogation

    //ui->lineEdit_certif->setWhatsThis("This is a certification for Qos =2"); point d'interrogation

    ui->label_10->setVisible(false);
    ui->SerialNumber->setVisible(false);
    ui->BrokerURI->setEnabled(false);
    ui->Port->setEnabled(false);
    ui->QOS->setEnabled(false);
    ui->Topic->setEnabled(false);
    ui->SecurityLevel->setEnabled(false);
    ui->Login->setEnabled(false);
    ui->Password->setEnabled(false);
    ui->lineEdit_certif->setEnabled(false);
}





QString TGURdata::GetSSID()
{
    HANDLE hClient = nullptr;
    DWORD dwMaxClient = 2;
    DWORD dwCurVersion = 0;
    DWORD dwResult = 0;

    dwResult = WlanOpenHandle(dwMaxClient, nullptr, &dwCurVersion, &hClient);
    if (dwResult != ERROR_SUCCESS) {
        qDebug() << "WlanOpenHandle failed with error:" << dwResult;
        //return;
    }

    WLAN_INTERFACE_INFO_LIST *pIfList = nullptr;
    dwResult = WlanEnumInterfaces(hClient, nullptr, &pIfList);
    if (dwResult != ERROR_SUCCESS) {
        qDebug() << "WlanEnumInterfaces failed with error:" << dwResult;
        WlanCloseHandle(hClient, nullptr);
        //return;
    }

    if (pIfList->dwNumberOfItems > 0) {
        WLAN_INTERFACE_INFO interfaceInfo = pIfList->InterfaceInfo[0];
        PWLAN_CONNECTION_ATTRIBUTES pConnAttributes = nullptr;
        DWORD connectInfoSize = sizeof(WLAN_CONNECTION_ATTRIBUTES);

        dwResult = WlanQueryInterface(hClient, &interfaceInfo.InterfaceGuid, wlan_intf_opcode_current_connection, nullptr, &connectInfoSize, reinterpret_cast<PVOID*>(&pConnAttributes), nullptr);
        if (dwResult == ERROR_SUCCESS) {
            QString ssid;
            QString ssidName;
            if (pConnAttributes->wlanAssociationAttributes.dot11Ssid.uSSIDLength > 0) {
                for (DWORD i = 0; i < pConnAttributes->wlanAssociationAttributes.dot11Ssid.uSSIDLength; ++i) {
                    ssidName += QChar(pConnAttributes->wlanAssociationAttributes.dot11Ssid.ucSSID[i]);
                }
                ssid = ssidName;
            } else {
                ssid = "Hidden SSID";
            }

            qDebug() << "Connected to SSID:" << ssid;

            WlanFreeMemory(pConnAttributes);
            return ssid;
        } else {
            qDebug() << "WlanQueryInterface failed with error:" << dwResult;
        }
    } else {
        qDebug() << "No wireless interfaces found.";
    }

    if (pIfList != nullptr) {
        WlanFreeMemory(pIfList);
    }

    WlanCloseHandle(hClient, nullptr);

}


TGURdata::~TGURdata()
{

    delete ui;
}

void TGURdata::SaveConfiguration(){


    m_Config->Host = ui->BrokerURI->text();
    m_Config->Port = ui->Port->value();
    m_Config->QOS = ui->QOS->currentText().toInt();
    m_Config->Username=ui->Login->text();
    m_Config->Password=ui->Password->text();
    m_Config->SecurityLevel=ui->SecurityLevel->currentText().toInt();
    m_Config->Topic=ui->Topic->text();
    m_Config->Certif=ui->lineEdit_certif->text();
    SaveConfigurationInINI();




}
void TGURdata::SaveConfigurationwifi(){


    m_Config->Host = ui->BrokerURI->text();
    m_Config->Port = ui->Port->value();
    m_Config->QOS = ui->QOS->currentText().toInt();
    m_Config->Username=ui->Login->text();
    m_Config->Password=ui->Password->text();
    m_Config->SecurityLevel=ui->SecurityLevel->currentText().toInt();
    m_Config->Topic=ui->Topic->text();
    m_Config->Certif=ui->lineEdit_certif->text();
    SaveConfigurationInINIWIFI();
}

void TGURdata::onconnectBtnclicked()
{

    //connect


    if (ui->Login->isEnabled() && ui->Password->isEnabled())
    {

        QString username = ui->Login->text();
        QString password = ui->Password->text();
        if (username == "test" && password == "test")
        {
            qDebug() << " Connexion etablie ";
            if (ui->GSMBtn_2->isChecked()) {
                SaveConfiguration();
                done(0);
            }
            else if(ui->WIFIBtn_2->isChecked()) {
                SaveConfigurationwifi();
                done(1);
            }
        }
        else
        {
            qDebug() << "pas de connexion  ";
        }
    }
    else
    {
        if (ui->GSMBtn_2->isChecked()) {
            SaveConfiguration();
            done(0);
        }
        else if(ui->WIFIBtn_2->isChecked()) {

            SaveConfigurationwifi();
            done(1);
        }
    }
}

void TGURdata::onGSMBtn2clicked()
{    ui->label_10->setVisible(false);
    ui->SerialNumber->setVisible(false);
    if (!m_FilledComboBoxes) {
        ui->QOS->addItem("0");
        ui->QOS->addItem("1");
        ui->QOS->addItem("2");

        ui->SecurityLevel->addItem("0");
        ui->SecurityLevel->addItem("1");
        ui->SecurityLevel->addItem("2");
    }
    m_FilledComboBoxes=true;

    // Enable the line edit
    ui->BrokerURI->setEnabled(true);
    ui->Port->setEnabled(true);
    ui->QOS->setEnabled(true);
    ui->Topic->setEnabled(true);
    ui->Topic->setText("VehicleDiagState/#");
    ui->SecurityLevel->setEnabled(true);
    ReadconfigurationINI();



}

void TGURdata::onWIFIBtn2clicked()
{    ui->label_10->setVisible(true);
    ui->SerialNumber->setVisible(true);
    /*ui->BrokerURI->setText("192.168.2.176");
    ui->Port->setValue(1883);
    ui->Login->setText("test");
    ui->Password->setText("test");
    ui->lineEdit_certif->setText("/");*/

    //done(3);
    if (!m_FilledComboBoxes) {
        ui->QOS->addItem("0");
        ui->QOS->addItem("1");
        ui->QOS->addItem("2");
        ui->SecurityLevel->addItem("0");
        ui->SecurityLevel->addItem("1");
        ui->SecurityLevel->addItem("2");
    }
    m_FilledComboBoxes=true;
    // Enable the line edit

    ui->BrokerURI->setEnabled(true);
    ui->Port->setEnabled(true);
    ui->QOS->setEnabled(true);
    ui->Topic->setEnabled(true);
    ui->Topic->setText("VehicleDigState/#");
    ui->SecurityLevel->setEnabled(true);

    ReadconfigurationINIWIFI();
    QString SSID;
    SSID=GetSSID();
    qDebug() << " we got this wifi name :" << SSID;
    QString SerialNumber ;
    for (const QChar c : SSID){
        if(c.isDigit()){
            SerialNumber.append(c);
        }
    }
    if (SerialNumber != ""){
    ui->SerialNumber->setText(SerialNumber);
    }
    else QMessageBox::information(nullptr,"ERROR","You are not connected to TGU-R WIFI\n Please verify your network connection!");
    /*auto currentWifiName = GetCurrentWifiName();
    qDebug() << " we got this wifi name :" << currentWifiName;
    if (GetCurrentWifiName().compare("")!=0){
        ui->SerialNumber->setText(currentWifiName);
    }*/
}

void TGURdata::SaveConfigurationInINI()
{
    QString localCurrentPath = QDir::currentPath();
    QString Fileini= QString ("%1/%2").arg(localCurrentPath,"Configuration.ini");
    /*saveinivalues(Fileini,"Login_Credentials","Broker_URI",ui->BrokerURI ->text());*/
    saveinivalues(Fileini,"Login_Credentials","Broker_URI",ui->BrokerURI->text());
    saveinivalues(Fileini,"Login_Credentials","topic",ui->Topic ->text());
    saveinivalues(Fileini,"Login_Credentials","login",ui->Login->text());
    saveinivalues(Fileini,"Login_Credentials","password",ui->Password->text());
    saveinivalues(Fileini,"Login_Credentials","QOS",ui->QOS->currentText());
    saveinivalues(Fileini,"Login_Credentials","SecurityLevel",ui->SecurityLevel->currentText());
    saveinivalues(Fileini,"Login_Credentials","Port",ui->Port->text());
}
void TGURdata::SaveConfigurationInINIWIFI()
{
    QString localCurrentPath = QDir::currentPath();
    qDebug()<< "localCurrentPath : "<<  localCurrentPath;
    QString Fileini1= QString ("%1/%2").arg(localCurrentPath,"ConfigurationWIFI.ini");
    saveinivalues(Fileini1,"Login_Credentials","Broker_URI_Wifi",ui->BrokerURI->text());
    saveinivalues(Fileini1,"Login_Credentials","topic",ui->Topic ->text());
    saveinivalues(Fileini1,"Login_Credentials","login",ui->Login->text());
    saveinivalues(Fileini1,"Login_Credentials","password",ui->Password->text());
    saveinivalues(Fileini1,"Login_Credentials","QOS",ui->QOS->currentText());
    saveinivalues(Fileini1,"Login_Credentials","SecurityLevel",ui->SecurityLevel->currentText());
    saveinivalues(Fileini1,"Login_Credentials","Port",ui->Port->text());
}
void TGURdata::ReadconfigurationINI()
{
    QString localCurrentPath = QDir::currentPath();
    QString Fileini= QString ("%1/%2").arg(localCurrentPath,"Configuration.ini");
    ui->BrokerURI->setText(readinivalues(Fileini,"Login_Credentials","Broker_URI"));
    ui->Port->setValue(readinivalues(Fileini,"Login_Credentials","Port").toInt());
    ui->Login->setText(readinivalues(Fileini,"Login_Credentials","login"));
    ui->Password->setText(readinivalues(Fileini,"Login_Credentials","password"));
    ui->QOS->setCurrentText(readinivalues(Fileini,"Login_Credentials","QOS"));
    ui->SecurityLevel->setCurrentText(readinivalues(Fileini,"Login_Credentials","SecurityLevel=1"));
    qDebug() << "BrokerURI" <<ui->BrokerURI->text();
    qDebug() << "login" <<ui->Login->text();
    qDebug() << "Password" <<ui->Password->text();
}
void TGURdata::ReadconfigurationINIWIFI()
{
    QString localCurrentPath = QDir::currentPath();
    QString Fileini1= QString ("%1/%2").arg(localCurrentPath,"ConfigurationWIFI.ini");
    ui->BrokerURI->setText(readinivalues(Fileini1,"Login_Credentials","Broker_URI_Wifi"));
    ui->Port->setValue(readinivalues(Fileini1,"Login_Credentials","Port").toInt());
    ui->Login->setText(readinivalues(Fileini1,"Login_Credentials","login"));
    ui->Password->setText(readinivalues(Fileini1,"Login_Credentials","password"));
    ui->QOS->setCurrentText(readinivalues(Fileini1,"Login_Credentials","QOS"));
    ui->SecurityLevel->setCurrentText(readinivalues(Fileini1,"Login_Credentials","SecurityLevel=1"));
    qDebug() << "BrokerURI" <<ui->BrokerURI->text();
    qDebug() << "login" <<ui->Login->text();
    qDebug() << "Password" <<ui->Password->text();
}
void TGURdata::onComboBoxSECCurrentTextChanged(const QString &text)
{
    //qDebug() << "Nouvelle valeur sélectionnée : " << text;
    if (text == "0")
    {

        ui->Login->setEnabled(false);
        ui->Password->setEnabled(false);
        ui->lineEdit_certif->setEnabled(false);
        if(ui->GSMBtn_2->isChecked()){
        ReadconfigurationINI();
        }
        else if(ui->WIFIBtn_2->isChecked()){
        ReadconfigurationINIWIFI();
        }
    }
    if (text == "1")
    {

        ui->Login->setEnabled(true);
        ui->Password->setEnabled(true);
        ui->lineEdit_certif->setEnabled(false);
        if(ui->GSMBtn_2->isChecked()){
        ReadconfigurationINI();
        }
        else if(ui->WIFIBtn_2->isChecked()){
        ReadconfigurationINIWIFI();
        }



       /* qDebug()<< "login et pass";*/
        /*QString localCurrentPath = QDir::currentPath();
    qDebug()<< localCurrentPath;
    QString Fileini= QString ("%1/%2").arg(localCurrentPath,"Configuration.ini");*/
      /*  ui->Login->setText(readinivalues(Fileini,"Login_Credentials","login"));
        ui->Password->setText(readinivalues(Fileini,"Login_Credentials","password"));*/

    }
    if (text == "2")
    {

        ui->Login->setEnabled(true);
        ui->Password->setEnabled(true);
        ui->lineEdit_certif->setEnabled(true);
        if(ui->GSMBtn_2->isChecked()){
        ReadconfigurationINI();
        }
        if(ui->WIFIBtn_2->isChecked()){
        ReadconfigurationINIWIFI();
        }
        /*QString localCurrentPath = QDir::currentPath();
        QString Fileini= QString ("%1/%2").arg(localCurrentPath,"Configuration.ini");
        ui->Login->setText(readinivalues(Fileini,"Login_Credentials","login"));
        ui->Password->setText(readinivalues(Fileini,"Login_Credentials","password"));*/

    }

}

void TGURdata::reject()
{
    qDebug() << "rejected";
    exit(-1); // memory leak...
}
void TGURdata::saveinivalues(const QString &path,const QString &groupename,const QString &Name,const QString &Value) {

    QSettings settings (path,QSettings::IniFormat);
    settings.beginGroup(groupename);
    settings.setValue(Name,Value);
    settings.endGroup();

}

QString TGURdata::readinivalues(const QString &path,const QString &groupename,const QString &Name) {
    auto Value= QString();
    QSettings settings (path,QSettings::IniFormat);
    settings.beginGroup(groupename);
    Value=settings.value(Name, QString()).toString();
    settings.endGroup();
    return Value;
}
