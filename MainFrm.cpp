//ID_APP_ABOUT Toolbar entry to show item help
//ID_CONTEXT_HELP
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "WorldTime2000.h"

#include "WorldTime2000view.h"
#include "MainFrm.h"

#include "htmlhelp.h"
//#include "display.h"
#include "regdata.h"
#include "DlgAlarms.h"

#include "PrefPropSheet.h"
#include "dlglocation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMainFrame * mainFrame;
CRect appRect;
short showToolbar = 1, showStatusBar = 1;
short versionUpgrade = 0;

HANDLE wallpaper;

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

#define WM_MY_TRAY_NOTIFICATION WM_USER+0

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
//{{AFX_MSG_MAP(CMainFrame)
ON_WM_CREATE()
ON_WM_SETFOCUS()
ON_COMMAND(ID_FILE_HOME, OnFileHome)
ON_COMMAND(ID_FILE_ADD, OnFileAdd)
ON_COMMAND(ID_FILE_ADDTODISPLAY, OnFileAddtodisplay)
ON_COMMAND(ID_FILE_PREFERENCES, OnFilePreferences)
ON_WM_SIZE()
ON_WM_MOVE()
ON_COMMAND(ID_FILE_DELETE, OnFileDelete)
ON_COMMAND(ID_FILE_MODIFY, OnFileModify)
ON_COMMAND(ID_FILE_ALARM, OnFileAlarm)
ON_COMMAND(ID_CONTEXT_DELETE, OnContextDelete)
ON_COMMAND(ID_CONTEXT_MODIFY, OnContextModify)
ON_COMMAND(ID_CONTEXT_MOVE, OnContextMove)
ON_COMMAND(ID_CONTEXT_FONT, OnContextFont)
ON_COMMAND(ID_HELP_CONTENTS, OnHelpContents)
ON_WM_DESTROY()
ON_COMMAND(ID_SHOW_STATUS_BAR, OnViewStatusBar)
ON_COMMAND(ID_SHOW_TOOLBAR, OnViewToolbar)
ON_COMMAND(ID_FILE_ALARMRESET, OnFileAlarmreset)
ON_COMMAND(ID_FILE_FONT, OnFileFont)
ON_MESSAGE(WM_MY_TRAY_NOTIFICATION, OnTrayNotification)
ON_WM_CLOSE()
ON_COMMAND(ID_APP_EXIT, OnAppExit)
ON_COMMAND(ID_APP_OPEN, OnAppOpen)
ON_COMMAND(ID_SORT_COUNTRY, OnSortCountry)
ON_COMMAND(ID_SORT_NAME, OnSortName)
ON_COMMAND(ID_SORT_TIME, OnSortTime)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_VIEW_GMT, OnViewGmt)
	ON_COMMAND(ID_HELP_LEGEND, OnHelpLegend)
	ON_WM_ENDSESSION()
	ON_COMMAND(ID_CONTEXT_WHATIF, OnContextWhatif)
	ON_COMMAND(ID_VIEW_WHATIF, OnViewWhatif)
	ON_COMMAND(ID_FILE_LOADSKIN, OnFileLoadskin)
	ON_COMMAND(ID_FILE_REMOVESKIN, OnFileRemoveskin)
	ON_COMMAND(ID_FILE_LOCATIONS, OnFileLocations)
	ON_COMMAND(ID_FILE_ALARMS, OnFileAlarms)
	//}}AFX_MSG_MAP
// Global help commands
ON_NOTIFY(TBN_DROPDOWN, AFX_IDW_TOOLBAR, OnDropDown)
END_MESSAGE_MAP()
//        ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
//        ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
//        ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
//        ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)


LRESULT CMainFrame::OnTrayNotification(WPARAM wp, LPARAM lp)
{                    
	// display message
	return m_trayIcon.OnTrayNotification(wp, lp);
}

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
        ID_INDICATOR_CAPS,
        ID_INDICATOR_NUM,
        ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame() : m_trayIcon(IDR_SYSTEMTRAY)
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: add member initialization code here
	appRect = rectDefault;
	mainFrame = this;
	m_bShutdown = false;
}

CMainFrame::~CMainFrame()
{
	DEBUGLINE ( __FILE__, __LINE__ );
	/*
	CMenu *menu = GetMenu();
	UINT retVal;
	
	  retVal = menu->GetMenuState ( ID_VIEW_TOOLBAR, MF_BYCOMMAND );
	  if ( retVal & MF_CHECKED )
	  showToolbar = 1;
	  else
	  showToolbar = 0;
	  
        retVal = menu->GetMenuState ( ID_VIEW_STATUS_BAR, MF_BYCOMMAND );
		if ( retVal & MF_CHECKED )
		showStatusBar = 1;
		else
		showStatusBar = 0;
	*/

     r.WriteRegistry();
     l.Save();
     m.Save();

}


