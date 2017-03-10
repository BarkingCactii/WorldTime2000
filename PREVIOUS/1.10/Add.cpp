// Add.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "Add.h"
//#include "home.h"
#include "location.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CAdd dialog

static float offset = 0.0;
static const float MaxOffset = 24.0f;

CAdd::CAdd(CWnd* pParent /*=NULL*/)
: CDialog(CAdd::IDD, pParent)
{
     //{{AFX_DATA_INIT(CAdd)
     m_name = _T("");
     m_hours = _T("");
     //}}AFX_DATA_INIT
}


void CAdd::DoDataExchange(CDataExchange* pDX)
{
     CDialog::DoDataExchange(pDX);
     //{{AFX_DATA_MAP(CAdd)
	DDX_Control(pDX, IDC_CHECK1, m_enable);
	DDX_Control(pDX, IDC_ADD_END_MONTH, m_endMonth);
	DDX_Control(pDX, IDC_ADD_END_FIRSTLAST, m_endFirstLast);
	DDX_Control(pDX, IDC_ADD_END_DAY, m_endDay);
	DDX_Control(pDX, IDC_ADD_START_MONTH, m_startMonth);
	DDX_Control(pDX, IDC_ADD_START_FIRSTLAST, m_startFirstLast);
	DDX_Control(pDX, IDC_ADD_START_DAY, m_startDay);
     DDX_Control(pDX, IDC_SLIDER1, m_offset);
     DDX_Text(pDX, IDC_EDIT1, m_name);
     DDX_Text(pDX, IDC_ADD_HOURS, m_hours);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdd, CDialog)
//{{AFX_MSG_MAP(CAdd)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, OnCustomdrawSlider1)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdd message handlers

BOOL CAdd::OnInitDialog() 
{
     CDialog::OnInitDialog();
     

     // TODO: Add extra initialization here
     CEdit * ec = ( CEdit * ) GetDlgItem ( IDC_EDIT1 );
     if ( ec )
          ec->SetFocus();

     m_offset.SetRangeMin ( 0 );
     m_offset.SetRangeMax (( int ) MaxOffset * 2 );
     
     for ( int i = 0; i < MaxOffset * 2; i+=2 )
          m_offset.SetTic ( i );
     
     m_offset.SetPos (( int )(( offset * 2 ) + MaxOffset ));

	 m_startDay.SetCurSel ( 0 );
	 m_startFirstLast.SetCurSel ( 0 );
	 m_startMonth.SetCurSel ( 0 );

	 m_endDay.SetCurSel ( 1 );
	 m_endFirstLast.SetCurSel ( 0 );
	 m_endMonth.SetCurSel ( 5 );

	 m_enable.SetCheck ( 1 );

     return FALSE;  // return TRUE unless you set the focus to a control
     // EXCEPTION: OCX Property Pages should return FALSE
}

void CAdd::OnOK() 
{
     // TODO: Add extra validation here
     
     UpdateData();
     
     offset = m_offset.GetPos () - MaxOffset;
     
     LocationItem * aItem = new LocationItem;
     aItem->name = ( char * ) m_name.GetBuffer ( 50 );
     aItem->offset = offset / 2.0f;

	 aItem->dsEnable = m_enable.GetCheck ();

	 aItem->dsStartDay = m_startDay.GetCurSel ();
	 aItem->dsStartMonth = m_startMonth.GetCurSel ();
	 aItem->dsStartWeek = m_startFirstLast.GetCurSel ();

	 aItem->dsEndDay = m_endDay.GetCurSel ();
	 aItem->dsEndMonth = m_endMonth.GetCurSel ();
	 aItem->dsEndWeek = m_endFirstLast.GetCurSel ();


     l.Add ( aItem );
     
     
     CDialog::OnOK();
}

void CAdd::OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
     // TODO: Add your control notification handler code here
     
     static int lastHour = -1;
     static int lastMin = -1;
     
     int hour = ( m_offset.GetPos() - ( int ) MaxOffset ) / 2;
	 int min = abs ((( m_offset.GetPos() - ( int ) MaxOffset ) % 2 ) * 30 );
     if ( hour == lastHour && min == lastMin )
          return;
     
     strstream sout;
     
     sout << hour << " hrs " << min << " mins" << ends;
     CString tmpS = sout.str();
     SetDlgItemText ( IDC_ADD_HOURS, tmpS );
     
     *pResult = 0;
}

void CAdd::OnCheck1() 
{
	// TODO: Add your control notification handler code here
    if ( m_enable.GetCheck ())
        {
                         GetDlgItem ( IDC_ADD_START_FIRSTLAST )->ShowWindow ( SW_SHOW );
                         GetDlgItem ( IDC_ADD_START_DAY )->ShowWindow ( SW_SHOW );
                         GetDlgItem ( IDC_ADD_START_MONTH )->ShowWindow ( SW_SHOW );
                         GetDlgItem ( IDC_ADD_END_FIRSTLAST )->ShowWindow ( SW_SHOW );
                         GetDlgItem ( IDC_ADD_END_DAY )->ShowWindow ( SW_SHOW );
                         GetDlgItem ( IDC_ADD_END_MONTH )->ShowWindow ( SW_SHOW );
        }
        else
        {
                         GetDlgItem ( IDC_ADD_START_FIRSTLAST )->ShowWindow ( SW_HIDE );
                         GetDlgItem ( IDC_ADD_START_DAY )->ShowWindow ( SW_HIDE );
                         GetDlgItem ( IDC_ADD_START_MONTH )->ShowWindow ( SW_HIDE );
                         GetDlgItem ( IDC_ADD_END_FIRSTLAST )->ShowWindow ( SW_HIDE );
                         GetDlgItem ( IDC_ADD_END_DAY )->ShowWindow ( SW_HIDE );
                         GetDlgItem ( IDC_ADD_END_MONTH )->ShowWindow ( SW_HIDE );
        }

	
}
