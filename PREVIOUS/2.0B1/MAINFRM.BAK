//ID_APP_ABOUT Toolbar entry to show item help
//ID_CONTEXT_HELP
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "WorldTime2000.h"

#include "WorldTime2000view.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMainFrame * mainFrame;
CRect appRect;
short showToolbar = 1, showStatusBar = 1;

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
        //{{AFX_MSG_MAP(CMainFrame)
        ON_WM_CREATE()
        ON_WM_SETFOCUS()
        ON_COMMAND(ID_FILE_HOME, OnFileHome)
        ON_COMMAND(ID_FILE_ADD, OnFileAdd)
        ON_COMMAND(ID_HELP_FUTURE, OnHelpFuture)
        ON_COMMAND(ID_FILE_ADDTODISPLAY, OnFileAddtodisplay)
        ON_COMMAND(ID_FILE_PREFERENCES, OnFilePreferences)
        ON_WM_SIZE()
        ON_WM_MOVE()
        ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
        ON_COMMAND(ID_FILE_DELETE, OnFileDelete)
        ON_COMMAND(ID_FILE_MODIFY, OnFileModify)
        ON_COMMAND(ID_FILE_ALARM, OnFileAlarm)
        ON_COMMAND(ID_CONTEXT_DELETE, OnContextDelete)
        ON_COMMAND(ID_CONTEXT_MODIFY, OnContextModify)
        ON_COMMAND(ID_CONTEXT_MOVE, OnContextMove)
        ON_COMMAND(ID_HELP_CONTENTS, OnHelpContents)
        ON_WM_DESTROY()
        ON_COMMAND(ID_SHOW_STATUS_BAR, OnViewStatusBar)
        ON_COMMAND(ID_SHOW_TOOLBAR, OnViewToolbar)
	ON_COMMAND(ID_FILE_ALARMRESET, OnFileAlarmreset)
	ON_COMMAND(ID_REGISTER, OnRegister)
	ON_COMMAND(ID_FILE_FONT, OnFileFont)
	ON_COMMAND(ID_ORDER, OnOrder)
	ON_COMMAND(ID_TIMESYNC, OnTimesync)
	//}}AFX_MSG_MAP
        // Global help commands
END_MESSAGE_MAP()
//        ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
//        ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
//        ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
//        ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)

static UINT indicators[] =
{
        ID_SEPARATOR,           // status line indicator
        ID_INDICATOR_CAPS,
        ID_INDICATOR_NUM,
        ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
        DEBUGLINE ( __FILE__, __LINE__ );
        // TODO: add member initialization code here
        appRect = rectDefault;
		mainFrame = this;
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

//	theApp.m_pMainWnd->MoveWindow ( &frameRect );
        MoveWindow ( &l.frameRect );
//	GetWindowRect ( &l.frameRect );

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


        DEBUGLINE ( __FILE__, __LINE__ );
        if (!m_wndToolBar.CreateEx(this) ||
//	    !m_wndToolBar.GetToolBarCtrl().SetButtonSize ( iconSize ) ||
//		!m_wndToolBar.LoadBitmap(IDB_BITMAP1))
                !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
        {
                TRACE0("Failed to create toolbar\n");
                return -1;      // fail to create
        }

/*

        m_wndToolBar.CreateEx(this);
//	m_wndToolBar.GetToolBarCtrl().SetButtonSize ( iconSize );
        m_wndToolBar.LoadToolBar(IDR_MAINFRAME);

        //CSize iconSize;
        iconSize.cx = 5; iconSize.cy = 32;

        m_wndToolBar.GetToolBarCtrl().SetButtonSize ( iconSize );
        m_wndToolBar.GetToolBarCtrl().SetButtonWidth ( 15, 15 );
        m_wndToolBar.GetToolBarCtrl().AutoSize ();
*/
//	m_wndToolBar.SetSizes ( iconSize, iconSize );
/*
        hWndToolbar = CreateToolbarEx (hWndParent, 
                WS_CHILD | WS_BORDER | WS_VISIBLE | WS_CHILD | TBSTYLE_TOOLTIPS, 
                ID_TOOLBAR, 11, (HINSTANCE)HINST_COMMCTRL, IDB_STD_SMALL_COLOR, 
                (LPCTBBUTTON)&tbButtons, 4, 0, 0, 100, 30, sizeof (TBBUTTON));
*/
/*
        if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, 
                CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
        {
                TRACE0("Failed to create dialogbar\n");
                return -1;		// fail to create
        }
*/
        DEBUGLINE ( __FILE__, __LINE__ );
        /*
        if (!m_wndReBar.Create(this) ||
                !m_wndReBar.AddBar(&m_wndToolBar)) // ||
//		!m_wndReBar.AddBar(&m_wndDlgBar))
        {
                TRACE0("Failed to create rebar\n");
                return -1;      // fail to create
        }
          */
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
        m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
                CBRS_TOOLTIPS | CBRS_FLYBY);

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



//		m_wndStatusBar.ShowWindow ( SW_HIDE );
        DEBUGLINE ( __FILE__, __LINE__ );
        return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
        DEBUGLINE ( __FILE__, __LINE__ );
        if( !CFrameWnd::PreCreateWindow(cs) )
                return FALSE;
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

// FIX FOR LAMA        return TRUE;
        cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
        cs.lpszClass = AfxRegisterWndClass(0);



        return TRUE;
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
//                return TRUE;
// debugging
        // otherwise, do default handling
//		return TRUE;
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

#include "features.h"

void CMainFrame::OnHelpFuture() 
{
        DEBUGLINE ( __FILE__, __LINE__ );
        // TODO: Add your command handler code here
        CFrameWnd * frame;

        frame = new CFrameWnd;

        CCreateContext context;

    context.m_pNewViewClass = RUNTIME_CLASS ( Features );
                                  /*
        frame.Create( LPCTSTR lpszClassName, 
                LPCTSTR lpszWindowName, 
                DWORD dwStyle = 
                WS_OVERLAPPEDWINDOW, 
                const RECT& rect = rectDefault, 
                CWnd* pParentWnd = NULL, 
                LPCTSTR lpszMenuName = NULL, 
                DWORD dwExStyle = 0, 
                CCreateContext* pContext = NULL );


                                */
        appRect.right = appRect.left + 500;
        appRect.bottom = appRect.top + 500;
        frame->Create ( NULL, "Release Notes", WS_OVERLAPPEDWINDOW, appRect, NULL, NULL, 0, &context );
    frame->ShowWindow(SW_SHOW);
    frame->InitialUpdateFrame( NULL, TRUE );

//	Sleep ( 30000 );

//	CFeatures dlg;

//	dlg.DoModal();

}

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

        // TODO: Add your command handler code here
        CPreferences dlg;

        if ( dlg.DoModal() == IDOK )
          ::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );

}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
        DEBUGLINE ( __FILE__, __LINE__ );
        CFrameWnd::OnSize(nType, cx, cy);

