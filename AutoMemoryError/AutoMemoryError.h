SYSTEMTIME StartTime, EndTime;

void GetFormatTime(SYSTEMTIME Time, char* TimeString) {
	sprintf(TimeString, "%04d/%02d/%02d %02d:%02d:%02d.%03d",
		Time.wYear, Time.wMonth, Time.wDay, Time.wHour, 
		Time.wMinute, Time.wSecond, Time.wMilliseconds
	);
} 

void MemoryErrorMain(SYSTEMTIME MainStartTime, FILE* ConfigFileReader, FILE* LogWriter) {
	GetLocalTime(&StartTime);
	
	char Text[MAX_ARRAY_SIZE] = {}, Title[MAX_ARRAY_SIZE] = {};
	
	char Operate[MAX_ARRAY_SIZE] = "0x00000000";
	char Address[MAX_ARRAY_SIZE] = "0x00000000";
	char CannotBe[MAX_ARRAY_SIZE] = "read";
	char ErrorProgram[MAX_ARRAY_SIZE] = "svchost.exe"; 
	
	fscanf(ConfigFileReader, "%s%s%s%s", Operate, Address, CannotBe, ErrorProgram);
	sprintf(Text, "\"%s\" 指令引用的 \"%s\" 内存。该内存不能为 \"%s\"。\n\n要终止程序，请单击“确定”。\n要调试程序，请单击“取消”。", Operate, Address, CannotBe);
	sprintf(Title, "%s - 应用程序错误", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OKCANCEL + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	char MainStartTimeString[MAX_ARRAY_SIZE], StartTimeString[MAX_ARRAY_SIZE], EndTimeString[MAX_ARRAY_SIZE];
	GetFormatTime(MainStartTime, MainStartTimeString);
	GetFormatTime(StartTime, StartTimeString); 
	GetFormatTime(EndTime, EndTimeString);
	
	fprintf(LogWriter, "主程序开始运行于 %s。\n", MainStartTimeString);
	fprintf(LogWriter, "本次弹出的错误类型为 MEMORY_ERROR。\n");
	fprintf(LogWriter, "窗口开始准备创建于 %s。\n", StartTimeString);
	fprintf(LogWriter, "窗口被关闭于 %s。\n", EndTimeString);
	fprintf(LogWriter, "程序显示的信息为：\n%s\n", Text);
	fprintf(LogWriter, "程序显示的标题为：%s\n", Title);
	fprintf(LogWriter, "用户按下的按钮为：%d。（1 为“确定”，2 为“取消”）\n", UserChoose);	
	fprintf(LogWriter, "\n------\n\n");
}
