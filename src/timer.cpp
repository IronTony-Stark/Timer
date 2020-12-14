//
// Created by Iron Tony on 08/12/2020.
//

#include <QTime>
#include <QUrl>
#include <QDir>

#include "include/timer.h"

static const char* const kTimeFormat = "mm:ss:zzz";
static const int kUpdateInterval = 30;

Timer::Timer(Logger& logger, QObject* parent)
        : QObject(parent), mTimer(this), mUpdateTimer(this), mLogger(logger) {
    mLogger.logMessage("Create Timer", Logger::INFO);

    mTimer.setSingleShot(true);
    mTimer.setInterval(mInitialTime);
    mUpdateTimer.setInterval(kUpdateInterval);
    updateTime(mInitialTime);

    connect(&mTimer, &QTimer::timeout, this, &Timer::onTimeOut);
    connect(&mUpdateTimer, &QTimer::timeout, this, &Timer::onUpdate);
}

void Timer::setInitialTime(const QString& time) {
    mLogger.logMessage("Set Initial Time: " + time, Logger::INFO);

    mInitialTime = QTime::fromString(time, kTimeFormat).msecsSinceStartOfDay();
    mTimer.setInterval(mInitialTime);
    updateTime(mInitialTime);
    mTimeListModel.setStringList({});
}

void Timer::setAlarmSound(const QString& pathToSoundFile) {
    mLogger.logMessage("Set Alarm Sound: " + pathToSoundFile, Logger::INFO);

    const QUrl url(pathToSoundFile);
    if (url.isLocalFile())
        mAlarmSoundLocation = QDir::toNativeSeparators(url.toLocalFile());
    else
        mAlarmSoundLocation = pathToSoundFile;
    QSound::play(mAlarmSoundLocation);
}

void Timer::start() {
    mLogger.logMessage("Start", Logger::INFO);

    mTimer.start();
    mUpdateTimer.start();
    emit activeChanged();
}

void Timer::pause() {
    mLogger.logMessage("Pause", Logger::INFO);

    int remaining = mTimer.remainingTime();
    mTimer.stop();
    mTimer.setInterval(remaining);

    mUpdateTimer.stop();
    emit activeChanged();
}

void Timer::reset() {
    mLogger.logMessage("Reset", Logger::INFO);

    mTimer.setInterval(mInitialTime);
    updateTime(mInitialTime);
    mTimeListModel.setStringList({});
}

void Timer::tap() {
    mLogger.logMessage("Tap", Logger::INFO);

    if (mTimeListModel.insertRow(0)) {
        QModelIndex index = mTimeListModel.index(0, 0);
        mTimeListModel.setData(index, mTimeOnTimer);
    }
}

QStringListModel& Timer::getTimeListModel() {
    return mTimeListModel;
}

bool Timer::isActive() const {
    return mTimer.isActive();
}

const QString& Timer::getTimeOnTimer() const {
    return mTimeOnTimer;
}

void Timer::onUpdate() {
    int remainingTime = mTimer.remainingTime();
    updateTime(remainingTime);
}

void Timer::onTimeOut() {
    mLogger.logMessage("Time Out", Logger::INFO);

    mUpdateTimer.stop();
    QSound::play(mAlarmSoundLocation);
    updateTime(0);
    mTimer.setInterval(0);
    emit activeChanged();
}

void Timer::updateTime(int remainingTimeMs) {
    QTime time = QTime::fromMSecsSinceStartOfDay(remainingTimeMs);
    mTimeOnTimer = time.toString(kTimeFormat);
    emit timeOnTimerChanged();
}
