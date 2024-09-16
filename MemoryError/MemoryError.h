void MemoryErrorMain(FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);
	
	char Text[SIZE] = {}, Title[SIZE] = {};
	
	char Operate[SIZE] = "0x00000000";
	char Address[SIZE] = "0x00000000";
	char CannotBe[SIZE] = "read";
	char ErrorProgram[SIZE] = "svchost.exe"; 
	
	fscanf(ConfigFileReader, "%s%s%s%s", Operate, Address, CannotBe, ErrorProgram);
	sprintf(Text, "\"%s\" 指令引用的 \"%s\" 内存。该内存不能为 \"%s\"。\n\n要终止程序，请单击“确定”。\n要调试程序，请单击“取消”。", Operate, Address, CannotBe);
	sprintf(Title, "%s - 应用程序错误", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OKCANCEL + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	WriteLog(LogWriter, StartTime, EndTime, "MEMORY_ERROR", Text, Title, UserChoose);
}
