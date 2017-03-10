#include "stdafx.h"
#include "regdata.h"
#include "registrykey.h"
#include <sys/types.h>
#include <sys/stat.h>
//#include "crypt.h"
//#include "shared\OF_EventLog.h"
#include "resource.h"
//#include "RestoreDefaults.h"
//#include "DlgRegistryBad.h"

//RegistryItem regData[24]; //= 

RegistryCollection r;
//{
//    { "Key 1", REG_SZ, 0, 
//        "" }, //string ( "Key 1" )  },
//    { "Key 2", REG_SZ, 0, "Key 1" },
//    { "Key 3", REG_SZ, 3, "Key 1" },
//    { "Key 5", REG_DWORD, 5, "Key 1" },
//};

RegistryCollection::RegistryCollection ( void )
{
    int i = 0;

    // Registry saves display preferences
    //
    // home name
    // window pos
    // fonts - name
    //         size
    //         italic
    //         bold
    // show hours from GMT ?
    // 12 / 24 hour display ?
    // show seconds ?
    // show tooltips ?
    // show AM / PM ?
    // wallpaper name
    // show wallpaper
    // Sounds
    //      alarm wav
    //      hour chime wav
    //      quarter chime wav
    // Sounds Toggle
    //      alarm on/off
    //      hour chime on/off
    //      quarter chime on/off

//    regData[i].name = "Home";
//    regData[i].type = REG_SZ;
//    regData[i].word = 0;
//    regData[i].str = "Home";

//    i++;
    regData[i].name = "winTop";
    regData[i].type = REG_DWORD;
    regData[i].word = 100;
    regData[i].str = "";

    i++;
    regData[i].name = "winLeft";
    regData[i].type = REG_DWORD;
    regData[i].word = 100;
    regData[i].str = "";

    i++;
    regData[i].name = "winBottom";
    regData[i].type = REG_DWORD;
    regData[i].word = 495;
    regData[i].str = "";

    i++;
    regData[i].name = "winRight";
    regData[i].type = REG_DWORD;
    regData[i].word = 710;
    regData[i].str = "";

    i++;
    regData[i].name = "FontName";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "Arial";

    i++;
    regData[i].name = "FontSize";
    regData[i].type = REG_DWORD;
    regData[i].word = 90;
    regData[i].str = "";

    i++;
    regData[i].name = "FontItalic";
    regData[i].type = REG_DWORD;
    regData[i].word = 0;
    regData[i].str = "";

    i++;
    regData[i].name = "FontBold";
    regData[i].type = REG_DWORD;
    regData[i].word = 0;
    regData[i].str = "";

    i++;
    regData[i].name = "FontColor";
    regData[i].type = REG_DWORD;
    regData[i].word = 0x00ffffff;
    regData[i].str = "";

//    i++;
//    regData[i].name = "ShowGMTOffset";
//    regData[i].type = REG_DWORD;
//    regData[i].word = 1;
//    regData[i].str = "";

    i++;
    regData[i].name = "Show24Hour";
    regData[i].type = REG_DWORD;
    regData[i].word = 0;
    regData[i].str = "";
//    i++;
//    regData[i].name = "ShowSeconds";
//    regData[i].type = REG_DWORD;
//    regData[i].word = 1;
//    regData[i].str = "";
//    i++;
//    regData[i].name = "ShowTooltips";
//    regData[i].type = REG_DWORD;
//    regData[i].word = 1;
//    regData[i].str = "";

    i++;
    regData[i].name = "ShowAM";
    regData[i].type = REG_DWORD;
    regData[i].word = 1;
    regData[i].str = "";
//    i++;
//    regData[i].name = "ShowMainWallpaper";
//    regData[i].type = REG_DWORD;
//    regData[i].word = 1;
//    regData[i].str = "";

    i++;
    regData[i].name = "ShowAll";
    regData[i].type = REG_DWORD;
    regData[i].word = 1;
    regData[i].str = "";

    i++;
    regData[i].name = "ShowDate";
    regData[i].type = REG_DWORD;
    regData[i].word = 1;
    regData[i].str = "";

    i++;
    regData[i].name = "ShowDST";
    regData[i].type = REG_DWORD;
    regData[i].word = 1;
    regData[i].str = "";


    i++;
    regData[i].name = "Detailed Localtime";
    regData[i].type = REG_DWORD;
    regData[i].word = 0;
    regData[i].str = "";


//    i++;
//    regData[i].name = "WallpaperMain";
//    regData[i].type = REG_SZ;
//    regData[i].word = 0;
//    regData[i].str = "default.bmp";

//    i++;
//    regData[i].name = "WallpaperIconBar";
//    regData[i].type = REG_SZ;
//    regData[i].word = 0;
//    regData[i].str = "default.bmp";

//    i++;
    /*
    regData[i].name = "WaveAlarm";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "alarm.wav";

    i++;
    regData[i].name = "WaveHour";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "hour.wav";

    i++;
    regData[i].name = "WaveQuarter";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "quarter.wav";

    i++;
    regData[i].name = "WaveAlarmOn";
    regData[i].type = REG_DWORD;
    regData[i].word = 1;
    regData[i].str = "";

    i++;
    regData[i].name = "WaveHourOn";
    regData[i].type = REG_DWORD;
    regData[i].word = 1;
    regData[i].str = "";

    i++;
    regData[i].name = "WaveQuarterOn";
    regData[i].type = REG_DWORD;
    regData[i].word = 1;
    regData[i].str = "";

    i++;
    regData[i].name = "WinScrollPos";
    regData[i].type = REG_DWORD;
    regData[i].word = 80;
    regData[i].str = "";

    i++;
    */
    i++;
    regData[i].name = "UpdateInterval";
    regData[i].type = REG_DWORD;
    regData[i].word = 2000;
    regData[i].str = "";

    /*
    %n name                 
    %t time                 
    %d date                 
    %o country code         
    %l latitude / longitude 
    %c country              
    %s daylight savings mode
    %e email                
    %p phone number         
    */

    i++;
    regData[i].name = "MemberTemplate";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "%n, %c";
//    regData[i].str += 0x0d;
//    regData[i].str += 0x0a;
//    regData[i].str +="%d %t";
//    regData[i].str = "%n %t %s";
//    regData[i].str += 0x0d;
//    regData[i].str += 0x0a;
//    regData[i].str += "%d %c (%o)";


    i++;
    regData[i].name = "MemberTemplate2";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "%t";

    i++;
    regData[i].name = "MemberTemplate3";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "%d";

    /*
    i++;
    regData[i].name = "ActualSize";
    regData[i].type = REG_DWORD;
    regData[i].word = 0;
    regData[i].str = "";

    i++;
    regData[i].name = "BackgroundColor";
    regData[i].type = REG_DWORD;
    regData[i].word = 0x00ff0000;
    regData[i].str = "";
      */
    i++;
    regData[i].name = "UseTemplate";
    regData[i].type = REG_DWORD;       
    regData[i].word = 0;
    regData[i].str = "";

    i++;
    regData[i].name = "ShowSeconds";
    regData[i].type = REG_DWORD;
    regData[i].word = 0;
    regData[i].str = "";


    i++;
    regData[i].name = "SoundQuarterFile";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "cuckoo1.wav";

    i++;
    regData[i].name = "SoundHourFile";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "chime1.wav";

    i++;
    regData[i].name = "SoundAlarmFile";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "alarm5.wav";

    i++;
    regData[i].name = "SoundQuarter";
    regData[i].type = REG_DWORD;
    regData[i].word = 0;
    regData[i].str = "";
    i++;
    regData[i].name = "SoundHour";
    regData[i].type = REG_DWORD;
    regData[i].word = 1;
    regData[i].str = "";

    i++;
    regData[i].name = "SoundAlarm";
    regData[i].type = REG_DWORD;
    regData[i].word = 1;
    regData[i].str = "";

    i++;
    regData[i].name = "Reserved"; //ShowMarquee";
    regData[i].type = REG_DWORD;
    regData[i].word = 1;
    regData[i].str = "";

    i++;
    regData[i].name = "SkinName";
    regData[i].type = REG_SZ;       
    regData[i].word = 1;
    regData[i].str = "default.skn";

    i++;
    regData[i].name = "AlwaysOnTop";
    regData[i].type = REG_DWORD;       
    regData[i].word = 0;
    regData[i].str = "";

//    COLORREF night = 0x00f3a59e;
//    COLORREF transition = 0x00f3b5ae;
//    COLORREF day = 0x00f3c5be;

    i++;
    regData[i].name = "DayColor";
    regData[i].type = REG_DWORD;       
    regData[i].word = 0x00f3c5be;
    regData[i].str = "";

    i++;
    regData[i].name = "NightColor";
    regData[i].type = REG_DWORD;       
    regData[i].word = 0x00ff0000;
//    regData[i].word = 0x00f3a59e;
    regData[i].str = "";

    i++;
    regData[i].name = "TwilightColor";
    regData[i].type = REG_DWORD;       
    regData[i].word = 0x00f3b5ae;
    regData[i].str = "";


    i++;
    regData[i].name = "MainView"; // 0 map, 1 list
    regData[i].type = REG_DWORD;       
    regData[i].word = 0x0;
    regData[i].str = "";


    i++;
    regData[i].name = "UpdateURL";
    regData[i].type = REG_SZ;
    regData[i].word = 0;
    regData[i].str = "http://users.tpg.com.au/adsld842/wt2003/";

    i++;
    regData[i].name = "ListColor";
    regData[i].type = REG_DWORD;       
    regData[i].word = 0x00a07070;
//    regData[i].word = 0x00f3a59e;
    regData[i].str = "";


    regDataSz = i + 1;

}

