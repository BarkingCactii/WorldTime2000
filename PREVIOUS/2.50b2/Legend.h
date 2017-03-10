#if !defined(AFX_LEGEND_H__58892725_9279_4A44_9410_4EA421F228D6__INCLUDED_)
#define AFX_LEGEND_H__58892725_9279_4A44_9410_4EA421F228D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Legend.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLegend dialog

class CLegend : public CDialog
{
// Construction
public:
	CLegend(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLegend)
	enum { IDD = IDD_LEGEND };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLegend)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLegend)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEGEND_H__58892725_9279_4A44_9410_4EA421F228D6__INCLUDED_)
