// WorldTime2000.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "WorldTime2000.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
        // TODO: add construction code here,
        // Place all significant initialization in InitInstance
        _tzset();
/*
                AddDocTemplate( new CMultiDocTemplate( IDR_MAINFRAME,
          RUNTIME_CLASS( CScribDoc ),
          RUNTIME_CLASS( CMDIChildWnd ),
          RUNTIME_CLASS( CScribView ) ) );
  */

}

CWorldTime2000App::~CWorldTime2000App()
{
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

BOOL CWorldTime2000App::InitInstance()
{
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



                dstOnIcon = LoadIcon ( IDI_DSTON );
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

//		backgroundBitmap.LoadBitmap ( IDB_BACKGROUND );
        // To create the main window, this code creates a new frame window
        // object and then sets it as the application's main window object.

//	CMainFrame* pFrame = new CMainFrame;
        pFrame = new CMainFrame;
        m_pMainWnd = pFrame;

        // create and load the frame with its resources

        pFrame->LoadFrame(IDR_MAINFRAME,
                WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
                NULL);


       // change application icon - MFC FAQ
       SetClassLong(m_pMainWnd->m_hWnd,GCL_HICON, (LONG)LoadIcon(IDR_MAINFRAME));



        // The one and only window has been initialized, so show and update it.
        pFrame->ShowWindow(SW_SHOW);
        pFrame->UpdateWindow();

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
	
	return CWinApp::ExitInstance();
}

void CWorldTime2000App::RecordRegistration ( void )
{

	WriteProfileInt ( "Settings", "RK", l.registeredCRC );
	WriteProfileInt ( "Settings", "DA", l.terminatingDay );
	WriteProfileInt ( "Settings", "MN", l.terminatingMonth );
}

int CWorldTime2000App::CheckRegistration ( void )
{
	ulong crc, day, month;

	// check to see if user has been fooling with the registry
	crc = GetProfileInt ( "Settings", "RK", 0 );
	day = GetProfileInt ( "Settings", "DA", RESET );
	month = GetProfileInt ( "Settings", "MN", RESET );

	// the registry or the data file has recorded program evaluation has expired...do NOT continue
	if ( day == EXPIRED || month == EXPIRED ||
		l.terminatingDay == EXPIRED || l.terminatingMonth == EXPIRED )
	{

        MessageBox ( m_pMainWnd->m_hWnd, "This program has expired. Please register the program if you wish to continue using it", "Trial Expired", MB_OK | MB_ICONEXCLAMATION );
		mainFrame->Register(); 
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
	if (( l.registeredCRC || crc ) && crc != l.registeredCRC )
	{
		if ( l.registeredCRC == 0 && l.terminatingDay == RESET && l.terminatingMonth == RESET )
	        MessageBox ( m_pMainWnd->m_hWnd, "This previously registered version is now un-registered. This is probably a result of upgrading WorldTime2000 to a newer version. Please re-enter your registration details", "Registration Problem", MB_OK | MB_ICONERROR );
		else
	        MessageBox ( m_pMainWnd->m_hWnd, "This previously registered version is now un-registered. Please re-enter your registration details. If the problem persists, please contact us stating your Name, Address, Phone & E-mail for more information", "Registration Problem", MB_OK | MB_ICONERROR );
		l.registeredName = "Trial version";
		l.registeredCRC = 0x00000000;

		l.terminatingDay = RESET;
		l.terminatingMonth = RESET;

		WriteProfileInt ( "Settings", "RK", l.registeredCRC );
		WriteProfileInt ( "Settings", "DA", l.terminatingDay );
		WriteProfileInt ( "Settings", "MN", l.terminatingMonth );

		return 0;
	}

	// program is registered, and CRC is ok
	if ( day == REGISTERED || month == REGISTERED ||
		l.terminatingDay == REGISTERED || l.terminatingMonth == REGISTERED )
		return 1;

	// registry has been diddled with
	if ( l.terminatingDay != day || l.terminatingMonth != month )
	{
        MessageBox ( m_pMainWnd->m_hWnd, "An error has occurred. This registered version is now un-registered. Please contact us with your name, address, phone & email for more information", "Trial version Problem", MB_OK | MB_ICONERROR );
		l.registeredName = "Trial version";
		l.registeredCRC = 0x00000000;
		WriteProfileInt ( "Settings", "DA", EXPIRED );
		WriteProfileInt ( "Settings", "MN", EXPIRED );
		exit ( 0 );
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
