#include "communicationThread.h"

#include "communicationManager.h"
#include "dataManager.h"
#include "../boatKernel.h"
#include "../logManager.h"
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
            //logManager::d("recvd buff = " + buf);
            //qInfo() << "recv = " << QString::fromStdString(buf);             
            rawDataPack r = dataManager::deserializeRawBoatData(buf);
            boatDataPack data(r);
            //qInfo() << "after parse = " << data.getTimestamp();

            boatKernel::getInstance()->receiveBoatDataPack(data);

        }
        buf.clear();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void communicationThread::stop(){
    isRunning = false;
}