void CMainFrame::InitData ( void )
{
    static bool init = false;

    if ( init == false )
    {
        // get the command line
        char * appPath = GetCommandLine();

        // set the data path ( same as application path )
        string dataPath;
        dataPath = appPath + 1; // jump past quote
        dataPath.resize ( dataPath.find_last_of ( "\\" ));
        dataPath += "\\";

        string locationsFile;
        locationsFile = dataPath + "locations.dat";

        string membersFile;
        membersFile = dataPath + "members.dat";

        // fix this
        
                                char * test = AfxGetApp()->m_lpCmdLine;
        if ( strstr ( AfxGetApp()->m_lpCmdLine, "recreate" ))
        {
            ::MessageBox ( NULL, "Recreating Locations.dat", "OnlineTime", MB_ICONEXCLAMATION );
            l.Create ( locationsFile );
        }
          

    // open locations.dat file
//    MessageBox ( "Opening files", "OnLineTime", MB_OK );

        l.Open ( locationsFile );
        m.Open ( membersFile );
//        g.Open ( dataPath );
#ifdef TEST
         
        // create some dummy members
        MemberItem * newItem;
        newItem = new MemberItem;
        newItem->name = "Jeff";
        m.Add ( newItem );
        newItem = new MemberItem;
        newItem->name = "Hunter";
        m.Add ( newItem );
          
#endif
//    g.Open ( dataPath );

     r.AddKey ( "SkinName", REG_SZ, 0, "winaqua.skn" ); // built in skin
     r.AddKey ( "ShowHoursGMT", REG_DWORD, 1, "" ); // built in skin
     r.AddKey ( "ShowWhatIf", REG_DWORD, 0, "" ); // built in skin
     r.AddKey ( "WindowTop", REG_DWORD, 100, "" ); // built in skin
     r.AddKey ( "WindowLeft", REG_DWORD, 100, "" ); // built in skin
     r.AddKey ( "WindowBottom", REG_DWORD, 450, "" ); // built in skin
     r.AddKey ( "WindowRight", REG_DWORD, 750, "" ); // built in skin
     r.AddKey ( "ShowWallpaper", REG_DWORD, 1, "" ); // built in skin
     r.AddKey ( "WallpaperName", REG_SZ, 0, "worldtime2000.bmp" );
     r.AddKey ( "Home", REG_SZ, 0, "Home" );
     r.AddKey ( "SoundQuarterFile", REG_SZ, 0, "quarter.wav" );
     r.AddKey ( "SoundHourFile", REG_SZ, 0, "hour.wav" );
     r.AddKey ( "SoundAlarmFile", REG_SZ, 0, "alarm.wav" );
     r.AddKey ( "PlayQuarter", REG_DWORD, 1, "" );
     r.AddKey ( "PlayHour", REG_DWORD, 1, "" );
     r.AddKey ( "PlayAlarm", REG_DWORD, 1, "" );
     r.AddKey ( "BackgroundColor", REG_DWORD, 0x00808080, "" );
     r.AddKey ( "ShowSeconds", REG_DWORD, 0, "" );
     r.AddKey ( "ShowTooltips", REG_DWORD, 1, "" );
     r.AddKey ( "ShowAM", REG_DWORD, 0, "" );
     r.AddKey ( "Show24Hour", REG_DWORD, 0, "" );



        if (! r.ReadRegistry())
            ::MessageBox ( NULL, "There was a problem reading onlineTime\'s settings from the registry", "Error", MB_OK );


//        if ( r.AlwaysOnTop())
//            SetWindowPos ( &wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE );
//
//         SetWindowPos ( NULL, r.WinLeft(), r.WinTop(), r.WinRight() - r.WinLeft (),
//            r.WinBottom() - r.WinTop(), SWP_NOZORDER );

     if ( r.GetKey("ShowWallpaper").word )
//     if ( d.showWallpaper )
          if (( wallpaper = LoadImage( 0, r.GetKey("WallpaperName").str.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE )) == NULL )
               r.GetKey("ShowWallpaper").word = false;

        init = true;

    }
}


#include <time.h>
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

	DEBUGLINE ( __FILE__, __LINE__ );
	/*
	int d = _daylight;
	int i = _timezone;
	char * c = tzname[0];
	char * c2 = tzname[1];

    */
	

    InitData();
	//	theApp.m_pMainWnd->MoveWindow ( &frameRect );

    // check if window positioning info is reasonable
     SetWindowPos ( NULL, r.GetKey("WindowLeft").word, r.GetKey("WindowTop").word, 
         r.GetKey("WindowRight").word - r.GetKey("WindowLeft").word,
         r.GetKey("WindowBottom").word - r.GetKey("WindowTop").word,
         SWP_NOZORDER );
//	MoveWindow ( &d.frameRect );
	//	GetWindowRect ( &l.frameRect );
  

//    theApp.m_pSkin->ApplySkin((long)m_hWnd); // Apply contained skin to the main frame and its child windows
    

//     EnableToolTips ( TRUE );
	DEBUGLINE ( __FILE__, __LINE__ );
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// create a view to occupy the client area of the frame
	m_wndView = new CWorldTime2000View;
	if (!m_wndView->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}
	
	// debugging, pause for slow machines
	//        Sleep ( 1000 );
	
	CSize iconSize;
	iconSize.cx = 5; iconSize.cy = 20;
	
	//	m_wndToolBar.GetToolBarCtrl().SetButtonSize ( iconSize );
	
	
	CBitmap bmpCold;
	bmpCold.LoadBitmap ( IDB_TOOLBAR_HOT );
	CBitmap bmpHot;
	bmpHot.LoadBitmap ( IDB_TOOLBAR_HOT );

             /*
	CBitmap bmp[9];
	bmp[0].LoadBitmap ( IDB_HOME );
	bmp[1].LoadBitmap ( IDB_DISPLAY );
	bmp[2].LoadBitmap ( IDB_ALARMS );
	bmp[3].LoadBitmap ( IDB_SKINS );
	bmp[4].LoadBitmap ( IDB_PREFERENCES );
	bmp[5].LoadBitmap ( IDB_BACKGROUND );
	bmp[6].LoadBitmap ( IDB_FONTS );
	bmp[7].LoadBitmap ( IDB_LOCATIONS );
	bmp[8].LoadBitmap ( IDB_HELP );
	           */
	
	
	
	
	CImageList img;
	
	if (!m_wndToolBar.CreateEx(this))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	// set up toolbar properties
	m_wndToolBar.GetToolBarCtrl().SetButtonWidth(48, 48);
//	m_wndToolBar.GetToolBarCtrl().SetExtendedStyle(TBSTYLE_EX_DRAWDDARROWS);
	
    img.Create( 48, 48, ILC_COLOR8 | ILC_MASK, 10, 0 );
	img.Add ( &bmpHot, RGB ( 255, 0, 255 ));
	m_wndToolBar.GetToolBarCtrl().SetHotImageList(&img);
	img.Detach();
	
	//          img.Create( 48, 48, ILC_COLOR8 | ILC_MASK, 10, 0 );
	img.Create( 48, 48, ILC_COLOR8 | ILC_MASK, 10, 0 );
	img.Add ( &bmpCold, RGB ( 255, 0, 255 )); // should be bmpCold
	m_wndToolBar.GetToolBarCtrl().SetImageList(&img);
	img.Detach();

    m_wndToolBar.ModifyStyle(0, TBSTYLE_FLAT | TBSTYLE_TOOLTIPS ); // | TBSTYLE_TRANSPARENT);
