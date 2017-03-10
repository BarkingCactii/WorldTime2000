// About.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "About.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAbout message handlers
/////////////////////////////////////////////////////////////////////////////
// About

IMPLEMENT_DYNCREATE(About, CHtmlView)

About::About()
{
        //{{AFX_DATA_INIT(About)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT
}

About::~About()
{
}

void About::DoDataExchange(CDataExchange* pDX)
{
        CHtmlView::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(About)
                // NOTE: the ClassWizard will add DDX and DDV calls here
        //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(About, CHtmlView)
        //{{AFX_MSG_MAP(About)
                // NOTE - the ClassWizard will add and remove mapping macros here.
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// About diagnostics

#ifdef _DEBUG
void About::AssertValid() const
{
        CHtmlView::AssertValid();
}

void About::Dump(CDumpContext& dc) const
{
        CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// About message handlers

void About::OnInitialUpdate() 
{
        //TODO: This code navigates to a popular spot on the web.
        //Change the code to go where you'd like.
        CHtmlView::OnInitialUpdate();
// 	Navigate2(_T("http://www.microsoft.com/visualc/"),NULL,NULL);
        LoadFromResource(IDR_ABOUT);

}

