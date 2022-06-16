#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <QObject>
#include <QString>
#include <string>
#include <deque>

class logManager : public QObject{
    Q_OBJECT
private:
    logManager();
    ~logManager();
    static logManager* instance;

    //

    const QString logPath = "logs.txt";

    int logCacheMaxSize = 100;
    std::deque<std::string> logCache;

    //

    void writeToLogFile(bool shouldReplaceContent);
    void writeToLogs(std::string s);
    void resizeLogs();

    std::string getCurrentTimestamp();

public:
    logManager* getInstance();

    void clearLogs();
    const std::deque<std::string>& getLogCache();

    int getMaxLogSize();
    void setMaxLogSize(int s);

    // info logs
    void i(QString s);
    void i(std::string s);

    // debug logs
    void d(QString s);
    void d(std::string s);

    // errors logs
    void e(QString s);
    void e(std::string s);

};

#endif