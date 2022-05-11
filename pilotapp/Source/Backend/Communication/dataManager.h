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
    //float CP; // Chip Temp
    double BV; // Battery Voltage
    //bool UV; // Undervoltage Protection
    bool SM; // Solar Mode
    bool EN; // Motor Enabled
    double BC; // Battery Current
    // End Motor Data
    double posLat;
    double posLon;
    double speed; // m/s
    double timeStamp;
public:
    boatDataPack(rawDataPack& raw);

    int getThrottlePercent();
    int getDutyPercent();
    //float getChipTemp();
    double getBatteryVoltage();
    //bool getUndervolt();
    bool getSolarMode();
    bool getMotorEnabled();
    double getBatteryCurrent();

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

    template<typename T>
    static std::string packData(T& data){
        std::stringstream stream;
        msgpack::pack(stream, data);
        return stream.str();
    }
};

#endif