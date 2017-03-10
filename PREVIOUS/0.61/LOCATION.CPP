// Location.cpp
//

#include "stdafx.h"
#include "resource.h"
#include "location.h"
#include "WorldTime2000.h"
#include "WorldTime2000view.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

Locations l;

bifstream & operator >> ( bifstream & fin, LocationItem & data )
{
    fin >> data.name >> data.offset >> data.dsEnable;
        fin >> data.dsStartWeek >> data.dsStartDay >> data.dsStartMonth;
        fin >> data.dsEndWeek >> data.dsEndDay >> data.dsEndMonth;

        return fin;
}

bofstream & operator << ( bofstream & fout, LocationItem & data )
{
    fout << data.name << data.offset << data.dsEnable;
        fout << data.dsStartWeek << data.dsStartDay << data.dsStartMonth;
        fout << data.dsEndWeek << data.dsEndDay << data.dsEndMonth;

        return fout;
}

float Locations::GMTOffset ( int idx )
{ 
        if ( idx < ll.Size()) 
               return ll.Nth ( idx )->offset;
        else 
             return 0.0f; 
}

float Locations::OffsetList ( int idx )
{ 
        if ( idx < ll.Size()) 
        {
                float dst = 0.0;
            CTime ti = CTime::GetCurrentTime();
                if ( view->DaylightSavings ( GetLocation ( idx ), &ti ))
                        dst = 1.0;

                return ll.Nth ( idx )->offset + dst; 
        }
        else 
                return 0.0f; 
}


void Locations::ResetOffset ( void )
{
        view->selected = 0;
}

List dayList[] = { 
        { 0, "Sunday" },
        { 1, "Monday" },
        { 2, "Tuesday" },
        { 3, "Wednesday" },
        { 4, "Thursday" },
        { 5, "Friday" },
        { 6, "Saturday" },
};

List weekList[] = { 
        { 0, "First" },
        { 1, "Second" },
        { 2, "Third" },
        { 3, "Fourth" },
        { 4, "Last" },
};

List monthList[] = { 
        { 0, "January" },
        { 1, "February" },
        { 2, "March" },
        { 3, "April" },
        { 4, "May" },
        { 5, "June" },
        { 6, "July" },
        { 7, "August" },
        { 8, "September" },
        { 9, "October" },
        { 10, "November" },
        { 11, "December" },
};


