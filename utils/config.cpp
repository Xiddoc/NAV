
#include "config.h"

char* readConfig(const char *configPath) {
	// Create file handle
	HANDLE ptr = CreateFileA(configPath, GENERIC_READ, 0,nullptr,
							 OPEN_EXISTING, FILE_READ_ATTRIBUTES, nullptr);
	if (ptr == INVALID_HANDLE_VALUE) return nullptr;

	// Get file size to declare buffer
	// Assumes the config is not larger than 3 gigabytes in size, at which point it
	// this function might fail if the file is exactly 0xffffffff bytes in size.
	DWORD fileSize = GetFileSize(ptr, nullptr);
	if (fileSize == INVALID_FILE_SIZE) return nullptr;

	// Create a buffer and copy the contents to it
	char* configBuf = (char*) malloc(fileSize);
	// Make sure we read the entire file
	auto readBytes = (LPDWORD) malloc(sizeof(LPDWORD));
	if (readBytes == nullptr) return nullptr;
	// Read synchronously
	int status = ReadFile(ptr, configBuf, fileSize, readBytes, nullptr);

	// Check that we read the entire file
	if (status == 0 || *readBytes != fileSize) return nullptr;

	// Return file contents
	return configBuf;
}

char *getCWD() {
	// Get size
	int cwdSize = GetCurrentDirectory(0, nullptr);

	// Create buffer with size and get CWD
	char* cwd = (char*) malloc(cwdSize);
	if (cwd == nullptr) return nullptr;

	int status = GetCurrentDirectory(cwdSize, cwd);
	if (status == 0) return nullptr;

	// Give back the ptr to our CWD
	return cwd;
}