//	m_wndToolBar.ModifyStyle(0, TBSTYLE_FLAT | TBSTYLE_TOOLTIPS ); // | TBSTYLE_TRANSPARENT);
	m_wndToolBar.SetButtons(NULL, 7);
	
	// set up each toolbar button
	m_wndToolBar.SetButtonInfo(0, ID_FILE_HOME, TBSTYLE_BUTTON, 1);
	//        str.LoadString(IDS_BACK);
	//       m_wndToolBar.SetButtonText(0, str);
	m_wndToolBar.SetButtonInfo(1, ID_FILE_ADDTODISPLAY, TBSTYLE_BUTTON, 3);
	//      str.LoadString(IDS_FORWARD);
	//     m_wndToolBar.SetButtonText(1, str);
	m_wndToolBar.SetButtonInfo(2, ID_FILE_LOADSKIN, TBSTYLE_BUTTON, 5);
    //    str.LoadString(IDS_STOP);
	//       m_wndToolBar.SetButtonText(2, str);
	m_wndToolBar.SetButtonInfo(3, ID_FILE_PREFERENCES, TBSTYLE_BUTTON, 0);
	//  str.LoadString(IDS_REFRESH);
	//     m_wndToolBar.SetButtonText(3, str);
	m_wndToolBar.SetButtonInfo(4, ID_FILE_ALARMS, TBSTYLE_BUTTON, 4);
	//        str.LoadString(IDS_HOME);
	//     m_wndToolBar.SetButtonText(4, str);
	m_wndToolBar.SetButtonInfo(5, ID_FILE_LOCATIONS, TBSTYLE_BUTTON, 2);
	//      str.LoadString(IDS_SEARCH);
	//   m_wndToolBar.SetButtonText(5, str);
	m_wndToolBar.SetButtonInfo(6, ID_HELP_CONTENTS, TBSTYLE_BUTTON, 6);
	//        str.LoadString(IDS_FAVORITES);
    //    m_wndToolBar.SetButtonText(6, str);


//	m_wndToolBar.SetButtonInfo(7, ID_FILE_FONT, TBSTYLE_BUTTON, 7);
//	m_wndToolBar.SetButtonInfo(8, ID_HELP_CONTENTS, TBSTYLE_BUTTON, 8);


//	m_wndToolBar.SetButtonInfo(7, ID_HELP_FUTURE, TBSTYLE_BUTTON | TBSTYLE_DROPDOWN, 7);
	//      m_wndToolBar.SetButtonInfo(7, ID_FILE_FONT, TBSTYLE_BUTTON, 7);
	//      str.LoadString(IDS_PRINT);
	//      m_wndToolBar.SetButtonText(7, str);
	//        m_wndToolBar.SetButtonInfo(8, ID_HELP_FUTURE, TBSTYLE_BUTTON | TBSTYLE_DROPDOWN, 8);
	//        str.LoadString(IDS_FONT);
	//       m_wndToolBar.SetButtonText(8, str);
	
	CRect rectButton;
	CRect rectImage;
	
	rectImage.top = 0;
	rectImage.left = 0;
	rectImage.bottom = 48;
	rectImage.right = 48;
	// set up toolbar button sizes
	//        m_wndToolBar.GetItemRect(0, &rectImage);
	
	rectButton = rectImage;
	rectButton.bottom += 6;
	rectButton.right += 7;
	
	
	m_wndToolBar.SetSizes( rectButton.Size(), rectImage.Size() ); //ToolBar.Size(), CSize(30,20));
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//
	//        DEBUGLINE ( __FILE__, __LINE__ );
	//        if (!m_wndToolBar.CreateEx(this) || !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	//        {
	//                TRACE0("Failed to create toolbar\n");
	//                return -1;      // fail to create
	//        }
	
	DEBUGLINE ( __FILE__, __LINE__ );
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	
	
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Remove this if you don't want tool tips
	//        m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
	//                CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_FIXED );
	
	CMenu *menu = GetMenu();
	/*
	m_bit[0].LoadBitmap ( IDB_FILE_ADD );
	m_bit[1].LoadBitmap ( IDB_FILE_ADDTODISPLAY );
	m_bit[2].LoadBitmap ( IDB_FILE_MODIFY );
	m_bit[3].LoadBitmap ( IDB_FILE_DELETE );
	m_bit[4].LoadBitmap ( IDB_FILE_HOME );
	m_bit[5].LoadBitmap ( IDB_APP_EXIT );
	m_bit[6].LoadBitmap ( IDB_HELP_CONTENTS );
	m_bit[7].LoadBitmap ( IDB_FILE_ALARMRESET );
	
	  menu->SetMenuItemBitmaps ( ID_FILE_ADD, MF_BYCOMMAND, &m_bit[0], &m_bit[0] );
	  menu->SetMenuItemBitmaps ( ID_FILE_ADDTODISPLAY, MF_BYCOMMAND, &m_bit[1], &m_bit[1] );
	  menu->SetMenuItemBitmaps ( ID_FILE_MODIFY, MF_BYCOMMAND, &m_bit[2], &m_bit[2] );
	  menu->SetMenuItemBitmaps ( ID_FILE_DELETE, MF_BYCOMMAND, &m_bit[3], &m_bit[3] );
	  menu->SetMenuItemBitmaps ( ID_FILE_HOME, MF_BYCOMMAND, &m_bit[4], &m_bit[4] );
	  menu->SetMenuItemBitmaps ( ID_APP_EXIT, MF_BYCOMMAND, &m_bit[5], &m_bit[5] );
	  menu->SetMenuItemBitmaps ( ID_HELP_CONTENTS, MF_BYCOMMAND, &m_bit[6], &m_bit[6] );
	  menu->SetMenuItemBitmaps ( ID_FILE_ALARMRESET, MF_BYCOMMAND, &m_bit[7], &m_bit[7] );
	*/
	
	if ( !showToolbar )
		m_wndToolBar.ShowWindow ( SW_HIDE );
	else
		GetMenu()->CheckMenuItem ( ID_SHOW_TOOLBAR, MF_CHECKED );
	
	if ( !showStatusBar )
		m_wndStatusBar.ShowWindow ( SW_HIDE );
	else
		GetMenu()->CheckMenuItem ( ID_SHOW_STATUS_BAR, MF_CHECKED );
	
	if ( !r.GetKey ( "ShowHoursGMT" ).word )
//	if ( !d.showHoursGMT )
          ;
	else
		GetMenu()->CheckMenuItem ( ID_VIEW_GMT, MF_CHECKED );
	
	if ( !r.GetKey ("ShowWhatIf").word )
