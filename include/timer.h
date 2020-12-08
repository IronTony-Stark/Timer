//
// Created by Iron Tony on 08/12/2020.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H


#include "logger.h"
#include <QObject>
#include <QtMultimedia/QSound>

class Timer : public QObject {
Q_OBJECT

public:
    explicit Timer(QObject* parent = nullptr);

    void setInitialTime(const QString& time);

    void setAlarmSound(const QString& pathToSoundFile);

    void start();

    void pause();

    void reset();

    void tap();

    bool isActive();

private:
    QString timeOnTimer;
    QSound alarmSound;
    Logger logger;
};


#endif //TIMER_TIMER_H
