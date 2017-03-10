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
/////////////////////////////////////////////////////////////////////////////
// Features

IMPLEMENT_DYNCREATE(Features, CHtmlView)

Features::Features()
{
	//{{AFX_DATA_INIT(Features)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

Features::~Features()
{
}

void Features::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Features)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Features, CHtmlView)
	//{{AFX_MSG_MAP(Features)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Features diagnostics

#ifdef _DEBUG
void Features::AssertValid() const
{
	CHtmlView::AssertValid();
}

void Features::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Features message handlers

void Features::OnInitialUpdate() 
{
	//TODO: This code navigates to a popular spot on the web.
	//Change the code to go where you'd like.
	CHtmlView::OnInitialUpdate();
// 	Navigate2(_T("http://www.microsoft.com/visualc/"),NULL,NULL);
 	LoadFromResource(IDR_FEATURES);

}


