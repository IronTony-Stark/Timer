//
// Created by Iron Tony on 08/12/2020.
//

#include <QTime>
#include <QUrl>
#include <QDir>

#include "include/timer.h"

static const char* const kTimeFormat = "mm:ss:zzz";
static const int kUpdateInterval = 30;

Timer::Timer(QObject* parent)
        : QObject(parent), mTimer(this), mUpdateTimer(this) {
    mTimer.setSingleShot(true);
    mTimer.setInterval(mInitialTime);
    mUpdateTimer.setInterval(kUpdateInterval);
    updateTime(mInitialTime);

    connect(&mTimer, &QTimer::timeout, this, &Timer::onTimeOut);
    connect(&mUpdateTimer, &QTimer::timeout, this, &Timer::onUpdate);
}

void Timer::setInitialTime(const QString& time) {
    mInitialTime = QTime::fromString(time, kTimeFormat).msecsSinceStartOfDay();
    mTimer.setInterval(mInitialTime);
    updateTime(mInitialTime);
    mTimeListModel.setStringList({});
}

void Timer::setAlarmSound(const QString& pathToSoundFile) {
    const QUrl url(pathToSoundFile);
    if (url.isLocalFile())
        mAlarmSoundLocation = QDir::toNativeSeparators(url.toLocalFile());
    else
        mAlarmSoundLocation = pathToSoundFile;
    QSound::play(mAlarmSoundLocation);
}

void Timer::start() {
    mTimer.start();
    mUpdateTimer.start();
    emit activeChanged();
}

void Timer::pause() {
    int remaining = mTimer.remainingTime();
    mTimer.stop();
    mTimer.setInterval(remaining);

    mUpdateTimer.stop();
    emit activeChanged();
}

void Timer::reset() {
    mTimer.setInterval(mInitialTime);
    updateTime(mInitialTime);
    mTimeListModel.setStringList({});
}

void Timer::tap() {
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
