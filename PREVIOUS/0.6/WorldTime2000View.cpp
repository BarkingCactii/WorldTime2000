// WorldTime2000View.cpp : implementation of the CWorldTime2000View class
//

#include "stdafx.h"
#include "resource.h"
#include <math.h>
#include "location.h"
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
	 selectedAdjustment = 0.0f;
	 selected = 0;
 	selectedAdjustment = -( _timezone / 3600 );
	drawing = 0;
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
static const int XHour = 180;
static const int XDate = 265;
static const int XDiff = 315;

void CWorldTime2000View::DrawTime ( CMemDC & memDC, CTime * t, int y, float offset )
{
	CFont font;
    font.CreatePointFont ( 110, "Arial" );
	CFont * saveFont = memDC->SelectObject ( &font );
	
	int hour = t->GetHour();
	int minute = t->GetMinute();
	int second = t->GetSecond();

	char * pm = "";

	if ( ! l.p._24hour && hour > 12 )
	{
		hour -= 12;
		pm = "PM";
	}

	char hourBuf[15];
	sprintf ( hourBuf, "%02d:%02d:%02d", hour, minute, second );
	CString s = hourBuf;
	memDC->TextOut ( XHour, y, s );
//	memDC->SelectObject ( saveFont );

	CFont smallFont;
    smallFont.CreatePointFont ( 70, "Arial" );
	memDC->SelectObject ( &smallFont );
//	saveFont = memDC->SelectObject ( &smallFont );
	s = pm;
	memDC->TextOut ( XHour + 60, y, s );
//	memDC->SelectObject ( saveFont );

	s = t->Format( "%d " );
	memDC->SelectObject ( &font );
//	saveFont = memDC->SelectObject ( &font );
	memDC->TextOut ( XDate, y, s );
//	saveFont = memDC->SelectObject ( &smallFont );
	memDC->SelectObject ( &smallFont );
	s = t->Format( "%b" );
	memDC->TextOut ( XDate + 20, y, s );
//	memDC->SelectObject ( saveFont );

//	if ( offset != -1 )
//	{
		strstream sout;
		char sign = ' ';

		if ( offset - selectedAdjustment > 0 )
			sign = '+';

		sout << sign;

		if ( offset - selectedAdjustment )
			sout << offset - selectedAdjustment << ends;
		else
			sout << "-----" << ends;

		memDC->SelectObject ( &font );
//		saveFont = memDC->SelectObject ( &font );
		memDC->TextOut ( XDiff, y, sout.str());
//		saveFont = memDC->SelectObject ( &smallFont );
		memDC->SelectObject ( &smallFont );
		memDC->TextOut ( XDiff + 34, y, "hrs" );
//		memDC->SelectObject ( saveFont );

//	}

	memDC->SelectObject ( saveFont );

}


void CWorldTime2000View::DrawHome ( CMemDC & memDC, CTime * t )
{
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

    CFont * saveFont = memDC->SelectObject ( &bigFont );
    memDC->SetTextColor( Yellow );
	memDC->TextOut ( X, YHome, ( char * ) l.homeName );
//	memDC->SelectObject ( saveFont );

	if ( _daylight )
		DrawIconEx(  memDC, XHour - 15, YHome + 2, theApp.dstIcon, 12, 12, 0, NULL, DI_NORMAL );
//	memDC->DrawIcon ( XHour - 5, YHome, theApp.dstIcon );

	DrawTime ( memDC, t, YHome, -( _timezone / 3600 ));
	  
//	int d = _daylight;
//	int i = _timezone;
//	char * c = tzname[0];
//	char * c2 = tzname[1];
	// display time zone description
   // saveFont = memDC->SelectObject ( &smallFont );
    memDC->SelectObject ( &smallFont );
	memDC->TextOut ( X + 5, YHome +YStep, tzname[0] );
    memDC->SelectObject ( saveFont );
}

