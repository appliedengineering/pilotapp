#ifndef BOAT_KERNEL_H
#define BOAT_KERNEL_H

class boatDataPack;

#include <QObject>

class boatKernel : public QObject{
    Q_OBJECT
private:
    boatKernel();
    ~boatKernel();
    static boatKernel* instance;

    bool isMotorEnabled = false;

    void updateSpeedLabel(double speed);
    void updateThrottle(int percent);
    void updateDuty(int percent);

public:
    static boatKernel* getInstance();

    void receiveBoatDataPack(boatDataPack data);
    void toggleMotor();

    bool getIsMotorEnabled();

signals:
    void throttleUpdateSignal(int percent);
    void dutyUpdateSignal(int percent);
    void motorStatusUpdateSignal();
};

#endif