//	l.frameRect.right = l.frameRect.left + cx;
        appRect.right = cx;
        l.frameRect.bottom = l.frameRect.top + cy;
//	appRect.bottom = cy;

        GetWindowRect ( &l.frameRect );
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
        l.frameRect.left = appRect.left = x;
        l.frameRect.top = appRect.top = y;

        GetWindowRect ( &l.frameRect );

}

#include "about.h"

void CMainFrame::OnAppAbout() 
{
        DEBUGLINE ( __FILE__, __LINE__ );
        // TODO: Add your command handler code here
        CFrameWnd * frame;

        frame = new CFrameWnd;

        CCreateContext context;

    context.m_pNewViewClass = RUNTIME_CLASS ( About );
        appRect.right = appRect.left + 450;
        appRect.bottom = appRect.top + 330;
        frame->Create ( NULL, "About WorldTime2000", WS_OVERLAPPEDWINDOW, appRect, NULL, NULL, 0, &context );
//	frame->Create ( NULL, "About WorldTime2000", WS_OVERLAPPEDWINDOW, appRect, NULL, NULL, 0, &context );
    frame->ShowWindow(SW_SHOW);
    frame->InitialUpdateFrame( NULL, TRUE );

//	   (LBS_STANDARD & ~WS_VSCROLL)  // NOT WS_VSCROLL


}

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
        dlg.DoModal();
    ::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );

}

#include "alarm.h"

void CMainFrame::OnFileAlarm() 
{
        // TODO: Add your command handler code here
        DEBUGLINE ( __FILE__, __LINE__ );
    CAlarm dlg;

    dlg.DoModal();
    ::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );
}

#include "help.h"

void CMainFrame::OnHelpContents() 
{
        DEBUGLINE ( __FILE__, __LINE__ );
        // TODO: Add your command handler code here
     CFrameWnd * frame;

     frame = new CFrameWnd;

     CCreateContext context;

     context.m_pNewViewClass = RUNTIME_CLASS ( Help );
     appRect.right = appRect.left + 500;
     appRect.bottom = appRect.top + 400;
     frame->Create ( NULL, "WorldTime2000 Help", WS_OVERLAPPEDWINDOW, appRect, NULL, NULL, 0, &context );
     frame->ShowWindow(SW_SHOW);
     frame->InitialUpdateFrame( NULL, TRUE );

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

    if ( MessageBox ( "Delete location ? ( This will only remove the location from the display )", "Confirm Delete", MB_YESNO | MB_ICONQUESTION ) != IDNO )
	   l.Delete ( view->selected );
}

void CMainFrame::OnContextModify() 
{
        DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	if ( view->selected == -1 )
	{
	    MessageBox ( "You cannot modify your home. Use Windows control panel to change time zones", "Error", MB_OK | MB_ICONERROR );
		return;
	}


	CModify dlg;
	dlg.SetSelected ( l.OffsetDisplay ( view->selected )); //m_list.GetCurSel());
        dlg.DoModal();
    ::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );
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
}

/*
void CMainFrame::OnModify ()
{
	OnContextModify():
}
  */
#include "register.h"

void CMainFrame::OnRegister() 
{
        DEBUGLINE ( __FILE__, __LINE__ );
	// TODO: Add your command handler code here
	CRegister dlg;
	
	dlg.DoModal ();
    ::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );
}



void CMainFrame::OnFileFont() 
{
        DEBUGLINE ( __FILE__, __LINE__ );
	LOGFONT userFont;
    CFont font;
    font.CreatePointFont ( l.fontSize, l.fontName );

	font.GetLogFont ( &userFont );
	if ( l.fontBold )
		userFont.lfWeight = FW_BOLD;
	userFont.lfItalic = l.fontItalic;

	// TODO: Add your command handler code here
	CFontDialog dlg ( &userFont );
	
	if ( dlg.DoModal() != IDOK )
		return;

	CString str = dlg.GetFaceName();
	l.fontName = str.GetBuffer ( 150 );
	l.fontSize = dlg.GetSize();
	l.fontItalic = dlg.IsItalic();
	l.fontBold = dlg.IsBold();
}

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
     frame->InitialUpdateFrame( NULL, TRUE );

	
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
     frame->InitialUpdateFrame( NULL, TRUE );
	
}
