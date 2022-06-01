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
    int batteryPercentage = 0;

    double boatLon = 0, boatLat = 0;

    void updateSpeedLabel(double speed);
    void updateThrottle(int percent);
    void updateDuty(int percent);
    void updateBattery(double voltage, double current, bool isSolar);
    void updateLocation(double lat, double lon);

public:
    static boatKernel* getInstance();

    void receiveBoatDataPack(boatDataPack data);
    void toggleMotor();

    bool getIsMotorEnabled();
    double getBoatLat();
    double getBoatLon();

signals:
    void speedUpdateSignal(double speed);
    void throttleUpdateSignal(int percent);
    void dutyUpdateSignal(int percent);
    void motorStatusUpdateSignal();
    void batteryPercentUpdateSignal(int percent);
    void locationUpdateSignal(double lat, double lon);
    void batteryDataUpdateSignal(double voltage, double current, bool isSolar);
};

#endif