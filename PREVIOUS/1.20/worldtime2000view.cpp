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
#include "register.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000View

CWorldTime2000View * view = 0;
int alarm = -1; // -1 is dormant, -2 is reset

CWorldTime2000View::CWorldTime2000View()
{
     view = this;
//	 selected = 0;
         selectedAdjustment = 0.0f;
         selected = -1;
         homeDST = 0.0;
        selectedAdjustment = -( _timezone / 3600 ) - homeDST;
        drawing = 0;
		moveModeOn = 0;
		
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
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
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

//static COLORREF homeColor ( RGB ( 255, 255, 0 ));
//static COLORREF locationColor ( RGB ( 0, 255, 255 ));
//static COLORREF selectedColor ( RGB ( 0, 255, 0 ));



static COLORREF Red ( RGB ( 255, 0, 0 ));
static COLORREF BetaColor ( RGB ( 0, 0, 100 ));
static COLORREF blue ( RGB ( 0, 0, 120 ));
static COLORREF brightBlue ( RGB ( 0, 0, 255 ));
static COLORREF grey ( RGB ( 180, 180, 180 ));
static COLORREF LightGrey ( RGB ( 230, 230, 230 ));
static COLORREF Black ( RGB ( 0, 0, 0 ));
//static COLORREF Orange ( RGB ( 180, 255, 180 ));
static COLORREF Orange ( RGB ( 0, 255, 255 ));

static COLORREF LightPink ( RGB ( 255, 190, 190 ));
static COLORREF DarkPink ( RGB ( 150, 50, 50 ));

static const int X = 5;
static int Y = 25;
static const int YHome = 5;
static int YStep = 20;
static const float XHour = 180;
static const float XDate = 265;
static const float XDiff = 315;
static int xOff;	// offset for PM, month, hrs indicator

#define YPOS ( Y + ( n * YStep ))

float ratio = 1.0f;

void CWorldTime2000View::DrawTime ( CMemDC & memDC, CTime * t, int y, float offset )
{
        int hour = t->GetHour();
        int minute = t->GetMinute();
        int second = t->GetSecond();

        char * pm = "";

        if ( ! l.p._24hour && hour > 12 )
        {
                hour -= 12;
                pm = "PM";
        }

		// display the hours, minutes & seconds
        char hourBuf[15];
        sprintf ( hourBuf, "%02d:%02d", hour, minute );
//        sprintf ( hourBuf, "%02d:%02d:%02d", hour, minute, second );
        CString s = hourBuf;
        memDC->TextOut (( int ) ( XHour * ratio ), y, s );
		CSize hourSize = memDC->GetTextExtent ( hourBuf, strlen ( hourBuf ));

		// display the day
        s = t->Format( "%d" );
        memDC->TextOut (( int ) ( XDate * ratio ), y, s );
		CSize daySize = memDC->GetTextExtent ( s.GetBuffer( 50 ), s.GetLength());

		// display hour difference
        strstream sout;
        char sign = ' ';
        if ( offset - selectedAdjustment + homeDST > 0 )
                sign = '+';
        sout << sign;
        if ( offset - selectedAdjustment + homeDST )
                sout << offset - selectedAdjustment + homeDST << ends;
        else
                sout << "---" << ends;
        memDC->TextOut (( int ) ( XDiff * ratio ), y, sout.str());
		CSize offsetSize = memDC->GetTextExtent ( sout.str(), strlen ( sout.str()));

		// now show all the stuff using small fonts
        CFont smallFont;
	    smallFont.CreatePointFont ( l.fontSize - 30, l.fontName );
        CFont * saveFont = memDC->SelectObject ( &smallFont );


		// display PM indicator
        s = pm;
        sprintf ( hourBuf, ":%02d %s", second, s );
        memDC->TextOut (( int ) ( XHour * ratio ) + hourSize.cx, y, hourBuf ); //s ); //60, y, s );
//        memDC->TextOut (( int ) ( XHour * ratio ) + hourSize.cx + xOff, y, hourBuf ); //s ); //60, y, s );


		// display the month
        s = t->Format( " %b" );
        memDC->TextOut (( int ) (( XDate * ratio ) + daySize.cx + ( xOff / 2 )) , y, s );
//        memDC->TextOut (( int ) (( XDate * ratio ) + daySize.cx + ( xOff / 2 )) , y, s );


		// display the hours label
//        memDC->TextOut (( int ) (( XDiff * ratio ) + offsetSize.cx + xOff ), y, " hrs" );
        memDC->TextOut (( int ) (( XDiff * ratio ) + offsetSize.cx ), y, " hrs" );

        memDC->SelectObject ( saveFont );

}


void CWorldTime2000View::DrawHome ( CMemDC & memDC, CTime * t )
{
        CBrush * brush = new CBrush ( homeColor );
        CRect rect ( 2, 2, ( int ) (( XDiff + 60 ) * ratio ), Y - 3 );
//        CRect rect ( 2, 2, ( int ) (( XDiff + 60 ) * ratio ), Y * 2 - 10 );
        memDC->FrameRect ( rect, brush );
        delete brush;

//        CFont bigFont;
//    bigFont.CreatePointFont ( 110, "Arial Bold Italic" );
//    bigFont.CreatePointFont ( fontSize + 20, fontName );
//    bigFont.CreatePointFont ( 90, "Arial Bold Italic" );
        CFont font;
    font.CreatePointFont ( l.fontSize + 20, l.fontName );


	LOGFONT base;
	font.GetLogFont ( &base );
	base.lfWeight = FW_BOLD;
	base.lfItalic = TRUE;
//	base.lfUnderline = TRUE;

	CFont bigFont;
	bigFont.CreateFontIndirect ( &base );


//    font.CreatePointFont ( 110, "Arial" );
//    font.CreatePointFont ( 90, "Arial" );
        CFont smallFont;
//    smallFont.CreatePointFont ( 70, "Arial" );
    smallFont.CreatePointFont ( l.fontSize - 30, l.fontName );

    CFont * saveFont = memDC->SelectObject ( &bigFont );
    memDC->SetTextColor( homeColor );
    memDC->TextOut ( X, YHome, ( char * ) l.GetHome()->name );
		
//	memDC->SelectObject ( saveFont );

        struct tm *newtime;
    time_t long_time;

    time( &long_time );                /* Get time as long integer. */
    newtime = localtime( &long_time ); /* Convert to local time. */

	if ( l.GetHome()->alarmEnable )
		DrawIconEx(  memDC, (int)(( XHour * ratio ) - 28), YHome + 2, theApp.alarmIcon, 12, 12, 0, NULL, DI_NORMAL );


        if ( newtime->tm_isdst )
        {
//	if ( _daylight )
                DrawIconEx(  memDC, (int)(( XHour * ratio ) - 15), YHome + 2, theApp.dstOnIcon, 12, 12, 0, NULL, DI_NORMAL );
                homeDST = 1.0f;
        }
        else
		{
			if ( _daylight )
                DrawIconEx(  memDC, (int)(( XHour * ratio ) - 15), YHome + 2, theApp.dstOffIcon, 12, 12, 0, NULL, DI_NORMAL );

            homeDST = 0.0f;
		}
//	memDC->DrawIcon ( XHour - 5, YHome, theApp.dstIcon );

				if ( l.GetHome()->alarmEnable && t->GetHour() == l.GetHome()->alarmHour && t->GetMinute() == l.GetHome()->alarmMinute )
					if ( alarm == -1 )
						// dont set the alarm if it was just reset
						alarm = 0;

					static blink = 0;
					if ( alarm == 0 )
					{
					if ( blink == 0 )
					{
			        DrawTime ( memDC, t, YHome, -( _timezone / 3600.0f ));
					blink = 1;
					}
					else
						blink = 0;
					}
					else
			        DrawTime ( memDC, t, YHome, -( _timezone / 3600.0f ));









//        DrawTime ( memDC, t, YHome, -( _timezone / 3600 ));

//	int d = _daylight;
//	int i = _timezone;
//	char * c = tzname[0];
//	char * c2 = tzname[1];
        // display time zone description
   // saveFont = memDC->SelectObject ( &smallFont );
    memDC->SelectObject ( &smallFont );
   if ( newtime->tm_isdst )
	   memDC->TextOut ( X + 5, YHome +YStep, tzname[1] );
   else
	   memDC->TextOut ( X + 5, YHome +YStep, tzname[0] );

   strstream sout;
   sout << "Registered to: " << l.registeredName << ends;
   memDC->TextOut (( int ) ( XHour * ratio ), YHome + YStep, sout.str ());
    memDC->SelectObject ( saveFont );
}

static int monthLimit[12] = 
{
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int CWorldTime2000View::DaylightSavingsZone ( LocationItem * li )
{
        // daylight savings not enabled
        if ( ! li->dsEnable )
                return 0;

		return 1;
}

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

        CFont baseFont;
//    font.CreatePointFont ( 110, "Arial" );
//    font.CreatePointFont ( 90, "Arial" );
    baseFont.CreatePointFont ( l.fontSize, l.fontName );

	LOGFONT base;
	baseFont.GetLogFont ( &base );
	base.lfWeight = FW_BOLD;
	base.lfUnderline = TRUE;

	CFont boldFont;
	boldFont.CreateFontIndirect ( &base );


	baseFont.GetLogFont ( &base );
	if ( l.fontBold )
		base.lfWeight = FW_BOLD;
	base.lfItalic = l.fontItalic;
	CFont font;
	font.CreateFontIndirect ( &base );


        CFont * saveFont = memDC->SelectObject ( &font );

        short * aItem;
        for ( int i = 0; aItem = l.Get ( i ); i++ )
        {
                LocationItem * li;
                CTime ti = *t;

                li = l.GetLocation ( *aItem );

                if ( li == 0 )
                        break;

                int n = i + 0;

                int ref;

				if ( li->alarmEnable )
	                DrawIconEx(  memDC, (int )(( XHour * ratio ) - 28), YPOS + 2, theApp.alarmIcon, 12, 12, 0, NULL, DI_NORMAL );
//	                DrawIconEx(  memDC, (int )(( XHour * ratio ) - 28), Y + ( n * YStep ) + 2, theApp.alarmIcon, 12, 12, 0, NULL, DI_NORMAL );

				if ( moveModeOn && n == moveSrc )
				{
					static int blink = 0;
					if ( blink == 0 )
					{
	                    memDC->SetTextColor( moveColor );
					    memDC->SelectObject ( &boldFont );
			            memDC->TextOut ( X, YPOS, ( char * ) "Select new position" );
						blink = 1;
					}
					else
						blink = 0;
				}
				else
                if ( selected == n )
                {
                    memDC->SetTextColor( selectedColor );
				    memDC->SelectObject ( &boldFont );
					DrawIconEx(  memDC, (int)(( XHour * ratio ) - 41), YPOS + 2, theApp.homeIcon, 12, 12, 0, NULL, DI_NORMAL );
//                   DrawIconEx(  memDC, (int)(( XHour * ratio ) - 41), Y + ( n * YStep ) + 2, theApp.homeIcon, 12, 12, 0, NULL, DI_NORMAL );
                        ref = 1;
	                memDC->TextOut ( X, YPOS, ( char * ) li->name );
                }
                else
                {
                    memDC->SetTextColor( locationColor );
                memDC->SelectObject ( &font );
                        ref = 0;
		            memDC->TextOut ( X, YPOS, ( char * ) li->name );
                }
//                memDC->TextOut ( X, Y + ( n * YStep ), ( char * ) li->name );

                float dst = 0.0;
                if ( DaylightSavings ( li, &ti ))
                {
                        DrawIconEx(  memDC, (int)(( XHour * ratio )  - 15), YPOS + 2, theApp.dstOnIcon, 12, 12, 0, NULL, DI_NORMAL );
//                        DrawIconEx(  memDC, (int)(( XHour * ratio )  - 15), Y + ( n * YStep ) + 2, theApp.dstOnIcon, 12, 12, 0, NULL, DI_NORMAL );
                        ti += CTimeSpan( 0, 1, 0, 0 );
                        dst = 1.0;
                }
				else
				if ( DaylightSavingsZone ( li ))
	                DrawIconEx(  memDC, (int)(( XHour * ratio ) - 15), YPOS + 2, theApp.dstOffIcon, 12, 12, 0, NULL, DI_NORMAL );
//	                DrawIconEx(  memDC, (int)(( XHour * ratio ) - 15), Y + ( n * YStep ) + 2, theApp.dstOffIcon, 12, 12, 0, NULL, DI_NORMAL );

                float mins = ( float ) floor ( li->offset ) - li->offset;
                if ( mins ) mins = 30.0f;
                ti += CTimeSpan( 0, ( int ) ( li->offset - gmtOffset - homeDST ), ( int ) mins, 0 ); // 1 hour exactly


				if ( li->alarmEnable && ti.GetHour() == li->alarmHour && ti.GetMinute() == li->alarmMinute )
					if ( alarm == -1 )
						// dont set the alarm if it was just reset
						alarm = i + 1;

					static int blink = 0;
					if ( alarm == i + 1 )
					{
					if ( blink == 0 )
					{
	                DrawTime ( memDC, &ti, YPOS, li->offset + dst - homeDST );
//	                DrawTime ( memDC, &ti, Y + ( n * YStep ) - 10, li->offset + dst - homeDST );
					blink = 1;
					}
					else
						blink = 0;
					}
					else
	                DrawTime ( memDC, &ti, YPOS, li->offset + dst - homeDST );
//	                DrawTime ( memDC, &ti, Y + ( n * YStep ) - 10, li->offset + dst - homeDST );

        }
        memDC->SelectObject ( saveFont );

}


//extern CRect appRect;

void CWorldTime2000View::OnPaint() 
{
        if ( drawing )
                return;


        drawing = 1;
        _tzset();


        CPaintDC dc(this); // device context for painting

        // TODO: Add your message handler code here

        // Do not call CWnd::OnPaint() for painting messages

        // set memory device context
    CMemDC memDC( GetDC() );
//    memDC.CreateCompatibleDC ( GetDC());


	
	ratio = ( float ) ( l.frameRect.right - l.frameRect.left - 15 ) / 375.0f;

        // set default font
        CFont font;
//    font.CreatePointFont ( 110, "Arial" );
    font.CreatePointFont ( l.fontSize, l.fontName );
    CFont * saveFont = memDC->SelectObject ( &font );

	CSize size = memDC->GetTextExtent ( "Yy", 2 );
	YStep = size.cy + 2;
	xOff = size.cx / 2;
	Y = ( size.cy * 2 ) + 10;

        // set background to black
        CBrush * background = new CBrush ( backgroundColor ); //PALETTERGB ( 0, 0, 0 ));
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
	/*
        CFont beta;
    beta.CreatePointFont ( 600, "Arial" );
//    saveFont = memDC->SelectObject ( &beta );
    memDC->SelectObject ( &beta );
    memDC->SetTextColor( BetaColor );
*/
	/*

  BETA MESSAGE

		static char *betaStr = "CFUB";
		for ( int i = 0; i < 4; i++ )
			betaStr[i] -= 1;
        memDC->TextOut ( 170, 5, betaStr );
		for ( i = 0; i < 4; i++ )
			betaStr[i] += 1;
*/
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


		    CDC dcMem;
		    dcMem.CreateCompatibleDC ( GetDC());


	// draw the background first
		if ( l.p.showWallpaper )
		{
		//    CDC dcMem;
//		    dcMem.CreateCompatibleDC ( GetDC());

			BITMAP bm;
			GetObject ( wallpaper, sizeof ( BITMAP ), & bm );

//		    CMaskedBitmap * currentBitmap = ( CMaskedBitmap* ) CMaskedBitmap::FromHandle (( HBITMAP ) wallpaper ); // ( CBitmap * ) shit; //dcMem.SelectObject (( HBITMAP ) shit );
//			currentBitmap->GetBitmap ( & bm );

		    CBitmap * pOldBitmap = ( CBitmap * ) dcMem.SelectObject (( HBITMAP ) wallpaper ); //itmap );
//		    CBitmap * pOldBitmap = ( CBitmap * ) dcMem.SelectObject ( currentBitmap );

		    dcMem.SetMapMode ( GetDC()->GetMapMode ());

	int width, height;
	width = l.frameRect.right - l.frameRect.left;
	height = l.frameRect.bottom - l.frameRect.top;
	for ( int h = 0; h < height; h+= bm.bmHeight )
	{
		for ( int w = 0; w < width; w+= bm.bmWidth )
		{
//		  dcMem.StretchBlt ( w, h, bm.bmWidth, bm.bmHeight, memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY ); //COPY);
		 int w2, h2;
		 if ( bm.bmWidth > width - w )
			 w2 = bm.bmWidth;
		 else
			 w2 = width - w;

		 if ( bm.bmHeight > height - h )
			 h2 = bm.bmHeight;
		 else
			 h2 = height - h;


//		 currentBitmap->Draw ( memDC, w, h );
		memDC->BitBlt ( w, h, w2, h2, &dcMem, 0, 0, SRCCOPY);
//		  memDC->StretchBlt ( w, h, bm.bmWidth, bm.bmHeight, &dcMem, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY ); //COPY);
//		  memDC->StretchBlt ( w, h, w2, h2, &dcMem, 0, 0, w2, h2, SRCCOPY ); //COPY);
		}
	}


//	  dcMem.SelectObject ( pOldBitmap );
	}

        if ( l.p.drawSphere )
        {
//    CDC dcMem;
//    dcMem.CreateCompatibleDC ( GetDC());


//    CBitmap * pOldBitmap = dcMem.SelectObject ( &theApp.worldBitmap[whichIcon] ); //itmap );
//    dcMem.SetMapMode (GetDC()->GetMapMode ());

	theApp.worldBitmap[whichIcon].DrawTransparent ( memDC, CRect ( 0, 0, 160, 160 ), 0x00000000 );
//    memDC->StretchBlt (0, 0, 160, 160, &dcMem, 0, 0, 160, 160, SRCPAINT ); //COPY);



//    dcMem.SelectObject ( pOldBitmap );

        whichIcon++;
        if ( whichIcon > 11 )
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
	static int timeOut = -1;

	if ( alarm >= 0 )
		Beep( 3000, 250 );
	else
	if ( alarm == -2 )
	{
		if ( timeOut == -1 )
			timeOut = 150;
		else
			timeOut--;

		if ( timeOut == 0 )
			alarm = -1;
	}
	else
		timeOut = -1;
//		Be
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

	if ( point.y < Y )
		selected = -1;
	else
        selected = ( point.y - Y ) / YStep;
        if ( selected >= 0 && selected < l.SizeDisplay())
		{
	        selectedAdjustment = l.OffsetList ( l.OffsetDisplay ( selected ));
			if ( moveModeOn )
				// swap the items around
				l.Move ( moveSrc, selected );
		}
        else
		{
			selected = -1;
            selectedAdjustment = -( _timezone / 3600 ) + homeDST;
		}
//		selectedAdjustment = locations.OffsetList ( locations.selected );
//		offset = 0;


//		Beep( 3000, 500 );
	moveModeOn = 0;
     CWnd::OnLButtonUp(nFlags, point);
}


void CWorldTime2000View::OnRButtonUp(UINT nFlags, CPoint point)
{
	moveModeOn = 0;
	if ( point.y < Y )
		selected = -1;
	else
        selected = ( point.y - Y ) / YStep;

        if ( selected >= -1)
        {
//                if ( MessageBox ( "Delete location ?", "Confirm Delete", MB_YESNO | MB_ICONQUESTION ) != IDNO )
//                        l.Delete ( selected - 1 );
//        }



			if ( selected > l.SizeDisplay() - 1 )
				return;

//			if ( l.SizeDisplay() < selected )
//				return;

	    CMenu menu;
		CMenu *submenu;
		// Load the menu.
	    menu.LoadMenu( IDR_CONTEXT );
	    // Get the pop-up menu.
		submenu = menu.GetSubMenu(0);
	    // Convert to screen coordinates.
	    ClientToScreen(&point);
	    // Post the menu
		submenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, point.x, point.y, AfxGetApp()->m_pMainWnd,NULL);
		}

			/*
        selected = ( point.y - Y ) / YStep;
        if ( selected )
        {
                if ( MessageBox ( "Delete location ?", "Confirm Delete", MB_YESNO | MB_ICONQUESTION ) != IDNO )
                        l.Delete ( selected - 1 );
        }

     CWnd::OnRButtonUp(nFlags, point);
	 */
}


BOOL CWorldTime2000View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return FALSE;	
	return CWnd ::OnEraseBkgnd(pDC);
}

#include "mainfrm.h"
void CWorldTime2000View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	moveModeOn = 0;
	if ( point.y < Y )
		selected = -1;
	else
        selected = ( point.y - Y ) / YStep;

    ::PostMessage ( mainFrame->m_hWnd, WM_COMMAND, ( WPARAM ) LOWORD( ID_CONTEXT_MODIFY ), 0 );

//	mainFrame->OnContextModify() 

	
//	CWnd ::OnMButtonDblClk(nFlags, point);
}
