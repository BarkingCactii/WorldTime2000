// WorldTime2000.h : main header file for the WORLDTIME2000 application
//

#if !defined(AFX_WORLDTIME2000_H__9F184077_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_WORLDTIME2000_H__9F184077_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_

#include "bitmap.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
        #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWorldTime2000App:
// See WorldTime2000.cpp for the implementation of this class
//

// active skin 
#include "SkinDialog.h"

class CWorldTime2000App : public CWinApp
{
private:
public:
    CSkinDialog m_dlgSkin; // A helper SkinDialog
    CComQIPtr<ISkin> m_pSkin; // A reference to the ActiveSkin's Skin component, that is contained in SkinDialog


//class CWorldTime2000App : public CWinApp
//{
//public:
        CWorldTime2000App();
        ~CWorldTime2000App();
//		void RecordRegistration ( void );
//		int CheckRegistration ( void );

        HICON dstOnIcon[4];
		HICON timeOfDay[14];
        HICON dstOffIcon;
        HICON homeIcon;
        HICON alarmIcon;
        HICON whatIfIcon;
//        HICON worldIcon[24];
        CMaskedBitmap worldBitmap[12];
        CBitmap backgroundBitmap;

// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CWorldTime2000App)
	public:
        virtual BOOL InitInstance();
    virtual BOOL OnIdle(LONG lCount);
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
        //{{AFX_MSG(CWorldTime2000App)
        afx_msg void OnAppAbout();
                // NOTE - the ClassWizard will add and remove member functions here.
                //    DO NOT EDIT what you see in these blocks of generated code !
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};


extern CWorldTime2000App theApp;

extern int GetLocationTag ( CListCtrl & m_list, int&, int& );
extern int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort );
extern int sortIdx;
extern int sortBy[3];
extern int InitLocationControl ( CListCtrl & m_list );
extern clock_t startProcess;


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORLDTIME2000_H__9F184077_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_)
