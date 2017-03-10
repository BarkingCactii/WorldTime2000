// Alarm.cpp : implementation file
//

#include "stdafx.h"
#include "worldtime2000.h"
#include "worldtime2000view.h"
#include "Alarm.h"
#include "location.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//long    enable = DTS_SHOWNONE;

static LocationItem * li;
String appToRun;

/////////////////////////////////////////////////////////////////////////////
// CAlarm dialog


CAlarm::CAlarm(CWnd* pParent /*=NULL*/)
	: CDialog(CAlarm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAlarm)
	//}}AFX_DATA_INIT
}


void CAlarm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAlarm)
	DDX_Control(pDX, IDC_CHECK1, m_runApp);
	DDX_Control(pDX, IDC_AMPM, m_ampm);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_enable);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAlarm, CDialog)
	//{{AFX_MSG_MAP(CAlarm)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlarm message handlers

void CAlarm::OnOK() 
{
	// TODO: Add extra validation here
     UpdateData();

	CTime time;	
	DWORD enable = m_enable.GetTime ( time );
//	li->alarmEnable = m_enable.GetCheck ();
	if ( enable == GDT_VALID )
	{
		li->alarmEnable = 1;
		li->alarmHour = time.GetHour();
          if ( li->alarmHour >= 12 )
               li->alarmHour -= 12;

		li->alarmMinute = time.GetMinute();

          if ( m_ampm.GetCurSel())
               li->alarmHour += 12;
//     else
//          m_ampm.SetCurSel ( 0 );


	}
	else
		li->alarmEnable = 0;

	char buf[255];
	GetDlgItemText ( IDC_EDIT1, buf, 255 );
	li->alarmMessage = buf;

     li->alarmRunApp = appToRun;
     li->alarmRunEnable = m_runApp.GetCheck ();

	CDialog::OnOK();
}

BOOL CAlarm::OnInitDialog() 
{
	CDialog::OnInitDialog();

	
//	CRect rect ( 0, 0, 15, 15 );
//	m_enable.Create( DTS_SHOWNONE, rect, this, 1000 ); //, 1000 );

	// TODO: Add extra initialization here
	if ( view->selected >= 0 )
	    li = l.GetLocationbyTag ( l.OffsetDisplay ( view->selected ));
	else
		li = l.GetHome ();

     appToRun = li->alarmRunApp;

	SetDlgItemText ( IDC_LOCATION, li->city );
	SetDlgItemText ( IDC_APP_NAME, appToRun );
	SetDlgItemText ( IDC_EDIT1, li->alarmMessage );
     m_runApp.SetCheck ( li->alarmRunEnable );

     if ( li->alarmHour >= 12 )
          m_ampm.SetCurSel ( 1 );
     else
          m_ampm.SetCurSel ( 0 );

	CTime time ( 1999, 1, 1, li->alarmHour, li->alarmMinute, 0 );
	m_enable.SetTime ( &time );

	SYSTEMTIME st;
	m_enable.GetTime ( &st );
	DateTime_SetSystemtime ( m_enable, GDT_NONE, &st );

	DateTime_SetSystemtime ( m_enable, li->alarmEnable ? GDT_VALID : GDT_NONE, &st );
     m_enable.SetFormat ( "'Alarm: 'h':'mm" );
//    m_enable.SetCheck ( li->alarmEnable );
//	m_hour = li->alarmHour;
//	m_minute = li->alarmMinute;

	UpdateData( FALSE );
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CAlarm::OnButton1() 
{
	// TODO: Add your control notification handler code here
      char * filterBuf= "Applications\0*.exe;*.cmo\0\0\0";
      CFileDialog openD ( TRUE );

      openD.m_ofn.lpstrFilter = filterBuf;
      openD.m_ofn.lpstrInitialDir = ".\\";
      openD.m_ofn.lpstrTitle = "Select Application to run on Alarm";

     if ( openD.DoModal () == IDOK )
     {
          appToRun = openD.m_ofn.lpstrFile;
     	SetDlgItemText ( IDC_APP_NAME, ( char *) appToRun );
          //
          // open file and read data
          //
//   		wallpaper = LoadImage( 0, openD.m_ofn.lpstrFile, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE );

//		if ( wallpaper == NULL )
//			l.p.showWallpaper = 0;

//        l.p.wallpaperName = openD.m_ofn.lpstrFile;
      }
	
}