//	if ( !d.showWhatIf )
          ;
	else
		GetMenu()->CheckMenuItem ( ID_VIEW_WHATIF, MF_CHECKED );

	
	// Notify me, please
	m_trayIcon.SetNotificationWnd(this, WM_MY_TRAY_NOTIFICATION); 
	//      m_trayIcon.SetIcon(IDI_MYICON);  
	m_trayIcon.SetIcon(IDI_TRAY);         //resource ID

     if ( versionUpgrade )
          MessageBox ( "Data file is being upgraded to latest version", "Locations Data", MB_OK );

     //		m_wndStatusBar.ShowWindow ( SW_HIDE );
	DEBUGLINE ( __FILE__, __LINE__ );



//    theApp.m_pSkin->ApplySkin((long)m_hWnd); // Apply contained skin to the main frame and its child windows
            theApp.m_pSkin->LoadSkin ( (_bstr_t)r.GetKey ( "SkinName" ).str.c_str()) ;// code. 
//            theApp.m_pSkin->LoadSkin ((_bstr_t)d.skinName.c_str()) ;// code. 
            theApp.m_pSkin->ApplySkin((long)m_hWnd ); //, (_bstr_t)openD.m_ofn.lpstrFile) ;// code. 



	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	DEBUGLINE ( __FILE__, __LINE__ );
	if( !CFrameWnd::PreCreateWindow(cs) )
		return false;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	/*
	cs.x = l.frameRect.left;
	cs.y = l.frameRect.top;
	cs.cx = l.frameRect.right + ( ::GetSystemMetrics ( SM_CXEDGE ) * 4 );
	cs.cy = l.frameRect.bottom + ::GetSystemMetrics ( SM_CYCAPTION )  + 32 + ( ::GetSystemMetrics ( SM_CYEDGE ) * 2 );
	*/
	//	cs.cx = 390;
	//	cs.cy = 345; //300;
	
	// FIX FOR LAMA        return true;
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	
	
	
	return true;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// forward focus to the view window
	//        m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	DEBUGLINE ( __FILE__, __LINE__ );
	//		m_wndView->m_pDocument = 0;
	// let the view have first crack at the command
	//        if (m_wndView->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
	//                return true;
	// debugging
	// otherwise, do default handling
	//		return true;
	m_wndView->ClearDocPtr();	// No document/view here. Will assert otherwise
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


#include "home.h"

void CMainFrame::OnFileHome() 
{
	
	
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	CHome dlg;
	
	if ( dlg.DoModal() == IDOK )
		::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );
}

#include "add.h"

void CMainFrame::OnFileAdd() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	CAdd dlg;
	
	dlg.DoModal();
	
}

/*
#include "features.h"

void CMainFrame::OnHelpFuture() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	CFrameWnd * frame;
	
	frame = new CFrameWnd;
	
	CCreateContext context;
	
    context.m_pNewViewClass = RUNTIME_CLASS ( Features );
	appRect.right = appRect.left + 500;
	appRect.bottom = appRect.top + 500;
	frame->Create ( NULL, "Release Notes", WS_OVERLAPPEDWINDOW, appRect, NULL, NULL, 0, &context );
    frame->ShowWindow(SW_SHOW);
    frame->InitialUpdateFrame( NULL, true );
	
}
  */
#include "adddisplay.h"

void CMainFrame::OnFileAddtodisplay() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	CAddDisplay dlg;
	
	if ( dlg.DoModal() == IDOK )
		::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );
	
}

#include "preferences.h"

void CMainFrame::OnFilePreferences() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	
               
           CPrefPropSheet   allcontrolssheet (_T("Preferences"));
           if ( allcontrolssheet.DoModal() == IDOK )  
	// TODO: Add your command handler code here
//	CPreferences dlg;
	
//	if ( dlg.DoModal() == IDOK )
		::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );
	
}

bool BoundsOK ( CRect & r )
{
    if ( r.left >= 0 && r.top >= 0 && r.right >= 0 && r.bottom >= 0
         && r.right > r.left && r.bottom > r.top )
         return true;

    return false;
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	if ( nType == SIZE_MINIMIZED )
	{
		OnClose();
		return;
	}
	DEBUGLINE ( __FILE__, __LINE__ );
	CFrameWnd::OnSize(nType, cx, cy);
	
	//	l.frameRect.right = l.frameRect.left + cx;
	appRect.right = cx;
  
    
  //  r.GetKey("WindowBottom").word = r.GetKey("WindowTop").word + cy;
//	m.frameRect.bottom = d.frameRect.top + cy;
	//	appRect.bottom = cy;
	
    CRect frameRect;
	GetWindowRect ( &frameRect );

    if ( BoundsOK ( frameRect ))
    {
    r.GetKey("WindowTop").word = frameRect.top;
    r.GetKey("WindowBottom").word = frameRect.bottom;
    r.GetKey("WindowLeft").word = frameRect.left;
    r.GetKey("WindowRight").word = frameRect.right;
    }
	// TODO: Add your message handler code here
	
	
	//		extern CSize viewExtents;
	//	 if ( view )
	//	 {
	//     CSize total ( l.frameRect.right - l.frameRect.left - 35, 1000 );
	//     view->SetScrollSizes ( MM_TEXT, viewExtents );
	//	 }
}

void CMainFrame::OnMove(int x, int y) 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	CFrameWnd::OnMove(x, y);
	
	// TODO: Add your message handler code here
//	d.frameRect.left = appRect.left = x;
//	d.frameRect.top = appRect.top = y;
//	d.frameRect.left = appRect.left = x;
//	d.frameRect.top = appRect.top = y;

    CRect frameRect;
	GetWindowRect ( &frameRect );
    if ( BoundsOK ( frameRect ))
    {
    r.GetKey("WindowTop").word = frameRect.top;
    r.GetKey("WindowBottom").word = frameRect.bottom;
    r.GetKey("WindowLeft").word = frameRect.left;
    r.GetKey("WindowRight").word = frameRect.right;
    }
	
}

//#include "about.h"

/*
void CMainFrame::OnAppAbout() 
{
	DEBUGLINE ( __FILE__, __LINE__ );

	// TODO: Add your command handler code here
    /*
	CFrameWnd * frame;
	
	frame = new CFrameWnd;
	
	CCreateContext context;
	
    context.m_pNewViewClass = RUNTIME_CLASS ( About );
	appRect.right = appRect.left + 450;
	appRect.bottom = appRect.top + 330;
	frame->Create ( NULL, "About WorldTime2000", WS_OVERLAPPEDWINDOW, appRect, NULL, NULL, 0, &context );
	//	frame->Create ( NULL, "About WorldTime2000", WS_OVERLAPPEDWINDOW, appRect, NULL, NULL, 0, &context );
    frame->ShowWindow(SW_SHOW);
    frame->InitialUpdateFrame( NULL, true );
	  */
	//	   (LBS_STANDARD & ~WS_VSCROLL)  // NOT WS_VSCROLL
	
	/*
}
  */
