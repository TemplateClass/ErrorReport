#include <Windows.h>
#include <stdio.h>

#include "Lib/BasicDefine.h"
#include "Lib/BasicFunction.h"
#include "MemoryError/MemoryError.h"
#include "DllMissingError/DllMissingError.h"
#include "ExeError/ExeError.h"

// We must change the way of getting string from config file.
// if we still use fscanf, it cannot read a space and doesnt fit for new error type.
// we have to change fgets, but i dont want to do it now. 

int ErrorType = DEFAULT_ERROR;

int main() {
	initTypeString();
	
	FILE* ConfigFileReader = fopen(CONFIG_FILENAME, "r");
	FILE* LogWriter = fopen(LOG_FILENAME, "at+");
	
	fscanf(ConfigFileReader, "%d", &ErrorType);
	
	switch (ErrorType) {
		case MEMORY_ERROR: {
			MemoryErrorMain(ConfigFileReader, LogWriter);
			break;
		}
		
		case DLL_MISSING_ERROR: {
			DllMissingErrorMain(ConfigFileReader, LogWriter);
			break;
		}
		
		case EXE_ERROR: {
			ExeErrorMain(ConfigFileReader, LogWriter);
			break;
		}
	}
	
	return 0;
}
