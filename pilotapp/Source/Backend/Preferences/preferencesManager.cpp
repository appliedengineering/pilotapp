#include "preferencesManager.h"

preferencesManager* preferencesManager::instance = nullptr;

preferencesManager::preferencesManager(){

}

preferencesManager::~preferencesManager(){

}

preferencesManager* preferencesManager::getInstance(){
    if (preferencesManager::instance == nullptr){
        preferencesManager::instance = new preferencesManager();
    }
    return preferencesManager::instance;
}

/*
List of options

Boat Kernel:
maxVoltage, minVoltage

Communications Manager:
ipcSub address/port, scriptPair address/port

Communications Thread:
loop timeout, stop thread

leftContentSlate:
speedometer units

Map Settings:
max coordinate precision

Map:
buoyMarkerSize, boatMarkerSize, map cache data

*/

