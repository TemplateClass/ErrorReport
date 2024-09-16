void GetFormatTime(SYSTEMTIME Time, char* TimeString) {
	sprintf(TimeString, "%04d/%02d/%02d %02d:%02d:%02d.%03d",
		Time.wYear, Time.wMonth, Time.wDay, Time.wHour, 
		Time.wMinute, Time.wSecond, Time.wMilliseconds
	);
}

void WriteLog(FILE* LogWriter, SYSTEMTIME StartTime, SYSTEMTIME EndTime, char* ErrorType, char* Text, char* Title, int UserChoose) {
	char StartTimeString[SIZE], EndTimeString[SIZE];
	GetFormatTime(StartTime, StartTimeString); 
	GetFormatTime(EndTime, EndTimeString);
	
	fprintf(LogWriter, "本次弹出的错误类型为 %s。\n", ErrorType);
	fprintf(LogWriter, "窗口开始准备创建于 %s。\n", StartTimeString);
	fprintf(LogWriter, "窗口被关闭于 %s。\n", EndTimeString);
	fprintf(LogWriter, "程序显示的信息为：\n%s\n", Text);
	fprintf(LogWriter, "程序显示的标题为：%s\n", Title);
	fprintf(LogWriter, "用户按下的按钮为：%s。\n", ButtonPressType[UserChoose]);	
	fprintf(LogWriter, "\n------\n\n");
}
