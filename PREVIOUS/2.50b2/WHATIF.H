#if !defined(AFX_WHATIF_H__33CEFE02_D4C7_4CF9_9729_56D80CEA034B__INCLUDED_)
#define AFX_WHATIF_H__33CEFE02_D4C7_4CF9_9729_56D80CEA034B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// whatif.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// whatif dialog

class whatif : public CDialog
{
// Construction
public:
	whatif(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(whatif)
	enum { IDD = IDD_WHATIF };
	CDateTimeCtrl	m_time;
	CDateTimeCtrl	m_date;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(whatif)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(whatif)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CTime whatIfTime;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WHATIF_H__33CEFE02_D4C7_4CF9_9729_56D80CEA034B__INCLUDED_)
