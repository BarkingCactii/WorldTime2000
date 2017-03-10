// Register.cpp : implementation file
//

#include "stdafx.h"
#include "worldtime2000.h"
#include "location.h"
#include "Register.h"
#include "crc32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//String registeredName = "Trial version";
//ulong registeredCRC = 0x00000000;

/////////////////////////////////////////////////////////////////////////////
// CRegister dialog


CRegister::CRegister(CWnd* pParent /*=NULL*/)
        : CDialog(CRegister::IDD, pParent)
{
        //{{AFX_DATA_INIT(CRegister)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT
}


void CRegister::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CRegister)
                // NOTE: the ClassWizard will add DDX and DDV calls here
        //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegister, CDialog)
        //{{AFX_MSG_MAP(CRegister)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegister message handlers

BOOL CRegister::OnInitDialog()
{
        CDialog::OnInitDialog();

        // TODO: Add extra initialization here

        return TRUE;  // return TRUE unless you set the focus to a control
                      // EXCEPTION: OCX Property Pages should return FALSE
}

void CRegister::OnOK()
{
        // TODO: Add extra validation here
        char name[100];
        char crc[100];

        GetDlgItemText ( IDC_REGISTER_NAME, name, 100 );
        GetDlgItemText ( IDC_REGISTER_KEY, crc, 100 );

        ulong userCRC;
        sscanf ( crc, "%ul", &userCRC );
        if ( Register ( name, crc ) == RegSuccess )
		{
                MessageBox ("Thank you for registering WorldTime2000!", "Registration Successful", MB_OK | MB_ICONEXCLAMATION );
// do this in thread
//				l.registeredName = name;
//				l.registeredCRC = userCRC;
//				l.terminatingDay = l.terminatingMonth = REGISTERED;

//				theApp.RecordRegistration ();

		}
		else
                MessageBox ("Please make sure you use the  exact same name you registered with ( including any Capital letters )", "Registration Failed", MB_OK | MB_ICONEXCLAMATION );

        CDialog::OnOK();
}
