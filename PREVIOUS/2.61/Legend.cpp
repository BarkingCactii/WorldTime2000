// Legend.cpp : implementation file
//

#include "stdafx.h"
#include "worldtime2000.h"
#include "Legend.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLegend dialog


CLegend::CLegend(CWnd* pParent /*=NULL*/)
	: CDialog(CLegend::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLegend)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLegend::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLegend)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLegend, CDialog)
	//{{AFX_MSG_MAP(CLegend)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLegend message handlers
