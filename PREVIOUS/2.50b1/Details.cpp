// Details.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "Details.h"
#include "location.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDetails dialog


CDetails::CDetails(CWnd* pParent /*=NULL*/)
	: CDialog(CDetails::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDetails)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDetails::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDetails)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDetails, CDialog)
	//{{AFX_MSG_MAP(CDetails)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()




/////////////////////////////////////////////////////////////////////////////
// CDetails message handlers

BOOL CDetails::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

    LocationItem * li = l.GetLocation ( selection );

    CString tmpS = li->name;
    SetDlgItemText ( IDC_DETAILS1, tmpS );
	

//	sout.seekp ( 0 );
//	sout.seekg ( 0 );
//	sout.clear();
	{
	    strstream sout;
		sout << "Hours from GMT is " << li->offset << " hours" << ends;
	    tmpS = sout.str();
		SetDlgItemText ( IDC_DETAILS2, tmpS );
	}

//	sout.seekp ( 0 );
	if ( ! li->dsEnable )
	{
		strstream sout;

		sout << "No Daylight Savings for this location" << ends;
		tmpS = sout.str();
	    SetDlgItemText ( IDC_DETAILS3, tmpS );

		tmpS = "";
	    SetDlgItemText ( IDC_DETAILS4, tmpS );
	    SetDlgItemText ( IDC_DETAILS5, tmpS );

		return TRUE;
	}

	{
		strstream sout;

		sout << "This location uses Daylight Savings" << ends;
		tmpS = sout.str();
	    SetDlgItemText ( IDC_DETAILS3, tmpS );

	}
	{
		strstream sout;

		sout << "Daylight Savings start " << weekList[li->dsStartWeek].name << " " << dayList[li->dsStartDay].name << " of " << monthList[li->dsStartMonth].name<< ends;
		tmpS = sout.str();
	    SetDlgItemText ( IDC_DETAILS4, tmpS );


	}

	{
		strstream sout;

		sout << "Daylight Savings end " << weekList[li->dsEndWeek].name << " " << dayList[li->dsEndDay].name << " of " << monthList[li->dsEndMonth].name << ends;
		tmpS = sout.str();
	    SetDlgItemText ( IDC_DETAILS5, tmpS );


	}

//	sout << "Hours from GMT is " << li->offset << ends;
//    tmpS = sout.str();
//    SetDlgItemText ( IDC_DETAILS2, tmpS );


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
