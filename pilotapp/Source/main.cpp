#include "MainWindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QFontDatabase>
#include <ArcGISRuntimeEnvironment.h>
#include <thread>
#include <chrono>
#include <future>

#include "Backend/Communication/communicationManager.h"
#include "Backend/Communication/communicationThread.h"

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
        qDebug() << "loaded style sheet";

        a->setStyleSheet(sheet.readAll());
    }
    sheet.close();
}

void setupArcGISEnvironment(){
    
    QFile apiKeyFile(":/Source/ArcGISApiKey.txt");
    if (apiKeyFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        
        QString key(apiKeyFile.readAll());
        
        qDebug() << "Loaded ArcGIS API Key";
        
        Esri::ArcGISRuntime::ArcGISRuntimeEnvironment::setApiKey(key);
    }
    else{
        qFatal("No ArcGIS API Key file found");
    }

    apiKeyFile.close();
}

int main(int argc, char *argv[]){
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    setupStyleSheet(&a);
    setupArcGISEnvironment();

    communicationManager::getInstance();

    auto commThread = std::async(std::launch::async, [&] {
        communicationThread::getInstance()->start();
    });
    
    //

    MainWindow w;
    w.show();
    return a.exec();
}
