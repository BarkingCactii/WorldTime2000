// WorldTime2000View.h : interface of the CWorldTime2000View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORLDTIME2000VIEW_H__9F18407D_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_WORLDTIME2000VIEW_H__9F18407D_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "memdc.h"
#include "location.h"

/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000View window

class CWorldTime2000View : public CWnd
{
// Construction
public:
	CWorldTime2000View();

// Attributes
public:
	int   selected; // currently selected location
	float	  selectedAdjustment; // adjustment in hour difference in selected location	
//	short offset;
	int	  drawing;

// Operations
public:

     void DrawHome ( CMemDC &, CTime * );
     void DrawLocation ( CMemDC & memDC, CTime * );
	 void DrawTime ( CMemDC & memDC, CTime * t, int y, float offset );
	 int DaylightSavings ( LocationItem *, CTime * );

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorldTime2000View)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWorldTime2000View();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWorldTime2000View)
	afx_msg void OnPaint();
    afx_msg void OnTimer(UINT nIDEvent);
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CWorldTime2000View * view;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORLDTIME2000VIEW_H__9F18407D_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_)
