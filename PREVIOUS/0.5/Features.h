#if !defined(AFX_FEATURES_H__2FFFB342_DFBF_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_FEATURES_H__2FFFB342_DFBF_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Features.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFeatures dialog

class CFeatures : public CDialog
{
// Construction
public:
	CFeatures(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFeatures)
	enum { IDD = IDD_FEATURES };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFeatures)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFeatures)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FEATURES_H__2FFFB342_DFBF_11D2_B3FD_0080C8C277AA__INCLUDED_)
