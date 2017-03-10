// WorldTime2000View.cpp : implementation of the CWorldTime2000View class
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "WorldTime2000View.h"
#include "memdc.h"
#include "home.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000View

CWorldTime2000View * view = 0;

CWorldTime2000View::CWorldTime2000View()
{
     view = this;
	 offset = reference = 0;
 	 offset = locations.OffsetList ( locations.currentLocation );
}

CWorldTime2000View::~CWorldTime2000View()
{
}


BEGIN_MESSAGE_MAP(CWorldTime2000View,CWnd )
	//{{AFX_MSG_MAP(CWorldTime2000View)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000View message handlers

BOOL CWorldTime2000View::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

static COLORREF BetaColor ( RGB ( 0, 0, 100 ));
static COLORREF blue ( RGB ( 0, 0, 120 ));
static COLORREF brightBlue ( RGB ( 0, 0, 255 ));
static COLORREF Yellow ( RGB ( 255, 255, 0 ));
static COLORREF grey ( RGB ( 180, 180, 180 ));
static COLORREF LightGrey ( RGB ( 230, 230, 230 ));
static COLORREF Red ( RGB ( 255, 0, 0 ));
static COLORREF Green ( RGB ( 0, 200, 50 ));

static COLORREF LightPink ( RGB ( 255, 190, 190 ));
static COLORREF DarkPink ( RGB ( 150, 50, 50 ));

static const int X = 5;
static const int Y = 5;
static const int YStep = 20;
static const int XHour = 150;
static const int XDate = 220;
static const int XDiff = 270;

void CWorldTime2000View::DrawHome ( CMemDC & memDC, CTime * t )
{
    LocationItem * aItem = locations.GetCurrent ();

	if ( aItem == 0 )
		return;

    memDC->SetTextColor( Yellow );
	memDC->TextOut ( X, Y, ( char * ) aItem->name );

	CString s = t->Format( "%H:%M:%S" );
	memDC->TextOut ( XHour, Y, s );
	s = t->Format( "%d %b" );
	memDC->TextOut ( XDate, Y, s );

	if ( reference != 0 )
	{
		strstream sout;
		char sign = ' ';

		if ( aItem->offset - offset > 0 )
			sign = '+';

		sout << sign;
		
		sout << aItem->offset - offset << " hrs" << ends;
		memDC->TextOut ( XDiff, Y, sout.str());
	}
}

void CWorldTime2000View::DrawLocation ( CMemDC & memDC, CTime * t )
{
    CString s;

	LocationItem *home = locations.GetLocation ( locations.currentLocation );
	if ( !home )
		return;

	short * aItem;
	for ( int i = 0; aItem = locations.Get ( i ); i++ )
	{
		LocationItem * li;
		CTime ti = *t;

		li = locations.GetLocation ( *aItem );

		if ( li == 0 )
			break;

		int n = i + 1;

		if ( reference == n )
		    memDC->SetTextColor( Red );
		else
		    memDC->SetTextColor( Green );

		memDC->TextOut ( X, Y + ( n * YStep ), ( char * ) li->name );
		ti += CTimeSpan( 0, li->offset - home->offset, 0, 0 ); // 1 hour exactly
		s = ti.Format( "%H:%M:%S" );
		memDC->TextOut ( XHour, Y + ( n * YStep ), s );
		s = ti.Format( "%d %b" );
		memDC->TextOut ( XDate, Y + ( n * YStep ), s );
		
		strstream sout;
		char sign = ' ';

		if ( li->offset - offset > 0 )
			sign = '+';

		sout << sign;
		
		sout << li->offset - offset << " hrs" << ends;
		memDC->TextOut ( XDiff, Y + ( n * YStep ), sout.str());

	}
}

void CWorldTime2000View::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
	CBrush * aBrush = new CBrush (PALETTERGB ( 0, 0, 0 ));

	CRect crect;
    GetClientRect (&crect);
    CMemDC    memDC( GetDC() ); //, crect);
    CTime t = CTime::GetCurrentTime();

