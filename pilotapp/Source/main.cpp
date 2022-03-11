#include "MainWindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QFontDatabase>

void setupStyleSheet(QApplication* a){
    
    QFontDatabase::addApplicationFont(":/Assets/Fonts/Inter-Regular.otf");
    QFontDatabase::addApplicationFont(":/Assets/Fonts/Inter-Bold.otf");
    QFontDatabase::addApplicationFont(":/Assets/Fonts/Inter-SemiBold.otf");

    QFontDatabase db;
    for(int i=0; i<db.families().size(); i++)
    {
        qDebug() << db.families().at(i);
    }

    //

    QFile sheet(":/Source/style.qss");

    if (sheet.open(QIODevice::ReadOnly | QIODevice::Text)){

        //qInfo() << sheet.readAll();
        qDebug() << "loaded style sheet";

        a->setStyleSheet(sheet.readAll());
        sheet.close();
    }
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    setupStyleSheet(&a);

    //

    MainWindow w;
    w.show();
    return a.exec();
}
