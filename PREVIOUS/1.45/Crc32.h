/*
 *   crc32.h
 */

#ifndef _CRC32_H
#define _CRC32_H

#include  <time.h>

#define   CR                  0x0d
#define   LF                  0x0a

#define CRC_KEY_SUFFIX "-1.42"

//#define   NUM_SEARCH_CHARS    4
//#define   MAX_CAT_PASSWORD    15
//typedef unsigned  long ulong;

extern short RegFailed;
extern short RegSuccess;


void Crc32 ( ulong *crc32, char *s, int blkSize );
int Register ( char * str, char * crc ); //ulong & userCRC );
UINT CRCThread ( LPVOID param );

#endif

