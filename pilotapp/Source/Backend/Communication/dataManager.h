#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <string>
#include <vector>
#include <map>
#include <msgpack.hpp>

class rawDataPack{
private:
    std::map<std::string, msgpack::type::variant> m;
public:
    //MSGPACK_DEFINE(TP, DP, CP, BV, UV, OV, SM, EN, timeStamp);
    MSGPACK_DEFINE(m);

    std::map<std::string, msgpack::type::variant> getMap(){
        return m;
    }
};

class boatDataPack{
private:
    int TP; // Throttle Percent
    int DP; // Duty Percent
    float CP; // Chip Temp
    double BV; // Battery Voltage
    bool UV; // Undervoltage Protection
    bool OV; // Overvoltage Protection
    bool SM; // Solar Mode
    bool EM; // Motor Enabled
    // End Motor Data
    double posLat;
    double posLon;
    double speed; // m/s
    double timeStamp;
public:
    boatDataPack(rawDataPack& raw);

    int getThrottlePercent();
    int getDutyPercent();
    float getChipTemp();
    double getBatteryVoltage();
    bool getUndervolt();
    bool getOvervolt();
    bool getSolarMode();
    bool getMotorEnabled();

    double getPosLat();
    double getPosLon();

    double getSpeed();

    double getTimestamp();
};

class dataManager{
private:
    // missing prefix and suffix chars needed for C++ version of msgpack
    static const char msgpackDataPrefix = static_cast<char>(-111);
    static const char msgpackDataSuffix = static_cast<char>(-112);
public:
    static rawDataPack deserializeRawBoatData(std::string& raw);
};

#endif