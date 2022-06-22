#include "MainWindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QFontDatabase>
//#include <ArcGISRuntimeEnvironment.h>
#include <thread>
#include <chrono>
#include <future>

#include "Backend/Communication/communicationManager.h"
#include "Backend/Communication/communicationThread.h"
#include "Backend/logManager.h"
#include "Backend/Display Control/displayControlEventFilter.h"

void setupStyleSheet(QApplication* a){
    
    QFontDatabase::addApplicationFont(":/Assets/Fonts/Inter-Regular.otf");
    QFontDatabase::addApplicationFont(":/Assets/Fonts/Inter-Bold.otf");
    QFontDatabase::addApplicationFont(":/Assets/Fonts/Inter-SemiBold.otf");

    /*
    QFontDatabase db;
    for(int i=0; i<db.families().size(); i++)
    {
        qDebug() << db.families().at(i);
    }
    */

    //

    QFile sheet(":/Source/style.qss");

    if (sheet.open(QIODevice::ReadOnly | QIODevice::Text)){

        //qInfo() << sheet.readAll();
        logManager::i("Loaded style sheet");

        a->setStyleSheet(sheet.readAll());
    }
    sheet.close();
}

/*void setupArcGISEnvironment(){ 

    QFile licenseKeyFile(":/Source/ArcGISLicenseKey.txt");
    if (licenseKeyFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString key(licenseKeyFile.readAll());

        qInfo() << "Loaded ArcGIS License Key";

        Esri::ArcGISRuntime::ArcGISRuntimeEnvironment::setLicense(key); 
    }
    else{
        qFatal("No ArcGIS License Key file found");
    }

    licenseKeyFile.close();
}*/

int main(int argc, char *argv[]){
    //qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    qputenv("QT_QPA_EGLFS_HIDECURSOR", QByteArray("1"));

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    setupStyleSheet(&a);
    //setupArcGISEnvironment();

    communicationManager::getInstance();

    auto commThread = std::async(std::launch::async, [&] {
        communicationThread::getInstance()->start();
    });

    //

    MainWindow w;
    w.show();

    //

    w.getDisplayFilter()->setDebug(true);
    w.getDisplayFilter()->setMaxBrightness(255);
    w.getDisplayFilter()->setMinBrightness(0);
    w.getDisplayFilter()->setTimeOut(1);
    a.installEventFilter(w.getDisplayFilter());

    w.getDisplayFilter()->commitBrightness(255);

    //

    return a.exec();
}