bool GetStringResource ( string & str, DWORD id )
{
    static CString cstr;
    cstr.LoadString ( id );

    str = cstr;
    return true;
}

bool RegistryCollection::ReadRegistry ( void )
{
//    InitRegistryData();

    CRegistryKey key; // index is set by regData[i].keyIndex //rootKey, cpKey;

    string rootName;
    GetStringResource ( rootName, IDS_REGROOT );
//    char buf[200];


    if ( key.Connect ( HKEY_CURRENT_USER, rootName ) == false )
    {
        if ( key.Connect ( HKEY_CURRENT_USER, rootName, TRUE ) == false )
            return false;
    }

//    CString keyName;
//    keyName.LoadString ( IDS_REGROOT );


//    LoadStringResource ( IDS_REGROOT, keyName.c_str() );
    for ( int i = 0; i < regDataSz; i++ )
//    for ( int i = 0; i < sizeof ( regData ) / sizeof ( RegistryItem ); i++ )
    {
        // get the root path for the application
        if ( key.QueryValue ( regData[i].name.c_str() ) == false )
        {
            // key doesn't exist, so create it now
            if ( key.SetValue ( regData[i].name.c_str(), regData[i].type, regData[i].type == REG_SZ ? ( void * ) regData[i].str.c_str() : ( void * ) &regData[i].word ) == false )
                // failed, bad error
                MessageBox ( NULL, "Failed to create registry keys", "Error", MB_OK );

//            regData[i].exists = false;
            continue;
        }

        regData[i].type = key.GetValueType();
        if ( regData[i].type == REG_DWORD )
        {
            DWORD * val = ( DWORD * ) key.GetValue ();
            regData[i].word = *val;
        }
        else
            regData[i].str = ( char * ) key.GetValue ();

    }

    //
    //  alert user there is something wrong with the registry
    //
    return true;
}

