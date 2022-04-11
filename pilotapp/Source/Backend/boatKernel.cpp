#include "boatKernel.h"

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
    
}