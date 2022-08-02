#ifndef PREFERENCES_MANAGER_H_
#define PERFERENCES_MANAGER_H_

#include <QObject>
#include <QFile>
#include <map>
#include <string>

class preferencesManager : public QObject{
    Q_OBJECT
private:
    preferencesManager();
    ~preferencesManager();
    static preferencesManager* instance;

    std::map<std::string, std::string> map;

    void loadMap();


public:
    preferencesManager* getInstance();
};

#endif