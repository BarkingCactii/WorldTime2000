// TimeSync.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "time.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CTimeSync message handlers
/////////////////////////////////////////////////////////////////////////////
// TimeSync

IMPLEMENT_DYNCREATE(TimeSync, CHtmlView)

TimeSync::TimeSync()
{
        DEBUGLINE ( __FILE__, __LINE__ );
        //{{AFX_DATA_INIT(TimeSync)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT
}

TimeSync::~TimeSync()
{
        DEBUGLINE ( __FILE__, __LINE__ );
}

void TimeSync::DoDataExchange(CDataExchange* pDX)
{
        CHtmlView::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(TimeSync)
                // NOTE: the ClassWizard will add DDX and DDV calls here
        //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TimeSync, CHtmlView)
        //{{AFX_MSG_MAP(TimeSync)
                // NOTE - the ClassWizard will add and remove mapping macros here.
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TimeSync diagnostics

#ifdef _DEBUG
void TimeSync::AssertValid() const
{
        CHtmlView::AssertValid();
}

void TimeSync::Dump(CDumpContext& dc) const
{
        CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// TimeSync message handlers

void TimeSync::OnInitialUpdate() 
{
        //TODO: This code navigates to a popular spot on the web.
        //Change the code to go where you'd like.
        CHtmlView::OnInitialUpdate();
 	Navigate2(_T("http://www.bldrdoc.gov/timefreq/service/acts.htm"),NULL,NULL);
//        LoadFromResource(IDR_TimeSync);

}

