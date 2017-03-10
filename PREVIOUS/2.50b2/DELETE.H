#if !defined(AFX_Delete_H__80F0CA00_E082_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_Delete_H__80F0CA00_E082_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Delete.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDelete dialog

class CDelete : public CDialog
{
// Construction
public:
        CDelete(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
        //{{AFX_DATA(CDelete)
	enum { IDD = IDD_DELETE };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CDelete)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
        //}}AFX_VIRTUAL

// Implementation
protected:

        // Generated message map functions
        //{{AFX_MSG(CDelete)
        virtual BOOL OnInitDialog();
        virtual void OnOK();
        afx_msg void OnDetails();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Delete_H__80F0CA00_E082_11D2_B3FD_0080C8C277AA__INCLUDED_)
