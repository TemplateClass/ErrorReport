void DllMissingErrorMain(SYSTEMTIME MainStartTime, FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);
	
	char Text[MAX_ARRAY_SIZE] = {}, Title[MAX_ARRAY_SIZE] = {};
	
	char MissingDll[MAX_ARRAY_SIZE] = "coredpus.dll";
	char ErrorProgram[MAX_ARRAY_SIZE] = "svchost.exe"; 
	
	fscanf(ConfigFileReader, "%s%s", MissingDll, ErrorProgram);
	sprintf(Text, "无法启动此程序，因为计算机中丢失 %s。尝试重新安装该程序以解决此问题。", MissingDll);
	sprintf(Title, "%s - 系统错误", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OK + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	char MainStartTimeString[MAX_ARRAY_SIZE], StartTimeString[MAX_ARRAY_SIZE], EndTimeString[MAX_ARRAY_SIZE];
	GetFormatTime(MainStartTime, MainStartTimeString);
	GetFormatTime(StartTime, StartTimeString); 
	GetFormatTime(EndTime, EndTimeString);
	
	fprintf(LogWriter, "主程序开始运行于 %s。\n", MainStartTimeString);
	fprintf(LogWriter, "本次弹出的错误类型为 DLL_MISSING_ERROR。\n");
	fprintf(LogWriter, "窗口开始准备创建于 %s。\n", StartTimeString);
	fprintf(LogWriter, "窗口被关闭于 %s。\n", EndTimeString);
	fprintf(LogWriter, "程序显示的信息为：\n%s\n", Text);
	fprintf(LogWriter, "程序显示的标题为：%s\n", Title);
	fprintf(LogWriter, "\n------\n\n");
}
