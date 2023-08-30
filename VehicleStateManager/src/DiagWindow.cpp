#include "DiagWindow.h"
#include "ui_DiagWindow.h"
#include "MainWindow.h"
#include "VAR.h"
#include "QDebug"
#include<QString>
#include <QDateTime>

void DiagWindow::updateValues()
{

    for(int row=0 ; row<8; row++){
        int column = 0;
        QModelIndex index = Model->index(row, column);
        QString val;
        QDateTime DateTime;
        switch(row){
        case (0) :

            //int value = Msg.SerialNumber;
            index = Model->index(row, column);
            val = QString::number(Message.SerialNumber);

            Model->setData(index, val );
            break;
        case (1):
            index = Model->index(row, column);

            DateTime.setSecsSinceEpoch(Message.timestamp );
            //QString val1 = DateTime.toString();
            Model->setData(index, DateTime.toString());
            break;
        case(2):
            index = Model->index(row, column);
            Model->setData(index,QString::number(Message.TransmissionPeriod));
            break;

        case (3) :
            index = Model->index(row, column);

            val = QString::number(Message.IMEI);

            Model->setData(index, val );
            break;

        case (4):
            index = Model->index(row, column);

            Model->setData(index, QString::number(Message.SignalStrength));
            break;
        case (5):
            index = Model->index(row, column);

            Model->setData(index, Message.NetworkStatus);
            break;
        case (6):
            index = Model->index(row, column);

            Model->setData(index, QString::number(Message.DiagnosticStatus));
            break;
        case (7):
            index = Model->index(row, column);

            Model->setData(index, Message.VIN);
            break;


        }

    }
}

DiagWindow::DiagWindow(QWidget *parent, int SerialNumber, QMap<long, TGURMsg> *CurrentData,QMqttClient* i_PtrClient):
    m_CurrentData(CurrentData),
    m_Client(i_PtrClient),
    m_SerialNumber(SerialNumber),
    QDialog(parent),
    //Msg(i_ptrMsg),
    ui(new Ui::DiagWindow)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint); //poue éliminer le point d'interrogation
    setWindowTitle("TGU-R data");
    QIcon icon("D:\\Projetstage\\VehicleStateManager\\media\\info.png"); // Use a valid path or resource URL
    // Set the window icon
    setWindowIcon(icon);

    connect(ui->pushButton, &QPushButton::clicked, this, &DiagWindow::Enddiagclicked);

    connect(this, &DiagWindow::destroyed, this, &DiagWindow::CroixRouge);
    QString ser= QString::number(SerialNumber);
    QString Msg= "{ \"SerialNumber\":"+ ser +",\"StartDiagflag\":true}";
    QMqttTopicName topicName= "VehicleDiagState/"+ser+"/StartDiag";
    m_Client->publish(topicName,Msg.toUtf8(),1,false);



    Model = new QStandardItemModel(8,1);

    for (int i=0 ; i<Model->columnCount() ; i++){

        QString headerText = "TGU-R" + QString::number(SerialNumber);
        qDebug() << "headerText:" << headerText ;

        Model->setHorizontalHeaderItem(i, new QStandardItem(headerText));
    }

    Model->setVerticalHeaderLabels({"TGU-R ID","TimeStamp","Transmission Period", "IMEI","Signal Strength","Status","Diag Status","VIN"});
    Updatecurrentdata(SerialNumber);

     Message = m_CurrentData->value(SerialNumber);
    updateValues();
    //qDebug() << Message.timestamp;



    ui->tableView->setModel(Model);

}



DiagWindow::~DiagWindow()
{
    delete ui;
}

void DiagWindow::Enddiagclicked()
{QString ser= QString::number(m_SerialNumber);
    QMqttTopicName topicName= "VehicleDiagState/"+ser+"/StartDiag";
    QString Msg= "{ \"SerialNumber\":"+ ser +",\"StartDiagflag\":false}";
    m_Client->publish(topicName,Msg.toUtf8(),1,false);
    this->close();
}
void DiagWindow::Updatecurrentdata(int serialnumber){
    qDebug() << "hello data got updates ";
    Message = m_CurrentData->value(serialnumber);
    if ( Message.SerialNumber == m_SerialNumber)
    updateValues();
}
void DiagWindow::CroixRouge()  {
    Enddiagclicked() ;
    qDebug()<<"ENDDIAG";
}
