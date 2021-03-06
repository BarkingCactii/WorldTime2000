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
#include "sounds.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000View

CWorldTime2000View * view = 0;
CSize viewExtents ( 500, 1000 );

CPoint lastPosition ( 0, 0 );
static int showTooltip = 0;
static int hourFlicker = 0;
static int dstIdx = 0;

int alarm = -1; // -1 is dormant, -2 is reset


CWorldTime2000View::CWorldTime2000View()
{
     DEBUGLINE ( __FILE__, __LINE__ );
     view = this;
     //	 selected = 0;
     selectedAdjustment = 0.0f;
     selected = -1;
     homeDST = 0.0;
     selectedAdjustment = -( _timezone / 3600.0f ) - homeDST;
     drawing = 0;
     moveModeOn = 0;

	 m_pDocument = 0;
     
     //	 selectedAdjustment = locations.OffsetList ( locations.selected );
}

CWorldTime2000View::~CWorldTime2000View()
{
     DEBUGLINE ( __FILE__, __LINE__ );
}


BEGIN_MESSAGE_MAP(CWorldTime2000View,CScrollView )
//{{AFX_MSG_MAP(CWorldTime2000View)
ON_WM_TIMER()
ON_WM_CREATE()
ON_WM_LBUTTONUP()
ON_WM_RBUTTONUP()
ON_WM_ERASEBKGND()
ON_WM_LBUTTONDBLCLK()
ON_WM_DESTROY()
ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000View message handlers

