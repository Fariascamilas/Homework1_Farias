#pragma once

#include <string>
using namespace std;

enum messages{DEBUG = 1, INFO, WARNING, ERROR, CRITICAL, SECURITY};

void logMessage(string message, int severity_level);

void logMessage(string error_message,string archive,int code_line);

void logMessage(string acces_message,string username);