//
// Created by Iron Tony on 08/12/2020.
//

#include <QDateTime>

#include "include/logger.h"

namespace {
    constexpr const char* const kDateTimeFormat = "dd-MM-yyyy hh:mm:ss";
}

Logger::Logger() {
    mFile.open(LOG_FILE_NAME, std::fstream::app);
}

Logger::~Logger() {
    mFile.close();
}

void Logger::logMessage(const QString& message, Logger::LogLevel level) {
    QString currentDateTime = QDateTime::currentDateTime().toString(kDateTimeFormat);
    mFile << currentDateTime.toStdString() << " " << toString(level) << " " << message.toStdString() << "\n";
}

const char* Logger::toString(Logger::LogLevel level) {
    switch (level) {
        case Logger::INFO:
            return "INFO";
        case Logger::DEBUG:
            return "DEBUG";
        case Logger::WARNING:
            return "WARNING";
        case Logger::CRITICAL:
            return "CRITICAL";
        default:
            return "UNKNOWN LEVEL";
    }
}
