// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__9F184079_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_STDAFX_H__9F184079_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT





typedef unsigned long ulong;

#include "atlbase.h"

#include <iostream>
#include <fstream>
#include <strstream>
//#include <strstrea.h>


#include "list.h"
#include <string>
using namespace std;

//#define DEBUGLINE

#include "location.h"
#include "member.h"
//#include "list.h"
//#include <string>
//using namespace std;
//#include <iostream>
//#include <fstream>

extern void DEBUGLINE ( char * file, int line ); 

extern int selectedbyTag;   // list control globals
extern int selectedbyRow;
extern string selectedbyString;


#import "actskn43.ocx" no_implementation raw_interfaces_only raw_native_types
using namespace ACTIVESKINLib;

//#include "atlbase.h"

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#endif // !defined(AFX_STDAFX_H__9F184079_DED6_11D2_B3FD_0080C8C277AA__INCLUDED_)
