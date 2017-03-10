#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <iostream.h>
#include <strstrea.h>

int main ( void )
{
     long buildNum = 0;
     char buf[100];

     ifstream fin;

     fin.open ( "build.dat" );

     fin >> buildNum;
     if ( fin.eof () && !fin )
          buildNum = 0;
     fin.close ();

     buildNum++;

     ofstream fout;

     fout.open ( "build.dat" );

     fout << buildNum;

     fout.close ();

     fout.open ( "build.inc" );
     fout << "IDR_MAINFRAME \"WorldTime2003" << " Build # " << buildNum << "\"" << endl;
     fout.close ();

     cout << "Current Build # -> " << --buildNum << endl;

     return 0;
}
