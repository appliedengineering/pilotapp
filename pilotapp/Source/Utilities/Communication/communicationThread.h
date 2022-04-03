#ifndef COMMUNICATION_THREAD_H
#define COMMUNICATION_THREAD_H

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