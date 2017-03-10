// Features.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "Features.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFeatures dialog


CFeatures::CFeatures(CWnd* pParent /*=NULL*/)
	: CDialog(CFeatures::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFeatures)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFeatures::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFeatures)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFeatures, CDialog)
	//{{AFX_MSG_MAP(CFeatures)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFeatures message handlers
