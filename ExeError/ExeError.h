void ExeErrorMain(SYSTEMTIME MainStartTime, FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);
	
	char Text[MAX_ARRAY_SIZE] = {}, Title[MAX_ARRAY_SIZE] = {};
	
	char ErrorName[MAX_ARRAY_SIZE] = "unknown software exception";
	char ErrorCode[MAX_ARRAY_SIZE] = "0x00000000";
	char Address[MAX_ARRAY_SIZE] = "0x0000000000000000";
	char ErrorProgram[MAX_ARRAY_SIZE] = "svchost.exe"; 
	
//	fscanf(ConfigFileReader, "%s%s%s%s", ErrorName, ErrorCode, Address, ErrorProgram);
	sprintf(Text, "应用程序发生异常 %s (%s)，位置为 %s。\n\n要终止程序，请单击“确定”。\n要调试程序，请单击“取消”。", ErrorName, ErrorCode, Address);
	sprintf(Title, "%s - 应用程序错误", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OKCANCEL + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	char MainStartTimeString[MAX_ARRAY_SIZE], StartTimeString[MAX_ARRAY_SIZE], EndTimeString[MAX_ARRAY_SIZE];
	GetFormatTime(MainStartTime, MainStartTimeString);
	GetFormatTime(StartTime, StartTimeString); 
	GetFormatTime(EndTime, EndTimeString);
	
	fprintf(LogWriter, "主程序开始运行于 %s。\n", MainStartTimeString);
	fprintf(LogWriter, "本次弹出的错误类型为 EXE_ERROR。\n");
	fprintf(LogWriter, "窗口开始准备创建于 %s。\n", StartTimeString);
	fprintf(LogWriter, "窗口被关闭于 %s。\n", EndTimeString);
	fprintf(LogWriter, "程序显示的信息为：\n%s\n", Text);
	fprintf(LogWriter, "程序显示的标题为：%s\n", Title);
	fprintf(LogWriter, "用户按下的按钮为：%d。（1 为“确定”，2 为“取消”）\n", UserChoose);	
	fprintf(LogWriter, "\n------\n\n");
}
