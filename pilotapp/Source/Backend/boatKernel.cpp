#include "boatKernel.h"
#include "Utilities/utilities.h"
#include "Communication/dataManager.h"
#include "Communication/communicationManager.h"

#include <QDebug>
#include <math.h>

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
    updateThrottle(data.getThrottlePercent());
    updateDuty(data.getDutyPercent());
    updateBattery(data.getBatteryVoltage(), data.getBatteryCurrent());

    if (data.getMotorEnabled() != isMotorEnabled){
        isMotorEnabled = data.getMotorEnabled();

        emit motorStatusUpdateSignal();
    }
}

void boatKernel::toggleMotor(){
    bool newMotorStatus = !isMotorEnabled;

    // send motor status to controller

    communicationManager::send(communicationManager::getInstance()->getScriptSocket(), dataManager::packData(newMotorStatus));
    //communicationManager::send(communicationManager::getInstance()->getScriptSocket(), "");
    //dataManager::packData(newMotorStatus);

    //isMotorEnabled = newMotorStatus;
}

//

void boatKernel::updateSpeedLabel(double speed){
    speed *= 1.94384; // from m/s to knots
    utilities::findMainWindow()->getHomePageWidget()->getLeftContentSlateWidget()->updateSpeedLabel(speed);
}

void boatKernel::updateThrottle(int percent){
    emit throttleUpdateSignal(percent);
    //utilities::findMainWindow()->getHomePageWidget()->getLeftContentSlateWidget()->updateThrottle(percent);
}

void boatKernel::updateDuty(int percent){
    emit dutyUpdateSignal(percent);
    //utilities::findMainWindow()->getHomePageWidget()->getLeftContentSlateWidget()->updateDuty(percent);
}

void boatKernel::updateBattery(double voltage, double current){

    const double maxVoltage = 30.0;
    const double minVoltage = 22.0;

    int currentBatteryPercent = (int)(100 * (std::max(std::min(voltage, maxVoltage), minVoltage) - minVoltage) / (maxVoltage - minVoltage));

    //qInfo() << "Battery V - " << voltage << " = " << currentBatteryPercent;

    if (currentBatteryPercent != batteryPercentage){
        batteryPercentage = currentBatteryPercent;
        emit batteryPercentUpdateSignal(batteryPercentage);
    }
}

bool boatKernel::getIsMotorEnabled(){
    return isMotorEnabled;
}