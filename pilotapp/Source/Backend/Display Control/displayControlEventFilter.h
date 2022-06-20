#ifndef DISPLAY_CONTROL_EVENT_FILTER_H_
#define DISPLAY_CONTROL_EVENT_FILTER_H_

// credits to https://github.com/eddyyanto/InactivityTimer

#include <QObject>
#include <QTimer>
#include <QString>
#include <QFile>

class displayControlEventFilter : public QObject{
    Q_OBJECT
private:
    bool DEBUG;
    int TIMEOUT; // milliseconds
    int MIN_BRIGHTNESS;
    int MAX_BRIGHTNESS;

    QTimer inactivityTimer;
    bool isSleeping;
    int lastBrightness;

public:
    explicit displayControlEventFilter(QObject *parent = 0);
    bool eventFilter(QObject *obj, QEvent *ev);

    void setTimeOut(int milliseconds);
    void setMinBrightness(int brightness);
    void setMaxBrightness(int brightness);
    void setDebug(bool status);
    void adjustBrightness(int brightness);
    void commitBrightness(int brightness);
    void debug(QString message);

public slots:
    void goToSleep();

};

#endif