#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(800, 480); // official raspberry pi display size
    
    w.show();
    return a.exec();
}
