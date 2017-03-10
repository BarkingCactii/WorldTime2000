// Home.cpp : implementation file
//

#include "stdafx.h"
//#include  <strstrea.h>
#include "WorldTime2000.h"
#include "Home.h"
#include "location.h"
//#include "display.h"
#include "regdata.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//#include "str.h"
//#include "bstream.h"

//Locations locations;

//#define NumLocations ( sizeof ( locations ) / sizeof ( LocationItem ))


/////////////////////////////////////////////////////////////////////////////
// CHome dialog


CHome::CHome(CWnd* pParent /*=NULL*/)
: CDialog(CHome::IDD, pParent)
{
     //{{AFX_DATA_INIT(CHome)
        //}}AFX_DATA_INIT

}


void CHome::DoDataExchange(CDataExchange* pDX)
{
     CDialog::DoDataExchange(pDX);
     //{{AFX_DATA_MAP(CHome)
        DDX_Control(pDX, IDC_EDIT1, m_name);
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
         m_name.SetWindowText ( r.GetKey("Home").str.c_str() );

     theApp.m_pSkin->ApplySkin((long)m_hWnd); // Apply contained skin to the main frame and its child windows

     return TRUE;  // return TRUE unless you set the focus to a control
     // EXCEPTION: OCX Property Pages should return FALSE
}

void CHome::OnOK() 
{
     // TODO: Add extra validation here
//     locations.currentLocation = m_list.GetCurSel ();

// 	 locations.ResetOffset ();
        UpdateData();
     char buf[200];

     m_name.GetWindowText ( buf, 200 );
     r.GetKey("Home").str = buf;

     CDialog::OnOK();
}
