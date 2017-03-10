// Modify.cpp : implementation file
//

#include "stdafx.h"
#include <math.h>
#include "WorldTime2000.h"
#include "Modify.h"
//#include "home.h"
#include "location.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CModify dialog

static float offset = 0.0;
static const float MaxOffset = 24.0f;
static int selected = 0;

void CModify::SetSelected ( int idx )
{
	selected = idx;
}

CModify::CModify(CWnd* pParent /*=NULL*/)
: CDialog(CModify::IDD, pParent)
{
     //{{AFX_DATA_INIT(CModify)
     m_name = _T("");
     m_hours = _T("");
     //}}AFX_DATA_INIT
}


void CModify::DoDataExchange(CDataExchange* pDX)
{
     CDialog::DoDataExchange(pDX);
     //{{AFX_DATA_MAP(CModify)
        DDX_Control(pDX, IDC_MODIFY_LIST, m_list);
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


BEGIN_MESSAGE_MAP(CModify, CDialog)
//{{AFX_MSG_MAP(CModify)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, OnCustomdrawSlider1)
        ON_LBN_SELCHANGE(IDC_MODIFY_LIST, OnSelchangeModifyList)
        ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModify message handlers


void CModify::BuildLine ( strstream & sout, int i )
{
         float offset = l.GMTOffset ( i );
                 float mins = offset - ( float )floor ( offset );
                 if ( mins )
                         mins = 30.0f;

         sout << "[GMT ";
         if ( offset >= 0 )
              sout << "+";
         else
              sout << "-";

         offset = ( float ) fabs ( floor ( offset ));

         sout.width ( 2 );
         sout.fill ( '0' );
         sout << offset << ":";
         sout.width ( 2 );
                 sout << mins << "] " << l.NameList ( i ) << ends;

}
BOOL CModify::OnInitDialog() 
{
     CDialog::OnInitDialog();


     // TODO: Modify extra initialization here
    for ( int i = 0; i < l.Size(); i++ )
    {
         strstream sout;

                 BuildLine ( sout, i );

         m_list.AddString ( sout.str());
    }

    m_list.SetCurSel ( selected );



     CEdit * ec = ( CEdit * ) GetDlgItem ( IDC_EDIT1 );
     if ( ec )
          ec->SetFocus();

     m_offset.SetRangeMin ( 0 );
     m_offset.SetRangeMax (( int ) MaxOffset * 2 );

     for ( i = 0; i < MaxOffset * 2; i+=2 )
          m_offset.SetTic ( i );

     m_offset.SetPos (( int )(( offset * 2 ) + MaxOffset ));

         m_startDay.SetCurSel ( 0 );
         m_startFirstLast.SetCurSel ( 0 );
         m_startMonth.SetCurSel ( 0 );

         m_endDay.SetCurSel ( 1 );
         m_endFirstLast.SetCurSel ( 0 );
         m_endMonth.SetCurSel ( 5 );

         m_enable.SetCheck ( 1 );

        OnSelchangeModifyList();

     return FALSE;  // return TRUE unless you set the focus to a control
     // EXCEPTION: OCX Property Pages should return FALSE
}

void CModify::OnOK() 
{
     // TODO: Modify extra validation here

     selected = m_list.GetCurSel ();

     UpdateData();

     offset = m_offset.GetPos () - MaxOffset;

     LocationItem * aItem = l.GetLocation ( selected ); // new LocationItem;
	 if ( !aItem )
	 {
         MessageBox ( "Operation Failed: Try again", NULL, MB_ICONEXCLAMATION );
		 return;
	 }
     aItem->name = ( char * ) m_name.GetBuffer ( 50 );
     aItem->offset = offset / 2.0f;

         aItem->dsEnable = m_enable.GetCheck ();

         aItem->dsStartDay = m_startDay.GetCurSel ();
         aItem->dsStartMonth = m_startMonth.GetCurSel ();
         aItem->dsStartWeek = m_startFirstLast.GetCurSel ();

         aItem->dsEndDay = m_endDay.GetCurSel ();
         aItem->dsEndMonth = m_endMonth.GetCurSel ();
         aItem->dsEndWeek = m_endFirstLast.GetCurSel ();


//     l.Modify ( aItem );


    m_list.DeleteString ( selected );

    strstream sout;

        BuildLine ( sout, selected );

     m_list.InsertString ( selected, sout.str() );
//         m_list.AddString ( sout.str());

///     CDialog::OnOK();
}

void CModify::OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
     // TODO: Modify your control notification handler code here

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

void CModify::OnSelchangeModifyList() 
{
        // TODO: Add your control notification handler code here
     selected = m_list.GetCurSel ();
     LocationItem * aItem = l.GetLocation ( selected );
         if ( aItem )
         {
             SetDlgItemText ( IDC_EDIT1, aItem->name );
//		m_name = aItem->name;
            offset =  aItem->offset * 2.0;
                m_offset.SetPos ( offset + MaxOffset );
//     offset = m_offset.GetPos () - MaxOffset;

        m_enable.SetCheck ( aItem->dsEnable );

         m_startDay.SetCurSel (aItem->dsStartDay );
         m_startMonth.SetCurSel ( aItem->dsStartMonth );
         m_startFirstLast.SetCurSel ( aItem->dsStartWeek );

         m_endDay.SetCurSel ( aItem->dsEndDay );
         m_endMonth.SetCurSel ( aItem->dsEndMonth );
         m_endFirstLast.SetCurSel ( aItem->dsEndWeek );

                 if ( !aItem->dsEnable )
                 {
                         GetDlgItem ( IDC_ADD_START_FIRSTLAST )->ShowWindow ( SW_HIDE );
                         GetDlgItem ( IDC_ADD_START_DAY )->ShowWindow ( SW_HIDE );
                         GetDlgItem ( IDC_ADD_START_MONTH )->ShowWindow ( SW_HIDE );
                         GetDlgItem ( IDC_ADD_END_FIRSTLAST )->ShowWindow ( SW_HIDE );
                         GetDlgItem ( IDC_ADD_END_DAY )->ShowWindow ( SW_HIDE );
                         GetDlgItem ( IDC_ADD_END_MONTH )->ShowWindow ( SW_HIDE );
                 }
                 else
                 {
                         GetDlgItem ( IDC_ADD_START_FIRSTLAST )->ShowWindow ( SW_SHOW );
                         GetDlgItem ( IDC_ADD_START_DAY )->ShowWindow ( SW_SHOW );
                         GetDlgItem ( IDC_ADD_START_MONTH )->ShowWindow ( SW_SHOW );
                         GetDlgItem ( IDC_ADD_END_FIRSTLAST )->ShowWindow ( SW_SHOW );
                         GetDlgItem ( IDC_ADD_END_DAY )->ShowWindow ( SW_SHOW );
                         GetDlgItem ( IDC_ADD_END_MONTH )->ShowWindow ( SW_SHOW );
                 }
         }

        UpdateData();	
}

void CModify::OnCheck1() 
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
