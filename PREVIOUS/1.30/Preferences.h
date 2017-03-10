#if !defined(AFX_PREFERENCES_H__510D2F00_E2A7_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_PREFERENCES_H__510D2F00_E2A7_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Preferences.h : header file
//

#include "bstream.h"

class CCustomStatic : public CButton
{
public:
// Operations
//    void AddColorItem(COLORREF color);

// Implementation
    virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMIS);
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);
//    virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCIS);
};


//extern int _24hour;

class Preferences
{
	friend bifstream & operator >> ( bifstream & fin,  Preferences & data );
	friend bofstream & operator << ( bofstream & fout, Preferences & data );
public:
	short _24hour;
	short drawSphere;
     short movingSphere; // version 1.30
     short frames;       // version 1.30

	String wallpaperName;
	short showWallpaper;

	Preferences ( void )
	{
		_24hour = 0;
		drawSphere = 1;
		wallpaperName = "worldtime2000.bmp";
		showWallpaper = 1;
          movingSphere = 1;
          frames = 30;
	}
};

//extern Preferences p;

/////////////////////////////////////////////////////////////////////////////
// CPreferences dialog

class CPreferences : public CDialog
{
// Construction
public:
	CPreferences(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPreferences)
	enum { IDD = IDD_Preferences };
	CButton	m_movingSphere;
	CButton	m_imageOn;
	CButton	m_homecolor;
	CButton	m_drawSphere;
	CButton	m_24hour;
	UINT	m_frames;
	//}}AFX_DATA
	COLORREF m_home;
	COLORREF m_location;
	COLORREF m_selected;
	COLORREF m_background;

	CBrush m_bkBrush;
//	CCustomStatic m_home;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreferences)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreferences)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnHomeColor();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLocationColor();
	afx_msg void OnSelectedColor();
	afx_msg void OnBackgroundColor();
	afx_msg void OnBackgroundTexture();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern COLORREF homeColor;
extern COLORREF locationColor;
extern COLORREF selectedColor;
extern COLORREF backgroundColor;
extern COLORREF moveColor;
extern HANDLE wallpaper;
//extern String fontName;
//extern short  fontSize;



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREFERENCES_H__510D2F00_E2A7_11D2_B3FD_0080C8C277AA__INCLUDED_)
