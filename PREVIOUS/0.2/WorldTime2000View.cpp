// WorldTime2000View.cpp : implementation of the CWorldTime2000View class
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "WorldTime2000View.h"
#include "memdc.h"
#include "home.h"
#include "preferences.h"

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
//	 selected = 0;
	 selectedAdjustment = selected = 0;
 	selectedAdjustment = -( _timezone / 3600 );
 //	 selectedAdjustment = locations.OffsetList ( locations.selected );
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
static const int Y = 25;
static const int YHome = 5;
static const int YStep = 20;
static const int XHour = 150;
static const int XDate = 235;
static const int XDiff = 285;

void CWorldTime2000View::DrawTime ( CMemDC & memDC, CTime * t, int y, int offset )
{
	CFont font;
    font.CreatePointFont ( 110, "Arial" );

//	CFont * p_font = ( CFont * ) memDC->SelectObject ( font );
	memDC->SelectObject ( font );
	
	int hour = t->GetHour();
	int minute = t->GetMinute();
	int second = t->GetSecond();

	char * pm = "";

	if ( ! locations._24hour && hour > 12 )
	{
		hour -= 12;
		pm = "PM";
	}

	char hourBuf[15];
	sprintf ( hourBuf, "%02d:%02d:%02d", hour, minute, second );
	CString s = hourBuf;
	memDC->TextOut ( XHour, y, s );

	CFont smallFont;
    smallFont.CreatePointFont ( 70, "Arial" );
	memDC->SelectObject ( smallFont );
	s = pm;
	memDC->TextOut ( XHour + 60, y, s );
	memDC->SelectObject ( font );

//	s = t->Format( "%d %b" );
	s = t->Format( "%d " );
	memDC->TextOut ( XDate, y, s );
	memDC->SelectObject ( smallFont );
	s = t->Format( "%b" );
	memDC->TextOut ( XDate + 20, y, s );


	if ( offset != -1 )
	{
//		int gmtOffset = -( _timezone / 3600 );

		strstream sout;
		char sign = ' ';

		if ( offset - selectedAdjustment > 0 )
			sign = '+';

		sout << sign;

//		if ( selected != 0 )
		if ( offset - selectedAdjustment )
			sout << offset - selectedAdjustment << ends;
		else
			sout << "---" << ends;
//		else
//			sout << offset - gmtOffset << ends; // << " hrs" << ends;
		memDC->SelectObject ( font );
		memDC->TextOut ( XDiff, y, sout.str());
		memDC->SelectObject ( smallFont );
		memDC->TextOut ( XDiff + 26, y, "hrs" );

	}

	memDC->SelectObject ( font );

//	memDC->SelectObject ( ( CFont * ) p_font );
}


void CWorldTime2000View::DrawHome ( CMemDC & memDC, CTime * t )
{
//    LocationItem * aItem = locations.GetCurrent ();

//	if ( aItem == 0 )
//		return;


	CBrush * brush = new CBrush ( Yellow );
	CRect rect ( 2, 2, XDiff + 55, Y * 2 - 10 );
	memDC->FrameRect ( rect, brush );
	delete brush;

	CFont bigFont;
    bigFont.CreatePointFont ( 110, "Arial Bold Italic" );
	CFont font;
    font.CreatePointFont ( 110, "Arial" );
	CFont smallFont;
    smallFont.CreatePointFont ( 70, "Arial" );

    memDC->SelectObject ( bigFont );

    memDC->SetTextColor( Yellow );
//	memDC->TextOut ( X, YHome, ( char * ) aItem->name );
	memDC->TextOut ( X, YHome, ( char * ) locations.homeName );

	DrawTime ( memDC, t, YHome, -( _timezone / 3600 ));
	/*
	memDC->SelectObject ( font );
	CString s;

	int hour = t->GetHour();
	int minute = t->GetMinute();
	int second = t->GetSecond();
	char * pm = "";

	if ( ! _24hour && hour > 12 )
	{
		hour -= 12;
		pm = "P";
	}

	char hourBuf[50];
	sprintf ( hourBuf, "%2d:%02d:%02d", hour, minute, second );
	s = hourBuf;
	memDC->TextOut ( XHour, YHome, s );
	memDC->SelectObject ( smallFont );
	s = pm;
	memDC->TextOut ( XDate - 30, YHome, s );
	memDC->SelectObject ( font );


	s = t->Format( "%d %b" );
	memDC->TextOut ( XDate, YHome, s );
	  */
								  /*
	int gmtOffset = ( ( float )_timezone / 3600.0 );

	if ( reference != 0 )
	{
		strstream sout;
		char sign = ' ';

		if ( gmtOffset - offset > 0 )
//		if ( aItem->offset - offset > 0 )
			sign = '+';

		sout << sign;
		
//		sout << aItem->offset - offset << " hrs" << ends;
		sout << gmtOffset - offset << " hrs" << ends;
		memDC->TextOut ( XDiff, YHome, sout.str());
	}
	*/
	  
	int d = _daylight;
	int i = _timezone;
	char * c = tzname[0];
	char * c2 = tzname[1];
    memDC->SelectObject ( smallFont );
	memDC->TextOut ( X + 5, YHome +YStep, tzname[0] );
    memDC->SelectObject ( font );
}