#include "delete.h"

void CMainFrame::OnFileDelete() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	CDelete dlg;
	
	if ( dlg.DoModal() == IDOK )
		::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );
	
}

#include "modify.h"

void CMainFrame::OnFileModify() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	CModify dlg;
	
	//    m_list.SetCurSel ( l.OffsetDisplay ( view->selected - 1 ));
	//		dlg.SetSelected ( l.OffsetDisplay ( view->selected - 1 )); //m_list.GetCurSel());
	//		dlg.SetSelected ( 
	if ( dlg.DoModal() == IDOK )
    {
        m.SetModified ();
        ::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );
    }
	
}

//#include "alarm.h"

void CMainFrame::OnFileAlarm() 
{
	// TODO: Add your command handler code here
	DEBUGLINE ( __FILE__, __LINE__ );
    CDlgAlarms dlg;
	
    dlg.DoModal();
    m.SetModified ();
}


void CMainFrame::OnHelpContents() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	                         
   ShellExecute( AfxGetMainWnd()->m_hWnd, NULL, "help 2.0\\default.htm" , NULL, NULL, SW_SHOWNORMAL );

//	HelpNavigator navigator = HelpNavigator::TableOfContents;
      //if (navigatorCombo->SelectedItem != 0) {
         //navigator = *__try_cast<__box HelpNavigator*>(navigatorCombo->SelectedItem);
      //}
//      Help::ShowHelp(this, helpfile, navigator, parameterTextBox->Text);
//	  Help::ShowHelp(this, "..\\help 2.0\\html\\default.htm");

//    HtmlHelp(NULL, "worldtime2000.chm::/title.htm", HH_DISPLAY_TOPIC, 0);
	// TODO: Add your command handler code here
/*	CFrameWnd * frame;
	
	frame = new CFrameWnd;
	
	CCreateContext context;
	
	context.m_pNewViewClass = RUNTIME_CLASS ( Help );
	appRect.right = appRect.left + 800; //550;
	appRect.bottom = appRect.top + 400;
	frame->Create ( NULL, "WorldTime2000 Help", WS_OVERLAPPEDWINDOW, appRect, NULL, NULL, 0, &context );
	frame->ShowWindow(SW_SHOW);
	frame->InitialUpdateFrame( NULL, true );
  */	
							 }


void CMainFrame::OnDestroy() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	CFrameWnd::OnDestroy();
	
	// TODO: Add your message handler code here
	/*
	CMenu *menu = GetMenu();
	UINT retVal;
	
	  MENUITEMINFO menuInfo;
	  menu->GetMenuItemInfo ( ID_VIEW_TOOLBAR, &menuInfo );
	  if ( menuInfo.fState & MFS_CHECKED )
	  showToolbar = 1;
	  else
	  showToolbar = 0;
	  
		menu->GetMenuItemInfo ( ID_VIEW_STATUS_BAR, &menuInfo );
		if ( menuInfo.fState & MFS_CHECKED )
		showStatusBar = 1;
		else
		showStatusBar = 0;
	*/
	/*
	retVal = menu->GetMenuState ( ID_VIEW_TOOLBAR, MF_BYCOMMAND );
	if ( retVal & MF_CHECKED )
	showToolbar = 1;
	else
	showToolbar = 0;
	
	  retVal = menu->GetMenuState ( ID_VIEW_STATUS_BAR, MF_BYCOMMAND );
	  if ( retVal & MF_CHECKED )
	  showStatusBar = 1;
	  else
	  showStatusBar = 0;
	*/
	
}

BOOL CMainFrame::DestroyWindow() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your specialized code here and/or call the base class
	/*        CMenu *menu = GetMenu();
	UINT retVal;
	
	  DWORD err;
	  
		MENUITEMINFO menuInfo;
		if ( menu->GetMenuItemInfo ( ID_VIEW_TOOLBAR, &menuInfo ) == 0 )
		err = GetLastError ();
		
		  if ( menuInfo.fState & MFS_CHECKED )
		  showToolbar = 1;
		  else
		  showToolbar = 0;
		  
			if ( menu->GetMenuItemInfo ( ID_VIEW_STATUS_BAR, &menuInfo ) == 0 )
			err = GetLastError();
			if ( menuInfo.fState & MFS_CHECKED )
			showStatusBar = 1;
			else
			showStatusBar = 0;
	*/
	
//	if ( MessageBox ( "Save your preferences and locations now ?", "Save Data", MB_YESNO ) == IDYES )
//		l.Save();

	return CFrameWnd::DestroyWindow();
}

void CMainFrame::OnViewStatusBar() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
    CMenu *menu = GetMenu();
	if ( showStatusBar )
	{
		showStatusBar = 0;
		menu->CheckMenuItem ( ID_SHOW_STATUS_BAR, MF_UNCHECKED );
		m_wndStatusBar.ShowWindow ( SW_HIDE );
		RecalcLayout();
	}
	else
	{
		showStatusBar = 1;
		menu->CheckMenuItem ( ID_SHOW_STATUS_BAR, MF_CHECKED );
		m_wndStatusBar.ShowWindow ( SW_SHOW );
		RecalcLayout();
	}
}

void CMainFrame::OnViewToolbar() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
    CMenu *menu = GetMenu();
	if ( showToolbar )
	{
		showToolbar = 0;
		menu->CheckMenuItem ( ID_SHOW_TOOLBAR, MF_UNCHECKED );
		m_wndToolBar.ShowWindow ( SW_HIDE );
		RecalcLayout();
	}
	else
	{
		showToolbar = 1;
		menu->CheckMenuItem ( ID_SHOW_TOOLBAR, MF_CHECKED );
		m_wndToolBar.ShowWindow ( SW_SHOW );
		RecalcLayout();
	}
	
}

extern int alarm;

void CMainFrame::OnFileAlarmreset() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	alarm = -2;
	// reset alarm in 1 minute
	
}

