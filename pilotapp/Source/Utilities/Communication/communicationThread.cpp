#include "communicationThread.h"

#include "communicationManager.h"
#include <thread>
#include <chrono>
#include <QDebug>

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

        std::string buf;
        if (communicationManager::recv(communicationManager::getInstance()->getIPCSocket(), buf)){
            qInfo() << "recv - " << QString::fromStdString(buf); 
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void communicationThread::stop(){
    isRunning = false;
}

