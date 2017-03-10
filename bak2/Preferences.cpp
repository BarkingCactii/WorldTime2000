// Preferences.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "Preferences.h"
#include "home.h"
#include "location.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


Preferences p;

#define COLOR_ITEM_HEIGHT   20

COLORREF homeColor ( RGB ( 255, 255, 0 ));
COLORREF locationColor ( RGB ( 0, 255, 255 ));
COLORREF selectedColor ( RGB ( 0, 255, 0 ));
COLORREF backgroundColor ( RGB ( 0, 0, 0 ));
COLORREF moveColor ( RGB ( 255, 0, 0 ));

HANDLE wallpaper;
//String * fontName[100] = "Arial";
//short  fontSize = 110;



void CCustomStatic::MeasureItem(LPMEASUREITEMSTRUCT lpMIS)
{
    // all items are of fixed size
    // must use LBS_OWNERDRAWVARIABLE for this to work
    lpMIS->itemHeight = COLOR_ITEM_HEIGHT;
}

void CCustomStatic::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
    CDC* pDC = CDC::FromHandle(lpDIS->hDC);
    CBrush br( PALETTERGB ( 0, 0, 0 ));
    pDC->FillRect(&lpDIS->rcItem, &br);
	/*
    COLORREF cr = (COLORREF)lpDIS->itemData; // RGB in item data

    if (lpDIS->itemAction & ODA_DRAWENTIRE)
    {
        // Paint the color item in the color requested
        CBrush br(cr);
        pDC->FillRect(&lpDIS->rcItem, &br);
    }

    if ((lpDIS->itemState & ODS_SELECTED) &&
        (lpDIS->itemAction & (ODA_SELECT | ODA_DRAWENTIRE)))
    {
        // item has been selected - hilite frame
        COLORREF crHilite = RGB(255-GetRValue(cr),
                        255-GetGValue(cr), 255-GetBValue(cr));
        CBrush br(crHilite);
        pDC->FrameRect(&lpDIS->rcItem, &br);
    }

    if (!(lpDIS->itemState & ODS_SELECTED) &&
        (lpDIS->itemAction & ODA_SELECT))
    {
        // Item has been de-selected -- remove frame
        CBrush br(cr);
        pDC->FrameRect(&lpDIS->rcItem, &br);
    }
	*/
}

//int _24hour = 0;
//Preferences p;

bifstream & operator >> ( bifstream & fin,  Preferences & data )
{
	fin >> data._24hour >> data.seconds >> data.tooltips >> data.drawSphere;

     if ( l.Version() >= 1.30f )
          fin >> data.movingSphere >> data.frames;

     // version 2.50 enchancement
     if ( l.Version() >= 2.50f )
          fin >> data.showAM;
     else
          versionUpgrade = true;
//     else
//     	MessageBox ( mainFrame->m_hWnd, "Upgrading older data file to current version", "Upgrading", MB_OK );
          
	string tmp;
	fin >> data.showWallpaper >> tmp;
    if ( tmp != "worldtime2000.bmp" )
		data.wallpaperName = tmp; 

	fin >> tmp;
    if ( tmp != "alarm.wav" )
		data.alarmName = tmp;
	fin >> data.alarmOn;

	fin >> tmp;
    if ( tmp != "hour.wav" )
		data.hourName = tmp;
	fin >> data.hourOn;

	fin >> tmp;
    if ( tmp != "quarter.wav" )
		 data.quarterName = tmp;
	fin >> data.quarterOn;
	
	return fin;
}

bofstream & operator << ( bofstream & fout, Preferences & data )
{
	fout << data._24hour << data.seconds << data.tooltips << data.drawSphere;
     fout << data.movingSphere << data.frames;
     fout << data.showAM;

#ifdef CREATENEW
	data.showWallpaper = 1;
	data.wallpaperName = "worldtime2000.bmp";
	data.alarmName = "alarm.wav";
	data.hourName = "hour.wav";
	data.quarterName = "quarter.wav";
	data.alarmOn = True;
	data.hourOn = True;
	data.quarterOn = True;
#endif
	fout << data.showWallpaper << data.wallpaperName;
	fout << data.alarmName << data.alarmOn;
	fout << data.hourName << data.hourOn;
	fout << data.quarterName << data.quarterOn;

	return fout;
}


/////////////////////////////////////////////////////////////////////////////
// CPreferences dialog


