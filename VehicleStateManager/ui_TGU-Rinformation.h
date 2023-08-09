/********************************************************************************
** Form generated from reading UI file 'TGU-Rinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TGU_2D_RINFORMATION_H
#define UI_TGU_2D_RINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogTest
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogTest)
    {
        if (DialogTest->objectName().isEmpty())
            DialogTest->setObjectName(QString::fromUtf8("DialogTest"));
        DialogTest->resize(400, 300);
        DialogTest->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(DialogTest);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(DialogTest);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        pushButton = new QPushButton(DialogTest);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(DialogTest);

        QMetaObject::connectSlotsByName(DialogTest);
    } // setupUi

    void retranslateUi(QDialog *DialogTest)
    {
        DialogTest->setWindowTitle(QCoreApplication::translate("DialogTest", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogTest", "End diag", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogTest: public Ui_DialogTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TGU_2D_RINFORMATION_H
