#include "communicationThread.h"

#include "communicationManager.h"
#include "dataManager.h"
#include <thread>
#include <chrono>
#include <QDebug>
#include <unordered_map>

communicationThread* communicationThread::instance = nullptr;

communicationThread::communicationThread(){
}

communicationThread::~communicationThread(){
}

communicationThread* communicationThread::getInstance(){
    if (instance == nullptr){
        instance = new communicationThread();
    }
    return instance;
}

//

void communicationThread::start(){
    isRunning = true;

    while(isRunning){

        //std::vector<uint8_t> buf;
        std::string buf;
        if (communicationManager::recv(communicationManager::getInstance()->getIPCSocket(), buf)){
            
            qInfo() << "recv - " << QString::fromStdString(buf); 
            /*msgpackmap data = msgpack::unpack<msgpackmap>(std::vector<uint8_t>(buf.begin(), buf.end()));
            for(std::pair<std::string, std::string> i : data.m){
                qInfo() << QString::fromStdString(i.first) << " " << QString::fromStdString(i.second);
            }*/

            //communicationManager::deserializeRawBoatData(buf);
            dataManager::deserializeRawBoatData(buf);

        }
        buf.clear();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void communicationThread::stop(){
    isRunning = false;
}

