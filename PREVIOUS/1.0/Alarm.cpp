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


static LocationItem * li;

/////////////////////////////////////////////////////////////////////////////
// CAlarm dialog


CAlarm::CAlarm(CWnd* pParent /*=NULL*/)
	: CDialog(CAlarm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAlarm)
	m_hour = 0;
	m_minute = 0;
	//}}AFX_DATA_INIT
}


void CAlarm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAlarm)
	DDX_Control(pDX, IDC_ENABLE, m_enable);
	DDX_Text(pDX, IDC_HOUR, m_hour);
	DDV_MinMaxUInt(pDX, m_hour, 0, 23);
	DDX_Text(pDX, IDC_MINUTE, m_minute);
	DDV_MinMaxUInt(pDX, m_minute, 0, 59);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAlarm, CDialog)
	//{{AFX_MSG_MAP(CAlarm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlarm message handlers

void CAlarm::OnOK() 
{
	// TODO: Add extra validation here
     UpdateData();

	li->alarmEnable = m_enable.GetCheck ();
	li->alarmHour = m_hour;
	li->alarmMinute = m_minute;

	CDialog::OnOK();
}

BOOL CAlarm::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if ( view->selected )
	    li = l.GetLocation ( l.OffsetDisplay ( view->selected - 1 ));
	else
		li = l.GetHome ();

	SetDlgItemText ( IDC_LOCATION, li->name );

    m_enable.SetCheck ( li->alarmEnable );
	m_hour = li->alarmHour;
	m_minute = li->alarmMinute;

	UpdateData( FALSE );
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
