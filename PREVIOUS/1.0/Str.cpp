//
//
//   STR.CPP
//
//   String Class member functions
//
//	Developed by:  Jeff Hill of PCM Computer Systems Pty Ltd
//                  for Reoforce Systems Pty Ltd
//
//

#include  "stdafx.h"
#include  <stdio.h>
#include  <string.h>
#include  <strstrea.h>
#include  <ctype.h>
//#include  "globals.h"
#include  "str.h"

static const int TmpBuffer = 128;
#define TmpBufSz 128
//
//   String constructors
//

// String x = unsigned long

String::String ( unsigned long num )
{
     char           tmpBuf[TmpBufSz];
     ostrstream     sout ( tmpBuf, sizeof ( tmpBuf ));
     sout << num << ends;

     s = new char[ strlen ( tmpBuf ) + 1 ];
     strcpy ( s, tmpBuf );
}

String::String ( short num )
{
     char           tmpBuf[TmpBufSz];
     ostrstream     sout ( tmpBuf, sizeof ( tmpBuf ));
     sout << num << ends;

     s = new char[ strlen ( tmpBuf ) + 1 ];
     strcpy ( s, tmpBuf );
}

String::String ( double num )
{
     char           tmpBuf[TmpBufSz];
     ostrstream     sout ( tmpBuf, sizeof ( tmpBuf ));
     sout << num << ends;

     s = new char[ strlen ( tmpBuf ) + 1 ];
     strcpy ( s, tmpBuf );
}

// String x = "abc"

String::String ( char* str )
{
     s = new char[ strlen ( str ) + 1 ];
     strcpy ( s, str );
}

// String x

static char empty[2] = { 0, 0 };

//#define empty ""

String::String ( void )
{

     s = new char[strlen ( empty ) + 1];
     strcpy ( s, empty );
}

// String x = String...

String::String ( String& str )
{
     s = new char[ strlen ( str.s ) + 1 ];
     strcpy ( s, str.s );
}

String::String ( const String& str )
{
     s = new char[ strlen ( str.s ) + 1 ];
     strcpy ( s, str.s );
}

String::~String ( void )
{
     delete [] s;
}

static String * result = 0;

String & operator + ( const String& s1, const String& s2 )
{
     char*     str = new char[strlen ( s1.s ) + strlen ( s2.s ) + 1];

     strcpy ( str, s1.s );
     strcat ( str, s2.s );

     if ( result )
          delete result;

     result = new String ( str );

     delete [] str;

     return *result;
}


String& String::operator = ( char * str )
{
     // check out
     delete [] s;

     if ( str )
     {
          s = new char[ strlen ( str ) + 1 ];
          strcpy ( s, str );
     }
     else
     {
          s = new char[strlen ( empty ) + 1];
          strcpy ( s, empty );
     }

     return ( *this );
}


String& String::operator = ( const char * str )
{

     // check out
     // DBP - YES!! Need to put "if ( p != 0 ) dlmSystem_mdlFree" to prevent the MDL error ("bad free")

     delete [] s;

     if ( str )
     {
          s = new char[ strlen ( str ) + 1 ];
          strcpy ( s, str );
     }
     else
     {
     s = new char[strlen ( empty ) + 1];
     strcpy ( s, empty );
//          s = new char[1];
//          *s = 0;
     }

     return ( *this );
}

String& String::operator = ( String& str )
{
     if ( this == &str )
          return ( *this );

     delete [] s;

     s = new char[ strlen ( str.s ) + 1 ];
     strcpy ( s, str.s );

     return ( *this );
}

String& String::operator = ( short val )
{
     delete [] s;

     char           tmpBuf[TmpBufSz];
     ostrstream     sout ( tmpBuf, sizeof ( tmpBuf ));
     sout << val << ends;

     s = new char[ strlen ( tmpBuf ) + 1 ];
     strcpy ( s, tmpBuf );

     return *this;
}

String& String::operator = ( int val )
{
     delete [] s;

     char           tmpBuf[TmpBufSz];
     ostrstream     sout ( tmpBuf, sizeof ( tmpBuf ));
     sout << val << ends;

     s = new char[ strlen ( tmpBuf ) + 1 ];
     strcpy ( s, tmpBuf );

     return *this;
}


String& String::operator = ( double val )
{
     delete [] s;

     char           tmpBuf[TmpBufSz];
     ostrstream     sout ( tmpBuf, sizeof ( tmpBuf ));
     sout << val << ends;

     s = new char[ strlen ( tmpBuf ) + 1 ];
     strcpy ( s, tmpBuf );

     return *this;
}


/* String& String::operator = ( double val )
{
     delete [] s;

     char           tmpBuf[TmpBufSz];
     ostrstream     sout ( tmpBuf, sizeof ( tmpBuf ));
     sout << val << " mm " << ends;

     s = new char[ strlen ( tmpBuf ) + 1 ];
     strcpy ( s, tmpBuf );

     return ( *this );
}
*/
char String::operator [] ( int i )
{
     if ( i > ( int ) strlen ( s ) - 1 )
          return ( 0 );

     return ( s[i] );
}

int String::SubStr ( String & str )
{
     if ( Length () == 0 || str.Length () == 0 )
          return 0;

     if ( Length () > str.Length ())
          return 0;

     char *chptr = s;
     for ( int i = 0; *chptr; i++, chptr++ )
     {
          if ( tolower ( *chptr ) != tolower ( str[i] ))
               return 0;         
     }
     return 1;

//     if ( strstr (( char * ) str, s ) == ( char * ) str )
//          return 1;
//     return 0;
}

ostream& operator << ( ostream& fout, String& str )
{
     // we must write at least a char, or the read will fail
//     char* text = str;
//     fout.write ( ( char * ) text, str.length() + 1 );
//     fout.write ( str, str.length() + 1 );
//     debug << "ostream << " << endl;
     fout.write ( str, str.Length() );
     return fout;
}

strstream& operator << ( strstream& sout, String& str )
{
     // we must write at least a char, or the read will fail
//     char* text = str;
//     fout.write ( ( char * ) text, str.length() + 1 );
//     fout.write ( str, str.length() + 1 );
//     debug << "ostream << " << endl;
     sout.write ( str, str.Length() );
     return sout;
}

istream& operator >> ( istream& fin, String& str )
{
     char tmpStr[TmpBuffer];

     fin.getline ( tmpStr, TmpBuffer, '\0' );
     str = tmpStr;
     return fin;
}

