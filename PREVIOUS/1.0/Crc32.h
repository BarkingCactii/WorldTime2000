/*
 *   crc32.h
 */

#ifndef _CRC32_H
#define _CRC32_H

#include  <time.h>

#define   CR                  0x0d
#define   LF                  0x0a

//#define   NUM_SEARCH_CHARS    4
//#define   MAX_CAT_PASSWORD    15
//typedef unsigned  long ulong;

extern short RegFailed;
extern short RegSuccess;


int Register ( char * str, ulong & userCRC );

#endif

