#ifndef BOAT_KERNEL_H
#define BOAT_KERNEL_H

#include "Communication/dataManager.h"

class boatKernel{
private:
    boatKernel();
    ~boatKernel();
    static boatKernel* instance;

    void updateSpeedLabel(double speed);
    void updateThrottle(int percent);
    void updateDuty(int percent);

public:
    static boatKernel* getInstance();

    void receiveBoatDataPack(boatDataPack data);
    //void toggleMotor();
};

#endif