#if !defined(AFX_ALARM_H__7D4A5565_F509_11D2_B3FE_0080C8C277AA__INCLUDED_)
#define AFX_ALARM_H__7D4A5565_F509_11D2_B3FE_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Alarm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAlarm dialog

class CAlarm : public CDialog
{
// Construction
public:
	CAlarm(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAlarm)
	enum { IDD = IDD_ALARM };
	CButton	m_runApp;
	CComboBox	m_ampm;
	CDateTimeCtrl	m_enable;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlarm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAlarm)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALARM_H__7D4A5565_F509_11D2_B3FE_0080C8C277AA__INCLUDED_)
