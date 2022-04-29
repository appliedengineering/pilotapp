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
    void* ipcSub = nullptr; // used to receive data from python script
    void* scriptPair = nullptr; // used to send data to python script

    void printZMQVersion();
    void setupIPCSocket();
    void setupScriptSocket();

public:
    static communicationManager* getInstance();

    void* getIPCSocket();
    void* getScriptSocket();
    static bool recv(void* s, std::string& b);
    static bool send(void* s, std::string b);

};

#endif