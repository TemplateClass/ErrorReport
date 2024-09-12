#include <Windows.h>
#include <stdio.h>

#include "Define/BasicDefine.h"
#include "MemoryError/MemoryError.h"

int ErrorType = DEFAULT_ERROR;
SYSTEMTIME MainStartTime;

int main() {
	FILE* ConfigFileReader = fopen(CONFIG_FILENAME, "r");
	FILE* LogWriter = fopen(LOG_FILENAME, "at+");
	
	GetLocalTime(&MainStartTime);
	
	fscanf(ConfigFileReader, "%d", &ErrorType);
	
	switch (ErrorType) {
		case 1: {
			MemoryErrorMain(MainStartTime, ConfigFileReader, LogWriter);
			break;
		}
	}
	
	return 0;
}
