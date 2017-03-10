#if !defined(AFX_Modify_H__48875362_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_Modify_H__48875362_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Modify.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CModify dialog

class CModify : public CDialog
{
// Construction
public:
                void SetSelected ( int tag, int raw );
        CModify(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
        //{{AFX_DATA(CModify)
	enum { IDD = IDD_MODIFY };
        CListCtrl       m_list;
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
	CString	m_country;
	UINT	m_countryCode;
	UINT	m_areaCode;
	//}}AFX_DATA


// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CModify)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
        //}}AFX_VIRTUAL

// Implementation
protected:
        void BuildLine ( strstream & sout, int i );

        // Generated message map functions
        //{{AFX_MSG(CModify)
        virtual BOOL OnInitDialog();
        virtual void OnOK();
        afx_msg void OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
        afx_msg void OnSelchangeModifyList();
        afx_msg void OnCheck1();
	afx_msg void OnItemchangedModifyList(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnCancel();
	//}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert Modifyitional declarations immediately before the previous line.

#endif // !defined(AFX_Modify_H__48875362_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_)
