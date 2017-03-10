// WorldTime2000.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "WorldTime2000.h"

#include "MainFrm.h"
#include "Crc32.h"

#include "trxtd200.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

clock_t startProcess;

/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000App

BEGIN_MESSAGE_MAP(CWorldTime2000App, CWinApp)
        //{{AFX_MSG_MAP(CWorldTime2000App)
        ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
                // NOTE - the ClassWizard will add and remove mapping macros here.
                //    DO NOT EDIT what you see in these blocks of generated code!
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000App construction

CWorldTime2000App::CWorldTime2000App()
{
       _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

        DEBUGLINE ( __FILE__, __LINE__ );
        // TODO: add construction code here,
        // Place all significant initialization in InitInstance
        _tzset();

          // keep a record of how long the program has been running
        startProcess = clock();

/*
                AddDocTemplate( new CMultiDocTemplate( IDR_MAINFRAME,
          RUNTIME_CLASS( CScribDoc ),
          RUNTIME_CLASS( CMDIChildWnd ),
          RUNTIME_CLASS( CScribView ) ) );
  */
//	GetRegistryKey ( "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\uninstall\\WorldTime2000" );

		HKEY key;
                RegOpenKeyEx ( HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\uninstall\\WorldTime2000", 0, KEY_ALL_ACCESS, &key );


		char * message = "This program has not been installed correctly, and as such cannot be uninstalled via Add/Remove Programs";

		unsigned char buf[255];
		unsigned long bufLen = 200;
		DWORD type;
		if ( RegQueryValueEx ( key, "UninstallString", NULL, &type, &buf[0], &bufLen ) != ERROR_SUCCESS )
		{
			MessageBox( NULL, message, "Information - Uninstall registry key not found", MB_ICONEXCLAMATION | MB_OK );
			RegCloseKey ( key );
			return;
		}

		char * dirPath = strstr ( ( const char * ) &buf[0], " " );

		if ( dirPath == 0 )
		{
			MessageBox( NULL, message, "ERROR", MB_OK );
			RegCloseKey ( key );
			return;
		}

		*dirPath = 0;
		if ( *(dirPath + 1 ) != '\"' )
		{

			String result = ( char * ) &buf[0];
			result = result + " \"";
			result = result + ( dirPath + 1 );
			result = result + "\"";

			char * tmp = result;

			if ( RegSetValueEx ( key, "UninstallString", NULL, type, ( const unsigned char * ) tmp, result.Length() + 1) != ERROR_SUCCESS )
				MessageBox( NULL, message, "ERROR", MB_OK );
		}
		RegCloseKey ( key );

		/*
		for ( int i = strlen ( buf ); i; i-- )
		{
			if ( &buf[i] == dirPath )
				break;

			buf[i] = buf[i-1];
		}
		  */
//		if ( RegQueryValue ( HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\uninstall\\WorldTime2000", buf, &bufLen ) != ERROR_SUCCESS )

//		char * ptr = "This is a test";
//		RegSetValue ( HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\uninstall\\WorldTime2000\\uninstallstring", REG_SZ, ptr, strlen ( ptr ) );

//		RegCloseKey ( key );
		return;
		/*
	CString str;

	m_pszAppName = "Worldtime2000";
	SetRegistryKey ( _T("\\HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\uninstall )); // \\WorldTime20001") );
    WriteProfileInt ( "Test", "TEST2", 1999 );
	str = GetProfileString ( "WorldTime2000", "uninstallstring" );
//	str = GetProfileString ( "\\HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\uninstall\\WorldTime2000", "uninstallstring" );
	
	int crap =1;
		  */
}

CWorldTime2000App::~CWorldTime2000App()
{
        DEBUGLINE ( __FILE__, __LINE__ );
        //First free the string allocated by MFC at CWinApp startup.
        //The string is allocated before InitInstance is called.
//	free((void*)m_pszRegistryKey);
        //Change the name of the registry key.
        //The CWinApp destructor will free the memory.
//	m_pszRegistryKey = 
//		_tcsdup(_T("PCM Computer Systems"));


//	SetRegistryKey ( "HKEY_CURRENT_USER\\Software\\PCM Computer Systems Pty Ltd\\WorldTime2000" );
//	WriteProfileInt ( "Settings", "RK", l.registeredCRC );
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWorldTime2000App object

CWorldTime2000App theApp;

/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000App initialization

static CMainFrame* pFrame;
//extern String imageName;
//extern HANDLE shit;

BOOL CWorldTime2000App::InitInstance()
{
        DEBUGLINE ( __FILE__, __LINE__ );

//        AfxOleInit (); // TrialX requirment
        AfxEnableControlContainer();

        // Standard initialization
        // If you are not using these features and wish to reduce the size
        //  of your final executable, you should remove from the following
        //  the specific initialization routines you do not need.

#ifdef _AFXDLL
        Enable3dControls();			// Call this when using MFC in a shared DLL
#else
        Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif


        // Change the registry key under which our settings are stored.
        // TODO: You should modify this string to be something appropriate
        // such as the name of your company or organization.
        SetRegistryKey(_T("PCM Computer Systems Pty Ltd"));



                dstOnIcon[0] = LoadIcon ( IDI_DSTON );
                dstOnIcon[1] = LoadIcon ( IDI_DSTON1);
                dstOnIcon[2] = LoadIcon ( IDI_DSTON2);
                dstOnIcon[3] = LoadIcon ( IDI_DSTON3);
                dstOffIcon = LoadIcon ( IDI_DSTOFF );
                homeIcon = LoadIcon ( IDI_HOME );
                alarmIcon = LoadIcon ( IDI_ALARM );

/*        worldIcon[0] = LoadIcon ( IDI_ANIM1 ); //ICON5 ); //IDI_WORLD2);
        worldIcon[1] = LoadIcon ( IDI_ANIM2 ); //IDI_WORLD2);
        worldIcon[2] = LoadIcon ( IDI_ANIM3 ); //IDI_WORLD2);
        worldIcon[3] = LoadIcon ( IDI_ANIM4 ); //IDI_WORLD2);
        worldIcon[4] = LoadIcon ( IDI_ANIM5 ); //IDI_WORLD2);
        worldIcon[5] = LoadIcon ( IDI_ANIM6 ); //IDI_WORLD2);
        worldIcon[6] = LoadIcon ( IDI_ANIM7 ); //IDI_WORLD2);
        worldIcon[7] = LoadIcon ( IDI_ANIM8 ); //IDI_WORLD2);
        worldIcon[8] = LoadIcon ( IDI_ANIM9 ); //IDI_WORLD2);
        worldIcon[9] = LoadIcon ( IDI_ANIM10 ); //IDI_WORLD2);
        worldIcon[10] = LoadIcon ( IDI_ANIM11 ); //IDI_WORLD2);
        worldIcon[11] = LoadIcon ( IDI_ANIM12 ); //IDI_WORLD2);
        worldIcon[12] = LoadIcon ( IDI_ANIM13 ); //IDI_WORLD2);
        worldIcon[13] = LoadIcon ( IDI_ANIM14 ); //IDI_WORLD2);
        worldIcon[14] = LoadIcon ( IDI_ANIM15 ); //IDI_WORLD2);
        worldIcon[15] = LoadIcon ( IDI_ANIM16 ); //IDI_WORLD2);
        worldIcon[16] = LoadIcon ( IDI_ANIM17 ); //IDI_WORLD2);
        worldIcon[17] = LoadIcon ( IDI_ANIM18 ); //IDI_WORLD2);
        worldIcon[18] = LoadIcon ( IDI_ANIM19 ); //IDI_WORLD2);
        worldIcon[19] = LoadIcon ( IDI_ANIM20 ); //IDI_WORLD2);
        worldIcon[20] = LoadIcon ( IDI_ANIM21 ); //IDI_WORLD2);
        worldIcon[21] = LoadIcon ( IDI_ANIM22 ); //IDI_WORLD2);
        worldIcon[22] = LoadIcon ( IDI_ANIM23 ); //IDI_WORLD2);
        worldIcon[23] = LoadIcon ( IDI_ANIM24 ); //IDI_WORLD2);
  */

        worldBitmap[0].LoadBitmap ( IDB_BITMAP1 ); //ICON5 ); //IDI_WORLD2);
        worldBitmap[1].LoadBitmap ( IDB_BITMAP2 ); //IDI_WORLD2);
        worldBitmap[2].LoadBitmap ( IDB_BITMAP3 ); //IDI_WORLD2);
        worldBitmap[3].LoadBitmap ( IDB_BITMAP4 ); //IDI_WORLD2);
        worldBitmap[4].LoadBitmap ( IDB_BITMAP5 ); //IDI_WORLD2);
        worldBitmap[5].LoadBitmap ( IDB_BITMAP6 ); //IDI_WORLD2);
        worldBitmap[6].LoadBitmap ( IDB_BITMAP7 ); //IDI_WORLD2);
        worldBitmap[7].LoadBitmap ( IDB_BITMAP8 ); //IDI_WORLD2);
        worldBitmap[8].LoadBitmap ( IDB_BITMAP9 ); //IDI_WORLD2);
        worldBitmap[9].LoadBitmap ( IDB_BITMAP10 ); //IDI_WORLD2);
        worldBitmap[10].LoadBitmap ( IDB_BITMAP11 ); //IDI_WORLD2);
        worldBitmap[11].LoadBitmap ( IDB_BITMAP12 ); //IDI_WORLD2);

//		OnOptionsBackground();
/*
                backgroundBitmap.LoadBitmap ( IDB_SANDSTONE );

                CFileDialog dlg ( TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "Bitmap Files (*.bmp)" ); 
                dlg.DoModal ();
//static char BASED_CODE szFilter[] = "Chart Files (*.xlc)|*.xlc|Worksheet Files (*.xls)|*.xls|Data Files (*.xlc;*.xls)|*.xlc; *.xls|All Files (*.*)|*.*||";

                shit = LoadImage( 0, "crap.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE );
*/ 
                if ( l.p.showWallpaper )
                        if (( wallpaper = LoadImage( 0, l.p.wallpaperName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE )) == NULL )
                                l.p.showWallpaper = 0;
        // To create the main window, this code creates a new frame window
        // object and then sets it as the application's main window object.

//	CMainFrame* pFrame = new CMainFrame;
        pFrame = new CMainFrame;
        m_pMainWnd = pFrame;

		if ( !pFrame )
			MessageBox( NULL, "Failed to create MainFrame", "ERROR", MB_OK );

        // create and load the frame with its resources

        DEBUGLINE ( __FILE__, __LINE__ );

        if ( pFrame->LoadFrame(IDR_MAINFRAME,
                WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
                NULL) == FALSE )
			MessageBox( NULL, "Failed to LoadFrame", "ERROR", MB_OK );

        DEBUGLINE ( __FILE__, __LINE__ );

       // change application icon - MFC FAQ
       SetClassLong(m_pMainWnd->m_hWnd,GCL_HICON, (LONG)LoadIcon(IDR_MAINFRAME));

        DEBUGLINE ( __FILE__, __LINE__ );


        // The one and only window has been initialized, so show and update it.
        pFrame->ShowWindow(SW_SHOW);
        DEBUGLINE ( __FILE__, __LINE__ );
        pFrame->UpdateWindow();
        DEBUGLINE ( __FILE__, __LINE__ );

                          
 	   AfxBeginThread ( CRCThread, this, THREAD_PRIORITY_IDLE );
        DEBUGLINE ( __FILE__, __LINE__ );
        /*
   // Set pWnd to some CWnd object whose window has already
   // been created.

                char dir[255];

                GetCurrentDirectory ( 255, dir );
                char * dir2;
                dir2 = GetCommandLine();
   // The following call to CWnd::MessageBox uses the application
   // title as the message box caption.
   MessageBox( m_pMainWnd->m_hWnd, dir2, "Some message", MB_OK );
   MessageBox( m_pMainWnd->m_hWnd, AfxGetApp()->m_pszAppName, "Some message", MB_OK );

   // A more direct way to get the application title is to 
   // call AfxGetAppName:
   MessageBox( m_pMainWnd->m_hWnd, AfxGetAppName(), "", MB_OK);

   // An easier way to display a message box using the application
   // title as the message box caption is to call AfxMessageBox:
   AfxMessageBox("Some message");
*/

#ifndef CREATENEW
                CheckRegistration ();
#else
        MessageBox ( m_pMainWnd->m_hWnd, "Running in test mode!!!", "NON RELEASE", MB_OK | MB_ICONEXCLAMATION );
#endif
        DEBUGLINE ( __FILE__, __LINE__ );
        return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000App message handlers





/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
        CAboutDlg();

// Dialog Data
        //{{AFX_DATA(CAboutDlg)
        enum { IDD = IDD_ABOUTBOX };
        //}}AFX_DATA

        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CAboutDlg)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        //{{AFX_MSG(CAboutDlg)
                // No message handlers
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
        //{{AFX_DATA_INIT(CAboutDlg)
        //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CAboutDlg)
        //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
        //{{AFX_MSG_MAP(CAboutDlg)
                // No message handlers
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CWorldTime2000App::OnAppAbout()
{
        CAboutDlg aboutDlg;
        aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000App message handlers


BOOL CWorldTime2000App::OnIdle(LONG lCount)
{
//	pFrame->View()->UpdateTime();

        return CWinApp::OnIdle(lCount);
}

int CWorldTime2000App::ExitInstance() 
{
        // TODO: Add your specialized code here and/or call the base class
//	WriteProfileInt ( "Settings", "DA", l.terminatingDay );
//	WriteProfileInt ( "Settings", "MN", l.terminatingMonth );
        DEBUGLINE ( __FILE__, __LINE__ );

        return CWinApp::ExitInstance();
}

void CWorldTime2000App::RecordRegistration ( void )
{
        DEBUGLINE ( __FILE__, __LINE__ );

		// new
		ulong crc32 = 0xffffffff;
		String crcStrInFile = l.registeredCRC;
		char *tmp = ( char * ) crcStrInFile;
		*(tmp + crcStrInFile.Length() - 5) = 0;

		Crc32 ( &crc32, crcStrInFile, crcStrInFile.Length ());
        WriteProfileInt ( "Settings", "RK", crc32 );

        WriteProfileInt ( "Settings", "DA", l.terminatingDay );
        WriteProfileInt ( "Settings", "MN", l.terminatingMonth );
}

ulong _crc;
int trashFile = 0;

ulong purchases[] = 
{       
219865424,
1726371876,
3963925748,
3647605326,
2278138037,
3214379,
3661654839,
3700114719,
4059524537,
198843700,
3048181516,
3900348374,
0,
};

int CWorldTime2000App::CheckRegistration ( void )
{
        DEBUGLINE ( __FILE__, __LINE__ );
        return 1;
        ulong crc, day, month;

        // check to see if user has been fooling with the registry
        crc = GetProfileInt ( "Settings", "RK", 0 );
        day = GetProfileInt ( "Settings", "DA", RESET );
        month = GetProfileInt ( "Settings", "MN", RESET );

// DEBUG ONLY
		extern int debugMode;
		if ( debugMode )
		{
		extern ofstream fout;
        fout << "Values " << crc << " " << day << " " << month << " " << l.registeredCRC << endl << flush;
		}
// END DEBUG

        // the registry or the data file has recorded program evaluation has expired...do NOT continue
        if ( day == EXPIRED || month == EXPIRED ||
                l.terminatingDay == EXPIRED || l.terminatingMonth == EXPIRED )
        {

        MessageBox ( m_pMainWnd->m_hWnd, "This program has expired. Please register the program if you wish to continue using it", "Trial Expired", MB_OK | MB_ICONEXCLAMATION );
                mainFrame->Register(); 
//				CheckRegistration();
                exit ( 0 );
        }

        if ( day == RESET && month == RESET )
        {
                if ( l.terminatingDay == RESET && l.terminatingMonth == RESET )
                {
                        // program is being run the first time, so store dates to run evaluation to
                    CTime t = CTime::GetCurrentTime();
                        l.terminatingDay = t.GetDay ();
                        l.terminatingMonth = t.GetMonth () + 1;
                        if ( l.terminatingMonth > 12 )
                                l.terminatingMonth = 1;

                        WriteProfileInt ( "Settings", "DA", l.terminatingDay );
                        WriteProfileInt ( "Settings", "MN", l.terminatingMonth );

                        return 1;
                }
                else
                {
                        // registry has been diddled with
                }
        }

        // key has been tampered with
		ulong crcInFile = 0xffffffff;
		String crcStrInFile = l.registeredCRC;

		if ( crcStrInFile.Length())
		{
			char *tmp = ( char * ) crcStrInFile;
			*(tmp + crcStrInFile.Length() - 5) = 0;
//		crcStrInFile[1] = '1';
//		( char ) *(crcStrInFile[crcStrInFile.Length() - 5] = 0;

//		Crc32 ( &crcInFile, crcStrInFile, crcStrInFile.Length());

			Crc32 ( &crcInFile, crcStrInFile, crcStrInFile.Length());
		}
		else
		{
			crcInFile = 0x0;
		}

        if (( crcInFile || crc ) && crc != crcInFile )
        {
                if ( crcInFile == 0 && l.terminatingDay == RESET && l.terminatingMonth == RESET )
                {
                    MessageBox ( m_pMainWnd->m_hWnd, "This previously registered version is now un-registered. This is probably a result of upgrading WorldTime2000 to a newer version. Please re-enter your registration details", "Registration Reset", MB_OK | MB_ICONERROR );
					int validUpgrade = 0;
					for ( int i = 0; purchases[i]; i++ )
					{
						if ( purchases[i] == crc )
						{
							validUpgrade = 1;
							break;
						}
					}
	                if ( !validUpgrade )
		            {
                     // only 1 registered user in version 1.10 -> [Jens Knoell] -> [219865424]

                     // PIRATE ALERT!!
						l.registeredName = "Trial version";
						l.registeredCRC = ""; //0x00000000;
		                WriteProfileInt ( "Settings", "DA", EXPIRED );
			            WriteProfileInt ( "Settings", "MN", EXPIRED );
				        _crc = crc;
					    trashFile = 1;
						    MessageBox ( m_pMainWnd->m_hWnd, "The registration contained in the previous version appear to be invalid. Please contact us on how to correct this problem", "Registration Details Error", MB_OK | MB_ICONERROR );
	                    exit ( 0 );
			        }
               }
                else
                    MessageBox ( m_pMainWnd->m_hWnd, "This previously registered version is now un-registered. Please re-enter your registration details. If the problem persists, please contact us stating your Name, Address, Phone & E-mail", "Registration Problem", MB_OK | MB_ICONERROR );

                l.registeredName = "Trial version";
                l.registeredCRC = ""; //0x00000000;

                l.terminatingDay = RESET;
                l.terminatingMonth = RESET;

		// new
		ulong crc32;
		Crc32 ( &crc32, l.registeredCRC, l.registeredCRC.Length ());
        WriteProfileInt ( "Settings", "RK", crc32 );


                //WriteProfileInt ( "Settings", "RK", l.registeredCRC );
                WriteProfileInt ( "Settings", "DA", l.terminatingDay );
                WriteProfileInt ( "Settings", "MN", l.terminatingMonth );

                return 0;
        }

        // program is registered, and CRC is ok
        if ( day == REGISTERED || month == REGISTERED ||
                l.terminatingDay == REGISTERED || l.terminatingMonth == REGISTERED )
                return 1;

        // registry may have been diddled with, or user upgrading
        if ( l.terminatingDay != day || l.terminatingMonth != month )
        { 
                if ( l.terminatingDay == RESET && l.terminatingMonth == RESET )
                {
                         // user upgrading to a newer version
                        l.terminatingDay = day;
                        l.terminatingMonth = month;
                }
                else
                {
                MessageBox ( m_pMainWnd->m_hWnd, "An error has occurred. This probably registered version is now un-registered. Please contact us with your name, address, phone & email", "Trial version Problem", MB_OK | MB_ICONERROR );
                        l.registeredName = "Trial version";
                        l.registeredCRC = ""; //0x00000000;
                        WriteProfileInt ( "Settings", "DA", EXPIRED );
                        WriteProfileInt ( "Settings", "MN", EXPIRED );
                        exit ( 0 );
                }
        }


        // check to see if evalulation version has timed out
    CTime t = CTime::GetCurrentTime();
        if ( t.GetDay() >= l.terminatingDay && t.GetMonth() >= l.terminatingMonth )
        {
        MessageBox ( m_pMainWnd->m_hWnd, "This program has expired. Please register the program if you wish to continue using it", "Trial Expired", MB_OK | MB_ICONEXCLAMATION );
                WriteProfileInt ( "Settings", "DA", EXPIRED );
                WriteProfileInt ( "Settings", "MN", EXPIRED );
                mainFrame->Register(); 
                exit ( 0 );
        }

        return 1;
}

  
int sortIdx = 0;
int sortBy[3] = { 1, 1, 1 };

    
int GetLocationTag ( CListCtrl & m_list, int & tag, int & raw )
{
     POSITION pos = m_list.GetFirstSelectedItemPosition();

     if (pos == NULL)
     {
//	     MessageBox( NULL, "No active selection", "Information", MB_ICONEXCLAMATION | MB_OK );
          return 0;
     }

     raw = m_list.GetNextSelectedItem(pos);
     tag = m_list.GetItemData ( raw );

     return 1;
}


int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort )
{
     LPLVITEM l1, l2;

     if ( lParam1 < 0 || lParam1 > l.lastTag )
     {
     	MessageBox( NULL, "Param1 bad in sort", "Error", MB_ICONSTOP | MB_OK );
          return 0;
     }

     if ( lParam2 < 0 || lParam2 > l.lastTag )
     {
     	MessageBox( NULL, "Param2 bad in sort", "Error", MB_ICONSTOP | MB_OK );
          return 0;
     }

     LocationItem *i1 = l.GetLocationbyTag ( lParam1 );
//     LocationItem *i1 = l.GetLocation ( lParam1 );
     if ( i1 == 0 )
          return 0;
     LocationItem *i2 = l.GetLocationbyTag ( lParam2 );
//     LocationItem *i2 = l.GetLocation ( lParam2 );
     if ( i2 == 0 )
          return 0;

     if ( lParamSort == 0 )
     {
          if ( sortBy[lParamSort] == 1 )
               return stricmp ( i1->city, i2->city );
          else
               return stricmp ( i2->city, i1->city );
     }

     if ( lParamSort == 1 )
     {
          if ( sortBy[lParamSort] == 1 )
               return stricmp ( i1->country, i2->country );
          else
               return stricmp ( i2->country, i1->country );
     }

     if ( lParamSort == 2 )
     {
          if ( sortBy[lParamSort] == 1 )
               return ( int ) ( i2->offset - i1->offset );
          else
               return ( int ) ( i1->offset - i2->offset );
     }

     return 0;
}


int InitLocationControl ( CListCtrl & m_list )
{
     CRect rect;

     m_list.SetBkColor ( 0x00000000 );
     m_list.SetTextBkColor ( 0x00000000 );
     m_list.SetTextColor ( 0x0000ffff );
     m_list.GetWindowRect(&rect);
     m_list.InsertColumn(0, "Location", LVCFMT_LEFT, rect.Width() / 2 - 35, 0);
     m_list.InsertColumn(1, "Country", LVCFMT_LEFT, rect.Width() / 2 - 35, 1);
     m_list.InsertColumn(2, "GMT", LVCFMT_LEFT, 50, 2);

//     int selectedIdx = 0;
     
     Boolean selectionMade = False;
     int selectedContextbyRow = 0;
     int selectedContextbyTag = 0;

     for ( int i = 0; i < l.Size(); i++ )
     {
         strstream sout;

         float offset = l.GMTOffset ( i );

         float mins = offset - ( float )floor ( offset );
         if ( mins )
              mins = 30.0f;

         if ( offset >= 0 )
              sout << "+";
         else
              sout << "-";

         offset = ( float ) fabs ( floor ( offset ));

         sout << offset << " hrs" << ends; // << ":";

          LVITEM lvitem;
                lvitem.mask = LVIF_TEXT | LVIF_PARAM;
                lvitem.iItem = i;
                lvitem.iSubItem = 0;
                lvitem.pszText = l.CityList ( i );
          lvitem.lParam = l.Tag ( i );


          if ( selectionMade == False )
          {          
          if ( selectedbyString == l.CityList ( i ))
          {
               lvitem.mask |= LVIF_STATE;
               lvitem.state = LVIS_SELECTED;
               lvitem.stateMask = LVIS_SELECTED;
//               selectedbyString = "";
               selectedContextbyRow = i;
               selectedContextbyTag = lvitem.lParam;
               selectionMade = True;
          }
          else
          if ( selectedbyString.Length() == 0 && selectedbyTag == lvitem.lParam )
          {
               // this location is initially selected
               lvitem.mask |= LVIF_STATE;
               lvitem.state = LVIS_SELECTED;
               lvitem.stateMask = LVIS_SELECTED;
  //             selectedIdx = i;
               selectionMade = True;
          }
          }
          m_list.InsertItem ( &lvitem );

                lvitem.mask = LVIF_TEXT;
                lvitem.iItem = i;
                lvitem.iSubItem = 1;
                lvitem.pszText = l.CountryList ( i );
          lvitem.lParam = l.Tag ( i );

          m_list.SetItem ( &lvitem );

                lvitem.mask = LVIF_TEXT;
                lvitem.iItem = i;
                lvitem.iSubItem = 2;
                lvitem.pszText = sout.str();
          lvitem.lParam = l.Tag ( i );


          m_list.SetItem ( &lvitem );

    }

     int retval;

//    m_list.EnsureVisible ( selectedbyRow, FALSE );
    if ( selectedbyString.Length())
     {
          // if choosing modify from context menu, dont sort, as we dont know what to index the tag
          selectedbyString = "";
         m_list.EnsureVisible ( selectedContextbyRow, FALSE );
          retval = selectedContextbyTag;
     }
     else
     {
         m_list.SortItems( CompareFunc, sortIdx );
         m_list.EnsureVisible ( selectedbyRow, FALSE );
          retval = selectedbyTag;
     }
    m_list.SetFocus();

     return retval;
}


