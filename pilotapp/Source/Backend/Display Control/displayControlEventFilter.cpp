#include "displayControlEventFilter.h"

#include "../logManager.h"

#include <QEvent>
#include <QFile>
#include <QDebug>
#include <QTextStream>

const QString filename = "/sys/class/backlight/10-0045/brightness";
QFile file(filename);

displayControlEventFilter::displayControlEventFilter(QObject *parent) : QObject(parent){
    DEBUG           = false;
    TIMEOUT         = 1;
    MIN_BRIGHTNESS  = 12;
    MAX_BRIGHTNESS  = 255;
    isAutoSleepEnabled = true;
    isSleeping      = false;
    lastBrightness  = MAX_BRIGHTNESS;
    inactivityTimer.setInterval(TIMEOUT);
    connect(&inactivityTimer, &QTimer::timeout, this, &displayControlEventFilter::goToSleep);
    inactivityTimer.start();
}

bool displayControlEventFilter::eventFilter(QObject *obj, QEvent *ev){
    if(ev->type() == QEvent::KeyPress || ev->type() == QEvent::MouseMove){
        isSleeping = false;
        inactivityTimer.stop();
        inactivityTimer.start();
        this->adjustBrightness(MAX_BRIGHTNESS);
    }
    return QObject::eventFilter(obj, ev);
}

void displayControlEventFilter::goToSleep(){
    if (isAutoSleepEnabled){
        //qInfo() << "go to sleep called";
        isSleeping = true;
        this->adjustBrightness(MIN_BRIGHTNESS);
    }
}

bool displayControlEventFilter::getIsAutoSleepEnabled(){
    return isAutoSleepEnabled;
}

void displayControlEventFilter::setAutoSleep(bool autoSleep){
    isAutoSleepEnabled = autoSleep;
    if (isAutoSleepEnabled)
        inactivityTimer.start();
    else
        inactivityTimer.stop();
}

void displayControlEventFilter::adjustBrightness(int brightness){
    if(isSleeping){
        if(brightness != lastBrightness){
            lastBrightness = MIN_BRIGHTNESS;
            this->commitBrightness(MIN_BRIGHTNESS);
            //this->debug(QString("Sleep."));
        }
    }
    else{
        if(brightness != lastBrightness){
            lastBrightness = MAX_BRIGHTNESS;
            this->commitBrightness(MAX_BRIGHTNESS);
            //this->debug(QString("Wake up."));
        }
    }
}

void displayControlEventFilter::commitBrightness(int brightness){
    if (file.open(QIODevice::ReadWrite)){
        QTextStream stream( &file );
        stream << brightness << endl;
    }
    else
        this->debug(QString("Unable to open file."));
    file.close();
}

int displayControlEventFilter::getCurrentBrightness(){
    if (file.open(QIODevice::ReadOnly)){
        QString data = file.readAll();
        bool validData = false;
        int brightness = data.toInt(&validData);
        if (validData){
            this->debug("Current Brightness is " + QString::number(brightness));
            file.close();
            return brightness;
        }
    }
    else
        this->debug("Unable to open file.");
    file.close();
    return 0;
}

void displayControlEventFilter::setTimeOut(int mins){
    int timeoutMilli = mins * 1000 * 60;
    this->TIMEOUT = (timeoutMilli < 0 ? (35000) : timeoutMilli); // integer overflow
    this->inactivityTimer.setInterval(this->TIMEOUT);
    logManager::i("Set display timeout at " + std::to_string(TIMEOUT) + " milliseconds or " + std::to_string(mins) + " mins");
}

int displayControlEventFilter::getTimeOut(){
    return this->TIMEOUT / (60000);
}

void displayControlEventFilter::setMinBrightness(int brightness){
    if(brightness < ABS_MIN_BRIGHTNESS && brightness > ABS_MAX_BRIGHTNESS){
        this->debug("Brightness out or range (0-255.");
        return;
    }
    this->MIN_BRIGHTNESS = brightness;
}

int displayControlEventFilter::getMinBrightness(){
    return this->MIN_BRIGHTNESS;
}

int displayControlEventFilter::getAbsoluteMinBrightness(){
    return this->ABS_MIN_BRIGHTNESS;
}

void displayControlEventFilter::setMaxBrightness(int brightness){
    if(brightness < ABS_MIN_BRIGHTNESS && brightness > ABS_MAX_BRIGHTNESS){
        this->debug("Brightness out or range (0-255.");
        return;
    }
    this->MAX_BRIGHTNESS = brightness;
}

int displayControlEventFilter::getMaxBrightness(){
    return this->MAX_BRIGHTNESS;
}

int displayControlEventFilter::getAbsoluteMaxBrightness(){
    return this->ABS_MAX_BRIGHTNESS;
}

void displayControlEventFilter::setDebug(bool status){
    this->DEBUG = status;
}

void displayControlEventFilter::debug(QString message){
    if(DEBUG)
        logManager::d("Display - " + message.toStdString());
}