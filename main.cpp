#include "utils/config.h"
#include "utils/logging.h"

int main() {
	// Make sure we are reading in the right folder
	Logger::info("Base dir set to:");
	Logger::info(getCWD());

	Logger::info(readConfig("config.ini"));

	return 0;
}
