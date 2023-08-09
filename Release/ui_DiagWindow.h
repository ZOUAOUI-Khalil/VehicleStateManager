/********************************************************************************
** Form generated from reading UI file 'DiagWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGWINDOW_H
#define UI_DIAGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DiagWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *DiagWindow)
    {
        if (DiagWindow->objectName().isEmpty())
            DiagWindow->setObjectName(QString::fromUtf8("DiagWindow"));
        DiagWindow->resize(400, 300);
        DiagWindow->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(DiagWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(DiagWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        pushButton = new QPushButton(DiagWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(DiagWindow);

        QMetaObject::connectSlotsByName(DiagWindow);
    } // setupUi

    void retranslateUi(QDialog *DiagWindow)
    {
        DiagWindow->setWindowTitle(QCoreApplication::translate("DiagWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("DiagWindow", "End diag", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DiagWindow: public Ui_DiagWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGWINDOW_H
