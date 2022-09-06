#pragma once 

// Define a data type used by the API
enum LogLevel {
    INFORMATION,
    WARNING,
    ERROR,
};

// Define a class that contains the state and functions
class Logger {
private:
    /// Drop messages whose level is below this threshold.
    LogLevel maxLogLevel;

public:
    /// Constructor
    Logger();

    /// Set the log level. Messages with a level below this threshold will be discarded.
    void setLogLevel(LogLevel newLevel);

    /// Log a new message.
    void log(LogLevel level, const char *msg);
};

// This is a singleton so provide a forward definition so other .cpp files can find the one defined by the driver
extern Logger logger;
