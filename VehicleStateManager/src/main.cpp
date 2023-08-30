#include "MainWindow.h"
#include "QDebug"
#include <QApplication>
#include <QStyleFactory>
//#include "DialogTest.h"
#include"QSplashScreen"
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap splashImage(":/new/prefix1/vehicle.jpg"); // Replace with your image path
    QSplashScreen splash(splashImage);

    QApplication::setStyle(QStyleFactory::create("fusion"));
    /* QTimer timer;
    int delayMilliseconds = 2000;
    timer.setSingleShot(true); // Arrêtez le QTimer après le délai
    timer.start(delayMilliseconds);
    splash.show();
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        // Code à exécuter après le délai
        splash.close();
        qDebug() << "Délai écoulé";
    });
    // Show the splash screen*/
    splash.show();
    QThread::sleep(2);
    splash.close();


    MainWindow w;


    if ((w.m_GSMMode == true) ||(w.m_WifiMode ==true)) {

        w.show();
    qDebug() << w.m_GSMMode;
    qDebug() << w.m_WifiMode;
    }

    return a.exec();

}
