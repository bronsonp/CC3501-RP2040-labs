#pragma once 

// Define a data type used by the API
enum LogLevel {
    INFORMATION,
    WARNING,
    ERROR,
};

// Define a structure that contains the state
struct Logger {
    /// Drop messages whose level is below this threshold.
    LogLevel maxLogLevel;
};

// This is a singleton so provide a forward definition so other .cpp files can find the one defined by the driver
extern Logger logger;

// Define the functions

/// Set the log level. Messages with a level below this threshold will be discarded.
void setLogLevel(Logger *logger, LogLevel newLevel);

/// Log a new message.
void log(Logger *logger, LogLevel level, const char *msg);
