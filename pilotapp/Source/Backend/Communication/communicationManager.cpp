#include "communicationManager.h"

#include <QDebug>
#include <iostream>

communicationManager* communicationManager::instance = nullptr;

communicationManager::communicationManager(){
    printZMQVersion();
    ctx = zmq_ctx_new();
    setupIPCSocket();
    setupScriptSocket();
}

communicationManager::~communicationManager(){
    if (ipcSub != nullptr){
        zmq_close(ipcSub);
    }
    if (scriptPair != nullptr){
        zmq_close(scriptPair);
    }
    zmq_ctx_term(ctx);
}

communicationManager* communicationManager::getInstance(){
    if (communicationManager::instance == nullptr){
        communicationManager::instance = new communicationManager();
    }
    return communicationManager::instance;
}

void communicationManager::printZMQVersion(){
    int major, minor, patch;
    zmq_version(&major, &minor, &patch);
    qInfo() << "ZMQ Version " << major << "." << minor << "." << patch;
}

//

void communicationManager::setupIPCSocket(){
    ipcSub = zmq_socket(ctx, ZMQ_SUB);
    if (zmq_setsockopt(ipcSub, ZMQ_SUBSCRIBE, "", 0) == -1)
        qCritical("Failed to set ipcSub subscribe option");
    
    int t = 1;
    if (zmq_setsockopt(ipcSub, ZMQ_CONFLATE, &t, sizeof(t)) == -1)
        qCritical("Failed to set ipcSub conflate option");

    if (zmq_connect(ipcSub, "tcp://localhost:5556") == -1)
        qCritical("Failed to connect ipcSub");
}

void communicationManager::setupScriptSocket(){
    scriptPair = zmq_socket(ctx, ZMQ_PAIR);
    if (zmq_bind(scriptPair, "tcp://*:5553") == -1)
        qCritical("Failed to connect scriptPair");
}

void* communicationManager::getIPCSocket(){
    return ipcSub;
}

void* communicationManager::getScriptSocket(){
    return scriptPair;
}

bool communicationManager::recv(void* s, std::string& b){
    if (!s){
        qDebug() << "nullptr socket passed to recv";
        return false;
    }

    zmq_msg_t msg;

    if (zmq_msg_init(&msg) == -1){
        qDebug() << "failed to init zmq msg in recv";
        return false;
    }

    if (zmq_msg_recv(&msg, s, ZMQ_NOBLOCK) == -1){
        if (zmq_errno() != EAGAIN)
            qDebug() << "failed to recv zmq msg";
        return false;
    }

    /*size_t msgsize = zmq_msg_size(&msg);
    b = std::vector<uint8_t>(msgsize);
    memcpy(b.data(), zmq_msg_data(&msg), msgsize);*/
    b = std::string(static_cast<char*>(zmq_msg_data(&msg)), zmq_msg_size(&msg));

    zmq_msg_close(&msg);
    return true;
}

bool communicationManager::send(void* s, std::string b){
    zmq_msg_t msg;
    
    if (zmq_msg_init(&msg) == -1){
        qCritical() << "failed to init zmq msg";
        return false;
    }

    if (zmq_msg_init_size(&msg, b.size()) == -1){
        qCritical() << "failed to init zmq msg with size of " << b.size();
        return false;
    }

    if (b.size())
        memcpy(zmq_msg_data(&msg), b.data(), b.size());

    if (zmq_msg_send(&msg, s, ZMQ_DONTWAIT) == -1){
        qDebug() << "Failed to send zmq msg " << zmq_strerror(zmq_errno());
        return false;
    }

    zmq_msg_close(&msg);
    return true;
}
