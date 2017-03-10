// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__9F18407B_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_MAINFRM_H__9F18407B_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WorldTime2000View.h"

class CMainFrame : public CFrameWnd
{

public:
        CMainFrame();
protected: 
        DECLARE_DYNAMIC(CMainFrame)

// Attributes
public:

// Operations
public:
		void Register ( void ) { OnRegister(); }
        CWorldTime2000View * View ( void ) { return &m_wndView; }

// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CMainFrame)
        public:
        virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
        virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
        virtual BOOL DestroyWindow();
        //}}AFX_VIRTUAL

// Implementation
public:
        virtual ~CMainFrame();
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
        CStatusBar  m_wndStatusBar;
        CToolBar    m_wndToolBar;
        CReBar      m_wndReBar;
        CBitmap		m_bit[8];
//	CDialogBar      m_wndDlgBar;
        CWorldTime2000View    m_wndView;

// Generated message map functions
protected:
        //{{AFX_MSG(CMainFrame)
        afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
        afx_msg void OnSetFocus(CWnd *pOldWnd);
        afx_msg void OnFileHome();
        afx_msg void OnFileAdd();
        afx_msg void OnHelpFuture();
        afx_msg void OnFileAddtodisplay();
        afx_msg void OnFilePreferences();
        afx_msg void OnSize(UINT nType, int cx, int cy);
        afx_msg void OnMove(int x, int y);
        afx_msg void OnAppAbout();
        afx_msg void OnFileDelete();
        afx_msg void OnFileModify();
        afx_msg void OnFileAlarm();
        afx_msg void OnContextDelete();
        afx_msg void OnContextModify();
        afx_msg void OnContextMove();
        afx_msg void OnHelpContents();
        afx_msg void OnDestroy();
        afx_msg void OnViewStatusBar();
        afx_msg void OnViewToolbar();
	afx_msg void OnFileAlarmreset();
	afx_msg void OnRegister();
	afx_msg void OnFileFont();
	afx_msg void OnOrder();
	//}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

extern CMainFrame * mainFrame;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__9F18407B_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_)
