//
// Created by Iron Tony on 08/12/2020.
//

#ifndef TIMER_LOGGER_H
#define TIMER_LOGGER_H


#include <QString>
#include <fstream>
#include <QObject>

class Logger : public QObject {
Q_OBJECT

public:
    enum LogLevel {
        INFO,
        DEBUG,
        WARNING,
        CRITICAL
    };

    Logger();
    ~Logger() override;

    void logMessage(const QString& message, LogLevel level);
    Q_INVOKABLE void logInfo(const QString& message) {
        logMessage(message, INFO);
    }

private:
    static const char* toString(Logger::LogLevel level);

    const char* const LOG_FILE_NAME = "timer.log";
    std::fstream mFile;
};


#endif //TIMER_LOGGER_H
