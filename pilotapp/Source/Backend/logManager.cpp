#include "logManager.h"


logManager* logManager::instance = nullptr;

logManager::logManager(){
}

logManager::~logManager(){
}

logManager* logManager::getInstance(){
    if (logManager::instance == nullptr){
        logManager::instance = new logManager();
    }
    return logManager::instance;
}

//

void logManager::clearLogFile(){

}

void logManager::appendToLogFile(QString s){

}

void logManager::writeToLogFile(QString s){

}

//

// info

void logManager::i(QString s){

}

void logManager::i(std::string s){

}

// debug

void logManager::d(QString s){

}

void logManager::d(std::string s){

}

// errors

void logManager::e(QString s){

}

void logManager::e(std::string s){

}

void logManager::clearLogs(){
    
}
