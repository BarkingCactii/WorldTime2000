// WorldTime2000View.cpp : implementation of the CWorldTime2000View class
//

#include "stdafx.h"
#include "resource.h"
#include <math.h>
#include "location.h"
//#include "display.h"
#include "WorldTime2000.h"
#include "WorldTime2000View.h"
#include "memdc.h"
#include "home.h"
#include "preferences.h"
#include "sounds.h"
#include "whatif.h"
#include "regdata.h"
#include "mainfrm.h"
#include "displaylocation.h"
#include "alarms.h"

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
bool mouseInView = false;	// is mouse in this view ?
static int flashWhatIf = 1;

int alarm = -1; // -1 is dormant, -2 is reset


//
//  Calculate which member item is selected
//
int CalculateSelected ( int y )
{
    int sumY = m.GetHome()->GetY();
    if ( y < sumY )
        return -1;

    for ( int i = 0; i < m.Size(); i++ )
    {
        sumY += m.GetMemberByIdx ( i )->GetY();
        if ( y < sumY )
            return i;
    }

    // nothing selected, default to home
    return -1;
}


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
ON_WM_MOUSEMOVE()
ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000View message handlers

BOOL CWorldTime2000View::PreCreateWindow(CREATESTRUCT& cs)
{
     DEBUGLINE ( __FILE__, __LINE__ );
     if (!CScrollView::PreCreateWindow(cs))
          return false;
     
     // FIX FOR LAMA     return true;
     cs.dwExStyle |= WS_EX_CLIENTEDGE;
//          cs.style |= CBRS_TOOLTIPS;
     //     cs.dwExStyle |= WS_VSCROLL;
     cs.style &= ~WS_BORDER;
     //     cs.style &= ~WS_HSCROLL;
     
     cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
          ::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);
     
     return true;
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

// #define YPOS ( Y + ( n * YStep )) to Define
int YPOS ( int n )
{
    int y;

    y = Y;
    for ( int i = 0; i < n; i++ )
    {
        MemberItem * mItem;
        if (!(mItem = m.GetMemberByIdx ( i )))
            break;

        y += mItem->GetY();
    }

    return y;
}

float ratio = 1.0f;

