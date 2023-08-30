#include "MainWindow.h"
#include "DialogT.h"
#include "DialogTest.h"
#include "ui_MainWindow.h"
#include "VAR.h"
#include <QDebug>
/*#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>*/
#include <QtMqtt/QMqttClient>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DialogT *Dialog = new DialogT();
    int rc = Dialog->exec();

    switch (rc)
    {
    case 0:
        m_GSMMode = true;
        qDebug() << "Wifi Mode is set to false";
        break;
    case 1:
        m_WifiMode = true;
        qDebug() << "Wifi Mode is set to true";
        break;
    default:
        break; // wont work..


    }
    // Delete this later

    m_Model = new QStandardItemModel(5,2);
    m_Model->setHorizontalHeaderLabels({"TGU-R ID", "Time Stamp"});
    for (int i=0 ; i<5 ; i++){
        QString headerText = "TGU-R" + QString::number(i);
        m_Model->setVerticalHeaderItem(i, new QStandardItem(headerText));}
    //m_Model->setVerticalHeaderItem(0, new QStandardItem("hi"));

       for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 2; column++) {
            QString value = "Valeur";  // Exemple de valeur à ajouter dans la cellule
            QModelIndex index = m_Model->index(row, column);
            m_Model->setData(index, value);
        }}






    ui->tableView->setModel(m_Model);
    QTableView* tableView = findChild<QTableView*>("tableView");


    if (tableView) {

        QHeaderView* verticalHeader = tableView->verticalHeader();
        connect(verticalHeader, &QHeaderView::sectionClicked,this, [=](int logicalIndex) {
            // Handling the event when a vertical header item is clicked
            VAR::variable= logicalIndex;
                DialogTest tgur ;
                tgur.setModal(true);
                tgur.exec();

                qDebug() << "Variable : " << VAR::variable;

                qDebug() << "Vertical header item clicked. Logical index: " << logicalIndex;
        });


    // connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::onPushButton3Clicked);
    } }

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pushButton_clicked()
{

}*/

/*void MainWindow::onPushButton3Clicked()
{
    qDebug() << "clicked ";

}*/
