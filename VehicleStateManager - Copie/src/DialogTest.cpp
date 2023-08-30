#include "DialogTest.h"
#include "ui_DialogTest.h"
#include "VAR.h"
#include "QDebug"
DialogTest::DialogTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTest)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &DialogTest::Enddiagclicked);
    Model = new QStandardItemModel(6,1);

    for (int i=0 ; i<Model->columnCount() ; i++){

    QString headerText = "TGU-R" + QString::number(VAR::variable); //le probleme iciiiiiiii
    qDebug() << "headerText:" << headerText ;

    Model->setHorizontalHeaderItem(i, new QStandardItem(headerText));
    }

    Model->setVerticalHeaderLabels({"TGU-R ID", "IMEI","Signal Strength","Status","Diag Status","VIN"});

    for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 2; column++) {
            QString value = "Valeur";  // Exemple de valeur à ajouter dans la cellule
            QModelIndex index = Model->index(row, column);
            Model->setData(index, value);
        }}






    ui->tableView->setModel(Model);

}

DialogTest::~DialogTest()
{
    delete ui;
}

void DialogTest::Enddiagclicked()
{
    this->close();
}

