
#include "logging.h"

void Logger::baseLog(char prefix, const char *msg) {
	printf("[%c] %s\n", prefix, msg);
}

void Logger::info(const char *msg) {
	baseLog('+', msg);
}

void Logger::error(const char *msg) {
	baseLog('!', msg);
}
