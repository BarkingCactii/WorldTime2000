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
        SetRegistryKey(_T("Local AppWizard-Generated Applications"));


		dstIcon = LoadIcon ( IDI_DST );

        worldIcon[0] = LoadIcon ( IDI_ANIM1 ); //ICON5 ); //IDI_WORLD2);
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
        worldBitmap[12].LoadBitmap ( IDB_BITMAP13 ); //IDI_WORLD2);
        worldBitmap[13].LoadBitmap ( IDB_BITMAP14 ); //IDI_WORLD2);
        worldBitmap[14].LoadBitmap ( IDB_BITMAP15 ); //IDI_WORLD2);
        worldBitmap[15].LoadBitmap ( IDB_BITMAP16 ); //IDI_WORLD2);
        worldBitmap[16].LoadBitmap ( IDB_BITMAP17 ); //IDI_WORLD2);
        worldBitmap[17].LoadBitmap ( IDB_BITMAP18 ); //IDI_WORLD2);
        worldBitmap[18].LoadBitmap ( IDB_BITMAP19 ); //IDI_WORLD2);
        worldBitmap[19].LoadBitmap ( IDB_BITMAP20 ); //IDI_WORLD2);
        worldBitmap[20].LoadBitmap ( IDB_BITMAP21 ); //IDI_WORLD2);
        worldBitmap[21].LoadBitmap ( IDB_BITMAP22 ); //IDI_WORLD2);
        worldBitmap[22].LoadBitmap ( IDB_BITMAP23 ); //IDI_WORLD2);
        worldBitmap[23].LoadBitmap ( IDB_BITMAP24 ); //IDI_WORLD2);

		backgroundBitmap.LoadBitmap ( IDB_BACKGROUND );
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
