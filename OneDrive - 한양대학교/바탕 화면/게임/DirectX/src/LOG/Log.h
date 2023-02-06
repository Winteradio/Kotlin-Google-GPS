#ifndef __SUBLOG_H__
#define __SUBLOG_H__

// Setting for see console Debug Log Message
#pragma comment(linker, "/entry:WinMainCRTStartup")
#pragma comment(linker, "/subsystem:console")

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctime>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define LOG_WARN(str, ...) LOG_print("WARN", __FILENAME__, __FUNCTION__, __LINE__, str, ##__VA_ARGS__)
#define LOG_ERROR(str, ...) LOG_print("ERROR", __FILENAME__, __FUNCTION__, __LINE__, str, ##__VA_ARGS__)
#define LOG_INFO(str, ...) LOG_print("INFO", __FILENAME__, __FUNCTION__, __LINE__, str, ##__VA_ARGS__)
#define LOG_DEBUG(str, ...) LOG_print("DEBUG", __FILENAME__, __FUNCTION__, __LINE__, str, ##__VA_ARGS__)
#define LOG_TRACE(str, ...) LOG_print("TRACE", __FILENAME__, __FUNCTION__, __LINE__, str, ##__VA_ARGS__)
#define LOG_ALL(str, ...) LOG_print("ALL", __FILENAME__, __FUNCTION__, __LINE__)printf(str, ##__VA_ARGS__, "\n")

#define LOG_NONE 0
#define LOG_LOW 1
#define LOG_HIGH 2

namespace LOG
{
	extern int LEVEL;
};

inline void LOG_print(const char* log_type,
	const char* filename,
	const char* funcname,
	const int linenum,
	const char* str, ...)
{
	time_t timer = time(NULL);
	tm time;
	localtime_s( &time, &timer );

	va_list List;
	va_start(List,str);
	if ( LOG::LEVEL >= LOG_NONE )
	{
		printf("%d:%d:%d ", time.tm_hour, time.tm_min, time.tm_sec );
	}
	else if ( LOG::LEVEL >= LOG_LOW )
	{
		printf("%s | ", log_type);
	}
	else if ( LOG::LEVEL == LOG_HIGH )
	{
		printf("FILE : %s / FUNC : %s / NUM : %d | ", filename, funcname, linenum);
	}
	vprintf(str,List);
	va_end(List);
	printf("\n");
}

#endif // __SUBLOG_H__