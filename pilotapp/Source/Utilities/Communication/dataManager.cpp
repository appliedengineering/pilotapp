#include "dataManager.h"
#include <iostream>

rawDataPack dataManager::deserializeRawBoatData(std::string& raw){
    //raw = dataManager::msgpackDataPrefix + raw + dataManager::msgpackDataSuffix;
    if (raw.empty() || raw[0] != dataManager::msgpackDataPrefix)
        raw = dataManager::msgpackDataPrefix + raw;

    if (raw.empty() || raw[raw.size() - 1] != dataManager::msgpackDataSuffix)
        raw += dataManager::msgpackDataSuffix;

    msgpack::object_handle oh = msgpack::unpack(raw.data(), raw.size());
    msgpack::object obj = oh.get();

    std::cout << obj << std::endl;

    //

    rawDataPack data;
    obj.convert(data);

    std::cout << "after conversion - " << data.getMap().size() << std::endl;

    return data;
}