// AddDisplay.cpp : implementation file
//

#include "stdafx.h"
#include <math.h>
#include "WorldTime2000.h"
#include "AddDisplay.h"
#include "location.h"
#include "details.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddDisplay dialog

static int selected = 0;
static int sortIdx = 0;
static int sortBy[3] = { 1, 1, 1 };


int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort )
{
     LPLVITEM l1, l2;

     LocationItem *i1 = l.GetLocationbyTag ( lParam1 );
     if ( i1 == 0 )
          return 0;
     LocationItem *i2 = l.GetLocationbyTag ( lParam2 );
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


CAddDisplay::CAddDisplay(CWnd* pParent /*=NULL*/)
        : CDialog(CAddDisplay::IDD, pParent)
{
        //{{AFX_DATA_INIT(CAddDisplay)
        //}}AFX_DATA_INIT
}


void CAddDisplay::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CAddDisplay)
        DDX_Control(pDX, IDC_ADD_DISPLAY_LIST, m_list);
        //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddDisplay, CDialog)
        //{{AFX_MSG_MAP(CAddDisplay)
        ON_BN_CLICKED(ID_DETAILS, OnDetails)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
//	ON_HDN_ITEMCLICK(IDC_ADD_DISPLAY_LIST, OnClickHeader)

/////////////////////////////////////////////////////////////////////////////
// CAddDisplay message handlers

BOOL CAddDisplay::OnInitDialog()
{
     CDialog::OnInitDialog();
     UpdateData();

     CRect rect;

     m_list.SetBkColor ( 0x00000000 );
     m_list.SetTextBkColor ( 0x00000000 );
     m_list.SetTextColor ( 0x0000ffff );
	m_list.GetWindowRect(&rect);
	m_list.InsertColumn(0, "Location", LVCFMT_LEFT, rect.Width() / 2 - 35, 0);
	m_list.InsertColumn(1, "Country", LVCFMT_LEFT, rect.Width() / 2 - 35, 1);
	m_list.InsertColumn(2, "GMT", LVCFMT_LEFT, 50, 2);

        // TODO: Add extra initialization here
    for ( int i = 0; i < l.Size(); i++ )
    {
         strstream sout;

         float offset = l.GMTOffset ( i );
                 float mins = offset - ( float )floor ( offset );
                 if ( mins )
                         mins = 30.0f;

//         sout << "[GMT ";
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


//          m_list.InsertItem ( 0, sout.str());
//         m_list.AddString ( sout.str());
    }

    m_list.SortItems( CompareFunc, sortIdx );

//    m_list.SetCurSel ( selected );

        return TRUE;  // return TRUE unless you set the focus to a control
                      // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddDisplay::OnOK() 
{
        // TODO: Add extra validation here
//        selected = m_list.GetCurSel ();
        l.AddDisplay ( selected );


        CDialog::OnOK();
}

#include "modify.h"

void CAddDisplay::OnDetails() 
{
     POSITION pos = m_list.GetFirstSelectedItemPosition();
     int nItem;
     if (pos == NULL)
          return;
//        TRACE0("No items were selected!\n");
     else
     {
//        while (pos)
//        {
           nItem = m_list.GetNextSelectedItem(pos);
//           TRACE1("Item %d was selected!\n", nItem);
           // you could do your own processing on nItem here
//        }
     }


     LocationItem *li = l.GetLocationbyTag ( nItem );
     if ( !li )
          return;

        // TODO: Add your control notification handler code here
	CModify dlg;
	
	dlg.SetSelected ( li->tag ); //m_list.GetCurSel());
	dlg.DoModal();
//    ::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );


//        CDetails dlg;

//        dlg.SetSelection ( m_list.GetCurSel ());


//        dlg.DoModal ();
}



BOOL CAddDisplay::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
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