/*
bool QueryRegistry ( void )
{
    CRegistryKey key[2]; // index is set by regData[i].keyIndex //rootKey, cpKey;
    char buf[200];

    if ( key[0].Connect ( HKEY_LOCAL_MACHINE, "Software\\OfficeFilter" ) == false )
    {
        LogEvent ( Error, key[0].GetError(), "Cannot connect to officeFilter Registry key [Software\\OfficeFilter]" );
        if ( key[0].Connect ( HKEY_LOCAL_MACHINE, "Software\\OfficeFilter", TRUE ) == false )
        {
            LogEvent ( Error, key[0].GetError(), "Error creating officeFilter Registry key [Software\\OfficeFilter]" );
            return false;
        }
        LogEvent ( Information, key[0].GetError(), "Registry key [OfficeFilter] has been created" );
    }

    if ( key[1].Connect ( HKEY_LOCAL_MACHINE, "Software\\OfficeFilter\\ControlPanel" ) == false )
    {
        LogEvent ( Error, key[1].GetError(), "Cannot connect to officeFilter Registry key [Software\\OfficeFilter\\ControlPanel]" );
        if ( key[1].Connect ( HKEY_LOCAL_MACHINE, "Software\\OfficeFilter\\ControlPanel", TRUE ) == false )
        {
            LogEvent ( Error, key[1].GetError(), "Error creating officeFilter Registry key [Software\\OfficeFilter\\ControlPanel]" );
            return false;
        }
        LogEvent ( Information, key[1].GetError(), "Registry key [ControlPanel] has been created" );
    }


    for ( int i = 0; i < NUM_REGITEMS; i++ )
    {
        // get the root path for the application
        if ( key[regData[i].keyIndex].QueryValue (( char * ) regData[i].name.c_str()) == false )
        {
            sprintf ( buf, "Error encounted querying key [%s]", regData[i].name.c_str() );
            LogEvent ( Error, key[regData[i].keyIndex].GetError(), buf);
            regData[i].exists = false;
            continue;
        }

        regData[i].type = key[regData[i].keyIndex].GetValueType();
        if ( regData[i].type == REG_DWORD )
        {
            DWORD * val = ( DWORD * ) key[regData[i].keyIndex].GetValue ();
            regData[i].word = *val;
        }
        else
            regData[i].str = ( char * ) key[regData[i].keyIndex].GetValue ();

        if ( ValidatePath ( regData[i].str.c_str(), regData[i].pathType ) == false )
        {
            sprintf ( buf, "Key [%s] contains an invalid path", regData[i].name.c_str() );
            LogEvent ( Error, GetLastError(), buf);
            regData[i].validPath = false;
        }
    }

    //
    //  alert user there is something wrong with the registry
    //
    if ( badInit == true )
    {
        CDlgRegistryBad dlg;
        int ret = dlg.DoModal ();

        switch ( ret )
        {
        case IDYES:
            // continue as normal. This option is only really useful if a path within
            // a registry entry is invalid, not if a key is missing
            LogEvent ( Information, GetLastError(), "User has choosen to try and fix registry problem manually" );
            break;
        case IDNO:
            for ( i = 0; i < NUM_REGITEMS; i++ )
            {
                if ( regData[i].exists && regData[i].validPath )
                    continue;

                if ( i == 0 )
                    // don't show the value being restored for the password
                    sprintf ( buf, "Do you want to restore the Registry key [%s] ?", regData[i].name.c_str());
                else
                {
                    if ( regData[i].type == REG_SZ )
                        sprintf ( buf, "Do you want to restore the Registry key [%s]\nwith the value [%s] ?", regData[i].name.c_str(), regData[i].str.c_str());
                    else
                        sprintf ( buf, "Do you want to restore the Registry key [%s]\nwith the value [%d] ?", regData[i].name.c_str(), regData[i].word );
                }

                RestoreDefaults dlg;
                static BOOL showDialog = TRUE;

                dlg.m_restoreMessage = buf;
                bool restoreData = false;

                if ( showDialog )
                {
                    if ( dlg.DoModal () == IDOK )
                    {
                        showDialog = dlg.m_dontShow ? FALSE : TRUE;
                        restoreData = true;
                    }
                }
                else
                    // restore all data can only be set if the user clicked ok, so restore it
                    restoreData = true;

                if ( restoreData )
                {
                    if ( !regData[i].exists )
                    {
                        if ( key[regData[i].keyIndex].SetValue ( ( char * ) regData[i].name.c_str(), regData[i].type, regData[i].type == REG_SZ ? ( void * ) regData[i].str.c_str() : ( void * ) &regData[i].word ))
                        {
                            sprintf ( buf, "Registry key [%s] has been created", regData[i].name.c_str() );
                            LogEvent ( Information, 0, buf );
                        }
                        else
                        {
                            sprintf ( buf, "Failed to create registry key [%s]", regData[i].name.c_str() );
                            LogEvent ( Error, GetLastError(), buf );
                        }
                    }

                    sprintf ( buf, "Registry key [%s] has been restored with the value [%s]", regData[i].name.c_str(), regData[i].str.c_str());
                    LogEvent ( Information, 0, buf );
                }
            }
            break;
        case IDC_LAUNCH_EVENTVIEWER:
            // not implemented
            break;
        case IDCANCEL:
            return false;
            break;
        }
    }

    //  decrypt administrator password
    //
    char src[200];
    char dest[200];

    memset ( src, 0, sizeof ( src ));
    memset ( dest, 0, sizeof ( dest ));
    strcpy ( src, regData[0].str.c_str());
    DecryptString (( unsigned char * ) src, ( unsigned char * ) dest );
    regData[0].str = dest;


    return true;

}
  */

