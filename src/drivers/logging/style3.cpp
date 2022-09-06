// Logging system, style 3 (state is defined in a C++ class)

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#include "drivers/logging/style3.h"

// --- Device driver internal state:
Logger logger;

// --- Device driver functions
Logger::Logger()
{
    this->maxLogLevel = LogLevel::INFORMATION;
}

void Logger::setLogLevel(LogLevel newLevel)
{
    this->maxLogLevel = newLevel;
}

void Logger::log(LogLevel level, const char *msg)
{
    // Should we show this message?
    if (level < this->maxLogLevel) {
        return;
    }

    // Get the time since boot
    uint32_t time = to_ms_since_boot(get_absolute_time());
    uint32_t time_sec = time / 1000;
    uint32_t time_decimal = (time % 1000);

    // Convert the level to a string
    const char *levelStr;
    switch (level) {
        case LogLevel::INFORMATION:
            levelStr = "Information";
            break;
        case LogLevel::WARNING:
            levelStr = "Warning";
            break;
        case LogLevel::ERROR:
            levelStr = "Error";
            break;
        
    };
    printf("[%u.%03u %s]: %s\n", time_sec, time_decimal, levelStr, msg);
}
