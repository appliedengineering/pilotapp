#include "MainWindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QFontDatabase>

void setupStyleSheet(QApplication* a){
    
    QFontDatabase::addApplicationFont("Fonts/Inter-Regular.otf");
    QFontDatabase::addApplicationFont("Fonts/Inter-Bold.otf");
    QFontDatabase::addApplicationFont("Fonts/Inter-SemiBold.otf");

    QFontDatabase db;
    for(int i=0; i<db.families().size(); i++)
    {
        qDebug() << db.families().at(i);
    }

    //

    QFile sheet("style.qss");

    if (sheet.open(QIODevice::ReadOnly | QIODevice::Text)){
        a->setStyleSheet(sheet.readAll());
        sheet.close();
    }
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    setupStyleSheet(&a);

    //

    MainWindow w;

    w.setFixedSize(800, 480); // official raspberry pi display size

    w.show();
    return a.exec();
}