static int monthLimit[12] = 
{
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int CWorldTime2000View::DaylightSavings ( LocationItem * li, CTime * t )
{
	// daylight savings not enabled
	if ( ! li->dsEnable )
		return 0;

	const int month = t->GetMonth () - 1;
	const int day = t->GetDay () - 1;
	const int dayofweek = t->GetDayOfWeek () - 1;

	// set array of months in dst
	char dstMonths[12];

	if ( li->dsEndMonth < li->dsStartMonth )
	{
		memset ( dstMonths, 1, sizeof ( dstMonths ));
		for ( int i = li->dsEndMonth + 1; i < li->dsStartMonth; i++ )
			dstMonths[i] = 0;
	}
	else
	{
		memset ( dstMonths, 0, sizeof ( dstMonths ));
		for ( int i = li->dsStartMonth; i <= li->dsEndMonth; i++ )
			dstMonths[i] = 1;
	}

	// month not in daylight savings period
	if ( !dstMonths[month] )
		return 0;

	// month is not in extreme boundary of dst, so must be dst
	if ( month != li->dsStartMonth && month != li->dsEndMonth )
		return 1;

	// if we get here, we still have determined that dst either starts or ends in
	// the current month. We must now be more specific and check the weeks and days

	CTime startMonth ( t->GetYear(), t->GetMonth(), 1, t->GetHour(), t->GetMinute(), t->GetSecond());
	const int startMonthDay = startMonth.GetDayOfWeek() - 1;

//	startMonth -= CTimeSpan( 0, 1, 0, 0 );
	// work out what day the 1st of the month is
/*	int startMonthDay;
	startMonthDay = ( day % 7 );
	if ( dayofweek - startMonthDay < 0 ) 
		startMonthDay -= abs ( 7 - dayofweek);
	else
		startMonthDay -= abs ( dayofweek );
*/
	// now work out what day to actually start from
	short	dsWeek;
	short	dsDay;

	if ( month == li->dsStartMonth )
	{
	dsWeek = li->dsStartWeek;
	dsDay = li->dsStartDay;

	int weekOffset = ( 7 * dsWeek );
	if ( dsDay < startMonthDay )
		dsDay += 7;
	int dayOffset = abs ( dsDay - startMonthDay );

	// week is LAST, not fourth so see if LAST is in fact the 5th week
	if ( dsWeek == 4 )
	{
		if ( weekOffset + dayOffset < monthLimit[month] - 7 )
			weekOffset += 7;
	}

	if ( day >= weekOffset + dayOffset )
		return 1;
	}
	else
	{
	dsWeek = li->dsEndWeek;
	dsDay = li->dsEndDay;

	int weekOffset = ( 7 * dsWeek );
	if ( dsDay < startMonthDay )
		dsDay += 7;
	int dayOffset = abs ( dsDay - startMonthDay );

	// week is LAST, not fourth so see if LAST is in fact the 5th week
	if ( dsWeek == 4 )
	{
		if ( weekOffset + dayOffset < monthLimit[month] - 7 )
			weekOffset += 7;
	}



		if ( day <= weekOffset + dayOffset )
			return 1;
	}
			  

	return 0;
}

void CWorldTime2000View::DrawLocation ( CMemDC & memDC, CTime * t )
{
    CString s;

	int gmtOffset = -( _timezone / 3600 );

	CFont font;
    font.CreatePointFont ( 110, "Arial" );

	CFont * saveFont = memDC->SelectObject ( &font );

	short * aItem;
	for ( int i = 0; aItem = l.Get ( i ); i++ )
	{
		LocationItem * li;
		CTime ti = *t;

		li = l.GetLocation ( *aItem );

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
		memDC->SelectObject ( &font );
		memDC->TextOut ( X, Y + ( n * YStep ), ( char * ) li->name );

		float dst = 0.0;
		if ( DaylightSavings ( li, &ti ))
		{
			DrawIconEx(  memDC, XHour - 15, Y + ( n * YStep ) + 2, theApp.dstIcon, 12, 12, 0, NULL, DI_NORMAL );
			ti += CTimeSpan( 0, 1, 0, 0 );
			dst = 1.0;
		}

		float mins = floor ( li->offset ) - li->offset;
		if ( mins ) mins = 30.0f;
		ti += CTimeSpan( 0, ( int ) li->offset - gmtOffset, ( int ) mins, 0 ); // 1 hour exactly

		DrawTime ( memDC, &ti, Y + ( n * YStep ), li->offset + dst );
	}
	memDC->SelectObject ( saveFont );

}


void CWorldTime2000View::OnPaint() 
{
	if ( drawing )
		return;

	drawing = 1;

	
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages

	// set memory device context
    CMemDC memDC( GetDC() );
//    memDC.CreateCompatibleDC ( GetDC());

	// set default font
	CFont font;
    font.CreatePointFont ( 110, "Arial" );
	CFont * saveFont = memDC->SelectObject ( &font );

	// set background to black
	CBrush * background = new CBrush (PALETTERGB ( 0, 0, 0 ));
	CRect backgroundRect;
    GetClientRect ( &backgroundRect );
    memDC->FillRect (&backgroundRect, background );
	delete background;

	// transparent drawing mode
	memDC->SetBkMode ( TRANSPARENT );

	// get current local time
    CTime t = CTime::GetCurrentTime();

	//
	//	Beta message
	//
	CFont beta;
    beta.CreatePointFont ( 600, "Arial" );
//    saveFont = memDC->SelectObject ( &beta );
    memDC->SelectObject ( &beta );
    memDC->SetTextColor( BetaColor );
	memDC->TextOut ( 100, 5, "BETA" );
	//memDC->SelectObject ( saveFont );

	// draw background icon of world
	static int whichIcon = 0;

	memDC->RealizePalette();

//    CDC dcMem;
//    dcMem.CreateCompatibleDC ( GetDC());
//    dcMem.SetMapMode (GetDC()->GetMapMode ());


//	DrawIconEx(  memDC, 0, 0, theApp.worldIcon[whichIcon], 100, 100, 0, NULL, DI_NORMAL );
//	DrawIconEx(  memDC, 0, 0, theApp.worldIcon[whichIcon], 200, 200, 0, NULL, DI_IMAGE );

//	CPoint p ( 0, 0 );
//	CSize s ( 100, 100 );
//	memDC->DrawState( ( CPoint ) p, ( CSize )s,
//		( HICON )theApp.worldIcon[whichIcon], 
//		( UINT ) DST_ICON ); //UINT nFlags, HBRUSH hBrush = NULL );


//	memDC->DrawIcon ( 0, 0, theApp.worldIcon[whichIcon] );
//	DrawIcon (  memDC, 0, 0, theApp.worldIcon[whichIcon] );

//	CBitmap bitmap;
//	bitmap.LoadBitmap ( IDB_BITMAP1 );
//	memDC->SelectObject ( bitmap );
	if ( l.p.drawSphere )
	{
    CDC dcMem;
    dcMem.CreateCompatibleDC ( GetDC());

//    CBitmap* pOldBitmap = dcMem.SelectObject ( &theApp.backgroundBitmap ); //itmap );
//    dcMem.SetMapMode (GetDC()->GetMapMode ());
//    memDC->StretchBlt (0, 0, 320, 240, &dcMem, 0, 0, 320, 240, SRCCOPY);

    CBitmap * pOldBitmap = dcMem.SelectObject ( &theApp.worldBitmap[whichIcon] ); //itmap );
    dcMem.SetMapMode (GetDC()->GetMapMode ());
    memDC->StretchBlt (-10, -10, 100, 100, &dcMem, 0, 0, 100, 100, SRCCOPY);
//    memDC->BitBlt (50, 50, 200, 200, &dcMem, 0, 0, SRCCOPY);
    dcMem.SelectObject ( pOldBitmap );

	whichIcon++;
	if ( whichIcon > 23 )
		whichIcon = 0;
	}

	// draw home location
	DrawHome ( memDC, &t );

	// draw locations
	DrawLocation ( memDC, &t );

	memDC->SelectObject ( saveFont );

	drawing = 0;
}


void CWorldTime2000View::OnTimer(UINT nIDEvent)
{
	if ( !drawing )
		Invalidate(FALSE);
//	else
//        MessageBox ( "Timer broken", NULL, MB_ICONEXCLAMATION );

    CWnd::OnTimer(nIDEvent);
}

int CWorldTime2000View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetTimer ( 101, 500, NULL );

	return 0;
}


void CWorldTime2000View::OnLButtonUp(UINT nFlags, CPoint point)
{
	selected = ( point.y - Y ) / YStep;
	if ( selected )
		selectedAdjustment = l.OffsetList ( l.OffsetDisplay ( selected - 1 ));
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
	{
		if ( MessageBox ( "Delete location ?", "Confirm Delete", MB_YESNO | MB_ICONQUESTION ) != IDNO )
			l.Delete ( selected - 1 );
	}

     CWnd::OnLButtonUp(nFlags, point);
}
