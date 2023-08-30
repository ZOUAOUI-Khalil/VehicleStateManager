/********************************************************************************
** Form generated from reading UI file 'DialogT.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGT_H
#define UI_DIALOGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogT
{
public:
    QGroupBox *groupBox;
    QPushButton *Connection;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QComboBox *comboBoxQOS;
    QLineEdit *lineEdit_5;
    QComboBox *comboBoxSEC;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_pass;
    QLineEdit *lineEdit_certif;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QRadioButton *GSMBtn_2;
    QRadioButton *WIFIBtn_2;

    void setupUi(QDialog *DialogT)
    {
        if (DialogT->objectName().isEmpty())
            DialogT->setObjectName(QString::fromUtf8("DialogT"));
        DialogT->resize(862, 574);
        groupBox = new QGroupBox(DialogT);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 90, 551, 351));
        Connection = new QPushButton(groupBox);
        Connection->setObjectName(QString::fromUtf8("Connection"));
        Connection->setEnabled(true);
        Connection->setGeometry(QRect(320, 310, 75, 24));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Connection->sizePolicy().hasHeightForWidth());
        Connection->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 40, 83, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(211, 41, 135, 220));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(layoutWidget1);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        comboBoxQOS = new QComboBox(layoutWidget1);
        comboBoxQOS->setObjectName(QString::fromUtf8("comboBoxQOS"));

        verticalLayout_2->addWidget(comboBoxQOS);

        lineEdit_5 = new QLineEdit(layoutWidget1);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout_2->addWidget(lineEdit_5);

        comboBoxSEC = new QComboBox(layoutWidget1);
        comboBoxSEC->setObjectName(QString::fromUtf8("comboBoxSEC"));

        verticalLayout_2->addWidget(comboBoxSEC);

        lineEdit_login = new QLineEdit(layoutWidget1);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        verticalLayout_2->addWidget(lineEdit_login);

        lineEdit_pass = new QLineEdit(layoutWidget1);
        lineEdit_pass->setObjectName(QString::fromUtf8("lineEdit_pass"));
        lineEdit_pass->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(lineEdit_pass);

        lineEdit_certif = new QLineEdit(layoutWidget1);
        lineEdit_certif->setObjectName(QString::fromUtf8("lineEdit_certif"));

        verticalLayout_2->addWidget(lineEdit_certif);

        layoutWidget2 = new QWidget(DialogT);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 50, 281, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        GSMBtn_2 = new QRadioButton(layoutWidget2);
        GSMBtn_2->setObjectName(QString::fromUtf8("GSMBtn_2"));

        horizontalLayout->addWidget(GSMBtn_2);

        WIFIBtn_2 = new QRadioButton(layoutWidget2);
        WIFIBtn_2->setObjectName(QString::fromUtf8("WIFIBtn_2"));

        horizontalLayout->addWidget(WIFIBtn_2);


        retranslateUi(DialogT);

        QMetaObject::connectSlotsByName(DialogT);
    } // setupUi

    void retranslateUi(QDialog *DialogT)
    {
        DialogT->setWindowTitle(QCoreApplication::translate("DialogT", "Dialog", nullptr));
        groupBox->setTitle(QString());
        Connection->setText(QCoreApplication::translate("DialogT", "Connect", nullptr));
        label->setText(QCoreApplication::translate("DialogT", "BROKER URI", nullptr));
        label_2->setText(QCoreApplication::translate("DialogT", "Port", nullptr));
        label_3->setText(QCoreApplication::translate("DialogT", "QOS", nullptr));
        label_4->setText(QCoreApplication::translate("DialogT", "Topic", nullptr));
        label_5->setText(QCoreApplication::translate("DialogT", "Security LvL", nullptr));
        label_6->setText(QCoreApplication::translate("DialogT", "Login", nullptr));
        label_7->setText(QCoreApplication::translate("DialogT", "Password", nullptr));
        label_8->setText(QCoreApplication::translate("DialogT", "Certificate path", nullptr));
        lineEdit_pass->setText(QString());
        label_9->setText(QCoreApplication::translate("DialogT", "Mode :", nullptr));
        GSMBtn_2->setText(QCoreApplication::translate("DialogT", "GSM", nullptr));
        WIFIBtn_2->setText(QCoreApplication::translate("DialogT", "WIFI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogT: public Ui_DialogT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGT_H
