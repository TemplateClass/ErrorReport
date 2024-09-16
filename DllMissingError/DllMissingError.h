void DllMissingErrorMain(FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);
	
	char Text[SIZE] = {}, Title[SIZE] = {};
	
	char MissingDll[SIZE] = "coredpus.dll";
	char ErrorProgram[SIZE] = "svchost.exe"; 
	
	fscanf(ConfigFileReader, "%s%s", MissingDll, ErrorProgram);
	sprintf(Text, "无法启动此程序，因为计算机中丢失 %s。尝试重新安装该程序以解决此问题。", MissingDll);
	sprintf(Title, "%s - 系统错误", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OK + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	WriteLog(LogWriter, StartTime, EndTime, "DLL_MISSING_ERROR", Text, Title, UserChoose);
}