BOOL CWorldTime2000View::PreCreateWindow(CREATESTRUCT& cs)
{
     DEBUGLINE ( __FILE__, __LINE__ );
     if (!CScrollView::PreCreateWindow(cs))
          return FALSE;
     
// FIX FOR LAMA     return TRUE;
     cs.dwExStyle |= WS_EX_CLIENTEDGE;
//     cs.style |= CBRS_TOOLTIPS;
//     cs.dwExStyle |= WS_VSCROLL;
     cs.style &= ~WS_BORDER;
//     cs.style &= ~WS_HSCROLL;

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

//void CWorldTime2000View::DrawTime ( CPaintDC * memDC, CTime * t, int y, float offset )
void CWorldTime2000View::DrawTime ( CMemDC & memDC, CTime * t, int y, float offset )
{
//return;
     DEBUGLINE ( __FILE__, __LINE__ );
     int hour = t->GetHour();
     int minute = t->GetMinute();
     int second = t->GetSecond();
     
     char * pm = "";
     
     if ( ! l.p._24hour && hour > 12 )
     {
          hour -= 12;
          pm = "PM";
     }
     if ( ! l.p._24hour && hour == 12 )
     {
          pm = "PM";
     }
     
     // display the hours, minutes & seconds
     char hourBuf[15];
     
     if ( hourFlicker )
          sprintf ( hourBuf, "%02d:%02d", hour, minute );
     else
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
	 char buf[255];

//     strstream sout;
     char sign = ' ';
     if ( offset - selectedAdjustment + homeDST > 0 )
          sign = '+';
//     sout << sign;
     if ( offset - selectedAdjustment + homeDST )
		 sprintf ( buf, "%c %.1f", sign, offset - selectedAdjustment + homeDST );
//          sout << offset - selectedAdjustment + homeDST << ends;
     else
		 strcpy ( buf, "---" );
//          sout << "---" << ends;
     memDC->TextOut (( int ) ( XDiff * ratio ), y, buf ); //sout.str());
     CSize offsetSize = memDC->GetTextExtent ( buf, strlen ( buf )); //sout.str(), strlen ( sout.str()));
     
     // now show all the stuff using small fonts
     CFont smallFont;
     smallFont.CreatePointFont ( l.fontSize - 30, l.fontName );
     CFont * saveFont = memDC->SelectObject ( &smallFont );
     
     
     // display PM indicator
     s = pm;
     if ( l.p.seconds )
          sprintf ( hourBuf, ":%02d %s", second, s );
     else
          sprintf ( hourBuf, " %s", s );

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


void CWorldTime2000View::DrawGradient ( CMemDC& pDC, CRect* pRect)
{
    CBrush* pBrush[64];

//     int idx = 63;
    for (int i = 0; i < 64; i++ )
    {
         int red = ( i * 4 ) - 80;
         int green = ( i * 4 ) - 80;
         int blue = ( i * 4 ) - 30;
//         int red = 255 - ( i * 4 ) - 70;
//         int green = 255 - ( i * 4 ) - 50;
//         int blue = 255 - ( i * 4 ) - 0; //40;
//         if ( red < 120 ) red = 120;
         if ( red < 0 ) red = 0;
         if ( green < 0 ) green = 0;
         if ( blue < 100 ) blue = 100;
        pBrush[i] = new CBrush (PALETTERGB ( red, green, blue ));
//    for (int i=0; i<64; i++)
//        pBrush[i] = new CBrush (PALETTERGB (0, 0, 255 - (i * 4)));
    }

    int nWidth = pRect->Width ();
    int nHeight = pRect->Height ();
    CRect rect; // = *pRect;

//    CRect crect;
//     GetClientRect (&crect);
//     CMemDC    dc(pDC, crect);

     
    for (i=0; i<nWidth; i++) {
        rect.SetRect ( pRect->left + i, pRect->top, pRect->left + i + 1, pRect->bottom );
        pDC->FillRect (&rect, pBrush[(i * 63) / nWidth]);
    }


//    for (i=0; i<nHeight; i++) {
//        rect.SetRect (0, i, nWidth, i + 1);
//        pDC->FillRect (&rect, pBrush[(i * 63) / nHeight]);
//    }

    for (i=0; i<64; i++)
        delete pBrush[i];
}


void CWorldTime2000View::DrawTooltip ( CMemDC & memDC )
{
	DEBUGLINE ( __FILE__, __LINE__ );
     CPoint offset = GetScrollPosition ();
     CPoint point = lastPosition;
     point += offset;
     DEBUGLINE ( __FILE__, __LINE__ );
     
     if ( point.y < Y )
	 {
          selected = -1;
          selectedAdjustment = -( _timezone / 3600.0f ) + homeDST;
	 }
     else
	 {
		  int oldSelected = selected;
          selected = ( point.y - Y ) / YStep;

		  if (! l.Get ( selected ))
		  {
			  selected = oldSelected;
			  return;
		  }

          selectedAdjustment = l.OffsetList ( l.OffsetDisplay ( selected ));
	 }
     // move a little away from pointer
     point.x -= 30;
     point.y += 20;

     if ( point.x < 0 )
          point.x = 5;


     // home
     LocationItem * li = 0;
     char buf[100];
     char buf2[100];

     CSize textSize;
     
     if ( selected == -1 )
          li = l.GetHome ();
     else
	 {
		  short * lIdx = l.Get ( selected );
		  if ( lIdx )
	          li = l.GetLocationbyTag ( *lIdx );
	 }

     if ( !li )
          return;

     if ( li->alarmEnable )
     {

          if ( l.p._24hour )
               sprintf ( buf2,"Set for %d:%02d", li->alarmHour, li->alarmMinute );
          else
          {
               char pm[3];

               pm[2] = 0;
               strcpy ( pm, "AM" );

               int hour, min;
               hour = li->alarmHour;
               min = li->alarmMinute;

               if ( hour >= 12 )
               {
                    if ( hour > 12 )
                    {
                         hour -= 12;
                         strcpy ( pm, "PM" );
                    }
                    if ( hour == 12 )
                         strcpy ( pm, "PM" );
               }
               sprintf ( buf2,"Set for %d:%02d%s", hour, min, pm ); //, li->alarmMessage );
          }
     }
     else
          strcpy ( buf2, "Off" );

	 if ( selected >= 0 )
	     sprintf ( buf, "(%s) GMT is %.1fhrs. Alarm is %s", li->country, li->offset, buf2 ); //( char * )li->name );
	 else
	     sprintf ( buf, "Alarm is %s", buf2 ); //( char * )li->name );

     textSize = memDC->GetTextExtent ( buf, strlen ( buf ));


     if ( point.x + textSize.cx > viewExtents.cx )
          // tooltip flowing off screen
     {
          int offset = ( point.x + textSize.cx ) - ( viewExtents.cx - 5 );
          point.x -= offset;
     }

     if ( point.y + textSize.cy > viewExtents.cy )
          // tooltip flowing off screen
     {
          int offset = ( point.y + textSize.cy ) - ( viewExtents.cy - 5 );
          point.y -= offset;
     }


	CRect rect ( point.x, point.y, point.x + textSize.cx, point.y + textSize.cy );

     COLORREF tooltipColor ( RGB ( 255, 255, 255 ));
	CFont font;
	font.CreatePointFont ( 80, "Arial" );
	CFont * saveFont = memDC->SelectObject ( &font );

     DrawGradient ( memDC, &rect );
//	memDC->FillSolidRect ( rect, RGB ( 0, 0, 128 ));
	CBrush * brush = new CBrush ( RGB ( 255, 255, 255 ));

	memDC->FrameRect ( rect, brush );
     delete brush;
	memDC->SetTextColor( tooltipColor );
   	memDC->TextOut ( point.x + 2, point.y + 2, buf );


     memDC->SelectObject ( saveFont );

}

const char * regTo = "Registered to: ";

//void CWorldTime2000View::DrawHome ( CPaintDC * memDC, CTime * t )
void CWorldTime2000View::DrawHome ( CMemDC & memDC, CTime * t )
{
	DEBUGLINE ( __FILE__, __LINE__ );
	CBrush * brush = new CBrush ( homeColor );
	CRect rect ( 2, 2, ( int ) (( XDiff + 60 ) * ratio ), Y - 3 );
    	memDC->FrameRect ( rect, brush );
	viewExtents.cx = rect.right - 20;
	delete brush;
	
	CFont font;
	font.CreatePointFont ( l.fontSize + 20, l.fontName );
	
	
	LOGFONT base;
	font.GetLogFont ( &base );
	base.lfWeight = FW_BOLD;
	base.lfItalic = TRUE;
	
	CFont bigFont;
	bigFont.CreateFontIndirect ( &base );
	
	
	CFont smallFont;
	smallFont.CreatePointFont ( l.fontSize - 30, l.fontName );
	
	CFont * saveFont = memDC->SelectObject ( &bigFont );
	memDC->SetTextColor( homeColor );

     
     if ( hourFlicker )
     {
          char buf[100];
          sprintf ( buf, "%s *", l.GetHome()->city );
	     memDC->TextOut ( X, YHome, buf );
     }
     else
	     memDC->TextOut ( X, YHome, ( char * ) l.GetHome()->city );
	
	struct tm *newtime;
	time_t long_time;
	
	time( &long_time );                /* Get time as long integer. */
	newtime = localtime( &long_time ); /* Convert to local time. */
	
	if ( l.GetHome()->alarmEnable )
		DrawIconEx(  memDC, (int)(( XHour * ratio ) - 28), YHome + 2, theApp.alarmIcon, 12, 12, 0, NULL, DI_NORMAL );
	
	if ( newtime->tm_isdst )
	{
		DrawIconEx(  memDC, (int)(( XHour * ratio ) - 15), YHome + 2, theApp.dstOnIcon[dstIdx], 12, 12, 0, NULL, DI_NORMAL );
		homeDST = 1.0f;
	}
	else
	{
		if ( _daylight )
			DrawIconEx(  memDC, (int)(( XHour * ratio ) - 15), YHome + 2, theApp.dstOffIcon, 12, 12, 0, NULL, DI_NORMAL );
		
		homeDST = 0.0f;
	}

	if ( l.GetHome()->alarmEnable && t->GetHour() == l.GetHome()->alarmHour && t->GetMinute() == l.GetHome()->alarmMinute )
		if ( alarm == -1 )
          {
			// dont set the alarm if it was just reset
               if ( l.GetHome()->alarmRunEnable )
                    ShellExecute( m_hWnd, NULL, l.GetHome()->alarmRunApp, NULL, NULL, SW_SHOWNORMAL );
			alarm = 0;
          }
		
	static blink = 0;
	if ( alarm == 0 )
	{
		if ( blink == 0 )
		{
			DrawTime ( memDC, t, YHome, -( _timezone / 3600.0f ));
			blink = 1;
		}
		else
		{
			memDC->TextOut (( int ) (XHour * ratio ), YHome, ( char * )l.GetHome()->alarmMessage );
			blink = 0;
		}
	}
	else
		DrawTime ( memDC, t, YHome, -( _timezone / 3600.0f ));

	// display time zone description
	memDC->SelectObject ( &smallFont );
	if ( newtime->tm_isdst )
		memDC->TextOut ( X + 5, YHome +YStep, tzname[1] );
	else
		memDC->TextOut ( X + 5, YHome +YStep, tzname[0] );


//return;	
	char buf[255];
	sprintf ( buf, "%s %s", regTo, l.registeredName );
	memDC->TextOut (( int ) ( XHour * ratio ), YHome + YStep, buf );
//	strstream sout;
//	sout << regTo << l.registeredName << ends;
//	memDC->TextOut (( int ) ( XHour * ratio ), YHome + YStep, sout.str ());

	memDC->SelectObject ( saveFont );

	// play quarterly chimes
	static int played = 0;
	static int numCuckoos = 1;

	if ( t->GetMinute() == 0 )
	{
		if ( !played )
			Playsound ( l.p.hourName, l.p.hourOn );

		played = 1;
	}
	else
	if ( t->GetMinute() == 15 )
	{
		if ( !played )
			numCuckoos = 1;

		if ( numCuckoos )
			if ( Playsound ( l.p.quarterName, l.p.quarterOn ))
				numCuckoos--;

		played = 1;
	}
	else
	if ( t->GetMinute() == 30 )
	{
		if ( !played )
			numCuckoos = 2;

		if ( numCuckoos )
			if ( Playsound ( l.p.quarterName, l.p.quarterOn ))
				numCuckoos--;

		played = 1;
	}
	else
	if ( t->GetMinute() == 45 )
	{
		if ( !played )
			numCuckoos = 3;

		if ( numCuckoos )
			if ( Playsound ( l.p.quarterName, l.p.quarterOn ))
				numCuckoos--;

		played = 1;
	}
	else
		played = 0;


//	memDC->SelectObject ( saveFont );
}

static int monthLimit[12] = 
{
     31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int CWorldTime2000View::DaylightSavingsZone ( LocationItem * li )
{
     DEBUGLINE ( __FILE__, __LINE__ );
     // daylight savings not enabled
     if ( ! li->dsEnable )
          return 0;
     
     return 1;
}

int CWorldTime2000View::DaylightSavings ( LocationItem * li, CTime * t )
{
     DEBUGLINE ( __FILE__, __LINE__ );
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

//void CWorldTime2000View::DrawLocation ( CPaintDC * memDC, CTime * t )
void CWorldTime2000View::DrawLocation ( CMemDC & memDC, CTime * t )
{
     DEBUGLINE ( __FILE__, __LINE__ );
     
     CString s;
     
     int gmtOffset = -( _timezone / 3600 );

     float gmtMinOffset = ( float ) -( floor (( float ) _timezone / 3600.0f ) - (( float ) _timezone / 3600.0f ));
     if ( gmtMinOffset ) gmtMinOffset = 30.0f;

//     int gmtMinOffset = -( _timezone / 3600  );
     
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
     base.lfItalic = ( unsigned char ) l.fontItalic;
     CFont font;
     font.CreateFontIndirect ( &base );
     
     
     CFont * saveFont = memDC->SelectObject ( &font );
     
     short * aItem;
     for ( int i = 0; aItem = l.Get ( i ); i++ )
     {
          LocationItem * li;
          CTime ti = *t;
          
          li = l.GetLocationbyTag ( *aItem );
          
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

                    char buf[100];
                    sprintf ( buf, "%s (%s)", li->city, li->country );

                    memDC->TextOut ( X, YPOS, ( char * ) buf ); //li->city );
               }
               else
               {
                    memDC->SetTextColor( locationColor );
                    memDC->SelectObject ( &font );
                    ref = 0;
                    memDC->TextOut ( X, YPOS, ( char * ) li->city );

                    // display country in small font
/*
                    CSize size = memDC->GetTextExtent ( ( char * ) li->city, li->city.Length());
                    CFont smallFont;
                    smallFont.CreatePointFont ( l.fontSize - 20, l.fontName );
                    CFont * saveFont = memDC->SelectObject ( &smallFont );
                    memDC->TextOut ( X + size.cx + 5, YPOS, ( char * ) li->country );
                    memDC->SelectObject ( saveFont );
*/
               }
               //                memDC->TextOut ( X, Y + ( n * YStep ), ( char * ) li->name );
               
               float dst = 0.0;
               if ( DaylightSavings ( li, &ti ))
               {
                    DrawIconEx(  memDC, (int)(( XHour * ratio )  - 15), YPOS + 2, theApp.dstOnIcon[dstIdx], 12, 12, 0, NULL, DI_NORMAL );
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
                    ti += CTimeSpan( 0, ( int ) (( int ) li->offset - gmtOffset - homeDST ), ( int ) mins - ( int ) gmtMinOffset, 0 ); // 1 hour exactly
                    
                    
                    if ( li->alarmEnable && ti.GetHour() == li->alarmHour && ti.GetMinute() == li->alarmMinute )
                         if ( alarm == -1 )
                         {
                              // dont set the alarm if it was just reset
                              if ( li->alarmRunEnable )
                                   ShellExecute( m_hWnd, NULL, li->alarmRunApp, NULL, NULL, SW_SHOWNORMAL );
                              alarm = i + 1;
                          }

                         static int blink = 0;
                         if ( alarm == i + 1 )
                         {
                              if ( blink == 0 )
                              {
                                   DrawTime ( memDC, &ti, YPOS, li->offset + dst - homeDST );
                                   blink = 1;
                              }
                              else
							  {
							     memDC->TextOut (( int ) (XHour * ratio ), YPOS, ( char * )li->alarmMessage );
                                   blink = 0;
							  }
                         }
                         else
                              DrawTime ( memDC, &ti, YPOS, li->offset + dst - homeDST );

                         
     }
	 
     int n = i;
	viewExtents.cy = YPOS;

     memDC->SelectObject ( saveFont );
     
}


//extern CRect appRect;

void CWorldTime2000View::OnDraw ( CDC * dc )
{
     if ( drawing )
          return;
     
     
     drawing = 1;
      _tzset();
     
     if ( hourFlicker )
          hourFlicker = 0;
     else
          hourFlicker = 1;
     
//     CPaintDC dc(this); // device context for painting
     // set memory device context
     CMemDC memDC( dc ); //GetDC() );
     
     
     
     ratio = ( float ) ( l.frameRect.right - l.frameRect.left - 15 ) / 375.0f;
     
     // set default font
     CFont font;
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
     
     // draw background icon of world
     static int whichIcon = 0;
     
     memDC->RealizePalette();
               
     
//     dcMem.Detach ();
//	dcMem.ReleaseOutputDC ();
//	dcMem.ReleaseAttribDC ();
  
//	 ReleaseDC ( &dcMem );

//     memDC->SelectObject ( saveFont );
//	 drawing = 0;
//	 return;

       
     // draw the background first
     if ( l.p.showWallpaper )
     {
	     CDC dcMem;
          dcMem.CreateCompatibleDC ( memDC ); //GetDC());
          //    CDC dcMem;
          
          BITMAP bm;
          GetObject ( wallpaper, sizeof ( BITMAP ), & bm );

          CBitmap * pOldBitmap = ( CBitmap * ) dcMem.SelectObject (( HBITMAP ) wallpaper ); //itmap );
          
          dcMem.SetMapMode ( memDC->GetMapMode ());
//          dcMem.SetMapMode ( GetDC()->GetMapMode ());
          
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
                    
                    
                    memDC->BitBlt ( w, h, w2, h2, &dcMem, 0, 0, SRCCOPY);
               }
          }
//          memDC->SelectObject ( pOldBitmap ); //itmap );
     }
     
     if ( l.p.drawSphere )
     {
//          static int moveAround = l.p.movingSphere;

          int frames = l.p.frames;

          int diff = ( l.frameRect.right - l.frameRect.left ) / frames;   // x difference
//          diff = 160 / 8; //11;

          CRect rect;
          rect.top = 0;
          rect.left = 0; //( l.frameRect.right - l.frameRect.left ) / 23 * whichIcon; //abs ( whichIcon - 12 );
          if ( l.p.movingSphere )
          {
          rect.bottom = ( diff * abs ( whichIcon - frames ));
          rect.right = ( diff * abs ( whichIcon - frames ));
          }
          else
          {
          rect.bottom = 160;
          rect.right = 160;
          }
          theApp.worldBitmap[whichIcon % 12].DrawTransparent ( memDC, rect, 0x00000000 );
          
          whichIcon++;
          if ( whichIcon > frames )
               whichIcon = 0;
     }
     
     // draw home location
     dstIdx++;
     if ( dstIdx == 4 )
          dstIdx = 0;


     DrawHome ( memDC, &t );
     
     // draw locations
     DrawLocation ( memDC, &t );
 
     if ( showTooltip )
          DrawTooltip ( memDC );
//     if ( showTooltip )
//          memDC->TextOut ( 10, 10, "TOOLTIP ON" );

     memDC->SelectObject ( saveFont );
     
//dcMem.Detach ();
//dcMem.ReleaseOutputDC ();
//     memDC->Detach ();
//	 memDC->ReleaseOutputDC ();
     drawing = 0;
  
}
/*
void CWorldTime2000View::OnPaint() 
{
	return;
     DEBUGLINE ( __FILE__, __LINE__ );
     if ( drawing )
          return;
     
     
     drawing = 1;
      _tzset();
     
     
     CPaintDC dc(this); // device context for painting
//	 CPaintDC * memDC = &dc;     
     // TODO: Add your message handler code here
     
     // Do not call CScrollView::OnPaint() for painting messages
     
     // set memory device context
     CMemDC memDC( &dc ); //GetDC() );
     
     
     
     ratio = ( float ) ( l.frameRect.right - l.frameRect.left - 15 ) / 375.0f;
     
     // set default font
     CFont font;
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
     
     // draw background icon of world
     static int whichIcon = 0;
     
     memDC->RealizePalette();
               
     
//     dcMem.Detach ();
//	dcMem.ReleaseOutputDC ();
//	dcMem.ReleaseAttribDC ();
  
//	 ReleaseDC ( &dcMem );

//     memDC->SelectObject ( saveFont );
//	 drawing = 0;
//	 return;

       
     // draw the background first
     if ( l.p.showWallpaper )
     {
	     CDC dcMem;
		 dcMem.CreateCompatibleDC ( memDC ); //GetDC());
          //    CDC dcMem;
          
          BITMAP bm;
          GetObject ( wallpaper, sizeof ( BITMAP ), & bm );

          CBitmap * pOldBitmap = ( CBitmap * ) dcMem.SelectObject (( HBITMAP ) wallpaper ); //itmap );
          
          dcMem.SetMapMode ( memDC->GetMapMode ());
//          dcMem.SetMapMode ( GetDC()->GetMapMode ());
          
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
                    
                    
                    memDC->BitBlt ( w, h, w2, h2, &dcMem, 0, 0, SRCCOPY);
               }
          }
//          memDC->SelectObject ( pOldBitmap ); //itmap );
     }
     
     if ( l.p.drawSphere )
     {
//          static int moveAround = l.p.movingSphere;

          int frames = l.p.frames;

          int diff = ( l.frameRect.right - l.frameRect.left ) / frames;   // x difference
//          diff = 160 / 8; //11;

          CRect rect;
          rect.top = 0;
          rect.left = 0; //( l.frameRect.right - l.frameRect.left ) / 23 * whichIcon; //abs ( whichIcon - 12 );
          if ( l.p.movingSphere )
          {
          rect.bottom = ( diff * abs ( whichIcon - frames ));
          rect.right = ( diff * abs ( whichIcon - frames ));
          }
          else
          {
          rect.bottom = 160;
          rect.right = 160;
          }
          theApp.worldBitmap[whichIcon % 12].DrawTransparent ( memDC, rect, 0x00000000 );
          
          whichIcon++;
          if ( whichIcon > frames )
               whichIcon = 0;
     }
     
     // draw home location
     DrawHome ( memDC, &t );
     
     // draw locations
     DrawLocation ( memDC, &t );
     
     memDC->SelectObject ( saveFont );
     
//dcMem.Detach ();
//dcMem.ReleaseOutputDC ();
//     memDC->Detach ();
//	 memDC->ReleaseOutputDC ();
     drawing = 0;
  
}
  */


static UINT Timer ( LPVOID param )
{
//     g_graphLeftEvent[0] = (HANDLE)g_graphLeftStart;
//     g_graphLeftEvent[1] = (HANDLE)g_graphLeftKill;
//     return ThreadLeft ( param );
     DEBUGLINE ( __FILE__, __LINE__ );
	while ( 1 )
	{
		Sleep ( 500 );
		view->OnDoTimer ();
	}
}


void CWorldTime2000View::OnDoTimer( void )
{
     DEBUGLINE ( __FILE__, __LINE__ );
	OnTimer ( 0 );
}

void CWorldTime2000View::OnTimer(UINT nIDEvent)
{
     DEBUGLINE ( __FILE__, __LINE__ );

     //
     // tooltip section
     //
     static CPoint position ( 1, 1 );
     static int ticks = 0;
     if ( position == lastPosition )
     {

          if ( ticks >= 2 )
          {
               if ( ticks > 20 )
               {
                    // reset after 10 seconds
                    ticks = 0;
                    showTooltip = False;
                    position.x = position.y = -1;
               }
               else
               {
                    if ( l.p.tooltips )
                         // only display if user has elected tooltips
                         showTooltip = True;
               }
          }

          ticks++;
     }
     else
     {
          ticks = 0;
          position = lastPosition;
          showTooltip = False;
     }

        DEBUGLINE ( __FILE__, __LINE__ );
	 CSize previousExtents ( 0, 0 );
	 if ( previousExtents != viewExtents )
	 {
		SetScrollSizes ( MM_TEXT, viewExtents );
		previousExtents = viewExtents;
	 }

      
     static int timeOut = -1;

        DEBUGLINE ( __FILE__, __LINE__ );
     if ( alarm >= 0 )
		 ::PlayAlarm ( l.p.alarmName, l.p.alarmOn );
//          Beep( 3000, 250 );
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
          //     ShellExecute( m_hWnd, NULL, "c:\\program files\\worldtime2000\\worldtime2000.exe", NULL, NULL, SW_SHOWNORMAL );
               timeOut = -1;
          if ( !drawing )
               Invalidate(FALSE);
       
        DEBUGLINE ( __FILE__, __LINE__ );
          
//          CScrollView::OnTimer(nIDEvent);
}

int CWorldTime2000View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
     DEBUGLINE ( __FILE__, __LINE__ );

//        l.frameRect.left = appRect.left = x;
//        l.frameRect.top = appRect.top = y;

//     CSize total ( l.frameRect.right - l.frameRect.left, 1000 );
     EnableToolTips(TRUE);

     SetScrollSizes ( MM_TEXT, viewExtents );
//     ResizeParentToFit();


     if (CScrollView::OnCreate(lpCreateStruct) == -1)
          return -1;
     
     //        return -1;
     DEBUGLINE ( __FILE__, __LINE__ );

	AfxBeginThread ( Timer, this, THREAD_PRIORITY_IDLE );
//     g_timerThread = AfxBeginThread ( ThreadLeftProc, this, THREAD_PRIORITY_IDLE );
//     g_timerStart.SetEvent ();
//     if ( !SetTimer ( 101, 500, NULL ))
//          MessageBox ( "Timer broken", NULL, MB_ICONEXCLAMATION );
     
     DEBUGLINE ( __FILE__, __LINE__ );
     
     return 0;
}


void CWorldTime2000View::OnLButtonUp(UINT nFlags, CPoint point)
{
     CPoint offset = GetScrollPosition ();
	 point += offset;

     DEBUGLINE ( __FILE__, __LINE__ );
     
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
          selectedAdjustment = -(( float ) _timezone / 3600.0f ) + homeDST;
     }
     //		selectedAdjustment = locations.OffsetList ( locations.selected );
     //		offset = 0;
     
     
     //		Beep( 3000, 500 );
     moveModeOn = 0;
     CScrollView::OnLButtonUp(nFlags, point);
}


