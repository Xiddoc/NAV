
#ifndef NAV_LOGGING_H
#define NAV_LOGGING_H

#include <cstdio>

class Logger {
private:
	static void baseLog(char prefix, const char* msg);

public:
	static void info(const char* msg);

	static void error(const char* msg);
};

#endif //NAV_LOGGING_H
