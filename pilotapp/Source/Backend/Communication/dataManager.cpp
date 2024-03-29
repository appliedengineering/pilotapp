#include "dataManager.h"

#include "../logManager.h"
#include <iostream>
//#include <iomanip>
#include <sstream>

#include <QDebug>

rawDataPack dataManager::deserializeRawBoatData(std::string& raw){
    //raw = dataManager::msgpackDataPrefix + raw + dataManager::msgpackDataSuffix;
    if (raw.empty() || raw[0] != dataManager::msgpackDataPrefix)
        raw = dataManager::msgpackDataPrefix + raw;

    if (raw.empty() || raw[raw.size() - 1] != dataManager::msgpackDataSuffix)
        raw += dataManager::msgpackDataSuffix;

    msgpack::object_handle oh = msgpack::unpack(raw.data(), raw.size());
    msgpack::object obj = oh.get();

    //std::cout << obj << std::endl;

    //

    rawDataPack data;
    obj.convert(data);

    return data;
}

// https://stackoverflow.com/a/47535491/
/*//template<typename T>
std::string dataManager::packData(T& data){
    std::stringstream stream;
    msgpack::pack(stream, data);
    return stream.str();
}*/

///

const int boatDataPack::maxPossibleVoltage = 30;
const int boatDataPack::minPossibleVoltage = 10;

boatDataPack::boatDataPack(rawDataPack& raw){
    std::map<std::string, msgpack::type::variant> m = raw.getMap();
    //qInfo() << "before const";
    try{
        TP = m["TP"].as_uint64_t();
        DP = m["DP"].as_uint64_t();
        //CP = m["CP"].as_double();
        BV = m["BV"].as_double();
        //UV = m["UV"].as_bool();
        SM = m["SM"].as_bool();
        EN = m["EN"].as_bool();
        BC = m["BC"].as_double();
    }
    catch(std::exception& e){
        logManager::e("Motor Data Unpack Error - " + std::string(e.what()));
    }

    try{
        posLat = m["posLat"].as_double();
        posLon = m["posLon"].as_double();

        speed = m["speed"].as_double();

        timeStamp = m["timeStamp"].as_double();
    }
    catch(std::exception& e){
        logManager::e("Telemetry Data Unpack Error - " + std::string(e.what()));
    }

    logData();

    //qInfo() << "after const";
}

void boatDataPack::logData(){
    using namespace std;
    string d = "{";
    d += "TP: " + to_string(TP) + ",";
    d += "DP: " + to_string(DP) + ",";
    d += "BV: " + to_string(BV) + ",";
    d += "SM: " + string(SM ? "True" : "False") + ",";
    d += "EN: " + string(EN ? "True" : "False") + ",";
    d += "BC: " + to_string(BC) + ",";
    d += "posLat: " + to_string(posLat) + ",";
    d += "posLon: " + to_string(posLon) + ",";
    d += "speed: " + to_string(speed) + ",";
    d += "timeStamp: " + to_string(timeStamp);
    d += "}";
    logManager::t(d);
}

//

int boatDataPack::getThrottlePercent(){
    return TP;
}

int boatDataPack::getDutyPercent(){
    return DP;
}

/*float boatDataPack::getChipTemp(){
    return CP;
}*/

double boatDataPack::getBatteryVoltage(){
    return BV;
}

/*bool boatDataPack::getUndervolt(){
    return UV;
}*/

bool boatDataPack::getSolarMode(){
    return SM;
}

bool boatDataPack::getMotorEnabled(){
    return EN;
}

double boatDataPack::getBatteryCurrent(){
    return BC;
}

double boatDataPack::getPosLat(){
    return posLat;
}

double boatDataPack::getPosLon(){
    return posLon;
}

double boatDataPack::getSpeed(){
    return speed;
}

double boatDataPack::getTimestamp(){
    return timeStamp;
}