#include <Windows.h>
#include <stdio.h>

#include "Define/BasicDefine.h"
#include "BasicFunction/BasicFunction.h"
#include "MemoryError/MemoryError.h"
#include "DllMissingError/DllMissingError.h"
#include "ExeError/ExeError.h"

int ErrorType = DEFAULT_ERROR;
SYSTEMTIME MainStartTime;

int main() {
	FILE* ConfigFileReader = fopen(CONFIG_FILENAME, "r");
	FILE* LogWriter = fopen(LOG_FILENAME, "at+");
	
	GetLocalTime(&MainStartTime);
	
	fscanf(ConfigFileReader, "%d", &ErrorType);
	
	switch (ErrorType) {
		case MEMORY_ERROR: {
			MemoryErrorMain(MainStartTime, ConfigFileReader, LogWriter);
			break;
		}
		
		case DLL_MISSING_ERROR: {
			DllMissingErrorMain(MainStartTime, ConfigFileReader, LogWriter);
			break;
		}
		
		case EXE_ERROR: {
			ExeErrorMain(MainStartTime, ConfigFileReader, LogWriter);
			break;
		}
	}
	
	return 0;
}