void CMainFrame::OnContextDelete() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
    if ( view->selected == -1 )
	{
		MessageBox ( "You cannot delete your home!", "Error", MB_OK | MB_ICONERROR );
		return;
	}
	
	
	char buf[200];

	string city = l.GetLocationbyTag( m.GetMemberByIdx ( view->selected )->LocRef())->city;
	string country = l.GetLocationbyTag( m.GetMemberByIdx ( view->selected )->LocRef())->country;

//	string city = l.GetLocationbyTag( l.OffsetDisplay ( view->selected ))->city;
//	string country = l.GetLocationbyTag( l.OffsetDisplay ( view->selected ))->country;
	
	sprintf ( buf, "Delete %s, %s ?\n( This will only remove the location from the display,\nNOT from the database )", city.c_str(), country.c_str() );
	
    if ( MessageBox ( buf, "Confirm Delete", MB_YESNO | MB_ICONQUESTION ) != IDNO )
		//    if ( MessageBox ( "Delete location ? ( This will only remove the location from the display )", "Confirm Delete", MB_YESNO | MB_ICONQUESTION ) != IDNO )
		m.DeleteList ( m.Tag (view->selected ));
}

void CMainFrame::OnContextModify() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	if ( view->selected == -1 )
	{
		MessageBox ( "You cannot modify your home. Use the Date/Time settings in the Windows control panel to set/alter time zones", "Error", MB_OK | MB_ICONERROR );
		return;
	}
	
	
	CModify dlg;
	
//	selectedbyString = l.GetLocationbyTag( l.OffsetDisplay ( view->selected ))->city;
	selectedbyString = l.GetLocationbyTag( m.GetMemberByIdx ( view->selected )->LocRef())->city;
	
	//        dlg.SetSelected ( l.OffsetDisplay ( view->selected ), 0 ); // FIX UP!!! //m_list.GetCurSel());
	if ( dlg.DoModal() == IDOK )
    {
         m.SetModified ();
	    ::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );
    }
}

void CMainFrame::OnContextMove() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	if ( view->selected == -1 )
	{
		MessageBox ( "You cannot move your home", "Error", MB_OK | MB_ICONERROR );
		return;
	}
	
	
	view->moveModeOn = 1;
	view->moveSrc = view->selected;
    m.SetModified ();
}


void CMainFrame::OnContextFont() 
{
	DEBUGLINE ( __FILE__, __LINE__ );

	LOGFONT userFont;
    CFont font;
    MemberItem * mItem;
	// TODO: Add your command handler code here
    if ( view->selected == -1 )
	{
        mItem = m.GetHome();
//        font.CreatePointFont ( m.GetHome()->GetFont()->fontSize, m.GetHome()->GetFont()->fontName.c_str() );
	}
    else
    {
        mItem = m.GetMemberByIdx(view->selected);
  //      font.CreatePointFont ( m.GetMemberByIdx(view->selected)->GetFont()->fontSize, m.GetMemberByIdx(view->selected)->GetFont()->fontName.c_str() );
//        font.CreatePointFont ( d.fontSize, d.fontName.c_str() );
    }
	
    font.CreatePointFont ( mItem->GetFont()->fontSize, mItem->GetFont()->fontName.c_str() );
	font.GetLogFont ( &userFont );
	if ( mItem->GetFont()->fontBold )
		userFont.lfWeight = FW_BOLD;
	userFont.lfItalic = ( unsigned char ) mItem->GetFont()->fontItalic;
	userFont.lfUnderline = ( unsigned char ) mItem->GetFont()->fontUnderline;
	
	// TODO: Add your command handler code here
	CFontDialog dlg ( &userFont );
	
    dlg.m_cf.rgbColors = mItem->GetFont()->fontColor;
	if ( dlg.DoModal() != IDOK )
		return;

    mItem->GetFont()->fontName = dlg.GetFaceName();
    mItem->GetFont()->fontSize = dlg.GetSize();
    mItem->GetFont()->fontItalic = dlg.IsItalic();
    mItem->GetFont()->fontBold = dlg.IsBold();
    mItem->GetFont()->fontColor = dlg.GetColor();
    mItem->GetFont()->fontUnderline = dlg.IsUnderline();

    m.SetModified ();
//	CString str = dlg.GetFaceName();
//	d.fontName = str.GetBuffer ( 150 );
//	d.fontSize = dlg.GetSize();
//	d.fontItalic = dlg.IsItalic();
//	d.fontBold = dlg.IsBold();
    
}


void CMainFrame::OnFileFont() 
{
	LOGFONT userFont;
    CFont font;
    font.CreatePointFont ( 110, "Arial" );
	font.GetLogFont ( &userFont );
	CFontDialog dlg ( &userFont );
	
	if ( dlg.DoModal() != IDOK )
		return;

    m.SetModified ();


    MemberItem * mItem = m.GetHome();
    mItem->GetFont()->fontName = dlg.GetFaceName();
    mItem->GetFont()->fontSize = dlg.GetSize();
    mItem->GetFont()->fontItalic = dlg.IsItalic();
    mItem->GetFont()->fontBold = dlg.IsBold();
    mItem->GetFont()->fontColor = dlg.GetColor();
    mItem->GetFont()->fontUnderline = dlg.IsUnderline();


    for ( int i = 0; mItem = m.GetMemberByIdx ( i ); i++ )
    {
        mItem->GetFont()->fontName = dlg.GetFaceName();
        mItem->GetFont()->fontSize = dlg.GetSize();
        mItem->GetFont()->fontItalic = dlg.IsItalic();
        mItem->GetFont()->fontBold = dlg.IsBold();
        mItem->GetFont()->fontColor = dlg.GetColor();
        mItem->GetFont()->fontUnderline = dlg.IsUnderline();

    }
    /*
	DEBUGLINE ( __FILE__, __LINE__ );
	LOGFONT userFont;
    CFont font;
    font.CreatePointFont ( d.fontSize, d.fontName.c_str() );
	
	font.GetLogFont ( &userFont );
	if ( d.fontBold )
		userFont.lfWeight = FW_BOLD;
	userFont.lfItalic = ( unsigned char ) d.fontItalic;
	
	// TODO: Add your command handler code here
	CFontDialog dlg ( &userFont );
	
	if ( dlg.DoModal() != IDOK )
		return;
	
	CString str = dlg.GetFaceName();
	d.fontName = str.GetBuffer ( 150 );
	d.fontSize = dlg.GetSize();
	d.fontItalic = dlg.IsItalic();
	d.fontBold = dlg.IsBold();
    */
}
/*
#include "order.h"
void CMainFrame::OnOrder() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	CFrameWnd * frame;
	
	frame = new CFrameWnd;
	
	CCreateContext context;
	
	context.m_pNewViewClass = RUNTIME_CLASS ( Order );
	appRect.right = appRect.left + 500;
	appRect.bottom = appRect.top + 400;
	frame->Create ( NULL, "How to order WorldTime2000", WS_OVERLAPPEDWINDOW, appRect, NULL, NULL, 0, &context );
	frame->ShowWindow(SW_SHOW);
	frame->InitialUpdateFrame( NULL, true );
	
	
}
  

#include "time.h"

void CMainFrame::OnTimesync() 
{
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	CFrameWnd * frame;
	
	frame = new CFrameWnd;
	
	CCreateContext context;
	
	context.m_pNewViewClass = RUNTIME_CLASS ( TimeSync );
	appRect.right = appRect.left + 500;
	appRect.bottom = appRect.top + 400;
	frame->Create ( NULL, "Sync with time server ( MUST BE ONLINE )", WS_OVERLAPPEDWINDOW, appRect, NULL, NULL, 0, &context );
	frame->ShowWindow(SW_SHOW);
	frame->InitialUpdateFrame( NULL, true );
	
}
  */
