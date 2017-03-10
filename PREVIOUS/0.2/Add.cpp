// Add.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "Add.h"
#include "home.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdd dialog

static int offset = 0;
static const int MaxOffset = 12;

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
     DDX_Control(pDX, IDC_SLIDER1, m_offset);
     DDX_Text(pDX, IDC_EDIT1, m_name);
     DDX_Text(pDX, IDC_ADD_HOURS, m_hours);
     //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdd, CDialog)
//{{AFX_MSG_MAP(CAdd)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, OnCustomdrawSlider1)
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
     m_offset.SetRangeMax ( MaxOffset * 2 );
     
     for ( int i = 0; i < MaxOffset * 2; i+=2 )
          m_offset.SetTic ( i );
     
     m_offset.SetPos ( offset + MaxOffset );
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
     aItem->offset = offset;
     locations.Add ( aItem );
     
     
     CDialog::OnOK();
}

void CAdd::OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
     // TODO: Add your control notification handler code here
     
     static int lastHour = -1;
     
     int hour = m_offset.GetPos() - MaxOffset;
     if ( hour == lastHour )
          return;
     
     strstream sout;
     
     sout << hour << " hours" << ends;
     CString tmpS = sout.str();
     SetDlgItemText ( IDC_ADD_HOURS, tmpS );
     
     *pResult = 0;
}