//        rect.SetRect (0, i, nWidth, i + 1);
    memDC->FillRect (&crect, aBrush );

	delete aBrush;

	memDC->SetBkMode ( TRANSPARENT );

	//
	//	Beta message
	//
	//
	CFont beta;
    beta.CreatePointFont ( 720, "Arial" );
    memDC->SelectObject ( beta );
    memDC->SetTextColor( BetaColor );
	memDC->TextOut ( 5, 5, "BETA" );

	CFont fonts;

    fonts.CreatePointFont ( 110, "Arial" );

    memDC->SelectObject ( fonts );
    memDC->SetTextColor( LightGrey );


//    CPen outline (PS_SOLID, 1, RGB ( 0, 0, 0 ));
//    pDC->SelectObject ( &outline );
//    pDC->SelectStockObject ( GRAY_BRUSH );

                        /*
	 CBrush * hilite = new CBrush (PALETTERGB ( 70, 70, 70 ));
//     pDC->SelectStockObject ( GRAY_BRUSH );
     memDC->FillRect ( CRect ( 0, 4, 255, 21 ), hilite);
	delete hilite;

     CPen border (PS_SOLID, 2, LightPink ); //RGB ( 190, 190, 190 ));
     memDC->SelectObject (&border);
     memDC->MoveTo ( 0, 21 );
     memDC->LineTo ( 0, 4 );
     memDC->LineTo ( 255, 4 );

     CPen border2 (PS_SOLID, 2, DarkPink ); //RGB ( 190, 190, 190 ));
     memDC->SelectObject (&border2);
     memDC->MoveTo ( 0, 21 );
     memDC->LineTo ( 255, 21 );
     memDC->LineTo ( 255, 4 );
                          */

/*
	     pDC->SelectObject (&border);
     pDC->MoveTo ( selectedRect.left, selectedRect.top );
     pDC->LineTo ( selectedRect.right,selectedRect.top );
     pDC->LineTo ( selectedRect.right,selectedRect.bottom );
     pDC->LineTo ( selectedRect.left, selectedRect.bottom );
     pDC->LineTo ( selectedRect.left, selectedRect.top );
*/
     /*
	memDC->TextOut ( 5, 5, "Nanango" );

	CTime t = CTime::GetCurrentTime();
	CString s = t.Format( "%H:%M:%S" );
	memDC->TextOut ( 100, 5, s );
	s = t.Format( "%d %b" );
	memDC->TextOut ( 200, 5, s );

*/
     DrawHome ( memDC, &t );

	 DrawLocation ( memDC, &t );
	 /*
     CString s;
     memDC->SetTextColor( Green );
	
	memDC->TextOut ( 5, 25, "Boise" );
	t -= CTimeSpan( 0, 17, 0, 0 ); // 1 hour exactly
	s = t.Format( "%H:%M:%S" );
	memDC->TextOut ( 100, 25, s );
	s = t.Format( "%d %b" );
	memDC->TextOut ( 200, 25, s );


	memDC->TextOut ( 5, 45, "Chicago" );
	t -= CTimeSpan( 0, 20, 0, 0 ); // 1 hour exactly
	s = t.Format( "%H:%M:%S" );
	memDC->TextOut ( 100, 45, s );
	s = t.Format( "%d %b" );
	memDC->TextOut ( 200, 45, s );
	   */
}


void CWorldTime2000View::OnTimer(UINT nIDEvent)
{
	Invalidate(FALSE);
    CWnd::OnTimer(nIDEvent);
}

int CWorldTime2000View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetTimer ( 101, 1000, NULL );

	return 0;
}


void CWorldTime2000View::OnLButtonUp(UINT nFlags, CPoint point)
{
	reference = ( point.y - Y ) / YStep;
	if ( reference )
		offset = locations.OffsetList ( locations.OffsetDisplay ( reference - 1 ));
	else
		offset = locations.OffsetList ( locations.currentLocation );
//		offset = 0;

     CWnd::OnLButtonUp(nFlags, point);
}


void CWorldTime2000View::OnRButtonUp(UINT nFlags, CPoint point)
{
	reference = ( point.y - Y ) / YStep;
	if ( reference )
		locations.Delete ( reference - 1 );

     CWnd::OnLButtonUp(nFlags, point);
}