void CWorldTime2000View::DrawLocation ( CMemDC & memDC, CTime * t )
{
    CString s;

//	LocationItem *home = locations.GetLocation ( locations.currentLocation );
//	if ( !home )
//		return;
	int gmtOffset = -( _timezone / 3600 );

	short * aItem;
	for ( int i = 0; aItem = locations.Get ( i ); i++ )
	{
		LocationItem * li;
		CTime ti = *t;

		li = locations.GetLocation ( *aItem );

		if ( li == 0 )
			break;

		int n = i + 1;

		int ref;

		if ( selected == n )
		{
		    memDC->SetTextColor( Red );
			ref = 1;
		}
		else
		{
		    memDC->SetTextColor( Green );
			ref = 0;
		}
		memDC->TextOut ( X, Y + ( n * YStep ), ( char * ) li->name );
		ti += CTimeSpan( 0, li->offset - gmtOffset, 0, 0 ); // 1 hour exactly
//		ti += CTimeSpan( 0, li->offset - home->offset, 0, 0 ); // 1 hour exactly

		DrawTime ( memDC, &ti, Y + ( n * YStep ), li->offset );


/*
		strstream sout;
		char sign = ' ';

		if ( li->offset - offset > 0 )
			sign = '+';

		sout << sign;
		
		sout << li->offset - offset << " hrs" << ends;
		memDC->TextOut ( XDiff, Y + ( n * YStep ), sout.str());
  */
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
	memDC->TextOut ( 70, 5, "BETA" );

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
/*
	CBitmap dst;
	dst.LoadBitmap ( IDB_WORLD );
	CDC dcMem;
	dcMem.CreateCompatibleDC (memDC);
	CBitmap* pOldBitmap = dcMem.SelectObject ( &dst );
	dcMem.SetMapMode ( memDC->GetMapMode ());

	memDC->BitBlt ( 0, 0, 48, 48, &dcMem, 0, 0, SRCCOPY);
	dcMem.SelectObject ( pOldBitmap );
*/
//	DrawIcon ( memDC, 0, 0, theApp.worldIcon );
	DrawIconEx(  memDC, 0, 0, theApp.worldIcon, 72, 72, 0, NULL, DI_NORMAL );

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

    memDC->SelectObject ( fonts );

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
	selected = ( point.y - Y ) / YStep;
	if ( selected )
		selectedAdjustment = locations.OffsetList ( locations.OffsetDisplay ( selected - 1 ));
	else
		selectedAdjustment = -( _timezone / 3600 );
//		selectedAdjustment = locations.OffsetList ( locations.selected );
//		offset = 0;

     CWnd::OnLButtonUp(nFlags, point);
}


void CWorldTime2000View::OnRButtonUp(UINT nFlags, CPoint point)
{
	selected = ( point.y - Y ) / YStep;
	if ( selected )
		locations.Delete ( selected - 1 );

     CWnd::OnLButtonUp(nFlags, point);
}
