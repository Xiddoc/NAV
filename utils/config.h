
#ifndef NAV_CONFIG_H
#define NAV_CONFIG_H

#include <fileapi.h>
#include <windows.h>
#include <cstdio>

char * readConfig(const char* configPath);
char * getCWD();

#endif //NAV_CONFIG_H
