// Preferences.cpp : implementation file
//

#include "stdafx.h"
#include "WorldTime2000.h"
#include "Preferences.h"
#include "home.h"
#include "location.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//int _24hour = 0;
//Preferences p;

bifstream & operator >> ( bifstream & fin,  Preferences & data )
{
	fin >> data._24hour >> data.drawSphere;
	return fin;
}

bofstream & operator << ( bofstream & fout, Preferences & data )
{
	fout << data._24hour << data.drawSphere;
	return fout;
}


/////////////////////////////////////////////////////////////////////////////
// CPreferences dialog


CPreferences::CPreferences(CWnd* pParent /*=NULL*/)
	: CDialog(CPreferences::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreferences)
	//}}AFX_DATA_INIT
}


void CPreferences::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreferences)
	DDX_Control(pDX, IDC_CHECK2, m_drawSphere);
	DDX_Control(pDX, IDC_CHECK1, m_24hour);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreferences, CDialog)
	//{{AFX_MSG_MAP(CPreferences)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreferences message handlers

void CPreferences::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	l.p._24hour = m_24hour.GetCheck ();
	l.p.drawSphere = m_drawSphere.GetCheck ();
	
	CDialog::OnOK();
}

BOOL CPreferences::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_24hour.SetCheck ( l.p._24hour );
	m_drawSphere.SetCheck ( l.p.drawSphere );
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int CPreferences::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
