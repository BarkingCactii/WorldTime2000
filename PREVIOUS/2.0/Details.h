#if !defined(AFX_DETAILS_H__9D2B89E0_E9BE_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_DETAILS_H__9D2B89E0_E9BE_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Details.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDetails dialog

class CDetails : public CDialog
{
// Construction
public:
	CDetails(CWnd* pParent = NULL);   // standard constructor

	int selection;
	void SetSelection ( int sel ) { selection = sel; }
// Dialog Data
	//{{AFX_DATA(CDetails)
	enum { IDD = IDD_DETAILS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDetails)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDetails)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETAILS_H__9D2B89E0_E9BE_11D2_B3FD_0080C8C277AA__INCLUDED_)
