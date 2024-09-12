void GetFormatTime(SYSTEMTIME Time, char* TimeString) {
	sprintf(TimeString, "%04d/%02d/%02d %02d:%02d:%02d.%03d",
		Time.wYear, Time.wMonth, Time.wDay, Time.wHour, 
		Time.wMinute, Time.wSecond, Time.wMilliseconds
	);
} 
