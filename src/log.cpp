/*
 *  File: log.cpp
 *  Last Updated: 11/04/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#include "log.h"
#include <iostream>
#include <sstream>
#include <time.h>
#include <string>

using namespace std;
using namespace Polymorphic;

bool Log::Initialize(string file_name) {
    if (initialized) {
        return initialized;
    } else {
        logf.open(file_name.c_str(), ios::out | ios::app);
        
        if(logf.is_open()) {
            initialized = true;
            LogMessage("Starting", "Log System initialized successfuly!");
            return true;
        } else {
            initialized = false;
            return false;
        }
    }

    return true;
}

void Log::LogMessage(string title, string msg) {
    time_t raw_time;
    struct tm *timeinfo;

    time(&raw_time);
    timeinfo = localtime(&raw_time);

    if (initialized) {
          logf << "[" << timeinfo->tm_mday << "-" << timeinfo->tm_mon << "-" << (1900+timeinfo->tm_year) << " " << timeinfo->tm_hour << ":" << timeinfo->tm_min << ":" << timeinfo->tm_sec << "]" << title << ": " << msg << endl;
    }
}

void Log::Shutdown() {
    if (initialized) {
        LogMessage("Warn", "Shutting down Log System");
        initialized = false;
        logf.close();
    }
}

bool Log::Initialized() {
    return initialized;
}