CPreferences::CPreferences(CWnd* pParent /*=NULL*/)
	: CDialog(CPreferences::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreferences)
	m_frames = 0;
	//}}AFX_DATA_INIT
	m_home = homeColor;
	m_location = locationColor;
	m_selected = selectedColor;
	m_background = backgroundColor;
//	brush = 0x00ff0000;
	m_bkBrush.CreateSolidBrush ( backgroundColor );
}


void CPreferences::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreferences)
	DDX_Control(pDX, IDC_CHECK8, m_showAM);
	DDX_Control(pDX, IDC_CHECK6, m_tooltips);
	DDX_Control(pDX, IDC_CHECK5, m_seconds);
	DDX_Control(pDX, IDC_SOUNDALARMON, m_alarmOn);
	DDX_Control(pDX, IDC_SOUNDQUARTERON, m_quarterOn);
	DDX_Control(pDX, IDC_SOUNDHOURON, m_hourOn);
	DDX_Control(pDX, IDC_CHECK4, m_movingSphere);
	DDX_Control(pDX, IDC_CHECK3, m_imageOn);
	DDX_Control(pDX, IDC_HOME_COLOR, m_homecolor);
	DDX_Control(pDX, IDC_CHECK2, m_drawSphere);
	DDX_Control(pDX, IDC_CHECK1, m_24hour);
	DDX_Text(pDX, IDC_EDIT1, m_frames);
	DDV_MinMaxUInt(pDX, m_frames, 11, 66);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreferences, CDialog)
	//{{AFX_MSG_MAP(CPreferences)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_HOME_COLOR, OnHomeColor)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_LOCATION_COLOR, OnLocationColor)
	ON_BN_CLICKED(IDC_SELECTED_COLOR, OnSelectedColor)
	ON_BN_CLICKED(IDC_BACKGROUND_COLOR, OnBackgroundColor)
	ON_BN_CLICKED(IDC_BACKGROUND_TEXTURE, OnBackgroundTexture)
	ON_BN_CLICKED(IDC_SOUNDALARM, OnSoundalarm)
	ON_BN_CLICKED(IDC_SOUNDHOUR, OnSoundhour)
	ON_BN_CLICKED(IDC_SOUNDQUARTER, OnSoundquarter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreferences message handlers

void CPreferences::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	p._24hour = m_24hour.GetCheck ();
	p.seconds = m_seconds.GetCheck ();
	p.tooltips = m_tooltips.GetCheck ();

	p.drawSphere = m_drawSphere.GetCheck ();
	p.showWallpaper = m_imageOn.GetCheck();
     p.movingSphere = m_movingSphere.GetCheck();
     p.frames = GetDlgItemInt ( IDC_EDIT1 );
     p.showAM = m_showAM.GetCheck();

	if ( p.showWallpaper && wallpaper == NULL )
		p.showWallpaper = 0;

	homeColor = m_home;
	locationColor = m_location;
	selectedColor = m_selected;
	backgroundColor = m_background;

    p.alarmOn = ( bool )m_alarmOn.GetCheck ();
    p.hourOn = ( bool )m_hourOn.GetCheck ();
    p.quarterOn = ( bool )m_quarterOn.GetCheck ();

	CDialog::OnOK();
}

BOOL CPreferences::OnInitDialog() 
{
	CDialog::OnInitDialog();
  	
	// subclass the control
//	VERIFY(m_home.SubclassDlgItem (IDC_HOME_SAMPLE, this));

	
	// TODO: Add extra initialization here
	m_24hour.SetCheck ( p._24hour );
	m_seconds.SetCheck ( p.seconds );
	m_tooltips.SetCheck ( p.tooltips );
	m_drawSphere.SetCheck ( p.drawSphere );
	m_imageOn.SetCheck ( p.showWallpaper );
     m_movingSphere.SetCheck ( p.movingSphere );
     m_showAM.SetCheck ( p.showAM );

     m_alarmOn.SetCheck ( p.alarmOn );
     m_hourOn.SetCheck ( p.hourOn );
     m_quarterOn.SetCheck ( p.quarterOn );

     SetDlgItemInt ( IDC_EDIT1, p.frames );
  
     theApp.m_pSkin->ApplySkin((long)m_hWnd); // Apply contained skin to the main frame and its child windows


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int CPreferences::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CPreferences::OnHomeColor() 
{
	// TODO: Add your control notification handler code here
     CColorDialog c;
     if ( c.DoModal () != IDOK )
          return;

	m_home = c.GetColor ();

//	 CFontDialog f;
//	 f.DoModal();
//          view->result = c.GetColor ();
//          view->Redraw();
	RedrawWindow();
	
}

HBRUSH CPreferences::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	COLORREF col;

	if ( pWnd->m_hWnd != GetDlgItem ( IDC_HOME_SAMPLE )->m_hWnd )
		if ( pWnd->m_hWnd != GetDlgItem ( IDC_LOCATION_SAMPLE )->m_hWnd )
			if ( pWnd->m_hWnd != GetDlgItem ( IDC_SELECTED_SAMPLE )->m_hWnd )
				if ( pWnd->m_hWnd != GetDlgItem ( IDC_BACKGROUND_SAMPLE )->m_hWnd )
					return hbr;
				else
					col = m_background;
			else
				col = m_selected;
		else
			col = m_location;
	else
		col = m_home;
	
	switch (nCtlColor) 
	{
       case CTLCOLOR_STATIC:
           pDC->SetTextColor( col ); //RGB(255, 255, 255));
           pDC->SetBkColor( m_background ); //RGB(0, 0, 0));

           return (HBRUSH)(m_bkBrush.GetSafeHandle());

       default:
           return hbr; //(HBRUSH)(m_bkBrush.GetSafeHandle());
	}
}

