// Delete.cpp : implementation file
//

#include "stdafx.h"
#include <math.h>
#include "WorldTime2000.h"
#include "WorldTime2000view.h"
#include "Delete.h"
#include "location.h"
#include "modify.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDelete dialog

static int selected = 0;
//static int sortIdx = 0;
//static int sortBy[3] = { 1, 1, 1 };

/*
static int sortIdx = 0;
static int sortBy[3] = { 1, 1, 1 };


int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort )
{
     LPLVITEM l1, l2;

     LocationItem *i1 = l.GetLocationbyTag ( lParam1 );
//     LocationItem *i1 = l.GetLocation ( lParam1 );
     if ( i1 == 0 )
          return 0;
     LocationItem *i2 = l.GetLocationbyTag ( lParam2 );
//     LocationItem *i2 = l.GetLocation ( lParam2 );
     if ( i2 == 0 )
          return 0;

     if ( lParamSort == 0 )
     {
          if ( sortBy[lParamSort] == 1 )
               return stricmp ( i1->city, i2->city );
          else
               return stricmp ( i2->city, i1->city );
     }

     if ( lParamSort == 1 )
     {
          if ( sortBy[lParamSort] == 1 )
               return stricmp ( i1->country, i2->country );
          else
               return stricmp ( i2->country, i1->country );
     }

     if ( lParamSort == 2 )
     {
          if ( sortBy[lParamSort] == 1 )
               return ( int ) ( i2->offset - i1->offset );
          else
               return ( int ) ( i1->offset - i2->offset );
     }

     return 0;
}

  */
CDelete::CDelete(CWnd* pParent /*=NULL*/)
        : CDialog(CDelete::IDD, pParent)
{
        //{{AFX_DATA_INIT(CDelete)
	//}}AFX_DATA_INIT
}


void CDelete::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CDelete)
	DDX_Control(pDX, IDC_DELETE, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDelete, CDialog)
        //{{AFX_MSG_MAP(CDelete)
        ON_BN_CLICKED(ID_DETAILS, OnDetails)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDelete message handlers

BOOL CDelete::OnInitDialog()
{
     CDialog::OnInitDialog();
     UpdateData();

     InitLocationControl ( m_list );
/*
     CRect rect;

     m_list.SetBkColor ( 0x00000000 );
     m_list.SetTextBkColor ( 0x00000000 );
     m_list.SetTextColor ( 0x0000ffff );
	m_list.GetWindowRect(&rect);
	m_list.InsertColumn(0, "Location", LVCFMT_LEFT, rect.Width() / 2 - 35, 0);
	m_list.InsertColumn(1, "Country", LVCFMT_LEFT, rect.Width() / 2 - 35, 1);
	m_list.InsertColumn(2, "GMT", LVCFMT_LEFT, 50, 2);

    for ( int i = 0; i < l.Size(); i++ )
    {
         strstream sout;

         float offset = l.GMTOffset ( i );
         float mins = offset - ( float )floor ( offset );
         if ( mins )
              mins = 30.0f;

         if ( offset >= 0 )
              sout << "+";
         else
              sout << "-";

         offset = ( float ) fabs ( floor ( offset ));

//         sout.width ( 2 );
//         sout.fill ( '0' );
         sout << offset << " hrs" << ends; // << ":";
//         sout.width ( 2 );
//                 sout << mins << "] " << l.CountryList ( i ) << ends;


          LVITEM lvitem;
		lvitem.mask = LVIF_TEXT | LVIF_PARAM; // | (iSubItem == 0? LVIF_IMAGE : 0);
		lvitem.iItem = i; //(iSubItem == 0)? iItem : iActualItem;
		lvitem.iSubItem = 0;
		lvitem.pszText = l.CityList ( i );
          lvitem.lParam = l.Tag ( i );

          m_list.InsertItem ( &lvitem );

		lvitem.mask = LVIF_TEXT; // | (iSubItem == 0? LVIF_IMAGE : 0);
		lvitem.iItem = i; //(iSubItem == 0)? iItem : iActualItem;
		lvitem.iSubItem = 1;
		lvitem.pszText = l.CountryList ( i );
          lvitem.lParam = l.Tag ( i );
          m_list.SetItem ( &lvitem );

		lvitem.mask = LVIF_TEXT; // | (iSubItem == 0? LVIF_IMAGE : 0);
		lvitem.iItem = i; //(iSubItem == 0)? iItem : iActualItem;
		lvitem.iSubItem = 2;
		lvitem.pszText = sout.str();
          lvitem.lParam = l.Tag ( i );
          m_list.SetItem ( &lvitem );

    }

    m_list.SortItems( CompareFunc, sortIdx );
  */
     theApp.m_pSkin->ApplySkin((long)m_hWnd); // Apply contained skin to the main frame and its child windows

    return FALSE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE


              /*

        CDialog::OnInitDialog();

        // TODO: Add extra initialization here
    for ( int i = 0; i < l.Size(); i++ )
    {
         strstream sout;

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
         m_list.AddString ( sout.str());
    }

//    m_list.SetCurSel ( l.OffsetDisplay ( view->selected - 1 ));
    m_list.SetCurSel ( selected );

        return TRUE;  // return TRUE unless you set the focus to a control
                      // EXCEPTION: OCX Property Pages should return FALSE
*/
}

void CDelete::OnOK() 
{
        // TODO: Add extra validation here
//        selected = m_list.GetCurSel ();
//        l.DeleteList ( selected );

          if ( MessageBox ( "Delete location ?", "Confirm Delete", MB_YESNO | MB_ICONQUESTION ) == IDNO )
               return;

          if ( GetLocationTag ( m_list, selectedbyTag, selectedbyRow ))
             l.DeleteList ( selectedbyTag );

//        int tag, raw;
//        if ( GetLocationTag ( m_list, tag, raw ))
//             l.DeleteList ( tag );

        CDialog::OnOK();
}

void CDelete::OnDetails() 
{
        // TODO: Add your control notification handler code here
//        CDetails dlg;

//        dlg.SetSelection ( m_list.GetCurSel ());


//        dlg.DoModal ();

//     LocationItem *li = l.GetLocation ( GetLocationTag ( m_list ));
     int tag, row;
     LocationItem *li = 0;
     if ( GetLocationTag ( m_list, tag, row ))
          li = l.GetLocationbyTag ( tag );

     if ( !li )
          return;

	CModify dlg;
	
	dlg.SetSelected ( li->tag, row ); //m_list.GetCurSel());
	dlg.DoModal();
}


BOOL CDelete::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
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

