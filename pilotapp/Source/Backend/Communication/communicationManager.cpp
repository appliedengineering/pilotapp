#include "communicationManager.h"

#include "../logManager.h"

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
    logManager::i("ZMQ Version " + std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch));
}

//

void communicationManager::setupIPCSocket(){
    ipcSub = zmq_socket(ctx, ZMQ_SUB);
    if (zmq_setsockopt(ipcSub, ZMQ_SUBSCRIBE, "", 0) == -1)
        logManager::e("Failed to set ipcSub subscribe option");
    
    int t = 1;
    if (zmq_setsockopt(ipcSub, ZMQ_CONFLATE, &t, sizeof(t)) == -1)
        logManager::e("Failed to set ipcSub conflate option");

    if (zmq_connect(ipcSub, "tcp://localhost:5556") == -1)
        logManager::e("Failed to connect ipcSub");
}

void communicationManager::setupScriptSocket(){
    scriptPair = zmq_socket(ctx, ZMQ_PAIR);
    if (zmq_bind(scriptPair, "tcp://*:5553") == -1)
        logManager::e("Failed to connect scriptPair");
}

void* communicationManager::getIPCSocket(){
    return ipcSub;
}

void* communicationManager::getScriptSocket(){
    return scriptPair;
}

bool communicationManager::recv(void* s, std::string& b){
    if (!s){
        logManager::e("nullptr socket passed to recv");
        return false;
    }

    zmq_msg_t msg;

    if (zmq_msg_init(&msg) == -1){
        logManager::e("failed to init zmq msg in recv");
        return false;
    }

    if (zmq_msg_recv(&msg, s, ZMQ_NOBLOCK) == -1){
        if (zmq_errno() != EAGAIN)
            logManager::e("failed to recv zmq msg");
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
        logManager::e("failed to init zmq msg");
        return false;
    }

    if (zmq_msg_init_size(&msg, b.size()) == -1){
        logManager::e("failed to init zmq msg with size of " + std::to_string(b.size()));
        return false;
    }

    if (b.size())
        memcpy(zmq_msg_data(&msg), b.data(), b.size());

    if (zmq_msg_send(&msg, s, ZMQ_DONTWAIT) == -1){
        logManager::e("Failed to send zmq msg " + std::string(zmq_strerror(zmq_errno())));
        return false;
    }

    logManager::i("Successfully sent message " + b);

    zmq_msg_close(&msg);
    return true;
}
