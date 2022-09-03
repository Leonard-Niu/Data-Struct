#include "../include/Logger.h"

bool Logger::sGlobalSwitch = globalLogSwitch;
std::FILE *Logger::sLogFile = stdout;

void Logger::d(std::string TAG, std::string msg) {
    if (sGlobalSwitch) {
        std::string target = "TAG-" + TAG + ":" + msg + "\n";
        fprintf(sLogFile, target.c_str());
    }
}