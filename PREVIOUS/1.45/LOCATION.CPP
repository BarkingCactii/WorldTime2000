// Location.cpp
//

#include "stdafx.h"
#include "resource.h"
#include "location.h"
#include "WorldTime2000.h"
#include "WorldTime2000view.h"
#include "register.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#define VERSION 1.42f

int debugMode = 0;

ofstream fout ( "worldtime2000.debug" );
void DEBUGLINE ( char * file, int line ) 
{
		if ( debugMode )
		{
		char * ptr = file + strlen ( file );
		while ( *ptr != '\\' )
			ptr--;
		if ( line == 207 )
			ptr = file;
        fout << ptr << " line " << line << endl << flush;
        }
}


Locations l;
extern short showToolbar, showStatusBar;
static char dataPath[255];
static char programPath[255];

bifstream & operator >> ( bifstream & fin, LocationItem & data )
{
        DEBUGLINE ( __FILE__, __LINE__ );
    fin >> data.name >> data.offset >> data.dsEnable;
        fin >> data.dsStartWeek >> data.dsStartDay >> data.dsStartMonth;
        fin >> data.dsEndWeek >> data.dsEndDay >> data.dsEndMonth;
        fin >> data.alarmEnable >> data.alarmHour >> data.alarmMinute >> data.alarmMessage;

        return fin;
}

bofstream & operator << ( bofstream & fout, LocationItem & data )
{
        DEBUGLINE ( __FILE__, __LINE__ );
    fout << data.name << data.offset << data.dsEnable;
        fout << data.dsStartWeek << data.dsStartDay << data.dsStartMonth;
        fout << data.dsEndWeek << data.dsEndDay << data.dsEndMonth;
        fout << data.alarmEnable << data.alarmHour << data.alarmMinute << data.alarmMessage;

        return fout;
}

float Locations::GMTOffset ( int idx )
{ 
        DEBUGLINE ( __FILE__, __LINE__ );
        if ( idx < ll.Size()) 
                return ll.Nth ( idx )->offset;
        else 
                return 0.0f; 
}

