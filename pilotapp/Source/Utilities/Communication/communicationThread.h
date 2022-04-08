#ifndef COMMUNICATION_THREAD_H
#define COMMUNICATION_THREAD_H

#include <unordered_map>
#include <string>

/*struct msgpackmap{
    std::unordered_map<std::string, std::string> m;
      
    template<class T>
    void pack(T &pack) {
        pack(m);
    }
};*/

class communicationThread{

private:
    communicationThread();
    ~communicationThread();
    static communicationThread* instance;

    bool isRunning = false;

public:
    static communicationThread* getInstance();

    void start();
    void stop();
};

#endif