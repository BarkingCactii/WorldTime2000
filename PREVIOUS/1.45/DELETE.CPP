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
        DDX_Control(pDX, IDC_ADD_DISPLAY_LIST, m_list);
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

//    m_list.SetCurSel ( l.OffsetDisplay ( view->selected - 1 ));
    m_list.SetCurSel ( selected );

        return TRUE;  // return TRUE unless you set the focus to a control
                      // EXCEPTION: OCX Property Pages should return FALSE
}

void CDelete::OnOK() 
{
        // TODO: Add extra validation here
        selected = m_list.GetCurSel ();
        l.DeleteList ( selected );

		if ( MessageBox ( "Delete location ?", "Confirm Delete", MB_YESNO | MB_ICONQUESTION ) == IDNO )
			return;


        CDialog::OnOK();
}

void CDelete::OnDetails() 
{
        // TODO: Add your control notification handler code here
//        CDetails dlg;

//        dlg.SetSelection ( m_list.GetCurSel ());


//        dlg.DoModal ();
	CModify dlg;
	
	dlg.SetSelected ( m_list.GetCurSel());
	dlg.DoModal();

}
