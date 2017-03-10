//
//
//   STR.H
//
//   String Class
//
//	Developed by:  Jeff Hill of PCM Computer Systems Pty Ltd
//
//

#ifndef _STR_H
#define _STR_H

#include  <fstream.h>
#include  <string.h>

class String
{
private:
     char*     s;                            // string data
public:
     // constructors
     String ( double );                      // String x = double
     String ( short );                       // String x = short
     String ( unsigned long );               // String x = ulong
     String ( char* );                       // String x = "abc"
     String ( void );                        // String x
     String ( String& );                     // String x = String...
     String ( const String& );               // String x = String...

     // destructor
    ~String ( void );

     // return data
     const char* Get ( void ) const { return s; }

     // information
     int Length ( void ) { return  strlen ( s ); }
     int SubStr ( String & );

     // assignment operators
     String& operator = ( char * );
     String& operator = ( const char * );
     String& operator = ( String& );
     String& operator = ( short );
     String& operator = ( double );
     String& operator = ( int );

     operator char * () { return s; }
     char operator [] ( int );

     // friend operators
     friend String &  operator + ( const String&, const String& );
     friend ostream& operator << ( ostream&, String& );
     friend istream& operator >> ( istream&, String& );

     friend int operator == ( const String& s1, const char* s2 )
     {
          return ( stricmp ( s1.s, s2 ) == 0 );
     }
     friend int operator == ( const char* s1, const String& s2 )
     {
          return ( stricmp ( s1, s2.s ) == 0 );
     }
     friend int operator == ( const String& s1, const String& s2 )
     {
          return ( stricmp ( s1.s, s2.s ) == 0 );
     }
     friend int operator != ( const String& s1, const char* s2 )
     {
          return ( stricmp ( s1.s, s2 ) != 0 );
     }
     friend int operator != ( const String& s1, const String& s2 )
     {
          return ( stricmp ( s1.s, s2.s ) != 0 );
     }

};



#endif
