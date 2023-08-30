/********************************************************************************
** Form generated from reading UI file 'TGURdata.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TGURDATA_H
#define UI_TGURDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TGURdata
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QLabel *label_9;
    QRadioButton *GSMBtn_2;
    QRadioButton *WIFIBtn_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLineEdit *SerialNumber;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *BrokerURI;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpinBox *Port;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QComboBox *QOS;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *Topic;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QComboBox *SecurityLevel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QLineEdit *Login;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QLineEdit *Password;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QLineEdit *lineEdit_certif;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *Connection;

    void setupUi(QDialog *TGURdata)
    {
        if (TGURdata->objectName().isEmpty())
            TGURdata->setObjectName(QString::fromUtf8("TGURdata"));
        TGURdata->resize(670, 555);
        verticalLayout = new QVBoxLayout(TGURdata);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_11 = new QLabel(TGURdata);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(0, 0));
        label_11->setMaximumSize(QSize(100, 100));
        label_11->setFrameShape(QFrame::NoFrame);
        label_11->setFrameShadow(QFrame::Plain);
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icons8-choose-48.png")));
        label_11->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_11->setMargin(5);
        label_11->setIndent(0);

        horizontalLayout->addWidget(label_11);

        label_9 = new QLabel(TGURdata);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_9->setFont(font);

        horizontalLayout->addWidget(label_9);

        GSMBtn_2 = new QRadioButton(TGURdata);
        GSMBtn_2->setObjectName(QString::fromUtf8("GSMBtn_2"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        GSMBtn_2->setFont(font1);

        horizontalLayout->addWidget(GSMBtn_2);

        WIFIBtn_2 = new QRadioButton(TGURdata);
        WIFIBtn_2->setObjectName(QString::fromUtf8("WIFIBtn_2"));
        WIFIBtn_2->setMinimumSize(QSize(0, 30));
        WIFIBtn_2->setFont(font1);

        horizontalLayout->addWidget(WIFIBtn_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_10 = new QLabel(TGURdata);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(105, 0));
        QFont font2;
        font2.setPointSize(10);
        label_10->setFont(font2);
        label_10->setFrameShape(QFrame::Panel);
        label_10->setFrameShadow(QFrame::Sunken);
        label_10->setLineWidth(0);

        horizontalLayout_2->addWidget(label_10);

        SerialNumber = new QLineEdit(TGURdata);
        SerialNumber->setObjectName(QString::fromUtf8("SerialNumber"));

        horizontalLayout_2->addWidget(SerialNumber);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(TGURdata);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(105, 0));
        label->setFont(font2);

        horizontalLayout_4->addWidget(label);

        BrokerURI = new QLineEdit(TGURdata);
        BrokerURI->setObjectName(QString::fromUtf8("BrokerURI"));

        horizontalLayout_4->addWidget(BrokerURI);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(TGURdata);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(105, 0));
        label_2->setFont(font2);

        horizontalLayout_5->addWidget(label_2);

        Port = new QSpinBox(TGURdata);
        Port->setObjectName(QString::fromUtf8("Port"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Port->sizePolicy().hasHeightForWidth());
        Port->setSizePolicy(sizePolicy2);
        Port->setMaximum(9999);

        horizontalLayout_5->addWidget(Port);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(TGURdata);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(105, 0));
        label_3->setFont(font2);

        horizontalLayout_6->addWidget(label_3);

        QOS = new QComboBox(TGURdata);
        QOS->setObjectName(QString::fromUtf8("QOS"));
        sizePolicy2.setHeightForWidth(QOS->sizePolicy().hasHeightForWidth());
        QOS->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(QOS);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_4 = new QLabel(TGURdata);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setMinimumSize(QSize(105, 0));
        label_4->setFont(font2);

        horizontalLayout_7->addWidget(label_4);

        Topic = new QLineEdit(TGURdata);
        Topic->setObjectName(QString::fromUtf8("Topic"));
        Topic->setMinimumSize(QSize(100, 0));

        horizontalLayout_7->addWidget(Topic);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(TGURdata);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setMinimumSize(QSize(105, 0));
        label_5->setFont(font2);

        horizontalLayout_8->addWidget(label_5);

        SecurityLevel = new QComboBox(TGURdata);
        SecurityLevel->setObjectName(QString::fromUtf8("SecurityLevel"));
        sizePolicy2.setHeightForWidth(SecurityLevel->sizePolicy().hasHeightForWidth());
        SecurityLevel->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(SecurityLevel);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_6 = new QLabel(TGURdata);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(105, 0));
        label_6->setFont(font2);

        horizontalLayout_9->addWidget(label_6);

        Login = new QLineEdit(TGURdata);
        Login->setObjectName(QString::fromUtf8("Login"));

        horizontalLayout_9->addWidget(Login);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_7 = new QLabel(TGURdata);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(105, 0));
        label_7->setFont(font2);

        horizontalLayout_10->addWidget(label_7);

        Password = new QLineEdit(TGURdata);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_10->addWidget(Password);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_8 = new QLabel(TGURdata);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(105, 0));
        label_8->setFont(font2);

        horizontalLayout_11->addWidget(label_8);

        lineEdit_certif = new QLineEdit(TGURdata);
        lineEdit_certif->setObjectName(QString::fromUtf8("lineEdit_certif"));

        horizontalLayout_11->addWidget(lineEdit_certif);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        Connection = new QPushButton(TGURdata);
        Connection->setObjectName(QString::fromUtf8("Connection"));
        Connection->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Connection->sizePolicy().hasHeightForWidth());
        Connection->setSizePolicy(sizePolicy4);
        Connection->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(Connection);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(TGURdata);

        QMetaObject::connectSlotsByName(TGURdata);
    } // setupUi

    void retranslateUi(QDialog *TGURdata)
    {
        TGURdata->setWindowTitle(QCoreApplication::translate("TGURdata", "Dialog", nullptr));
        label_11->setText(QString());
        label_9->setText(QCoreApplication::translate("TGURdata", "Mode :", nullptr));
        GSMBtn_2->setText(QCoreApplication::translate("TGURdata", "GSM", nullptr));
        WIFIBtn_2->setText(QCoreApplication::translate("TGURdata", "WIFI", nullptr));
        label_10->setText(QCoreApplication::translate("TGURdata", "Serial Number", nullptr));
        label->setText(QCoreApplication::translate("TGURdata", "BROKER URI", nullptr));
        label_2->setText(QCoreApplication::translate("TGURdata", "Port", nullptr));
        label_3->setText(QCoreApplication::translate("TGURdata", "QOS", nullptr));
        label_4->setText(QCoreApplication::translate("TGURdata", "Topic", nullptr));
        label_5->setText(QCoreApplication::translate("TGURdata", "Security LvL", nullptr));
        label_6->setText(QCoreApplication::translate("TGURdata", "Login", nullptr));
        label_7->setText(QCoreApplication::translate("TGURdata", "Password", nullptr));
        Password->setText(QString());
        label_8->setText(QCoreApplication::translate("TGURdata", "Certificate path", nullptr));
        Connection->setText(QCoreApplication::translate("TGURdata", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TGURdata: public Ui_TGURdata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TGURDATA_H
