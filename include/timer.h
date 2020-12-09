//
// Created by Iron Tony on 08/12/2020.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H


#include "logger.h"

#include <QObject>
#include <QtMultimedia/QSound>
#include <QTimer>

class Timer : public QObject {
Q_OBJECT

    Q_PROPERTY(QString timeOnTimer READ getTimeOnTimer NOTIFY timeOnTimerChanged)
    Q_PROPERTY(bool isActive READ isActive NOTIFY activeChanged)

public:
    explicit Timer(QObject* parent = nullptr);

    Q_INVOKABLE void setInitialTime(const QString& time);
    Q_INVOKABLE void setAlarmSound(const QString& pathToSoundFile);
    Q_INVOKABLE void start();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void reset();
    Q_INVOKABLE void tap();

    bool isActive() const;
    const QString& getTimeOnTimer() const;

signals:
    void timeOnTimerChanged();
    void activeChanged();

private slots:
    void onUpdate();
    void onTimeOut();

private:
    QTimer mTimer;
    QTimer mUpdateTimer;
    QString mTimeOnTimer;
    int mInitialTime = 5000;
    QString mAlarmSoundLocation = "../sound/beep.wav";
    Logger mLogger;

    void updateTime(int remainingTimeMs);
};


#endif //TIMER_TIMER_H
