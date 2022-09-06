#pragma once 

// Define a data type used by the API
enum LogLevel {
    INFORMATION,
    WARNING,
    ERROR,
};

// Define the functions

/// Set the log level. Messages with a level below this threshold will be discarded.
void setLogLevel(LogLevel newLevel);

/// Log a new message.
void log(LogLevel level, const char *msg);
