#include "boatKernel.h"
#include "Utilities/utilities.h"

#include <QDebug>

//

boatKernel* boatKernel::instance = nullptr;

boatKernel::boatKernel(){
}

boatKernel::~boatKernel(){
}

boatKernel* boatKernel::getInstance(){
    if (boatKernel::instance == nullptr){
        boatKernel::instance = new boatKernel();
    }
    return boatKernel::instance;
}

//

void boatKernel::receiveBoatDataPack(boatDataPack data){
    qInfo() << "recv boat data";
    
    //

    updateSpeedLabel(data.getSpeed());
}

//

void boatKernel::updateSpeedLabel(double speed){
    utilities::findMainWindow()->getHomePageWidget()->getLeftContentSlateWidget()->updateSpeedLabel(speed);
}