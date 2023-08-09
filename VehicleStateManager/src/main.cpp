#include "MainWindow.h"
#include "QDebug"
#include <QApplication>
#include <QStyleFactory>
//#include "DialogTest.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("fusion"));
    MainWindow w;
    if ((w.m_GSMMode == true) ||(w.m_WifiMode ==true)) {
    w.show();
    qDebug() << w.m_GSMMode;
    qDebug() << w.m_WifiMode;
    }

    return a.exec();

}
