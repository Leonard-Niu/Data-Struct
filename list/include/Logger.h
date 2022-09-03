#ifndef LOGGER_H
#define LOGGER_H


#include <iostream>
#include <string>
#include <fstream>

static const bool globalLogSwitch = true;

enum class Level {
    VERBOSE,
    DEBUG,
    INFO,
    WARNING,
    ERROR,
};

class Logger {
public:
    static bool sGlobalSwitch;
    static void v(std::string TAG, std::string msg);
    static void d(std::string TAG, std::string msg);
    static void i(std::string TAG, std::string msg);
    static void w(std::string TAG, std::string msg);
    static void e(std::string TAG, std::string msg);
    static void f(std::string TAG, std::string msg);

private:
    static std::FILE *sLogFile;
};

#endif