#include "DialogT.h"
#include "ui_DialogT.h"
#include "MainWindow.h"
#include "VAR.h"
#include <QDebug>

DialogT::DialogT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogT)
{
    ui->setupUi(this);
    connect(ui->Connection, &QPushButton::clicked, this, &DialogT::onconnectBtnclicked); //Connect
    /*connect(ui->WIFIBtn,&QPushButton::clicked,this,&DialogT::onWIFIBtnclicked); //WIFI*/
    connect(ui->GSMBtn_2, &QRadioButton::clicked, this, &DialogT::onGSMBtn2clicked);   // GSM
    connect(ui->WIFIBtn_2, &QRadioButton::clicked, this, &DialogT::onWIFIBtn2clicked); // WIFI
    connect(ui->comboBoxSEC, &QComboBox::currentTextChanged, this, &DialogT::on_comboBoxSEC_currentTextChanged);

    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->comboBoxQOS->setEnabled(false);
    ui->lineEdit_5->setEnabled(false);
    ui->comboBoxSEC->setEnabled(false);
    ui->lineEdit_login->setEnabled(false);
    ui->lineEdit_pass->setEnabled(false);
    ui->lineEdit_certif->setEnabled(false);
}

DialogT::~DialogT()
{
    delete ui;
}

void DialogT::onconnectBtnclicked()
{

    if (ui->lineEdit_login->isEnabled() && ui->lineEdit_pass->isEnabled())
    {
        QString username = ui->lineEdit_login->text();
        QString password = ui->lineEdit_pass->text();
        if (username == "test" && password == "test")
        {
            qDebug() << " Connexion etablie ";
            if (ui->GSMBtn_2->isChecked()) {

            done(0);
            }
            else if(ui->WIFIBtn_2->isChecked()) {
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
            done(0);
        }
        else if(ui->WIFIBtn_2->isChecked()) {
            done(1);
        }
    }
}

int C=0;

void DialogT::onGSMBtn2clicked()
{
    /* qDebug() << " GSM clicked ";
      done(2);*/


    if (C == 0) {
    ui->comboBoxQOS->addItem("0");
    ui->comboBoxQOS->addItem("1");
    ui->comboBoxQOS->addItem("2");

    ui->comboBoxSEC->addItem("0");
    ui->comboBoxSEC->addItem("1");
    ui->comboBoxSEC->addItem("2"); }
    C++;

    // Disable the line edit
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->comboBoxQOS->setEnabled(true);
    ui->lineEdit_5->setEnabled(true);
    ui->lineEdit_5->setText("VehicleDigState/#");
    ui->comboBoxSEC->setEnabled(true);
}

void DialogT::onWIFIBtn2clicked()
{
     //done(3);
    if (C == 0) {
    ui->comboBoxQOS->addItem("0");
    ui->comboBoxQOS->addItem("1");
    ui->comboBoxQOS->addItem("2");

    ui->comboBoxSEC->addItem("0");
    ui->comboBoxSEC->addItem("1");
    ui->comboBoxSEC->addItem("2"); }
    C++;
    // Disable the line edit
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->comboBoxQOS->setEnabled(true);
    ui->lineEdit_5->setEnabled(true);
    ui->lineEdit_5->setText("VehicleDigState/#");
    ui->comboBoxSEC->setEnabled(true);
    /* qDebug() << " WIFI clicked ";
      done(1);*/
    /* ui->lineEdit_2->setEnabled(true);
     ui->lineEdit_3->setEnabled(true);
     ui->lineEdit_4->setEnabled(true);
     ui->lineEdit_5->setEnabled(true);
     ui->lineEdit_6->setEnabled(true);
     ui->lineEdit_login->setEnabled(true);
     ui->lineEdit_pass->setEnabled(true);
     ui->lineEdit_certif->setEnabled(true);*/
}

void DialogT::on_comboBoxSEC_currentTextChanged(const QString &text)
{
    //qDebug() << "Nouvelle valeur sélectionnée : " << text;
    if (text == "0")
    {

        ui->lineEdit_login->setEnabled(false);
        ui->lineEdit_pass->setEnabled(false);
        ui->lineEdit_certif->setEnabled(false);
    }
    if (text == "1")
    {

        ui->lineEdit_login->setEnabled(true);
        ui->lineEdit_pass->setEnabled(true);
        ui->lineEdit_certif->setEnabled(false);
    }
    if (text == "2")
    {

        ui->lineEdit_login->setEnabled(true);
        ui->lineEdit_pass->setEnabled(true);
        ui->lineEdit_certif->setEnabled(true);
    }
}
