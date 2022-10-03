/*
 * log.c
 *
 *  Created on: Oct 3, 2022
 *      Author: Szymon
 */
#include "log.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

// TODO: dodac kolejki i jakis nieblokujacy sposob wysylania
// ale to pewnie w jakiejs oddzielnej bibliotece bedzie (?)

/* PRIVATE */

char buffer[LOG_BUFFER_SIZE];

const char* end_of_log = LOG_END_OF_LOG;

const char* lvl_error 	= "[ERROR]";
const char* lvl_warning = "[WARN]";
const char* lvl_info 	= "[INFO]";
const char* lvl_debug	= "[DEBUG]";
const char* lvl_verbose	= "[VERBOSE]";


uint32_t _GetSystime(void) {
	return HAL_GetTick();
}


void _PrintLog(uint32_t systime, const char* lvl, const char* tag, char* str) {

	char time_lvl_tag[32];
	int len = sprintf(time_lvl_tag, "%ld:\t%s [%s] ", systime, lvl, tag);

	HAL_UART_Transmit(&huart1, (const uint8_t *)time_lvl_tag, (uint16_t)len, 10);
	HAL_UART_Transmit(&huart1, (const uint8_t *)str, strlen(str), 10);
	HAL_UART_Transmit(&huart1, (const uint8_t *)end_of_log, strlen(end_of_log), 10);
}


void _Log(const char* lvl, const char* tag, char* string, ...) {

	uint32_t systime = _GetSystime();

	va_list args;
	va_start(args, string);
	vsprintf(buffer, (const char *)string, args);

	_PrintLog(systime, lvl, tag, buffer);

	va_end(args);
}

/* PUBLIC */

// TODO: dokonczyc biblioteke

// FIXME: naprawic wyswietlanie argumentow


void Log_Error(const char* tag, char* string, ...) {

#if (LOG_LEVEL >= LOG_LEVEL_ERROR)
	va_list args;
	uint32_t systime = _GetSystime();
	vsprintf(buffer, (const char *)string, args);
	_PrintLog(systime, lvl_error, tag, buffer);
	va_end(args);
#endif

}

void Log_Warning(const char* tag, char* string, ...) {

#if (LOG_LEVEL >= LOG_LEVEL_WARNING)
	_Log(lvl_warning, tag, string);
#endif

}

void Log_Info(const char* tag, char* string, ...) {

#if (LOG_LEVEL >= LOG_LEVEL_INFO)
	_Log(lvl_info, tag, string);
#endif

}

void Log_Debug(const char* tag, char* string, ...) {

#if (LOG_LEVEL >= LOG_LEVEL_DEBUG)
	_Log(lvl_debug, tag, string);
#endif

}

void Log_Verbose(const char* tag, char* string, ...) {

#if (LOG_LEVEL >= LOG_LEVEL_VERBOSE)
	_Log(lvl_verbose, tag, string);
#endif

}






