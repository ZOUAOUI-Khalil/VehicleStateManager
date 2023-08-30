#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool m_WifiMode= false;
    bool m_GSMMode= false ;
    //QStandardItemModel * m_Model= nullptr;



private slots:
   //void on_pushButton_clicked();
   //void onPushButton3Clicked();


private:
    /*bool m_WifiMode= false;
    bool m_GSMMode= false ;*/
    QStandardItemModel * m_Model= nullptr;
    Ui::MainWindow *ui;
    void showDialog();
};
#endif // MAINWINDOW_H
