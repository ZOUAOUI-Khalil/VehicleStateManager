#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QMqttClient>
#include <QHash>
#include "TypesAndDefines.h"
#include <QTimer>
#include <QTcpSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void currentdatachanged(int ser);

public:
    //TGURMsg Msg ;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool m_WifiMode= false;
    bool m_GSMMode= false ;
    int m_Row=0;
    int Selectedrow;
    //TGURMsg Msg;
    //QStandardItemModel * m_Model= nullptr;


public slots:

    void OnItemSelected(QModelIndex index);
    void OnClientConnected();
    void OnClientDisconnected();
    void onMessageReceived(QMqttMessage msg);
    void refresh();
    void TCPConnected();
    void TCPMsg();
    /*void saveinivalues(const QString &path,const QString &groupename,const QString &Name,const QString &Value);
    QString readinivalues(const QString &path,const QString &groupename,const QString &Name);*/

private slots:
    void on_Refreshbutton_clicked();

private:
    Configuration m_Configuration;
    //TGURMsg* Msg=nullptr;
    QTimer* m_timer= new QTimer();
    QTcpSocket *socket = new QTcpSocket(this);
    QString IP;
    int port;

    QMap<long,TGURMsg> m_Currentdata;
    QStandardItemModel * m_Model= nullptr;
    QMqttClient* m_Client=nullptr;
    Ui::MainWindow *ui;
    void showDialog();
    int StartConfigurationDialog();
    void ERREUR(QJsonParseError Error);
    TGURMsg buildTGURmsg(QMqttMessage msg);
    void UpdateModel(TGURMsg Msg);
    void InsertNewValueInTable(TGURMsg Msg);
    void UpdateTable(TGURMsg Msg);
    void getTGURMsg(TGURMsg msg);

};
#endif // MAINWINDOW_H
