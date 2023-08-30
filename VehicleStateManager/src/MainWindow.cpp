#include "MainWindow.h"
#include "TGURdata.h"
#include "DiagWindow.h"
#include "ui_MainWindow.h"
#include "VAR.h"
#include <QDebug>
#include<QSettings>
#include<QString>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtMqtt/QMqttClient>
#include <QMessageBox>
#include <QTimer>
#include <QTcpSocket>


int MainWindow::StartConfigurationDialog()
{
    TGURdata *Dialog = new TGURdata(nullptr,m_Client,&m_Configuration);
//
    QPalette CurrentDialogPalette = Dialog->palette();

    CurrentDialogPalette.setColor(QPalette::Window, QColor("#f6f6ee")); // Couleur de fond
    CurrentDialogPalette.setColor(QPalette::WindowText, QColor("#264d00")); // Couleur du texte #336600
    //CurrentDialogPalette.setColor(QPalette::Button, QColor("#ffffff")); // Couleur des boutons
    //CurrentDialogPalette.setColor(QPalette::Button, QColor("#ffffff")); // Couleur des boutons
    // ... définissez d'autres couleurs selon vos besoins

    QBrush CurrentDialogbrush =CurrentDialogPalette.brush(QPalette::Window);
    //CurrentDialogbrush.setColor(QColor("#cccc99"));
    //CurrentDialogbrush.setStyle(Qt::SolidPattern);

    // Appliquer la brosse modifiée à la palette du dialogue
    //CurrentDialogPalette.setBrush(QPalette::Window, CurrentDialogbrush);
    //Dialog->setPalette(CurrentDialogPalette);
    //Dialog->setStyleSheet("QPushButton { background-color: Green }");
    Dialog->setStyleSheet("color: #264d00;"
                            "background-color: #f6f6ee;"
                            "selection-color: #264d00;"
                            "selection-background-color: #9fdf9f;");
    //
    int rc = Dialog->exec();
    setWindowTitle("TGU-R");
    Dialog->update();
    Dialog->deleteLater();
    QIcon icon("D:\\Projetstage\\VehicleStateManager\\media\\info.png"); // Use a valid path or resource URL
    // Set the window icon
    setWindowIcon(icon);


    return rc;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int rc = StartConfigurationDialog();


    m_Client = new QMqttClient(this);
    connect(m_Client,&QMqttClient::connected,this,&MainWindow::OnClientConnected);
    connect(m_Client,&QMqttClient::disconnected,this,&MainWindow::OnClientDisconnected);


    //QSslCertificate Cert()

    //QSslConfiguration Configuration;
    //Configuration.addCaCertificate();
    //m_Client->connectToHostEncrypted(sslConfig);
    m_Client->setHostname(m_Configuration.Host); //test.mqtt.d2hub.fr
    qDebug() << "Hostname" << m_Client->hostname();
    m_Client->setPort(m_Configuration.Port); //1883
    qDebug() << "Port" << m_Client->port();

    switch(m_Configuration.SecurityLevel) {
    case 0:
        qDebug()<<"pas de parametres";
        break;

    case 1:
        m_Client->setUsername(m_Configuration.Username);
        qDebug() << "Username" << m_Client->username();
        m_Client->setPassword(m_Configuration.Password);
        qDebug() << "Password" << m_Client->password();
        break;
    case 2:
        m_Client->setUsername(m_Configuration.Username);
        qDebug() << "Username" << m_Client->username();
        m_Client->setPassword(m_Configuration.Password);
        qDebug() << "Password" << m_Client->password();
        break;
    }
 /*QString localCurrentPath = QDir::currentPath();
    QString Fileini= QString ("%1/%2").arg(localCurrentPath,"Configuration.ini");
    saveinivalues(Fileini,"Login_Credentials","login",ui->lineEditUser->text());
    saveinivalues(Fileini,"Login_Credentials","password",ui->lineEditPassword->text());*/

    switch (rc)
    {
    case (0) :
        m_GSMMode = true;
        qDebug() << "Wifi Mode is set to false";
        break;
    case (1) :
        m_WifiMode = true;
        qDebug() << "Wifi Mode is set to true";
        //m_socket = new QTcpSocket (this);
        //QTcpSocket *socket = new QTcpSocket(this);
        port = 8080;
        IP = "192.168.2.1";
        socket->connectToHost(IP,port);
        connect(socket,&QTcpSocket::connected ,this,&MainWindow::TCPConnected); // signal émis lors de la connexion au serveur
        //connect(socket,&QTcpSocket::readyRead , this,&MainWindow::TCPMsg);
        break;
    default:
        break; // wont work..
    }


    m_Client->connectToHost();

    m_Model = new QStandardItemModel();
    m_Model->setHorizontalHeaderLabels({"TGU-R ID", "Time Stamp","Transmission Period"});

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows); //selectionner toute la ligne
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch); // tableView ajustable
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers); //impossible de modifier les valeurs

    connect(ui->tableView,&QTableView::doubleClicked,this,&MainWindow::OnItemSelected);

    m_Model->setColumnCount(3);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setModel(m_Model);


    connect(m_timer,&QTimer::timeout , this, &MainWindow::refresh);
    m_timer->start(45000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnItemSelected(QModelIndex index)
{

    TGURMsg Msg;
    Selectedrow= index.row();
    QStandardItem* item = m_Model->item (Selectedrow,0) ;
    long SerialNumber  = item->text().toLong(); // check again .
    DiagWindow tgur(nullptr,SerialNumber,&m_Currentdata,m_Client) ;
    tgur.setModal(true);
    connect(this, &MainWindow::currentdatachanged, &tgur ,&DiagWindow::Updatecurrentdata);
    tgur.exec();


}

void MainWindow::OnClientConnected()
{
    //QMessageBox::information(nullptr,"Vehicle State Manager","client connected!");
    qDebug()<< "m_client state : " <<m_Client->state();
    QMqttSubscription* Subscription = m_Client->subscribe(m_Configuration.Topic,m_Configuration.QOS);
    if (Subscription){
        qDebug()<< "m_client state : " <<m_Client->state();
        connect(Subscription,&QMqttSubscription::messageReceived,this,&MainWindow::onMessageReceived);
        qDebug() << "Client subscribed";


    }else{
        qDebug() << "Nullptr subscription";
    }

}
void MainWindow::OnClientDisconnected()
{
    QMessageBox::information(nullptr,"Vehicle State Manager","client disconnected!");
    qDebug()<< "m_client state : " <<m_Client->state();
}

void MainWindow::ERREUR(QJsonParseError Error)
{
    switch (Error.error) {
    case(0):
        // QMessageBox::information(nullptr,"ERROR","No error occurred");
        break;;
    case(1):
        QMessageBox::information(nullptr,"ERROR","An object is not correctly terminated with a closing curly bracket");
        break;
    case(2):
        QMessageBox::information(nullptr,"ERROR","A comma separating different items is missing");
        break;
    case(3):
        QMessageBox::information(nullptr,"ERROR","The array is not correctly terminated with a closing square bracket");
        break;
    case(4):
        QMessageBox::information(nullptr,"ERROR","A colon separating keys from values inside objects is missing");
        break;
    case(5):
        QMessageBox::information(nullptr,"ERROR","The value is illegal");
        break;
    case(6):
        QMessageBox::information(nullptr,"ERROR","The input stream ended while parsing a number");
        break;



    }
}


TGURMsg MainWindow::buildTGURmsg(QMqttMessage msg)
{
    TGURMsg Msg;
    qDebug() << msg.payload();
    QJsonParseError Error;
    QJsonDocument Json = QJsonDocument::fromJson(msg.payload(),&Error);
    ERREUR(Error);
    qDebug()<< "pas d'erreur";

    QJsonObject jsonObj;
    jsonObj = Json.object();

    QJsonValue localValue,localValue1,localValue2,localValue3,localValue4,localValue5,localValue6,localValue7,localValue8,localval;

    localValue= jsonObj["timestamp"];
    qWarning()<<localValue;
    int timestamp = localValue.toInt();
    Msg.timestamp=timestamp;
    qDebug() << "timestamp"<< Msg.timestamp;
    /*QDateTime DateTime1;
    DateTime1.setSecsSinceEpoch(timestamp);
    qDebug()<< DateTime1.toString();*/


    localValue1= jsonObj["TransmissionPeriod"];
    qWarning()<<localValue1;
    int TransmissionPeriod = localValue1.toInt();
    Msg.TransmissionPeriod=TransmissionPeriod;
    qDebug() << "TransmissionPeriod" << Msg.TransmissionPeriod;


    localval=jsonObj["ID"].toObject();
    localValue2=localval["Serial Number"];
    qWarning()<<localValue2;
    QString SerialNumber = localValue2.toString();
    qDebug() <<"SerialNumber"<< SerialNumber;
    Msg.SerialNumber=SerialNumber.toInt();
    qDebug() <<"SerialNumber"<< Msg.SerialNumber;



    localValue3= localval["IMEI"];
    qWarning()<<localValue3;
    QString IMEI = localValue3.toString();
    Msg.IMEI= IMEI.toLongLong();
    qDebug() <<"IMEI"<< Msg.IMEI;



    localval=jsonObj["Board Status"].toObject();
    localValue4= localval["NetworkStatus"];
    qWarning()<<localValue4;
    QString NetworkStatus = localValue4.toString();
    Msg.NetworkStatus= NetworkStatus;
    qDebug() <<"NetworkStatus"<< Msg.NetworkStatus;

    localValue5= localval["SignalStrength"];
    qWarning()<<localValue5;
    QString SignalStrength = localValue5.toString();
    Msg.SignalStrength=SignalStrength.toInt();
    qDebug() <<"SignalStrength"<<Msg.SignalStrength;

    localValue6= localval["DiagnosticStatus"];
    qWarning()<<localValue6;
    QString DiagnosticStatus = localValue6.toString();
    Msg.DiagnosticStatus=DiagnosticStatus.toInt();
    qDebug() <<"DiagnosticStatus"<< Msg.DiagnosticStatus;

    localval=jsonObj["Vehicle Status"].toObject();
    localValue7= localval["APC"];
    qWarning()<<localValue7;
    QString APC = localValue7.toString();
    Msg.APC= APC.toInt();
    qDebug() <<"APC"<< Msg.APC;

    localValue8= localval["VIN"];
    qWarning()<<localValue8;
    QString VIN = localValue8.toString();
    Msg.VIN=VIN;
    qDebug() << "VIN"<< Msg.VIN;
    return Msg;
}

void MainWindow::onMessageReceived(QMqttMessage msg)
{
    qDebug()<<"onMessageReceived";

    TGURMsg Msg = buildTGURmsg(msg);
    if (Msg.timestamp!=0){
    UpdateModel(Msg);
    }else{
    qDebug() << "Invalid message, not updating model.";
    }

    }

void MainWindow::UpdateModel(TGURMsg Msg){

    //

    TGURMsg CurrentMsg= m_Currentdata.value(Msg.SerialNumber);
    if (CurrentMsg.SerialNumber == 0 ){
        qDebug() << "Serial number doesn't exist : " << CurrentMsg.SerialNumber;
        qDebug() <<" Adding Current Msg to list" ;
        Msg.RowInWindow=m_Row++;
        InsertNewValueInTable(Msg);
    }else{
        qDebug() << "Serial Number exists :" << CurrentMsg.SerialNumber;
        qDebug() << "not adding to list, updating value.";
        Msg.RowInWindow = CurrentMsg.RowInWindow;
        UpdateTable(Msg);
    }
    m_Currentdata[Msg.SerialNumber]= Msg ;
    emit currentdatachanged(Msg.SerialNumber);
}
void MainWindow:: InsertNewValueInTable(TGURMsg Msg){

    int column=0;
    m_Model->setRowCount(Msg.RowInWindow+1);

    long value = Msg.SerialNumber ;  // Exemple de valeur à ajouter dans la cellule
    QString val = QString::number(value);
    //int CurrentRowCount = m_Model->rowCount();
    QModelIndex index = m_Model->index(Msg.RowInWindow,column++);

    m_Model->setData(index, val);
    long value1 = Msg.timestamp ;  // Exemple de valeur à ajouter dans la cellule
    QDateTime DateTime1;
    DateTime1.setSecsSinceEpoch(Msg.timestamp);
    //QString val1 = QString::number(value1);
    QString val1 = DateTime1.toString();
    index = m_Model->index(Msg.RowInWindow, column++);
    m_Model->setData(index,val1);
    long value2 = Msg.TransmissionPeriod;
    QString Transperiod = QString::number(value2);
    index= m_Model->index(Msg.RowInWindow,column);
    m_Model->setData(index,Transperiod);

}

void MainWindow:: UpdateTable(TGURMsg Msg) {
    int column=1;
    long value1 = Msg.timestamp ;
    QDateTime DateTime1;
    DateTime1.setSecsSinceEpoch(Msg.timestamp);
    QString val1 = DateTime1.toString();// Exemple de valeur à ajouter dans la cellule
    //qDebug()<< "Rowinwindow" << Msg.RowInWindow;
    QModelIndex index = m_Model->index(Msg.RowInWindow, column++);
    m_Model->setData(index,val1);
    index = m_Model->index(Msg.RowInWindow, column);
    m_Model->setData(index,QString::number(Msg.TransmissionPeriod));



}
void MainWindow::refresh()
{
    m_Model->clear();
    m_Model->setHorizontalHeaderLabels({"TGU-R ID", "Time Stamp","Transmission Period"});
    m_Currentdata.clear();
    m_Row=0;

}
void MainWindow::on_Refreshbutton_clicked()
{
   refresh();
}
void MainWindow::TCPConnected () {
   qDebug() << "connexion established with TCP";
   QString ser = "515543377";
   switch (socket->ConnectedState)
   {
   case (0) :
      QMessageBox::information(nullptr,"INFO","connected State");
        break;
   case(1):
        QMessageBox::information(nullptr,"ERROR"," Different SN  ");
        break;
   case(5):
        QMessageBox::information(nullptr,"ERROR","Diag in progress");
        break;
   }
   QJsonObject jsonMessage;
   ser.remove(QRegExp("\\s+"));
   jsonMessage["SerialNumber"] =ser;
   QString brokerUri = m_Configuration.Host + ":" + QString::number(m_Configuration.Port);
   brokerUri.remove(QRegExp("\\s+"));
   jsonMessage["BrokerURI"] =brokerUri;
   jsonMessage["Login"] =m_Configuration.Username.trimmed();
   jsonMessage["Password"] =m_Configuration.Password.trimmed();
   jsonMessage["QoS"]=m_Configuration.QOS;
   jsonMessage["SecurityLvl"]=m_Configuration.SecurityLevel;
   jsonMessage["CertPath"] ="/";
   QJsonDocument jsonDoc(jsonMessage);
   //QString Jsonstring =jsonDoc.toJson(QJsonDocument::Indented);
   //QString Msg= "{ \"SerialNumber\":"+ ser+",\"BrokerURI\":"+m_Configuration.Host+",\"Login\":"+m_Configuration.Username+",\"Password\":"+m_Configuration.Password+",\"QOS\":"+QString::number(m_Configuration.QOS)+",\"SecurityLvl\":"+QString::number(m_Configuration.SecurityLevel)+",""\"CertPath\": \"/\" }";
   socket->write(jsonDoc.toJson());
   socket->close();
}
/*void MainWindow::TCPMsg() {
   QString MsgTCP;
   while ( socket->canReadLine() )
   {
        MsgTCP = socket->readLine();

   }
}*/

