// Help.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "Help.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelp dialog



/////////////////////////////////////////////////////////////////////////////
// CHelp message handlers
/////////////////////////////////////////////////////////////////////////////
// Help

IMPLEMENT_DYNCREATE(Help, CHtmlView)

Help::Help()
{
        //{{AFX_DATA_INIT(Help)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT
}

Help::~Help()
{
}

void Help::DoDataExchange(CDataExchange* pDX)
{
        CHtmlView::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(Help)
                // NOTE: the ClassWizard will add DDX and DDV calls here
        //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Help, CHtmlView)
        //{{AFX_MSG_MAP(Help)
                // NOTE - the ClassWizard will add and remove mapping macros here.
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Help diagnostics

#ifdef _DEBUG
void Help::AssertValid() const
{
        CHtmlView::AssertValid();
}

void Help::Dump(CDumpContext& dc) const
{
        CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Help message handlers

void Help::OnInitialUpdate() 
{
        //TODO: This code navigates to a popular spot on the web.
        //Change the code to go where you'd like.
        CHtmlView::OnInitialUpdate();
// 	Navigate2(_T("http://www.microsoft.com/visualc/"),NULL,NULL);
        LoadFromResource(IDR_HELP);

}


