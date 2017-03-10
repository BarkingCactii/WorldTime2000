#if !defined(AFX_PREFERENCES_H__510D2F00_E2A7_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_PREFERENCES_H__510D2F00_E2A7_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Preferences.h : header file
//

//extern int _24hour;

/////////////////////////////////////////////////////////////////////////////
// CPreferences dialog

class CPreferences : public CDialog
{
// Construction
public:
	CPreferences(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPreferences)
	enum { IDD = IDD_Preferences };
	CButton	m_24hour;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreferences)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreferences)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREFERENCES_H__510D2F00_E2A7_11D2_B3FD_0080C8C277AA__INCLUDED_)
