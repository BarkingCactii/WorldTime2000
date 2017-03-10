// PrefTimePropPage.cpp : implementation file
//

#include "stdafx.h"
#include "worldtime2000.h"
#include "PrefTimePropPage.h"
#include "regdata.h"
#include "DlgUpdater.h"
//#include "skinDlg.h"
#include "htmlhelp.h"
#include "mainfrm.h"
//#include "OnLineTimeView.h"
//#include <strstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "label.h"
/////////////////////////////////////////////////////////////////////////////
// CPrefTimePropPage property page

IMPLEMENT_DYNCREATE(CPrefTimePropPage, CPropertyPage)

CPrefTimePropPage::CPrefTimePropPage() : CPropertyPage(CPrefTimePropPage::IDD)
{   /*
	m_showWallpaper = r.GetKey("ShowWallpaper").word;
	m_backgroundColor = r.GetKey("BackgroundColor").word;
	m_wallpaperName = r.GetKey("WallpaperName").str.c_str();
      */
	//{{AFX_DATA_INIT(CPrefTimePropPage)

	m_24Hour = r.GetKey("Show24Hour").word;
	m_showAM = r.GetKey("ShowAM").word;
	m_alwaysOnTop = 0;
	m_seconds = r.GetKey("ShowSeconds").word;
	m_tooltips = r.GetKey("ShowTooltips").word;
	//}}AFX_DATA_INIT
}

CPrefTimePropPage::~CPrefTimePropPage()
{
}

void CPrefTimePropPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrefTimePropPage)
	DDX_Check(pDX, IDC_PREFERENCES_24HOUR, m_24Hour);
	DDX_Check(pDX, IDC_PREFERENCES_SHOWAM, m_showAM);
	DDX_Check(pDX, IDC_PREFERENCES_TOPMOST, m_alwaysOnTop);
	DDX_Check(pDX, IDC_PREFERENCES_SECONDS, m_seconds);
	DDX_Check(pDX, IDC_PREFERENCES_TOOLTIPS, m_tooltips);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrefTimePropPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPrefTimePropPage)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrefTimePropPage message handlers

BOOL CPrefTimePropPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
    SetModified ( TRUE );

	// TODO: Add extra initialization here

    strstream sout;

    sout << r.FontName().c_str() << " " 
         << ( int ) (r.FontSize() / 10) 
         << ( r.FontItalic() ? " Italic" : "" )
         << ( r.FontBold() ? " Bold" : "" )
         << ends << flush;


//    m_message.SetFontItalic ( TRUE );

     theApp.m_pSkin->ApplySkin((long)m_hWnd); // Apply contained skin to the main frame and its child windows

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPrefTimePropPage::OnOK() 
{
	// TODO: Add your specialized code here and/or call the base class
//    r.BackgroundColor ( m_backgroundColor );

//	r.Show24Hour( m_24Hour );
//	r.ShowSeconds( m_showSeconds );
//	r.ShowAM( m_showAM );

//    r.ShowDetailed ( m_detailed );

 //   r.AlwaysOnTop ( m_alwaysOnTop );
//     mainView->Invalidate ( FALSE );

	r.GetKey("Show24Hour").word = m_24Hour;
	r.GetKey("ShowAM").word = m_showAM;
	r.GetKey("ShowSeconds").word = m_seconds;
	r.GetKey("ShowTooltips").word = m_tooltips;


        if ( m_alwaysOnTop )
            mainFrame->SetWindowPos ( &wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE );
        else
            mainFrame->SetWindowPos ( &wndNoTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE );
  
	CPropertyPage::OnOK();
}

BOOL CPrefTimePropPage::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
    SetModified ( TRUE );
	
	return CPropertyPage::OnSetActive();
}

void CPrefTimePropPage::OnUpdate() 
{
	// TODO: Add your control notification handler code here
    CDlgUpdater dlg;
    dlg.DoModal ();
	
}

BOOL CPrefTimePropPage::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	
    NMHDR* phdr = (NMHDR*)lParam;

    switch(phdr->code)
    {
        case PSN_HELP:
        {
//            HtmlHelp(NULL, "WorldTIme2003.chm::/preferences_time.htm", HH_DISPLAY_TOPIC, 0);
            return TRUE;
        break;
        }
    }

	return CPropertyPage::OnNotify(wParam, lParam, pResult);
}
