// Home.cpp : implementation file
//

#include "stdafx.h"
#include  <strstrea.h>
#include "WorldTime2000.h"
#include "Home.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "str.h"
#include "bstream.h"

Locations locations;

//#define NumLocations ( sizeof ( locations ) / sizeof ( LocationItem ))


/////////////////////////////////////////////////////////////////////////////
// CHome dialog


CHome::CHome(CWnd* pParent /*=NULL*/)
: CDialog(CHome::IDD, pParent)
{
     //{{AFX_DATA_INIT(CHome)
     // NOTE: the ClassWizard will add member initialization here
     //}}AFX_DATA_INIT
     
}


void CHome::DoDataExchange(CDataExchange* pDX)
{
     CDialog::DoDataExchange(pDX);
     //{{AFX_DATA_MAP(CHome)
     DDX_Control(pDX, IDC_HOME_LIST, m_list);
     //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHome, CDialog)
//{{AFX_MSG_MAP(CHome)
ON_WM_CREATE()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHome message handlers

int CHome::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
     if (CDialog::OnCreate(lpCreateStruct) == -1)
          return -1;
     
     // TODO: Add your specialized creation code here
     return 0;
}

BOOL CHome::OnInitDialog() 
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
     
     m_list.SetCurSel ( locations.currentLocation );
     
     return TRUE;  // return TRUE unless you set the focus to a control
     // EXCEPTION: OCX Property Pages should return FALSE
}

void CHome::OnOK() 
{
     // TODO: Add extra validation here
     locations.currentLocation = m_list.GetCurSel ();
     
 	 locations.ResetOffset ();

     CDialog::OnOK();
}
