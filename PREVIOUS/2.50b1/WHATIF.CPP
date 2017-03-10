// whatif.cpp : implementation file
//

#include "stdafx.h"
#include "worldtime2000.h"
#include "worldtime2000view.h"
#include "whatif.h"
#include "location.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CTime whatIfTime = GetCurrentTime();

/////////////////////////////////////////////////////////////////////////////
// whatif dialog


whatif::whatif(CWnd* pParent /*=NULL*/)
	: CDialog(whatif::IDD, pParent)
{
	//{{AFX_DATA_INIT(whatif)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void whatif::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(whatif)
	DDX_Control(pDX, IDC_TIME, m_time);
	DDX_Control(pDX, IDC_DATE, m_date);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(whatif, CDialog)
	//{{AFX_MSG_MAP(whatif)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// whatif message handlers

static LocationItem * li;

BOOL whatif::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if ( view->selected >= 0 )
	    li = l.GetLocationbyTag ( l.OffsetDisplay ( view->selected ));
	else
		li = l.GetHome ();

     char buf[255];

     sprintf ( buf, "What if the time in %s was...", li->city );

	SetDlgItemText ( IDC_LOCATION, buf );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void whatif::OnOK() 
{
	// TODO: Add extra validation here
     UpdateData();

	CTime date, time;	
	DWORD enabled = m_date.GetTime ( date );

     int year = date.GetYear ();
     int month = date.GetMonth (); // Jan = 1
     int day = date.GetDay (); // 1st = 1

	DWORD enablet = m_time.GetTime ( time );

     int hour = time.GetHour (); // from 0 to 23
     int minute = time.GetMinute (); // from 0 to 59

	m_date.GetTime ( whatIfTime );
	m_time.GetTime ( whatIfTime );
     //	li->alarmEnable = m_enable.GetCheck ();

     l.showWhatIf = 1;

	if ( enabled == GDT_VALID && enablet == GDT_VALID )
	{
/*		li->alarmEnable = 1;
		li->alarmHour = time.GetHour();
          if ( li->alarmHour >= 12 )
               li->alarmHour -= 12;

		li->alarmMinute = time.GetMinute();

          if ( m_ampm.GetCurSel())
               li->alarmHour += 12;
*/

	}
//	else
  //		li->alarmEnable = 0;
/*
	char buf[255];
	GetDlgItemText ( IDC_EDIT1, buf, 255 );
	li->alarmMessage = buf;

     li->alarmRunApp = appToRun;
     li->alarmRunEnable = m_runApp.GetCheck ();
  */
     


	CDialog::OnOK();
}