bool RegistryCollection::WriteRegistry ( void )
{
    CRegistryKey key; // index is set by regData[i].keyIndex //rootKey, cpKey;

    string rootName;
    GetStringResource ( rootName, IDS_REGROOT );
//    char buf[200];


    if ( key.Connect ( HKEY_CURRENT_USER, rootName ) == false )
    {
        if ( key.Connect ( HKEY_CURRENT_USER, rootName, TRUE ) == false )
            return false;
    }


    for ( int i = 0; i < regDataSz; i++ )
//    for ( int i = 0; i < sizeof ( regData ) / sizeof ( RegistryItem ); i++ )
//    for ( int i = 0; i < NUM_REGITEMS; i++ )
    {
        if ( key.QueryValue ( ( char * ) regData[i].name.c_str()) == false )
        {
//            sprintf ( buf, "Error encounted querying key [%s]", regData[i].name.c_str());
//            LogEvent ( Error, key[regData[i].keyIndex].GetError(), buf );
            continue;
        }

        if ( key.SetValue (( char * ) regData[i].name.c_str(), regData[i].type,
            ( regData[i].type == REG_DWORD ) ? ( void * ) &regData[i].word : ( void * ) regData[i].str.c_str()) == false )
        {
//            sprintf ( buf, "Error encounted writing [%s] to Registry.", regData[i].name.c_str());
//            LogEvent ( Error, key[regData[i].keyIndex].GetError(), buf );
        }


    }
    return true;
}

  