void CMainFrame::OnDropDown(NMHDR* pNotifyStruct, LRESULT* pResult)
{
	// this function handles the dropdown menus from the toolbar
	NMTOOLBAR* pNMToolBar = (NMTOOLBAR*)pNotifyStruct;
	CRect rect;
	
	// translate the current toolbar item rectangle into screen coordinates
	// so that we'll know where to pop up the menu
	m_wndToolBar.GetToolBarCtrl().GetRect(pNMToolBar->iItem, &rect);
	rect.top = rect.bottom;
	::ClientToScreen(pNMToolBar->hdr.hwndFrom, &rect.TopLeft());
	if(pNMToolBar->iItem == ID_FILE_PREFERENCES)
	{
		CMenu menu;
		CMenu* pPopup;
		
		// the font popup is stored in a resource
		menu.LoadMenu(IDR_PREFERENCES);
		pPopup = menu.GetSubMenu(0);
		pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, rect.left, rect.top + 1, AfxGetMainWnd());
	}
	else if(pNMToolBar->iItem == ID_HELP_CONTENTS )
	{
		CMenu menu;
		CMenu* pPopup;
		
		menu.LoadMenu(IDR_DOCUMENTATION);
		pPopup = menu.GetSubMenu(0);
		pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, rect.left, rect.top + 1, AfxGetMainWnd());
		// for the favorties popup, just steal the menu from the main window
		//  pPopup = GetMenu()->GetSubMenu(3);
		//  pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, rect.left, rect.top + 1, AfxGetMainWnd());
	}
	*pResult = TBDDRET_DEFAULT;
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	if (m_bShutdown)
		CFrameWnd::OnClose();
	else
		ShowWindow(SW_HIDE);
}

void CMainFrame::OnAppExit() 
{
	// TODO: Add your command handler code here

//	if ( MessageBox ( "Save your preferences and locations now ?", "Save Data", MB_YESNO ) == IDYES )
//		l.Save();

	m_bShutdown = true;             // really exit
	SendMessage(WM_CLOSE);
}

void CMainFrame::OnAppOpen() 
{
	// TODO: Add your command handler code here
	
	ShowWindow(SW_NORMAL);
	SetForegroundWindow();
}

void CMainFrame::OnSortCountry() 
{
	// TODO: Add your command handler code here
	static bool ascending = true;
	
	MemberItem * aItem1, *aItem2;
	bool sorted = false;
	
	while ( sorted == false )
	{
		sorted = true;
		
		for ( int i = 0; aItem2 = m.GetMemberByIdx ( i + 1 ); i++ )
		{
			aItem1 = m.GetMemberByIdx ( i );
			LocationItem * li1, * li2;
			
			if ( aItem1 == 0 || aItem2 == 0 )
				break;
			
			li1 = l.GetLocationbyTag ( aItem1->LocRef() );
			li2 = l.GetLocationbyTag ( aItem2->LocRef() );
			
			if ( ascending )
			{
				if ( stricmp ( li2->country.c_str(), li1->country.c_str() ) < 0 )
				{
                    m.Move ( i+1, i );  // move only works if greater number 1st argument
//					short tmp = *aItem2;
//					*aItem2 = *aItem1;
//					*aItem1 = tmp;
					sorted = false;
				}
			}
			else
			{
				if ( stricmp ( li2->country.c_str(), li1->country.c_str() ) > 0 )
				{
                    m.Move ( i+1, i);
//					short tmp = *aItem2;
//					*aItem2 = *aItem1;
//					*aItem1 = tmp;
					sorted = false;
				}
			}
		}
	}
	
	( ascending == true ) ? ascending = false : ascending = true;
	
}

void CMainFrame::OnSortName() 
{
	// TODO: Add your command handler code here
	static bool ascending = true;
	
	MemberItem * aItem1, *aItem2;
	bool sorted = false;
	
	while ( sorted == false )
	{
		sorted = true;
		
		for ( int i = 0; aItem2 = m.GetMemberByIdx ( i + 1 ); i++ )
		{
			aItem1 = m.GetMemberByIdx ( i );
			LocationItem * li1, * li2;
			
			if ( aItem1 == 0 || aItem2 == 0 )
				break;
			
			li1 = l.GetLocationbyTag ( aItem1->LocRef() );
			li2 = l.GetLocationbyTag ( aItem2->LocRef() );
			
			if ( ascending )
			{
				if ( stricmp ( li2->city.c_str(), li1->city.c_str() ) < 0 )
				{
                    m.Move ( i+1, i );
//					short tmp = *aItem2;
//					*aItem2 = *aItem1;
//					*aItem1 = tmp;
					sorted = false;
				}
			}
			else
			{
				if ( stricmp ( li2->city.c_str(), li1->city.c_str() ) > 0 )
				{
                    m.Move ( i+1, i );
//					short tmp = *aItem2;
//					*aItem2 = *aItem1;
//					*aItem1 = tmp;
					sorted = false;
				}
			}
		}
	}
	
	( ascending == true ) ? ascending = false : ascending = true;
}

