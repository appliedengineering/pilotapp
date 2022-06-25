#ifndef PREFERENCES_MANAGER_H_
#define PERFERENCES_MANAGER_H_

#include <QObject>

class preferencesManager : public QObject{
    Q_OBJECT
private:
    preferencesManager();
    ~preferencesManager();
    static preferencesManager* instance;

    
public:
};

#endif