Locations::Locations ( void  )
{
        version = 2;
        selected = 0;
                        homeName = "Home";
//                    _24hour = 0;
//#define CREATENEW
#ifndef CREATENEW
        bifstream bin ( "WorldTime2000.dat" );

                         char c;
                         bin >> c;

                         if ( bin.eof () || !bin )
                         {
                bin.close ();
                                return;
                        }

                        bin.seekg ( 0 );
        short	numLocations;
        bin >> version >> selected >> numLocations >> homeName;

                        bin >> p;

		bin >> frameRect.top >> frameRect.left >> frameRect.bottom >> frameRect.right;



        for ( int i = 0; i < numLocations; i++ )
        {
                LocationItem * aItem = new LocationItem;
                                        bin >> *aItem;
//                        bin >> aItem->name >> aItem->offset;
                ll.Add ( aItem );
        }

        short numDisplays;

        bin >> numDisplays;
        for ( i = 0; i < numDisplays; i++ )
        {
                short * aItem = new short;
                bin >> *aItem;
                d.Add ( aItem );
        }

        bin.close ();
#else
        ifstream fin ( "default.txt" );
        while ( !fin.eof() )
        {
             char buf[255];
             fin.getline ( buf, sizeof ( buf ));

             if ( strlen ( buf ) == 0)
                  break;

             char town[100];
             char country[100];
                         char dst[255];
                         town[0] = country[0] = dst[0] = 0;
             LocationItem * aItem = new LocationItem;
             sscanf ( buf, "%23[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz `'-.] %26[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz `'-.] %f %[^\n]", town, country, &aItem->offset, dst );

                         // remove trailing spaces
                         for ( int i = strlen ( town ) - 1; town[i] == ' '; i-- )
                                 town[i] = 0;
                         for ( i = strlen ( country ) - 1; country[i] == ' '; i-- )
                                 country[i] = 0;

             aItem->name = town;
             aItem->name = aItem->name + ", ";
             aItem->name = aItem->name + country;

                        aItem->dsStartWeek = -1;
                        aItem->dsStartDay = -1;
                        aItem->dsStartMonth = -1;
                        aItem->dsEndWeek = -1;
                        aItem->dsEndDay = -1;
                        aItem->dsEndMonth = -1;
                 aItem->dsEnable = 1;


                 char timeStr[4][255];
             sscanf ( dst, "%s %s %s %s", timeStr[0], timeStr[1], timeStr[2], timeStr[3] );

                         if ( timeStr[0][0] == '<' )
                         {
                                 aItem->dsEnable = 0;
                     ll.Add ( aItem );
                                 continue;
                         }

                         for ( i = 0; i < sizeof ( weekList ) / sizeof ( List ); i++ )
                         {
                                 if ( !stricmp ( timeStr[0], weekList[i].name ))
                                 {
                                        aItem->dsStartWeek = i;
                                        break;
                                 }

                         }

                         for ( i = 0; i < sizeof ( dayList ) / sizeof ( List ); i++ )
                         {
                                 if ( !stricmp ( timeStr[1], dayList[i].name ))
                                 {
                                        aItem->dsStartDay = i;
                                        break;
                                 }

                         }

                         for ( i = 0; i < sizeof ( monthList ) / sizeof ( List ); i++ )
                         {
                                 if ( !stricmp ( timeStr[3], monthList[i].name ))
                                 {
                                        aItem->dsStartMonth = i;
                                        break;
                                 }

                         }

             sscanf ( &dst[34], "%s %s %s %s", timeStr[0], timeStr[1], timeStr[2], timeStr[3] );

                         for ( i = 0; i < sizeof ( weekList ) / sizeof ( List ); i++ )
                         {
                                 if ( !stricmp ( timeStr[0], weekList[i].name ))
                                 {
                                        aItem->dsEndWeek = i;
                                        break;
                                 }

                         }

                         for ( i = 0; i < sizeof ( dayList ) / sizeof ( List ); i++ )
                         {
                                 if ( !stricmp ( timeStr[1], dayList[i].name ))
                                 {
                                        aItem->dsEndDay = i;
                                        break;
                                 }

                         }

                         for ( i = 0; i < sizeof ( monthList ) / sizeof ( List ); i++ )
                         {
                                 if ( !stricmp ( timeStr[3], monthList[i].name ))
                                 {
                                        aItem->dsEndMonth = i;
                                        break;
                                 }

                         }


                                if ( aItem->dsStartWeek == -1 ||
                        aItem->dsStartDay == -1 ||
                        aItem->dsStartMonth == -1 ||
                        aItem->dsEndWeek == -1 ||
                        aItem->dsEndDay == -1 ||
                        aItem->dsEndMonth == -1 )
                    MessageBox ( NULL, "Unknown dst option", NULL, MB_ICONEXCLAMATION );




//             aItem->name = buf;
             ll.Add ( aItem );
       }
       fin.close ();
#endif
}

Locations::~Locations ( void )
{
        bofstream bout ( "WorldTime2000.dat" );

        bout << version << selected << ( short ) ll.Size() << homeName; // << _24hour;

        bout << p;

//		CRect frameRect;
//		theApp.m_pMainWnd->GetWindowRect ( &frameRect );
		bout << frameRect.top << frameRect.left << frameRect.bottom << frameRect.right;


        for ( int i = 0; i < ll.Size(); i++ )
        {
                LocationItem * aItem = ll.Nth ( i );
                bout << *aItem; //aItem->name << aItem->offset;
        }

        bout << ( short ) d.Size();
        for ( i = 0; i < d.Size(); i++ )
        {
                short * aItem = d.Nth ( i );
                bout << *aItem;
        }

        bout.close();
}
