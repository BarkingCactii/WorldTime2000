// PrefLocationPropPage.cpp : implementation file
//

#include "stdafx.h"
#include "worldtime2000.h"
#include "PrefDisplayPropPage.h"
#include "regdata.h"
//#include "OnLineTimeView.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrefLocationPropPage property page

IMPLEMENT_DYNCREATE(CPrefLocationPropPage, CPropertyPage)

CPrefLocationPropPage::CPrefLocationPropPage() : CPropertyPage(CPrefLocationPropPage::IDD)
{
	//{{AFX_DATA_INIT(CPrefLocationPropPage)
	m_showWallpaper = r.GetKey("ShowWallpaper").word;
	m_backgroundColor = r.GetKey("BackgroundColor").word;
	m_wallpaperName = r.GetKey("WallpaperName").str.c_str();
	//}}AFX_DATA_INIT
}

CPrefLocationPropPage::~CPrefLocationPropPage()
{
}

void CPrefLocationPropPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrefLocationPropPage)
	DDX_Control(pDX, IDC_PREFERENCES_WALLPAPERNAME, m_wallpaperNameCtrl);
	DDX_Check(pDX, IDC_PREFERENCES_SHOWWALLPAPER, m_showWallpaper);
	DDX_Text(pDX, IDC_PREFERENCES_WALLPAPERNAME, m_wallpaperName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrefLocationPropPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPrefLocationPropPage)
	ON_BN_CLICKED(IDC_PREFERENCES_BACKGROUNDCOLOR, OnPreferencesBackgroundcolor)
	ON_BN_CLICKED(IDC_PREFERENCES_LOADWALLPAPER, OnPreferencesLoadwallpaper)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrefLocationPropPage message handlers


BOOL CPrefLocationPropPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
    SetModified ( TRUE );

	// TODO: Add extra initialization here

//    m_manualUpdate = r.ManualView ();
//    int controlID = ( m_manualUpdate ) ? IDC_PREFERENCES_MANUALUPDATE : IDC_PREFERENCES_AUTOUPDATE;
//    CheckRadioButton ( IDC_PREFERENCES_AUTOUPDATE, IDC_PREFERENCES_MANUALUPDATE, controlID );

//    m_message.SetFontItalic ( TRUE );

     theApp.m_pSkin->ApplySkin((long)m_hWnd); // Apply contained skin to the main frame and its child windows

//    m_locBackgroundType.SetCurSel ( r.LocBackgroundType());
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPrefLocationPropPage::OnOK() 
{
	// TODO: Add your specialized code here and/or call the base class

//     r.ManualView ( m_manualUpdate );

//	r.ShowAll( m_showAll);
//	r.UseTemplate(m_useTemplate);
//	r.UpdateInterval ( m_updateInterval);

//     r.LocBackgroundType ( m_locBackgroundType.GetCurSel ());

//     mainView->Invalidate ( FALSE );

    r.GetKey("ShowWallpaper").word = m_showWallpaper;
    r.GetKey("WallpaperName").str = (const char * )m_wallpaperName;
    r.GetKey("BackgroundColor").word = m_backgroundColor;

	CPropertyPage::OnOK();
}


BOOL CPrefLocationPropPage::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
    SetModified ( TRUE );
	
	return CPropertyPage::OnSetActive();
}


void CPrefLocationPropPage::OnPreferencesBackgroundcolor() 
{
	// TODO: Add your control notification handler code here
     CColorDialog c;
     if ( c.DoModal () != IDOK )
          return;

	m_backgroundColor = c.GetColor ();
}

void CPrefLocationPropPage::OnPreferencesLoadwallpaper() 
{
	// TODO: Add your control notification handler code here
          char * filterBuf= "WorldTime2000 Wallpapers\0*.bmp;*.cmo\0\0\0";
          CFileDialog openD ( true );

          openD.m_ofn.lpstrFilter = filterBuf;
          openD.m_ofn.lpstrInitialDir = ".\\";
          openD.m_ofn.lpstrTitle = "Select a Wallpaper";

         if ( openD.DoModal () == IDOK )
         {

            
            wallpaper = LoadImage( 0, openD.m_ofn.lpstrFile, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE );

          if ( wallpaper == NULL )
               m_showWallpaper = FALSE;
          else
          {
             m_wallpaperName = openD.m_ofn.lpstrFile ;
             m_wallpaperNameCtrl.SetWindowText ( openD.m_ofn.lpstrFile );
          }
         }	
}
