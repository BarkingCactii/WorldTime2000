// Preferences.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "Preferences.h"
#include "home.h"
#include "location.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define COLOR_ITEM_HEIGHT   20

COLORREF homeColor ( RGB ( 255, 255, 0 ));
COLORREF locationColor ( RGB ( 0, 255, 255 ));
COLORREF selectedColor ( RGB ( 0, 255, 0 ));
COLORREF backgroundColor ( RGB ( 0, 0, 0 ));


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
	fin >> data._24hour >> data.drawSphere;
	return fin;
}

bofstream & operator << ( bofstream & fout, Preferences & data )
{
	fout << data._24hour << data.drawSphere;
	return fout;
}


/////////////////////////////////////////////////////////////////////////////
// CPreferences dialog


CPreferences::CPreferences(CWnd* pParent /*=NULL*/)
	: CDialog(CPreferences::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreferences)
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
	DDX_Control(pDX, IDC_HOME_COLOR, m_homecolor);
	DDX_Control(pDX, IDC_CHECK2, m_drawSphere);
	DDX_Control(pDX, IDC_CHECK1, m_24hour);
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreferences message handlers

void CPreferences::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	l.p._24hour = m_24hour.GetCheck ();
	l.p.drawSphere = m_drawSphere.GetCheck ();
	
	homeColor = m_home;
	locationColor = m_location;
	selectedColor = m_selected;
	backgroundColor = m_background;

	CDialog::OnOK();
}

BOOL CPreferences::OnInitDialog() 
{
	CDialog::OnInitDialog();
  	
	// subclass the control
//	VERIFY(m_home.SubclassDlgItem (IDC_HOME_SAMPLE, this));

	
	// TODO: Add extra initialization here
	m_24hour.SetCheck ( l.p._24hour );
	m_drawSphere.SetCheck ( l.p.drawSphere );
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
