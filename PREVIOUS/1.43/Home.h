#if !defined(AFX_HOME_H__48875361_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_HOME_H__48875361_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Home.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CHome dialog

class CHome : public CDialog
{
        // Construction
public:
        CHome(CWnd* pParent = NULL);   // standard constructor

        // Dialog Data
        //{{AFX_DATA(CHome)
	enum { IDD = IDD_HOME };
	CEdit	m_name;
	//}}AFX_DATA


        // Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CHome)
protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

        // Implementation
protected:

        // Generated message map functions
        //{{AFX_MSG(CHome)
        afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
        virtual BOOL OnInitDialog();
        virtual void OnOK();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.





#endif // !defined(AFX_HOME_H__48875361_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_)
