//
// Created by Iron Tony on 08/12/2020.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H


#include <QObject>
#include <QtMultimedia/QSound>
#include <QTimer>
#include <QStringListModel>

#include "logger.h"

class Timer : public QObject {
Q_OBJECT

    Q_PROPERTY(QString timeOnTimer READ getTimeOnTimer NOTIFY timeOnTimerChanged)
    Q_PROPERTY(bool isActive READ isActive NOTIFY activeChanged)

public:
    explicit Timer(Logger& logger, QObject* parent = nullptr);

    Q_INVOKABLE void setInitialTime(const QString& time);
    Q_INVOKABLE void setAlarmSound(const QString& pathToSoundFile);
    Q_INVOKABLE void start();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void reset();
    Q_INVOKABLE void tap();

    QStringListModel& getTimeListModel();

    bool isActive() const;
    const QString& getTimeOnTimer() const;

signals:
    void timeOnTimerChanged();
    void activeChanged();

private slots:
    void onUpdate();
    void onTimeOut();

private:
    void updateTime(int remainingTimeMs);

    QTimer mTimer;
    QTimer mUpdateTimer;
    QString mTimeOnTimer;
    int mInitialTime = 5000;
    QString mAlarmSoundLocation = "../sound/beep.wav";
    QStringListModel mTimeListModel;
    Logger& mLogger;
};


#endif //TIMER_TIMER_H
