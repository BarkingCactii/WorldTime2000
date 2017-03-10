#if !defined(AFX_DLGUPDATER_H__17FA13CD_DD4C_45E8_B88F_0BF6DC86A11F__INCLUDED_)
#define AFX_DLGUPDATER_H__17FA13CD_DD4C_45E8_B88F_0BF6DC86A11F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgUpdater.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgUpdater dialog

class CDlgUpdater : public CDialog
{
// Construction
public:
	CDlgUpdater(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgUpdater)
	enum { IDD = IDD_UPDATER };
	CListBox	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgUpdater)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgUpdater)
	afx_msg void OnUpdaterStart();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGUPDATER_H__17FA13CD_DD4C_45E8_B88F_0BF6DC86A11F__INCLUDED_)
