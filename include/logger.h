//
// Created by Iron Tony on 08/12/2020.
//

#ifndef TIMER_LOGGER_H
#define TIMER_LOGGER_H


#include <QString>

class Logger {
public:
    enum LogLevel {
        INFO,
        DEBUG,
        WARNING,
        CRITICAL
    };

    void logMessage(const QString& message, LogLevel level);

private:
    const QString LOG_FILE_NAME = "timer.log";
};


#endif //TIMER_LOGGER_H
