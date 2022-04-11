#ifndef BOAT_KERNEL_H
#define BOAT_KERNEL_H

#include "Communication/dataManager.h"

class boatKernel{
private:
    boatKernel();
    ~boatKernel();
    static boatKernel* instance;

public:
    static boatKernel* getInstance();

    void receiveBoatDataPack(boatDataPack data);
};

#endif