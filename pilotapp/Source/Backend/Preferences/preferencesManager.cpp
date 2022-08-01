#include "preferencesManager.h"

#include "../../Custom/json.hpp"

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
maxVoltage (double), minVoltage (double)

Communications Manager:
ipcSubAddr (str), ipcSubPort (int), scriptPairAddress (str), scriptPairPort (int)

Communications Thread:
threadTimeout (int), threadRunning (bool)

leftContentSlate:
speedometerUnits (enum)

Map Settings:
coordinatePrecision (int)

Map:
buoyMarkerSize (int), boatMarkerSize (int), shouldCacheMapData (bool), reset cache data button

*/

