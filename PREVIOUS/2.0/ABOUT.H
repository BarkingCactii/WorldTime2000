#if !defined(AFX_About_H__2FFFB342_DFBF_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_About_H__2FFFB342_DFBF_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// About.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// About html view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include <afxhtml.h>

class About : public CHtmlView
{
protected:
        About();           // protected constructor used by dynamic creation
        DECLARE_DYNCREATE(About)

// html Data
public:
        //{{AFX_DATA(About)
                // NOTE: the ClassWizard will add data members here
        //}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(About)
        public:
        virtual void OnInitialUpdate();
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
        virtual ~About();
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif

        // Generated message map functions
        //{{AFX_MSG(About)
                // NOTE - the ClassWizard will add and remove member functions here.
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_About_H__2FFFB342_DFBF_11D2_B3FD_0080C8C277AA__INCLUDED_)
