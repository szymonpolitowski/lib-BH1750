/*
 * log.h
 *
 *  Created on: Oct 3, 2022
 *      Author: Szymon
 */

#ifndef LOG_LOG_H_
#define LOG_LOG_H_
#include <stdarg.h>

#define LOG_LEVE_NONE		0
#define LOG_LEVEL_ERROR		1
#define LOG_LEVEL_WARNING	2
#define LOG_LEVEL_INFO		3
#define LOG_LEVEL_DEBUG		4
#define LOG_LEVEL_VERBOSE	5

#define LOG_LEVEL			LOG_LEVEL_DEBUG


#define LOG_BUFFER_SIZE		128

#define LOG_END_OF_LOG		"\r\n"


void Log_Error(const char* tag, char* string, ...);

void Log_Warning(const char* tag, char* string, ...);

void Log_Info(const char* tag, char* string, ...);

void Log_Debug(const char* tag, char* string, ...);

void Log_Verbose(const char* tag, char* string, ...);


#endif /* LOG_LOG_H_ */
