#include "logManager.h"

#include <QDateTime>
#include <QFile>
#include <QDebug>

//

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

void logManager::writeToLogs(std::string s){
    qInfo() << QString::fromStdString(s); // console output
    
    logCache.push_back(s);
    emit appendLogEntrySignal();

    resizeLogs();
}

void logManager::resizeLogs(){
    while (logCache.size() > logCacheMaxSize){ // removes excess data points
        logCache.pop_front();
        emit removeFrontLogEntrySignal();
    }
}

std::string logManager::getCurrentTimestamp(){
    return "[" + QString::number(QDateTime::currentSecsSinceEpoch()).toStdString() + "]";
}

//

void logManager::saveToLogFile(bool shouldReplaceContent){

    QFile f(logPath);
    
    bool isFileOpen = false;
    if (shouldReplaceContent)
        isFileOpen = f.open(QIODevice::WriteOnly | QIODevice::Text);
    else
        isFileOpen = f.open(QIODevice::WriteOnly | QIODevice::Append);


    if (isFileOpen){
        for (std::string i : logCache)
            f.write(QString::fromStdString(i + '\n').toUtf8());
        f.close();
    }
}

void logManager::clearLogs(){
    logCache.clear();
}

const std::deque<std::string>& logManager::getLogCache(){
    return logManager::logCache;
}

int logManager::getMaxLogSize(){
    return logCacheMaxSize;
}

void logManager::setMaxLogSize(int s){
    logCacheMaxSize = s;
}

void logManager::setLogTypeEnabled(logType t, bool isEnabled){
    logTypeFilter[static_cast<int>(t)] = isEnabled;
}

bool logManager::getIsLogTypeEnabled(logType t){
    return logTypeFilter[static_cast<int>(t)];
}

// info

/*void logManager::i(QString s){
    logManager::i(s.toStdString());
}*/

void logManager::i(std::string s){
    logManager::getInstance()->writeToLogs("Info " + logManager::getInstance()->getCurrentTimestamp() + ": " + s);
}

// debug

/*void logManager::d(QString s){
    logManager::d(s.toStdString());
}*/

void logManager::d(std::string s){
    logManager::getInstance()->writeToLogs("Debug " + logManager::getInstance()->getCurrentTimestamp()  + ": " + s);
}

// errors

/*void logManager::e(QString s){
    logManager::e(s.toStdString());
}*/

void logManager::e(std::string s){
    logManager::getInstance()->writeToLogs("ERROR " + logManager::getInstance()->getCurrentTimestamp() + ": " + s);
}


// telemetry

void logManager::t(std::string s){
    logManager::getInstance()->writeToLogs("Tmtry " + logManager::getInstance()->getCurrentTimestamp() + ": " + s);
}