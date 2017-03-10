// Order.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "Order.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COrder dialog



/////////////////////////////////////////////////////////////////////////////
// COrder message handlers
/////////////////////////////////////////////////////////////////////////////
// Order

IMPLEMENT_DYNCREATE(Order, CHtmlView)

Order::Order()
{
        //{{AFX_DATA_INIT(Order)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT
}

Order::~Order()
{
}

void Order::DoDataExchange(CDataExchange* pDX)
{
        CHtmlView::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(Order)
                // NOTE: the ClassWizard will add DDX and DDV calls here
        //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Order, CHtmlView)
        //{{AFX_MSG_MAP(Order)
                // NOTE - the ClassWizard will add and remove mapping macros here.
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Order diagnostics

#ifdef _DEBUG
void Order::AssertValid() const
{
        CHtmlView::AssertValid();
}

void Order::Dump(CDumpContext& dc) const
{
        CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Order message handlers

void Order::OnInitialUpdate() 
{
        //TODO: This code navigates to a popular spot on the web.
        //Change the code to go where you'd like.
        CHtmlView::OnInitialUpdate();
// 	Navigate2(_T("http://www.microsoft.com/visualc/"),NULL,NULL);
        LoadFromResource(IDR_ORDER);

}


