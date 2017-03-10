#if !defined(AFX_ADD_H__48875362_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_ADD_H__48875362_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Add.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdd dialog

class CAdd : public CDialog
{
// Construction
public:
	CAdd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdd)
	enum { IDD = IDD_ADD_LOCATION };
	CButton	m_enable;
	CComboBox	m_endMonth;
	CComboBox	m_endFirstLast;
	CComboBox	m_endDay;
	CComboBox	m_startMonth;
	CComboBox	m_startFirstLast;
	CComboBox	m_startDay;
	CSliderCtrl	m_offset;
	CString	m_name;
	CString	m_hours;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdd)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADD_H__48875362_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_)
