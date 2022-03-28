#include "MainWindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QFontDatabase>
#include <ArcGISRuntimeEnvironment.h>

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
        QString key = apiKeyFile.readAll();
        //qDebug() << "ArcGIS API Key - " << key;
        Esri::ArcGISRuntime::ArcGISRuntimeEnvironment::setApiKey(key);
    }
    else{
        qFatal("No ArcGIS API Key file found");
    }

    apiKeyFile.close();
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    setupStyleSheet(&a);
    setupArcGISEnvironment();

    //

    MainWindow w;
    w.show();
    return a.exec();
}
