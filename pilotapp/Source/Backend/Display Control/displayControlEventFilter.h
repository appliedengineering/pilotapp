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
    int TIMEOUT; // mins
    bool isAutoSleepEnabled;

    const int ABS_MIN_BRIGHTNESS = 0;
    int MIN_BRIGHTNESS;

    const int ABS_MAX_BRIGHTNESS = 255;
    int MAX_BRIGHTNESS;

    QTimer inactivityTimer;
    bool isSleeping;
    int lastBrightness;

    void debug(QString message);

public:
    explicit displayControlEventFilter(QObject *parent = 0);
    bool eventFilter(QObject *obj, QEvent *ev);

    void setTimeOut(int mins);
    int getTimeOut();
    void setMinBrightness(int brightness);
    int getMinBrightness();
    int getAbsoluteMinBrightness();
    void setMaxBrightness(int brightness);
    int getMaxBrightness();
    int getAbsoluteMaxBrightness();
    void setDebug(bool status);
    void adjustBrightness(int brightness);
    void commitBrightness(int brightness);
    int getCurrentBrightness();
    bool getIsAutoSleepEnabled();
    void setAutoSleep(bool autoSleep);

public slots:
    void goToSleep();

};

#endif