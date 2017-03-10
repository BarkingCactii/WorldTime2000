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

/////////////////////////////////////////////////////////////////////////////
// CAddDisplay message handlers

BOOL CAddDisplay::OnInitDialog()
{
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
                 sout << mins << "] " << l.NameList ( i ) << ends;
         m_list.AddString ( sout.str());
    }

    m_list.SetCurSel ( selected );
//    m_list.SetCurSel ( locations.selected );

        return TRUE;  // return TRUE unless you set the focus to a control
                      // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddDisplay::OnOK() 
{
        // TODO: Add extra validation here
        selected = m_list.GetCurSel ();
        l.AddDisplay ( selected );


        CDialog::OnOK();
}

#include "modify.h"

void CAddDisplay::OnDetails() 
{
        // TODO: Add your control notification handler code here
	CModify dlg;
	
	dlg.SetSelected ( m_list.GetCurSel());
	dlg.DoModal();
//    ::PostMessage ( view->m_hWnd, WM_PAINT, 0, 0 );


//        CDetails dlg;

//        dlg.SetSelection ( m_list.GetCurSel ());


//        dlg.DoModal ();
}
