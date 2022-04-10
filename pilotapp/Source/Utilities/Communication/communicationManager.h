#ifndef COMMUNICATION_MANAGER_H
#define COMMUNICATION_MANAGER_H

#include <zmq.h>
#include <string>
#include <vector>
#include <map>
#include <msgpack.hpp>

class communicationManager{
private:
    communicationManager();
    ~communicationManager();
    static communicationManager* instance;

    void* ctx = nullptr;
    void* ipcSub = nullptr; // used to communicate with python script

    void printZMQVersion();
    void setupIPCSocket();

public:
    static communicationManager* getInstance();

    void* getIPCSocket();
    static bool recv(void* s, std::string& b);

};

#endif