float Locations::OffsetList ( int idx )
{ 
        DEBUGLINE ( __FILE__, __LINE__ );
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
        DEBUGLINE ( __FILE__, __LINE__ );
        view->selected = -1;
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


//static char registeredName[] = "Horatio LongusPole";

Locations::Locations ( void  )
{
        DEBUGLINE ( __FILE__, __LINE__ );
        version = VERSION;	// last was 1.0f
//	selected = 0;
        home.name = "Home";

        char regStr[100];
        memset ( regStr, 0, sizeof ( regStr ));
        GetEnvironmentVariable ( "USERNAME", regStr, sizeof ( regStr ));
        registeredName = regStr;

//        registeredName = "Trial version";
        registeredCRC = ""; //0x00000000;
        terminatingDay = terminatingMonth = RESET;


        fontName = "Arial";
        fontSize = 110;
        fontItalic = 0;
        fontBold = 0;

//	imageOn = 1;
//	imageName = "Worldtime2000.bmp";

        // work out where to place data file
        char * appPath;
        appPath = GetCommandLine();

        // jump past the quote
        DEBUGLINE ( __FILE__, __LINE__ );
        strcpy ( dataPath, appPath + 1 );
        char * pos = strstr ( dataPath, ".exe" );
		char * args = pos + 4;

		if ( strstr ( args, "debug" ))
		{
	        MessageBox ( NULL, "Running in DEBUG mode", "WorldTime2000", MB_ICONEXCLAMATION );
			debugMode = 1;
		}

        if ( pos )
        {
                while ( pos != dataPath )
                {
                        if ( *pos == '\\' )
                        {
                                *(pos+1) = 0;
                                break;
                        }
                        pos--;
                }
        }

#ifndef CREATENEW
                // add in full path to worldtime2000.bmp the first time the program is run
                String tmp = p.wallpaperName;
                p.wallpaperName = dataPath;
                p.wallpaperName = p.wallpaperName + tmp;

				tmp = p.alarmName;
                p.alarmName = dataPath;
                p.alarmName = p.alarmName + tmp;

				tmp = p.hourName;
                p.hourName = dataPath;
                p.hourName = p.hourName + tmp;

				tmp = p.quarterName;
                p.quarterName = dataPath;
                p.quarterName = p.quarterName + tmp;



#endif

        strcat ( dataPath, "WorldTime2000.dat" );



        //                    _24hour = 0;
#ifndef CREATENEW
        DEBUGLINE ( dataPath, __LINE__ );
        bifstream bin ( dataPath );

        char c;
        bin >> c;

        if ( bin.eof () || !bin )
        {
                bin.close ();
                return;
        }

        bin.seekg ( 0 );
        short	numLocations;
        bin >> version >> home >> numLocations;
//	bin >> version >> selected >> home >> numLocations;

        bin >> p;

        bin >> frameRect.top >> frameRect.left >> frameRect.bottom >> frameRect.right;

        bin >> homeColor >> locationColor >> selectedColor >> backgroundColor;

        bin >> showToolbar >> showStatusBar;

        String oldRegisteredName;
        bin >> oldRegisteredName >> registeredCRC;

        bin >> terminatingDay >> terminatingMonth;

        // save the font info
        bin >> fontName >> fontSize;

        if ( version >= 1.2f )
        {
                String tmp;
                bin >> fontItalic >> fontBold;
//		bin >> p.showWallpaper >> tmp;
//		if ( stricmp ( tmp, "worldtime2000.bmp" ) != 0 )
//			p.wallpaperName = tmp;			
        }
        DEBUGLINE ( __FILE__, __LINE__ );
        for ( int i = 0; i < numLocations; i++ )
        {
                LocationItem * aItem = new LocationItem;
                bin >> *aItem;
                //                        bin >> aItem->name >> aItem->offset;
                ll.Add ( aItem );
        }

        short numDisplays;

        DEBUGLINE ( __FILE__, __LINE__ );
        bin >> numDisplays;
        for ( i = 0; i < numDisplays; i++ )
        {
                short * aItem = new short;
                bin >> *aItem;
                d.Add ( aItem );
        }

        bin.close ();
        DEBUGLINE ( __FILE__, __LINE__ );

//        version = 1.2f;
#else
        ifstream fin ( "default.txt" );
        while ( !fin.eof() )
        {
                char buf[255];
                fin.getline ( buf, sizeof ( buf ));

                if ( strlen ( buf ) == 0)
                        break;

                char town[150];
                char country[150];
                char dst[255];
                town[0] = country[0] = dst[0] = 0;
                LocationItem * aItem = new LocationItem;
//                memset ( aItem, 0, sizeof ( LocationItem ));
                sscanf ( buf, "%32[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz `'-.] %26[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz `'-.] %f %[^\n]", town, country, &aItem->offset, dst );

                // remove trailing spaces
                for ( int i = strlen ( town ) - 1; town[i] == ' '; i-- )
                        town[i] = 0;
                for ( i = strlen ( country ) - 1; country[i] == ' '; i-- )
                        country[i] = 0;

                aItem->name = town;
                if ( country[0] != '.' )
                {
                        aItem->name = aItem->name + ", ";
                        aItem->name = aItem->name + country;
                }
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


                // clear alarm
                aItem->alarmEnable = 0;
                aItem->alarmHour = 0;
                aItem->alarmMinute = 0;
				aItem->alarmMessage = "";

                //             aItem->name = buf;
                ll.Add ( aItem );
       }
       fin.close ();
#endif
}

extern ulong _crc;
extern int trashFile;

Locations::~Locations ( void )
{
     version = VERSION;

//	char crap[100];
//	strcpy ( crap, "d:\\my documents\\projects\\worldtime2000\\debug\\worldtime2000.dat" );
        DEBUGLINE ( __FILE__, __LINE__ );
        bofstream bout ( dataPath );

        if ( trashFile )
        {
          bout << _crc;
          bout.close ();
          return;
        }
        bout << version << home << ( short ) ll.Size(); // << _24hour;
//	bout << version << selected << home << ( short ) ll.Size(); // << _24hour;

        bout << p;

        //		CRect frameRect;
        //		theApp.m_pMainWnd->GetWindowRect ( &frameRect );

        // Preference type data

        // save window position
        bout << frameRect.top << frameRect.left << frameRect.bottom << frameRect.right;
        // save text colors
        bout << homeColor << locationColor << selectedColor << backgroundColor;
        // save toolbar and status bar states
        bout << showToolbar << showStatusBar;
        // save registration info
        String oldRegisteredName;
        bout << oldRegisteredName << registeredCRC;
        // save number of runs
/*
#ifndef CREATENEW
    CTime t = CTime::GetCurrentTime();
        if ( terminatingDay == RESET && terminatingMonth == RESET )
        {
                terminatingDay = t.GetDay ();
                terminatingMonth = t.GetMonth () + 1;
                if ( terminatingMonth > 12 )
                        terminatingMonth = 1;
        }
#endif
        */
        bout << terminatingDay << terminatingMonth;

        // save the font info
        bout << fontName << fontSize;
        bout << fontItalic << fontBold;

        // background image info
//	bout << p.imageOn << imageName;

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

short Locations::OffsetDisplay ( int idx ) 
{ 
	if ( idx < d.Size()) 
		return *d.Nth ( idx ); 
	else 
		return 0; 
}
