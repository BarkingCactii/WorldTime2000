#if !defined(AFX_SKINDIALOG_H__BD7A2E80_B6C1_4D6A_A752_8A3F266C80DF__INCLUDED_)
#define AFX_SKINDIALOG_H__BD7A2E80_B6C1_4D6A_A752_8A3F266C80DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSkinDialog dialog

class CSkinDialog : public CDialog
{
// Construction
public:
	CSkinDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSkinDialog)
	enum { IDD = IDD_SKINDIALOG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSkinDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINDIALOG_H__BD7A2E80_B6C1_4D6A_A752_8A3F266C80DF__INCLUDED_)
