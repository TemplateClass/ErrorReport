void ExeErrorMain(FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);
	
	char Text[SIZE] = {}, Title[SIZE] = {};
	
	char ErrorName[SIZE] = "unknown software exception";
	char ErrorCode[SIZE] = "0x00000000";
	char Address[SIZE] = "0x0000000000000000";
	char ErrorProgram[SIZE] = "svchost.exe"; 
	
//	fscanf(ConfigFileReader, "%s%s%s%s", ErrorName, ErrorCode, Address, ErrorProgram);
	sprintf(Text, "应用程序发生异常 %s (%s)，位置为 %s。\n\n要终止程序，请单击“确定”。\n要调试程序，请单击“取消”。", ErrorName, ErrorCode, Address);
	sprintf(Title, "%s - 应用程序错误", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OKCANCEL + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	WriteLog(LogWriter, StartTime, EndTime, "EXE_ERROR", Text, Title, UserChoose);
}