//void CWorldTime2000View::DrawTime ( CPaintDC * memDC, CTime * t, int y, float offset )
void CWorldTime2000View::DrawTime ( CMemDC & memDC, CTime * t, int y, float offset, int idx )
{
     //return;
     DEBUGLINE ( __FILE__, __LINE__ );
     int hour = t->GetHour();
     int minute = t->GetMinute();
     int second = t->GetSecond();
     
     char * pm = "";
     
     if ( !r.GetKey("Show24Hour" ).word )
     {
          if ( hour < 12 )
          {
             if ( r.GetKey("ShowAM" ).word )
        //       if ( p.showAM )
                    pm = "AM";
          }
          else
          if ( hour == 12 )
               pm = "PM";
          else
          if ( hour >= 12 )
          {
               hour -= 12;
               pm = "PM";
          }

     }
         
     /*
     if ( ! p._24hour && hour > 12 )
     {
          hour -= 12;
          pm = "PM";
     }
     else
     {
          if ( p.showAM )
               pm = "AM";
     }
     if ( ! p._24hour && hour == 12 )
     {
          pm = "PM";
     }
     else
     {
          if ( p.showAM )
               pm = "AM";
     }
       */
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
     if ( r.GetKey("ShowHoursGMT").word )
         memDC->TextOut (( int ) ( XDiff * ratio ), y, buf ); //sout.str());
     CSize offsetSize = memDC->GetTextExtent ( buf, strlen ( buf )); //sout.str(), strlen ( sout.str()));
     
     // now show all the stuff using small fonts
     CFont smallFont;
     if ( idx == -1 )
         // home
         smallFont.CreatePointFont ( m.GetHome ()->GetFont()->fontSize - 30, m.GetHome()->GetFont()->fontName.c_str() );
     else
         smallFont.CreatePointFont ( m.GetMemberByIdx ( idx )->GetFont()->fontSize - 30, m.GetMemberByIdx(idx)->GetFont()->fontName.c_str() );
//     smallFont.CreatePointFont ( d.fontSize - 30, d.fontName.c_str() );
     CFont * saveFont = memDC->SelectObject ( &smallFont );
     
     
     // display PM indicator
     s = pm;
    if ( r.GetKey("ShowSeconds" ).word )
//     if ( p.seconds )
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
     if ( r.GetKey("ShowHoursGMT").word )//d.showHoursGMT )
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

bool CWorldTime2000View::FormatToolTip ( CPoint point )
{
    float timeAdjustment = 0.0f;
	m_datatip.ResetText();

    int whichLoc = CalculateSelected ( point.y );
    MemberItem * mItem = m.GetMemberByIdx ( whichLoc );
    if ( !mItem )
        return false;
    LocationItem * lItem = l.GetLocationbyTag ( mItem->LocRef());
    if ( !lItem )
        return false;
    if ( whichLoc == -1 )
        timeAdjustment = -( _timezone / 3600.0f ) + homeDST;
    else
        timeAdjustment = l.OffsetList ( m.GetMemberByIdx ( whichLoc )->Tag());

    char buf[100];
    sprintf ( buf, "%s, %s    %0.1f hrs GMT", lItem->city.c_str(), lItem->country.c_str(), lItem->offset );
	m_datatip.AddText(buf);
    sprintf ( buf, "Area Code (%d), Country Code (%d)", lItem->areaCode, lItem->countryCode );
	m_datatip.AddText(buf);

    string str;
    SunHours ( str, lItem );
//    sprintf ( buf, "Lat (%0.2f) Long (%0.2f)", lItem->latitude, lItem->longitude );
	m_datatip.AddText(str.c_str());
    CTime t = CTime::GetCurrentTime();
    sprintf ( buf, "Daylight Savings is %s", DaylightSavings ( lItem, &t ) ? "ON" : "OFF" );
	m_datatip.AddText(buf);
    sprintf ( buf, "(%d) Alarm(s) pending", mItem->NumAlarms());
	m_datatip.AddText(buf);
    
    return true;
}
void CWorldTime2000View::DrawTooltip ( CMemDC & memDC )
{
//    CToolTipCtrl tt;

//    tt.Create ( this, TTS_ALWAYSTIP );

    /* TO FIX

     DEBUGLINE ( __FILE__, __LINE__ );
     CPoint offset = GetScrollPosition ();
     CPoint point = lastPosition;
     point += offset;
     DEBUGLINE ( __FILE__, __LINE__ );
	 int tooltipLocation;
     
	 
     if ( point.y < Y )
     {
          tooltipLocation = -1;
//          selected = -1;
//          selectedAdjustment = -( _timezone / 3600.0f ) + homeDST;
     }
     else
     {
          int oldSelected = selected;
//          selected = ( point.y - Y ) / YStep;
          tooltipLocation = ( point.y - Y ) / YStep;
          
          if (! m.GetMemberByIdx ( tooltipLocation ))
          {
               selected = oldSelected;
               return;
          }
          
//          selectedAdjustment = l.OffsetList ( l.OffsetDisplay ( selected ));
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
     
     short *lIdx;
     if ( tooltipLocation == -1 ) //selected == -1 )
     {
         return;
//          MemberItem * di = m.GetHome ();
     }
     else
     {
          lIdx = m.Get ( tooltipLocation ); //selected );
          if ( lIdx )
               li = l.GetLocationbyTag ( *lIdx );
     }
     
     if ( !li )
          return;

     MemberItem * mi = m.GetByTag ( *lIdx );
     if ( !di )
         return;

     if ( mi->alarmEnable )
     {
          
          if ( p._24hour )
               sprintf ( buf2,"Set for %d:%02d", di->alarmHour, di->alarmMinute );
          else
          {
               char pm[3];
               
               pm[2] = 0;
               strcpy ( pm, "AM" );
               
               int hour, min;
               hour = di->alarmHour;
               min = di->alarmMinute;
               
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
     
     if ( tooltipLocation >= 0 )
//     if ( selected >= 0 )
          sprintf ( buf, "%s (%d) GMT is %.1fhrs. Alarm is %s", li->country, li->countryCode, li->offset, buf2 ); //( char * )li->name );
//          sprintf ( buf, "(%s) GMT is %.1fhrs. Alarm is %s", li->country, li->offset, buf2 ); //( char * )li->name );
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
    */ 
}

const char * regTo = "Registered to: ";

//void CWorldTime2000View::DrawHome ( CPaintDC * memDC, CTime * t )
void CWorldTime2000View::DrawHome ( CMemDC & memDC, CTime * t )
{
//    return;
    
     DEBUGLINE ( __FILE__, __LINE__ );
     /*
     CBrush * brush = new CBrush ( m.GetHome()->GetFont()->fontColor );


     CRect rect;
     if ( r.GetKey("ShowHoursGMT" ).word )
     {
          rect.left = 2; rect.top = 2; rect.bottom = Y - 3;
          rect.right = ( int ) (( XDiff + 60 ) * ratio );
//          ( 2, 2, ( int ) (( 60 ) * ratio ), Y - 3 );
     }
     else
     {
          rect.left = 2; rect.top = 2; rect.bottom = Y - 3;
          rect.right = ( int ) (( XDiff ) * ratio );
//          CRect rect ( 2, 2, ( int ) (( XDiff + 60 ) * ratio ), Y - 3 );
     }

    	memDC->FrameRect ( rect, brush );
     viewExtents.cx = rect.right - 20;
     delete brush;
       */
     CFont font;
     font.CreatePointFont ( m.GetHome()->GetFont()->fontSize + 20, m.GetHome()->GetFont()->fontName.c_str() );
//     font.CreatePointFont ( d.fontSize + 20, d.fontName.c_str() );
     
     
     LOGFONT base;
     font.GetLogFont ( &base );
     base.lfWeight = FW_BOLD;
     base.lfItalic = true;

        MemberItem * mItem = m.GetHome();
          if ( mItem->GetFont()->fontBold )
            base.lfWeight = FW_BOLD;
          base.lfItalic = ( unsigned char ) mItem->GetFont()->fontItalic;
          base.lfUnderline = ( unsigned char ) mItem->GetFont()->fontUnderline;
//          CFont font;
 //         font.CreateFontIndirect ( &base );
//         saveFont = memDC->SelectObject ( &font );

          memDC->SetTextColor( mItem->GetFont()->fontColor );//locationColor );

     

     CFont bigFont;
     bigFont.CreateFontIndirect ( &base );

     
     

     CFont smallFont;
     smallFont.CreatePointFont ( m.GetHome()->GetFont()->fontSize - 30, m.GetHome()->GetFont()->fontName.c_str() );
//     smallFont.CreatePointFont ( d.fontSize - 30, d.fontName.c_str() );
     
     CFont * saveFont = memDC->SelectObject ( &bigFont );
//     memDC->SetTextColor( homeColor );
     
     
          CSize size = memDC->GetTextExtent ( "Yy", 2 );
//          YStep = size.cy + 2;
//          xOff = size.cx / 2;
          Y = ( size.cy * 2 ) + 10;
          m.GetHome()->Y ( Y );

          


     CBrush * brush = new CBrush ( m.GetHome()->GetFont()->fontColor );


     CRect rect;
     if ( r.GetKey("ShowHoursGMT" ).word )
     {
          rect.left = 2; rect.top = 2; rect.bottom = Y - 3;
          rect.right = ( int ) (( XDiff + 60 ) * ratio );
//          ( 2, 2, ( int ) (( 60 ) * ratio ), Y - 3 );
     }
     else
     {
          rect.left = 2; rect.top = 2; rect.bottom = Y - 3;
          rect.right = ( int ) (( XDiff ) * ratio );
//          CRect rect ( 2, 2, ( int ) (( XDiff + 60 ) * ratio ), Y - 3 );
     }

    	memDC->FrameRect ( rect, brush );
     viewExtents.cx = rect.right - 20;
     delete brush;








     if ( hourFlicker )
     {
          char buf[100];
          sprintf ( buf, "%s *", r.GetKey("Home").str.c_str() );
          memDC->TextOut ( X, YHome, buf );
     }
     else
          memDC->TextOut ( X, YHome, r.GetKey("Home").str.c_str());
     
     struct tm *newtime;
     time_t long_time;
     
     time( &long_time );                // Get time as long integer. 
     newtime = localtime( &long_time ); // Convert to local time. 
     
//     static flashWhatIf = 1;
     if ( r.GetKey("ShowWhatIf").word && flashWhatIf )
     {
          DrawIconEx(  memDC, (int)(( XHour * ratio ) - 28), YHome + 2, theApp.whatIfIcon, 12, 12, 0, NULL, DI_NORMAL );
          flashWhatIf = 0;
     }
     else
     {
          flashWhatIf = 1;
          if ( m.GetHome()->NumAlarms() )
               DrawIconEx(  memDC, (int)(( XHour * ratio ) - 28), YHome + 2, theApp.alarmIcon, 12, 12, 0, NULL, DI_NORMAL );
     }
     
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
/*     
     if ( m.GetHome()->NumAlarms() && t->GetHour() == d.GetHome()->alarmHour && t->GetMinute() == d.GetHome()->alarmMinute )
          if ( alarm == -1 )
          {
               // dont set the alarm if it was just reset
               if ( d.GetHome()->alarmRunEnable )
                    ShellExecute( m_hWnd, NULL, d.GetHome()->alarmRunApp.c_str(), NULL, NULL, SW_SHOWNORMAL );
               alarm = 0;
          }
*/          
          static blink = 0;
          if ( alarm == 0 )
          {
               if ( blink == 0 )
               {
                    DrawTime ( memDC, t, YHome, -( _timezone / 3600.0f ), -1 );
                    blink = 1;
               }
               else
               {
                    memDC->TextOut (( int ) (XHour * ratio ), YHome, ( char * )m.GetHome()->Name().c_str());// FIXalarmMessage.c_str() );
                    blink = 0;
               }
          }
          else
               DrawTime ( memDC, t, YHome, -( _timezone / 3600.0f ), -1 );
          
          // display time zone description
          memDC->SelectObject ( &smallFont );
          if ( newtime->tm_isdst )
               memDC->TextOut ( X + 5, YHome + m.GetHome()->GetY() / 2, tzname[1] );
//               memDC->TextOut ( X + 5, YHome +YStep, tzname[1] );
          else
               memDC->TextOut ( X + 5, YHome + m.GetHome()->GetY() / 2, tzname[0] );
          
          
          //return;	
          char buf[255];
          sprintf ( buf, "%s %s", regTo, m.registeredName.c_str() );
          memDC->TextOut (( int ) ( XHour * ratio ), YHome + m.GetHome()->GetY() / 2, buf );
          //	strstream sout;
          //	sout << regTo << l.registeredName << ends;
          //	memDC->TextOut (( int ) ( XHour * ratio ), YHome + YStep, sout.str ());
          
          memDC->SelectObject ( saveFont );
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
               else
               // our calculations exceed the number of days for this month, so crop back
               if ( weekOffset + dayOffset > monthLimit[month] )
                    weekOffset -= 7;

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
               else
               // our calculations exceed the number of days for this month, so crop back
               if ( weekOffset + dayOffset > monthLimit[month] )
                    weekOffset -= 7;

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
     
//     CString s;
     
     int gmtOffset = -( _timezone / 3600 );
     
     float gmtMinOffset = ( float ) -( floor (( float ) _timezone / 3600.0f ) - (( float ) _timezone / 3600.0f ));
     if ( gmtMinOffset ) gmtMinOffset = 30.0f;
     
     //     int gmtMinOffset = -( _timezone / 3600  );
/*     
     CFont baseFont;
     //    font.CreatePointFont ( 110, "Arial" );
     //    font.CreatePointFont ( 90, "Arial" );
     baseFont.CreatePointFont ( m.GetMemberByIdx ( 0 )->GetFont()->fontSize, m.GetMemberByIdx(0)->GetFont()->fontName.c_str() );
//     baseFont.CreatePointFont ( d.fontSize, d.fontName.c_str());
     
     LOGFONT base;
     baseFont.GetLogFont ( &base );
     base.lfWeight = FW_BOLD;
     base.lfUnderline = true;
     
     CFont boldFont;
     boldFont.CreateFontIndirect ( &base );
     
     
     baseFont.GetLogFont ( &base );
     if ( d.fontBold )
          base.lfWeight = FW_BOLD;
     base.lfItalic = ( unsigned char ) d.fontItalic;
     CFont font;
     font.CreateFontIndirect ( &base );
     
     
  */   
     CFont * saveFont;

     MemberItem * mItem;
//     bool init = false;
     for ( int i = 0; mItem = m.GetMemberByIdx ( i ); i++ )
     {
          LocationItem * li;
          CTime ti = *t;
          
          li = l.GetLocationbyTag ( mItem->LocRef() );
    
//          MemberItem * di = m.GetByTag ( *aItem );
 //         if ( di == 0 )
              // null pointer, abort, but keep processing next
  //            continue;







         CFont baseFont;
         baseFont.CreatePointFont ( mItem->GetFont()->fontSize, mItem->GetFont()->fontName.c_str() );
     
         LOGFONT base;
         baseFont.GetLogFont ( &base );
         base.lfWeight = FW_BOLD;
         base.lfUnderline = true;
     
         CFont boldFont;
         boldFont.CreateFontIndirect ( &base );
     
         baseFont.GetLogFont ( &base );

//          FontData *f = mItem->GetFont();
          if ( mItem->GetFont()->fontBold )
            base.lfWeight = FW_BOLD;
          base.lfItalic = ( unsigned char ) mItem->GetFont()->fontItalic;
          base.lfUnderline = ( unsigned char ) mItem->GetFont()->fontUnderline;
          CFont font;
          font.CreateFontIndirect ( &base );
         saveFont = memDC->SelectObject ( &font );

          memDC->SetTextColor( mItem->GetFont()->fontColor );//locationColor );

          // text extents are different for each line
          CSize size = memDC->GetTextExtent ( "Yy", 2 );
          YStep = size.cy + 2;
          xOff = size.cx / 2;
//          Y = ( size.cy * 2 ) + 10;
          mItem->Y ( YStep );






          if ( li == 0 )
               break;
          
          int n = i + 0;
          
          int ref;
          
//          static flashWhatIf = 1;
          if ( r.GetKey("ShowWhatIf").word && flashWhatIf )
          {
               DrawIconEx(  memDC, (int)(( XHour * ratio ) - 28), YPOS(n) + 2, theApp.whatIfIcon, 12, 12, 0, NULL, DI_NORMAL );
//               flashWhatIf = 0;
          }
          else
          {
  //             flashWhatIf = 1;
               if ( mItem->NumAlarms() )
                    DrawIconEx(  memDC, (int )(( XHour * ratio ) - 28), YPOS(n) + 2, theApp.alarmIcon, 12, 12, 0, NULL, DI_NORMAL );
          }
          //	                DrawIconEx(  memDC, (int )(( XHour * ratio ) - 28), Y + ( n * YStep ) + 2, theApp.alarmIcon, 12, 12, 0, NULL, DI_NORMAL );
          
          if ( moveModeOn && n == moveSrc )
          {
               static int blink = 0;
               if ( blink == 0 )
               {
                    memDC->SetTextColor( moveColor );
                    memDC->SelectObject ( &boldFont );
                    memDC->TextOut ( X, YPOS(n), ( char * ) "Select new position" );
                    blink = 1;
               }
               else
                    blink = 0;
          }
          else
               if ( selected == n )
               {
//                    memDC->SetTextColor( selectedColor );
                    memDC->SelectObject ( &boldFont );

					// 
					//	draw time of day

					//
                    //DrawIconEx(  memDC, (int)(( XHour * ratio ) - 41), YPOS(n) + 2, theApp.homeIcon, 12, 12, 0, NULL, DI_NORMAL );

                    ref = 1;
                    

                    char buf[100];
//                    sprintf ( buf, "%s %s (%d)", li->city, li->country, li->countryCode );
                    sprintf ( buf, "%s", li->city.c_str() );

//                    sprintf ( buf, "%s (%s)", li->city, li->country );
                    
                    memDC->TextOut ( X, YPOS(n), ( char * ) buf ); //li->city );


                    CSize size = memDC->GetTextExtent ( buf, strlen ( buf ));

                    CFont smallFont;
                     smallFont.CreatePointFont ( m.GetMemberByIdx ( n )->GetFont()->fontSize - 30, m.GetMemberByIdx(n)->GetFont()->fontName.c_str() );
                //    smallFont.CreatePointFont ( d.fontSize - 30, d.fontName.c_str() );
                    memDC->SelectObject ( &smallFont );

                    sprintf ( buf, "%s (%d)", li->country.c_str(), li->countryCode );

                    memDC->TextOut ( X + size.cx + 5, YPOS(n), ( char * ) buf ); //li->city );

                    memDC->SelectObject ( &boldFont );
               }
               else
               {
                    memDC->SetTextColor( mItem->GetFont()->fontColor );//locationColor );
                    memDC->SelectObject ( &font );
                    ref = 0;
                    memDC->TextOut ( X, YPOS(n), ( char * ) li->city.c_str() );
                    
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
                    DrawIconEx(  memDC, (int)(( XHour * ratio )  - 15), YPOS(n) + 2, theApp.dstOnIcon[dstIdx], 12, 12, 0, NULL, DI_NORMAL );
                    //                        DrawIconEx(  memDC, (int)(( XHour * ratio )  - 15), Y + ( n * YStep ) + 2, theApp.dstOnIcon, 12, 12, 0, NULL, DI_NORMAL );
                    ti += CTimeSpan( 0, 1, 0, 0 );
                    dst = 1.0;
               }
               else
                    if ( DaylightSavingsZone ( li ))
                         DrawIconEx(  memDC, (int)(( XHour * ratio ) - 15), YPOS(n) + 2, theApp.dstOffIcon, 12, 12, 0, NULL, DI_NORMAL );
                    //	                DrawIconEx(  memDC, (int)(( XHour * ratio ) - 15), Y + ( n * YStep ) + 2, theApp.dstOffIcon, 12, 12, 0, NULL, DI_NORMAL );
                    
                    float mins = ( float ) floor ( li->offset ) - li->offset;
                    if ( mins ) mins = 30.0f;
                    ti += CTimeSpan( 0, ( int ) (( int ) li->offset - gmtOffset - homeDST ), ( int ) mins - ( int ) gmtMinOffset, 0 ); // 1 hour exactly
                    
// alarm processing
                    // to implement

                    /*
                    if ( mItem->NumAlarms() && ti.GetHour() == di->alarmHour && ti.GetMinute() == di->alarmMinute )
                         if ( alarm == -1 )
                         {
                              // dont set the alarm if it was just reset
                              if ( di->alarmRunEnable )
                                   ShellExecute( m_hWnd, NULL, di->alarmRunApp.c_str(), NULL, NULL, SW_SHOWNORMAL );
                              alarm = i + 1;
                         }
*/                         
                         static int blink = 0;
                         /* TO FIX
                         if ( alarm == i + 1 )
                         {
                              if ( blink == 0 )
                              {
                                   DrawTime ( memDC, &ti, YPOS, li->offset + dst - homeDST );
                                   blink = 1;
                              }
                              else
                              {
                                   memDC->TextOut (( int ) (XHour * ratio ), YPOS, ( char * )di->alarmMessage.c_str() );
                                   blink = 0;
                              }
                         }
                         else
                         */

						 // 
					//	draw time of day
					//	
					//
						 static int timeOfDayIdx[] = { 2, 4, 5, 6, 8, 9, 12, 15, 16, 18, 19, 20, 22, 23 };
							int idx;
						 for ( idx = sizeof ( timeOfDayIdx ) / sizeof ( int ) - 1; idx >= 0; idx-- )
						 {

							 if ( ti.GetHour() >= timeOfDayIdx[idx] || idx == 0 )
							 {
								DrawIconEx(  memDC, (int)(( XHour * ratio ) - 41), YPOS(n) + 2, theApp.timeOfDay[idx], 12, 12, 0, NULL, DI_NORMAL );
								break;
							 }
                       	 }

						

                              DrawTime ( memDC, &ti, YPOS(n), li->offset + dst - homeDST, i );
                         
                         
     }
     
     int n = i;
     viewExtents.cy = YPOS(n);
     
     memDC->SelectObject ( saveFont );
     
}


//extern CRect appRect;

void CWorldTime2000View::OnDraw ( CDC * dc )
{
     if ( drawing )
          return;
     
     
     drawing = 1;
     _tzset();
     
     if ( m.Size () == 0 )
         return;

     if ( hourFlicker )
          hourFlicker = 0;
     else
          hourFlicker = 1;
     
     //     CPaintDC dc(this); // device context for painting
     // set memory device context
     CMemDC memDC( dc ); //GetDC() );
     
     
     if ( r.GetKey("ShowHoursGMT" ).word )
          ratio = ( float ) ( r.GetKey("WindowRight").word - r.GetKey("WindowLeft").word - 15 ) / ( XDiff + 60.0f );
     else
          ratio = ( float ) ( r.GetKey("WindowRight").word - r.GetKey("WindowLeft").word - 15 ) / ( XDiff );
//static const float XDiff = 315;
     
     // set default font
     CFont font;
     font.CreatePointFont ( m.GetMemberByIdx ( 0 )->GetFont()->fontSize, m.GetMemberByIdx(0)->GetFont()->fontName.c_str() );
//     font.CreatePointFont ( d.fontSize, d.fontName.c_str() );
     CFont * saveFont = memDC->SelectObject ( &font );
     
     CSize size = memDC->GetTextExtent ( "Yy", 2 );
     YStep = size.cy + 2;
     xOff = size.cx / 2;
     Y = ( size.cy * 2 ) + 10;
     
     // set background to black
     
     CBrush * background = new CBrush ( r.GetKey("BackgroundColor").word ); //PALETTERGB ( 0, 0, 0 ));
     CRect backgroundRect;
     GetClientRect ( &backgroundRect );
     memDC->FillRect (&backgroundRect, background );
     delete background;
     
     // transparent drawing mode
     memDC->SetBkMode ( TRANSPARENT );
     
     // get current local time
     CTime t = CTime::GetCurrentTime();
     
     if ( r.GetKey("ShowWhatIf").word )
     {
          t = whatIfTime;



//            li->offset + dst - homeDST - selectedAdjustment + homeDST;
////          if ( offset - selectedAdjustment + homeDST )

          LocationItem * li;

               float dst = 0.0;
               float locationOffset;
          if ( selected >= 0 )
          {
          li = l.GetLocationbyTag ( l.OffsetDisplay ( selected ) );
//          li->offset + dst - homeDST
//          hmmm what to do ?

               if ( DaylightSavings ( li, &t ))
               {
//                    ti += CTimeSpan( 0, 1, 0, 0 );
                    dst = 1.0;
               }

               locationOffset = li->offset;
          }
          else
               locationOffset = _timezone / 3600.0f;
//            li->offset + dst - homeDST - selectedAdjustment + homeDST;

          float offset = -( _timezone / 3600.0f ) - selectedAdjustment; // | dst
//          float offset = locationOffset + dst - selectedAdjustment;
//          float offset = locationOffset + dst - selectedAdjustment;
//          float offset = li->offset + dst - homeDST - selectedAdjustment + homeDST;
//          float offset = li->offset + dst - homeDST;
//_timezone - selectedAdjustment - homeDST;
//          float offset = _timezone - selectedAdjustment - homeDST;
          float minOffset = ( float ) ceil ( offset ) - offset; 
          minOffset *= 60.0f;

          CTimeSpan ts ( 0, ( int ) offset, ( int ) minOffset, 0 );
          t += ts;
//          t.SetHour ( t.GetHour += ( int ) offset );
               //offset - selectedAdjustment + homeDST
     }
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
     if ( r.GetKey("ShowWallpaper").word )
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
          width =  r.GetKey("WindowRight").word - r.GetKey("WindowLeft").word;   // x difference
          height = r.GetKey("WindowBottom").word - r.GetKey("WindowTop").word;   // x difference

//          width = d.frameRect.right - d.frameRect.left;
//          height = d.frameRect.bottom - d.frameRect.top;
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
     
     // draw home location
     //dstIdx++; change back
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

    char buf[100];
    
//    CTime t = CTime::GetCurrentTime();
    string s = t.Format( "%I:%M %p" ); // on %b %d, %Y" );
    sprintf ( buf, "%d Alarm(s) pending | Local time %.1lf hours GMT", m.AlarmsPending(), -_timezone / 3600.0f );
//    sprintf ( buf, "%d Alarms | %.1lf hours GMT", s.c_str(), ( _daylight ) ? _tzname[0] : _tzname[1], m.AlarmsPending(), -_timezone / 3600.0f );
    if ( IsWindow ( mainFrame->GetStatusBar()))
        mainFrame->GetStatusBar().SetPaneText ( 0, buf );


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
                                              if ( p.showWallpaper )
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
                                                            
                                                              if ( p.drawSphere )
                                                              {
                                                              //          static int moveAround = p.movingSphere;
                                                              
                                                                int frames = p.frames;
                                                                
                                                                  int diff = ( l.frameRect.right - l.frameRect.left ) / frames;   // x difference
                                                                  //          diff = 160 / 8; //11;
                                                                  
                                                                    CRect rect;
                                                                    rect.top = 0;
                                                                    rect.left = 0; //( l.frameRect.right - l.frameRect.left ) / 23 * whichIcon; //abs ( whichIcon - 12 );
                                                                    if ( p.movingSphere )
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
          Sleep ( 1000 );
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

/*
     static int ticks = 0;
     if ( position == lastPosition )
     {

          if ( ticks >= 2 )
          {
               if ( ticks > 8 )
               {
                    // reset after 4 seconds
                    ticks = 0;
                    showTooltip = false;
                    position.x = position.y = -1;
					mouseInView = false;
               }
               else
               {
                    if ( p.tooltips )
					{
                         // only display if user has elected tooltips and mouse is in the vuew
							if ( mouseInView )
		                         showTooltip = true;
					}
               }
          }
          
          ticks++;
     }
     else
     {
          ticks = 0;
          position = lastPosition;
          showTooltip = false;
     }
  */   
     DEBUGLINE ( __FILE__, __LINE__ );
     CSize previousExtents ( 0, 0 );
     if ( previousExtents != viewExtents )
     {
          SetScrollSizes ( MM_TEXT, viewExtents );
          previousExtents = viewExtents;
     }
     
     
     static int timeOut = -1;
     
     DEBUGLINE ( __FILE__, __LINE__ );
          if ( !drawing )
               Invalidate(false);
          


  /*
    char buf[100];
    
//    CTime t = CTime::GetCurrentTime();
    string s = t.Format( "%I:%M %p on %b %d, %Y" );
    sprintf ( buf, "Local time %s | %s | %d Alarms | %.1lf hours GMT", s.c_str(), ( _daylight ) ? _tzname[0] : _tzname[1], m.AlarmsPending(), -_timezone / 3600.0f );
    if ( IsWindow ( mainFrame->GetStatusBar()))
        mainFrame->GetStatusBar().SetPaneText ( 0, buf );
    */

    CTime t = CTime::GetCurrentTime();
           ProcessAlarms ( t );

         ProcessChimes ( t );

          DEBUGLINE ( __FILE__, __LINE__ );
          
          //          CScrollView::OnTimer(nIDEvent);
}

int CWorldTime2000View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
     DEBUGLINE ( __FILE__, __LINE__ );
     
     //        l.frameRect.left = appRect.left = x;
     //        l.frameRect.top = appRect.top = y;
     
     //     CSize total ( l.frameRect.right - l.frameRect.left, 1000 );
//     EnableToolTips(TRUE);
     
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

//     CStatic * stat = new CStatic;
//     stat->Create( "SHITHEAD", WS_CHILD, CRect ( 0, 0, 500, 500 ), this, 65535 );

     return 0;
}


void CWorldTime2000View::OnLButtonUp(UINT nFlags, CPoint point)
{
     CPoint offset = GetScrollPosition ();
     point += offset;
     
     DEBUGLINE ( __FILE__, __LINE__ );
     
     selected = CalculateSelected ( point.y );
//     if ( point.y < Y )
//          selected = -1;
//     else
//          selected = ( point.y - Y ) / YStep;
     if ( selected >= 0 && selected < m.Size())
     {
          selectedAdjustment = l.OffsetList ( m.GetMemberByIdx ( selected )->LocRef());
//          selectedAdjustment = l.OffsetList ( l.OffsetDisplay ( selected ));
          if ( moveModeOn )
               // swap the items around
               m.Move ( moveSrc, selected );
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

     selected = CalculateSelected ( point.y );
//     if ( point.y < Y )
//          selected = -1;
//     else
//          selected = ( point.y - Y ) / YStep;
     
     if ( selected >= -1)
     {
          //                if ( MessageBox ( "Delete location ?", "Confirm Delete", MB_YESNO | MB_ICONQUESTION ) != IDNO )
          //                        l.Delete ( selected - 1 );
          //        }
          
          
          
          if ( selected > m.Size() - 1 )
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
     return false;	
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

     selected = CalculateSelected ( point.y );
//     if ( point.y < Y )
 //         selected = -1;
  //   else
   //       selected = ( point.y - Y ) / YStep;
     
     ::PostMessage ( mainFrame->m_hWnd, WM_COMMAND, ( WPARAM ) LOWORD( ID_CONTEXT_MODIFY ), 0 );
     
     //	mainFrame->OnContextModify() 
     
     
     //	CScrollView ::OnMButtonDblClk(nFlags, point);
}

void CWorldTime2000View::OnDestroy() 
{

   	if( IsWindow(m_datatip.m_hWnd) ) 
        m_datatip.DestroyWindow();

     CScrollView ::OnDestroy();
     
     // TODO: Add your message handler code here
     KillTimer ( 101 );
}



void CWorldTime2000View::OnMouseMove(UINT nFlags, CPoint point) 
{
     // TODO: Add your message handler code here and/or call default
	 mouseInView = true;

     lastPosition = point;
     
     CScrollView ::OnMouseMove(nFlags, point);

    

     // format tooltip
     FormatToolTip ( point );
//	m_datatip.AddText("from the second");
//	m_datatip.AddText("and the third line");
	m_datatip.SetNewTip(point);

  //   m_datatip.Set(point, str.c_str());

//     EnableToolTips ( TRUE );
}

/*
BOOL CWorldTime2000View::ShowToolTip( UINT id, NMHDR * pNMHDR, LRESULT * pResult )
{
    TOOLTIPTEXT *pTTT = (TOOLTIPTEXT *)pNMHDR;
    UINT nID =pNMHDR->idFrom;
    if (pTTT->uFlags & TTF_IDISHWND)
    {
        // idFrom is actually the HWND of the tool
        nID = ::GetDlgCtrlID((HWND)nID);
        if(nID)
        {
            pTTT->lpszText = "TEST"; //MAKEINTRESOURCE(nID);
            pTTT->hinst = AfxGetResourceHandle();
            return(TRUE);
        }
    }
    return(FALSE);
}
  */
void CWorldTime2000View::OnInitialUpdate() 
{
	CScrollView ::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
//	EnableToolTips ( TRUE );
    // enable datatips for this window
   	m_datatip.Create(this);
    m_datatip.On(TRUE);
	m_datatip.SetSurrounding(4, 4);


}
