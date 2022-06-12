#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <QObject>
#include <QString>
#include <string>

class logManager : public QObject{
    Q_OBJECT
private:
    logManager();
    ~logManager();
    static logManager* instance;

    //

    const QString logPath = "logs.txt";

    void clearLogFile();
    void appendToLogFile(QString s); // appends onto preexisting logs
    void writeToLogFile(QString s); // removes preexisting logs

public:
    logManager* getInstance();

    // info logs
    void i(QString s);
    void i(std::string s);

    // debug logs
    void d(QString s);
    void d(std::string s);

    // errors logs
    void e(QString s);
    void e(std::string s);

    void clearLogs();
};

#endif