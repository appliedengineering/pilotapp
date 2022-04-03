#include "communicationThread.h"

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
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void communicationThread::stop(){
    isRunning = false;
}

