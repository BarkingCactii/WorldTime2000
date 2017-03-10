// AddDisplay.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "AddDisplay.h"
#include "home.h"

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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddDisplay message handlers

BOOL CAddDisplay::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    for ( int i = 0; i < locations.Size(); i++ )
    {
         strstream sout;

         int offset = locations.OffsetList ( i );
         
         sout << "[GMT ";
         if ( offset >= 0 )
              sout << "+";
         else
              sout << "-";
         
         offset = abs ( offset );
         sout.width ( 2 );
         sout.fill ( '0' );
         sout << offset << ":00] " << locations.NameList ( i ) << ends;
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
	locations.AddDisplay ( selected );

	
	CDialog::OnOK();
}
