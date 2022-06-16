#include "logManager.h"

#include <QDateTime>
#include <QFile>

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

void logManager::writeToLogFile(bool shouldReplaceContent){
    QFile f(logPath);
    if (f.open(QIODevice::WriteOnly | (shouldReplaceContent ? QIODevice::Text : QIODevice::Append)))
        for (std::string i : logCache)
            f.write(QString::fromStdString(i).toUtf8());
}

void logManager::writeToLogs(std::string s){
    logCache.push_back(s);
    resizeLogs();
}

void logManager::resizeLogs(){
    while (logCache.size() > logCacheMaxSize){ // removes excess data points
        logCache.pop_front();
    }
}

std::string logManager::getCurrentTimestamp(){
    return "[" + QString::number(QDateTime::currentSecsSinceEpoch()).toStdString() + "]";
}

//

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

// info

void logManager::i(QString s){
    logManager::i(s.toStdString());
}

void logManager::i(std::string s){
    writeToLogs(getCurrentTimestamp() + " Info: " + s);
}

// debug

void logManager::d(QString s){
    logManager::d(s.toStdString());
}

void logManager::d(std::string s){
    writeToLogs(getCurrentTimestamp()  + " Debug: " + s);
}

// errors

void logManager::e(QString s){
    logManager::e(s.toStdString());
}

void logManager::e(std::string s){
    writeToLogs(getCurrentTimestamp() + " ERROR: " + s);
}
