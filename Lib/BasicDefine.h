#include <Windows.h>
#include <string.h>

#define SIZE 255

#define CONFIG_FILENAME "Config.ini"
#define LOG_FILENAME "ErrorReportLog.log"

#define MEMORY_ERROR 1
#define DLL_MISSING_ERROR 2
#define EXE_ERROR 3 

#define DEFAULT_ERROR MEMORY_ERROR

char ButtonPressType[SIZE][SIZE];
char IconType[SIZE][SIZE];
char ButtonType[SIZE][SIZE];

void initTypeString() {
	strcpy(ButtonPressType[IDOK], "确定");
	strcpy(ButtonPressType[IDCANCEL], "取消");
	strcpy(ButtonPressType[IDABORT], "终止");
	strcpy(ButtonPressType[IDRETRY], "重试");
	strcpy(ButtonPressType[IDIGNORE], "忽略");
	strcpy(ButtonPressType[IDYES], "是");
	strcpy(ButtonPressType[IDNO], "否");
	strcpy(ButtonPressType[IDTRYAGAIN], "重试");
	strcpy(ButtonPressType[IDCONTINUE], "继续");
}
