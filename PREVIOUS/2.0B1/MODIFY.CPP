// Modify.cpp : implementation file
//

#include "stdafx.h"
#include <math.h>
#include "WorldTime2000.h"
#include "WorldTime2000view.h"
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

static float offset = 0.0f;
static const float MaxOffset = 24.0f;
//static int selected = 0;

void CModify::SetSelected ( int tag, int raw )
{
        view->selected = tag;
         selectedbyTag = tag;
        selectedbyRow = raw;
}

CModify::CModify(CWnd* pParent /*=NULL*/)
: CDialog(CModify::IDD, pParent)
{
     //{{AFX_DATA_INIT(CModify)
     m_name = _T("");
     m_hours = _T("");
	m_country = _T("");
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
	DDX_Text(pDX, IDC_EDIT2, m_country);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModify, CDialog)
//{{AFX_MSG_MAP(CModify)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, OnCustomdrawSlider1)
        ON_LBN_SELCHANGE(IDC_MODIFY_LIST, OnSelchangeModifyList)
        ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_MODIFY_LIST, OnItemchangedModifyList)
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
                 sout << mins << "] " << l.CityList ( i ) << ends;

}

BOOL CModify::OnInitDialog() 
{
     CDialog::OnInitDialog();
     UpdateData();

     // initialize slider control
     m_offset.SetRangeMin ( 0 );
     m_offset.SetRangeMax (( int ) MaxOffset * 2 );

     for ( int i = 0; i < MaxOffset * 2; i+=2 )
          m_offset.SetTic ( i );


     selectedbyTag = InitLocationControl ( m_list );



               LocationItem *li = l.GetLocationbyTag ( selectedbyTag ); //l.Tag ( selectedbyRow ));

               if ( li )
               {
                   offset = li->offset; //l.GMTOffset ( i );
                   m_offset.SetPos (( int )(( offset * 2 ) + MaxOffset ));

                   m_startDay.SetCurSel ( li->dsStartDay );
                   m_startFirstLast.SetCurSel ( li->dsStartWeek );
                   m_startMonth.SetCurSel ( li->dsStartMonth );

                   m_endDay.SetCurSel ( li->dsEndDay );
                   m_endFirstLast.SetCurSel ( li->dsEndWeek );
                   m_endMonth.SetCurSel ( li->dsEndMonth );

                   m_enable.SetCheck ( li->dsEnable );
               }
               else
                   MessageBox ( "The location you were last working on cannot be found", "Location not found", MB_ICONEXCLAMATION );


     return FALSE;

//     ListView_SetItemState( m_list, 1, LVIS_SELECTED & 0xffff, LVIS_SELECTED );		
//    int i, 		
//    UINT state, 		
//    UINT mask		
//);		

//    m_list.SetCurSel ( view->selected );

//          m_offset.SetPos (( int )(( offset * 2 ) + MaxOffset ));

         m_startDay.SetCurSel ( 0 );
         m_startFirstLast.SetCurSel ( 0 );
         m_startMonth.SetCurSel ( 0 );

         m_endDay.SetCurSel ( 1 );
         m_endFirstLast.SetCurSel ( 0 );
         m_endMonth.SetCurSel ( 5 );

         m_enable.SetCheck ( 1 );



    return FALSE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE




          /*
     CDialog::OnInitDialog();


     // TODO: Modify extra initialization here
    for ( int i = 0; i < l.Size(); i++ )
    {
         strstream sout;

                 BuildLine ( sout, i );

         m_list.AddString ( sout.str());
    }

//    m_list.SetCurSel ( l.OffsetDisplay ( view->selected - 1 ));
    m_list.SetCurSel ( view->selected );



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
*/
}

void CModify::OnOK() 
{
     // TODO: Modify extra validation here
//     int tag, raw;
     LocationItem *aItem = 0;
     if ( GetLocationTag ( m_list, selectedbyTag, selectedbyRow ))
//     if ( GetLocationTag ( m_list, tag, raw ))
     {
          aItem = l.GetLocationbyTag ( selectedbyTag );
     }

//     view->selected = m_list.GetCurSel ();

//     UpdateData();

     offset = m_offset.GetPos () - MaxOffset;

//     LocationItem * aItem = l.GetLocation ( view->selected ); // new LocationItem;
//         if ( !aItem )
//         {
//         MessageBox ( "Operation Failed: Try again", NULL, MB_ICONEXCLAMATION );
//                 return;
//         }
     aItem->city = ( char * ) m_name.GetBuffer ( 50 );
     aItem->country = ( char * ) m_country.GetBuffer ( 50 );
     aItem->offset = offset / 2.0f;

         aItem->dsEnable = m_enable.GetCheck ();

         aItem->dsStartDay = m_startDay.GetCurSel ();
         aItem->dsStartMonth = m_startMonth.GetCurSel ();
         aItem->dsStartWeek = m_startFirstLast.GetCurSel ();

         aItem->dsEndDay = m_endDay.GetCurSel ();
         aItem->dsEndMonth = m_endMonth.GetCurSel ();
         aItem->dsEndWeek = m_endFirstLast.GetCurSel ();


/*
    m_list.DeleteString ( view->selected );

    strstream sout;

        BuildLine ( sout, view->selected );

     m_list.InsertString ( view->selected, sout.str() );

        m_list.SetCurSel ( view->selected );
*/
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
//     view->selected = m_list.GetCurSel ();
     int tag, raw;
     LocationItem *aItem = 0;
     if ( GetLocationTag ( m_list, tag, raw ))
          aItem = l.GetLocationbyTag ( tag );

//     LocationItem *aItem = l.GetLocationbyTag ( GetLocationTag ( m_list ));
//     LocationItem * aItem = l.GetLocation ( view->selected );
         if ( aItem )
         {
             SetDlgItemText ( IDC_EDIT1, aItem->city );
             SetDlgItemText ( IDC_EDIT2, aItem->country );
//		m_name = aItem->name;
            offset =  aItem->offset * 2.0f;
                m_offset.SetPos (( int ) ( offset + MaxOffset ));
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


BOOL CModify::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
      NMHDR* phdr = (NMHDR*)lParam;

      switch(phdr->code)
      {
           case HDN_ITEMCLICK:
          {
               NMHEADER * header = ( NMHEADER * ) lParam;

               if ( header->iItem >= 0 && header->iItem <= 2 )
               {
                    sortIdx = header->iItem;
                    sortBy[header->iItem] *= -1;
                    m_list.SortItems( CompareFunc, header->iItem );
               }

               break;

          }
     }


        return CDialog::OnNotify(wParam, lParam, pResult);
}


void CModify::OnItemchangedModifyList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
     OnSelchangeModifyList() ;
}

void CModify::OnCancel() 
{
	// TODO: Add extra cleanup here
//     int tag, raw;
//     LocationItem *aItem = 0;
     GetLocationTag ( m_list, selectedbyTag, selectedbyRow );
//          aItem = l.GetLocationbyTag ( tag );

//     selected = raw;
	
	CDialog::OnCancel();
}