void CPreferences::OnLocationColor() 
{
	// TODO: Add your control notification handler code here
     CColorDialog c;
     if ( c.DoModal () != IDOK )
          return;

	m_location = c.GetColor ();

	RedrawWindow();
	
}

void CPreferences::OnSelectedColor() 
{
	// TODO: Add your control notification handler code here
     CColorDialog c;
     if ( c.DoModal () != IDOK )
          return;

	m_selected = c.GetColor ();

	RedrawWindow();
	
}

void CPreferences::OnBackgroundColor() 
{
	// TODO: Add your control notification handler code here
     CColorDialog c;
     if ( c.DoModal () != IDOK )
          return;

	m_background = c.GetColor ();
   m_bkBrush.Detach();
m_bkBrush.CreateSolidBrush ( m_background );


//	m_bkBrush.CreateSolidBrush ( m_background );
	RedrawWindow();
	
}

// TODO: Add your control notification handler code here
//String imageName = "Worldtime2000.bmp";

void CPreferences::OnBackgroundTexture() 
{
        // TODO: Add your command handler code here
      char * filterBuf= "Bitmap Files\0*.bmp;*.cmo\0\0\0";
      CFileDialog openD ( TRUE );

      openD.m_ofn.lpstrFilter = filterBuf;
      openD.m_ofn.lpstrInitialDir = ".\\";
      openD.m_ofn.lpstrTitle = "Select Background Bitmap";

     if ( openD.DoModal () == IDOK )
     {
          //
          // open file and read data
          //
   		wallpaper = LoadImage( 0, openD.m_ofn.lpstrFile, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE );

		if ( wallpaper == NULL )
			p.showWallpaper = 0;

        p.wallpaperName = openD.m_ofn.lpstrFile;
      }
}

void CPreferences::OnSoundalarm() 
{
	// TODO: Add your control notification handler code here
      char * filterBuf= "PCM Wave Files\0*.wav;*.cmo\0\0\0";
      CFileDialog openD ( TRUE );

      openD.m_ofn.lpstrFilter = filterBuf;
      openD.m_ofn.lpstrInitialDir = ".\\";
      openD.m_ofn.lpstrTitle = "Select Sound file";

     if ( openD.DoModal () == IDOK )
		 p.alarmName = openD.m_ofn.lpstrFile;
}

void CPreferences::OnSoundhour() 
{
	// TODO: Add your control notification handler code here
      char * filterBuf= "PCM Wave Files\0*.wav;*.cmo\0\0\0";
      CFileDialog openD ( TRUE );

      openD.m_ofn.lpstrFilter = filterBuf;
      openD.m_ofn.lpstrInitialDir = ".\\";
      openD.m_ofn.lpstrTitle = "Select Sound file";

     if ( openD.DoModal () == IDOK )
		 p.hourName = openD.m_ofn.lpstrFile;
	
}

void CPreferences::OnSoundquarter() 
{
	// TODO: Add your control notification handler code here
      char * filterBuf= "PCM Wave Files\0*.wav;*.cmo\0\0\0";
      CFileDialog openD ( TRUE );

      openD.m_ofn.lpstrFilter = filterBuf;
      openD.m_ofn.lpstrInitialDir = ".\\";
      openD.m_ofn.lpstrTitle = "Select Sound file";

     if ( openD.DoModal () == IDOK )
		 p.quarterName = openD.m_ofn.lpstrFile;
	
}