void CWorldTime2000View::OnRButtonUp(UINT nFlags, CPoint point)
{
     CPoint offset = GetScrollPosition ();
	 point += offset;

     DEBUGLINE ( __FILE__, __LINE__ );
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
          
		  point -= offset;
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
     
       CScrollView::OnRButtonUp(nFlags, point);
     */
}


BOOL CWorldTime2000View::OnEraseBkgnd(CDC* pDC) 
{
     DEBUGLINE ( __FILE__, __LINE__ );
     // TODO: Add your message handler code here and/or call default
     return FALSE;	
     return CScrollView ::OnEraseBkgnd(pDC);
}

#include "mainfrm.h"
void CWorldTime2000View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
     CPoint offset = GetScrollPosition ();
	 point += offset;

     DEBUGLINE ( __FILE__, __LINE__ );
     // TODO: Add your message handler code here and/or call default
     moveModeOn = 0;
     if ( point.y < Y )
          selected = -1;
     else
          selected = ( point.y - Y ) / YStep;
     
     ::PostMessage ( mainFrame->m_hWnd, WM_COMMAND, ( WPARAM ) LOWORD( ID_CONTEXT_MODIFY ), 0 );
     
     //	mainFrame->OnContextModify() 
     
     
     //	CScrollView ::OnMButtonDblClk(nFlags, point);
}

void CWorldTime2000View::OnDestroy() 
{
     CScrollView ::OnDestroy();
     
     // TODO: Add your message handler code here
     KillTimer ( 101 );
}



void CWorldTime2000View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
     lastPosition = point;
     
	CScrollView ::OnMouseMove(nFlags, point);
}