void CMainFrame::OnSortTime() 
{
	// TODO: Add your command handler code here
	static bool ascending = true;
	
	MemberItem * aItem1, *aItem2;
	bool sorted = false;
	
	while ( sorted == false )
	{
		sorted = true;
		
		for ( int i = 0; aItem2 = m.GetMemberByIdx ( i + 1 ); i++ )
		{
			aItem1 = m.GetMemberByIdx ( i );
			LocationItem * li1, * li2;
			
			if ( aItem1 == 0 || aItem2 == 0 )
				break;
			
			li1 = l.GetLocationbyTag ( aItem1->LocRef() );
			li2 = l.GetLocationbyTag ( aItem2->LocRef() );
			
			if ( ascending )
			{
				if ( li2->offset < li1->offset )
				{
                    m.Move ( i+1, i );
//					short tmp = *aItem2;
//					*aItem2 = *aItem1;
//					*aItem1 = tmp;
					sorted = false;
				}
			}
			else
			{
				if ( li2->offset > li1->offset )
				{
                    m.Move ( i+1, i );
//					short tmp = *aItem2;
//					*aItem2 = *aItem1;
//					*aItem1 = tmp;
					sorted = false;
				}
			}
		}
	}
	
	( ascending == true ) ? ascending = false : ascending = true;
	
}

void CMainFrame::OnFileSave() 
{
	// TODO: Add your command handler code here
	l.Save();	
}

void CMainFrame::OnViewGmt() 
{
	// TODO: Add your command handler code here
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
    CMenu *menu = GetMenu();
	if ( r.GetKey ( "ShowHoursGMT" ).word )
//	if ( d.showHoursGMT )
	{
    	r.GetKey ( "ShowHoursGMT" ).word  = 0;
		//d.showHoursGMT = 0;
		menu->CheckMenuItem ( ID_VIEW_GMT, MF_UNCHECKED );
//		m_wndStatusBar.ShowWindow ( SW_HIDE );
		RecalcLayout();
	}
	else
	{
    	r.GetKey ( "ShowHoursGMT" ).word  = 1;
		//d.showHoursGMT = 1;
		menu->CheckMenuItem ( ID_VIEW_GMT, MF_CHECKED );
//		m_wndStatusBar.ShowWindow ( SW_SHOW );
		RecalcLayout();
	}
	
}

#include "legend.h"

void CMainFrame::OnHelpLegend() 
{
	// TODO: Add your command handler code here
	DEBUGLINE ( __FILE__, __LINE__ );
	
	// TODO: Add your command handler code here
	CLegend dlg;
	
     dlg.DoModal();
//		::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );
	
}

void CMainFrame::OnEndSession(BOOL bEnding) 
{
	CFrameWnd::OnEndSession(bEnding);
	
	if ( MessageBox ( "Save your preferences and locations now ?", "Save Data", MB_YESNO ) == IDYES )
		l.Save();


	// TODO: Add your message handler code here
	
}

#include "whatif.h"

void CMainFrame::OnContextWhatif() 
{
	// TODO: Add your command handler code here
	whatif dlg;
	
     dlg.DoModal();
	
}

void CMainFrame::OnViewWhatif() 
{
	// TODO: Add your command handler code here
	DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
    CMenu *menu = GetMenu();
	if ( r.GetKey ("ShowWhatIf").word )
//	if ( d.showWhatIf )
	{
    	r.GetKey ("ShowWhatIf").word = 0;
		//d.showWhatIf = 0;
		menu->CheckMenuItem ( ID_VIEW_WHATIF, MF_UNCHECKED );
		//m_wndStatusBar.ShowWindow ( SW_HIDE );
		RecalcLayout();
	}
	else
	{
    	r.GetKey ("ShowWhatIf").word = 1;
		//d.showWhatIf = 1;
		menu->CheckMenuItem ( ID_VIEW_WHATIF, MF_CHECKED );
		//m_wndStatusBar.ShowWindow ( SW_SHOW );
		RecalcLayout();
	}
}

void CMainFrame::OnFileLoadskin() 
{
	// TODO: Add your command handler code here

            
            // TODO: Add your command handler code here
          char * filterBuf= "WorldTime2000 Skins\0*.skn;*.cmo\0\0\0";
          CFileDialog openD ( true );

          openD.m_ofn.lpstrFilter = filterBuf;
          openD.m_ofn.lpstrInitialDir = ".\\";
          openD.m_ofn.lpstrTitle = "Select a Skin";

         if ( openD.DoModal () == IDOK )
         {
            //
            // open file and read data
            //

//             CComQIPtr<ISkin> pSkin = AfxGetMainWnd()->GetDlgItem(IDC_SKIN)->GetControlUnknown();
//             main->pSkin->LoadSkin ( (_bstr_t) openD.m_ofn.lpstrFile );


//            theApp.m_pSkin->ApplySkinByName((long)m_hWnd, L"test") ;// code. 
            theApp.m_pSkin->LoadSkin ((_bstr_t)openD.m_ofn.lpstrFile) ;// code. 
            r.GetKey("SkinName").str = openD.m_ofn.lpstrFile ;// code. 
            //d.skinName = openD.m_ofn.lpstrFile ;// code. 
//            theApp.m_pSkin->ApplySkinByName((long)AfxGetMainWnd(), L"main" );// code. 

//            theApp.m_pSkin->ApplySkinByName((long)m_hWnd, (_bstr_t)openD.m_ofn.lpstrFile) ;// code. 
//             main->ApplySkin ( openD.m_ofn.lpstrFile );

            theApp.m_pSkin->ApplySkin((long)m_hWnd ); //, (_bstr_t)openD.m_ofn.lpstrFile) ;// code. 
//            theApp.m_pSkin->ApplySkinByName((long)AfxGetMainWnd(), (_bstr_t)openD.m_ofn.lpstrFile) ;// code. 

//             theApp.m_pSkin->ApplySkin ((long) openD.m_ofn.lpstrFile );
         }
             


}

void CMainFrame::OnFileRemoveskin() 
{
	// TODO: Add your command handler code here
    theApp.m_pSkin->RemoveSkin ((long)m_hWnd);	
    r.GetKey ( "SkinName" ).str = "";
//    d.skinName = "";
//    theApp.m_pSkin->RemoveSkin ((long)AfxGetMainWnd());	
}



void CMainFrame::OnFileLocations() 
{
	// TODO: Add your command handler code here
    CDlgLocation dlg;
    dlg.DoModal ();	
}

void CMainFrame::OnFileAlarms() 
{
	// TODO: Add your command handler code here
    OnFileAlarm();	
}
