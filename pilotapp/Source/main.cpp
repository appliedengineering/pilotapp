#include "MainWindow.h"

#include <QApplication>
#include <QFile>

void setupStyleSheet(QApplication* a){
    QFile sheet(":/style.qss");

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
