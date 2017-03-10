// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "trxtd200.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CTrialLicense properties

/////////////////////////////////////////////////////////////////////////////
// CTrialLicense operations

void CTrialLicense::SetCustom3(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialLicense::GetCustom3()
{
	CString result;
	InvokeHelper(0x6803000b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialLicense::SetCustom2(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialLicense::GetCustom2()
{
	CString result;
	InvokeHelper(0x6803000a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialLicense::SetCustom1(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030009, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialLicense::GetCustom1()
{
	CString result;
	InvokeHelper(0x68030009, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialLicense::SetSerial(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030008, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialLicense::GetSerial()
{
	CString result;
	InvokeHelper(0x68030008, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialLicense::SetAddr2(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030007, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialLicense::GetAddr2()
{
	CString result;
	InvokeHelper(0x68030007, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialLicense::SetAddr1(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialLicense::GetAddr1()
{
	CString result;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialLicense::SetCompany(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialLicense::GetCompany()
{
	CString result;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialLicense::SetName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialLicense::GetName()
{
	CString result;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialLicense::SetFilename(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialLicense::GetFilename()
{
	CString result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialLicense::Fetch()
{
	InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialLicense::Store()
{
	InvokeHelper(0x6003000e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL CTrialLicense::Check()
{
	BOOL result;
	InvokeHelper(0x60030010, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CTrialLicense::Remove()
{
	InvokeHelper(0x60030012, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTrial properties

/////////////////////////////////////////////////////////////////////////////
// CTrial operations

LPDISPATCH CTrial::GetLicense()
{
	LPDISPATCH result;
	InvokeHelper(0x40030001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void CTrial::SetRefLicense(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x40030001, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH CTrial::GetBuy()
{
	LPDISPATCH result;
	InvokeHelper(0x40030079, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void CTrial::SetRefBuy(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x40030079, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms,
		 newValue);
}

void CTrial::SetAllowPurchase(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x68030043, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CTrial::GetAllowPurchase()
{
	BOOL result;
	InvokeHelper(0x68030043, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CTrial::SetLabelHelp(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803002b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetLabelHelp()
{
	CString result;
	InvokeHelper(0x6803002b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetLabelUnlock(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803002a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetLabelUnlock()
{
	CString result;
	InvokeHelper(0x6803002a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetLabelReg(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030029, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetLabelReg()
{
	CString result;
	InvokeHelper(0x68030029, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetLabelBack(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030028, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetLabelBack()
{
	CString result;
	InvokeHelper(0x68030028, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetLabelNext(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030027, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetLabelNext()
{
	CString result;
	InvokeHelper(0x68030027, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetLabelCancel(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030026, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetLabelCancel()
{
	CString result;
	InvokeHelper(0x68030026, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetLabelOK(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030025, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetLabelOK()
{
	CString result;
	InvokeHelper(0x68030025, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CTrial::GetMsgStart()
{
	CString result;
	InvokeHelper(0x68030024, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetMsgStart(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030024, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetCaption()
{
	CString result;
	InvokeHelper(0x68030023, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetMsgExtend(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030022, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetMsgExtend()
{
	CString result;
	InvokeHelper(0x68030022, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetCaption(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030023, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CTrial::Check2()
{
	long result;
	InvokeHelper(0x6003002c, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CTrial::Check()
{
	BOOL result;
	InvokeHelper(0x6003002d, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CTrial::Remove()
{
	InvokeHelper(0x6003002e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrial::Add()
{
	InvokeHelper(0x6003002f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long CTrial::TimeLeft()
{
	long result;
	InvokeHelper(0x60030030, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long CTrial::GetDuration()
{
	long result;
	InvokeHelper(0x68030021, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CTrial::SetDuration(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030021, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CTrial::GetStyle()
{
	long result;
	InvokeHelper(0x68030020, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CTrial::SetStyle(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030020, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void CTrial::About()
{
	InvokeHelper(0x60030031, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrial::Reset()
{
	InvokeHelper(0x60030032, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString CTrial::GetHelpFile()
{
	CString result;
	InvokeHelper(0x6803001f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetHelpFile(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803001f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetMsgAllow()
{
	CString result;
	InvokeHelper(0x6803001e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetMsgAllow(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803001e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetMsgBadUnlock()
{
	CString result;
	InvokeHelper(0x6803001d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetMsgBadUnlock(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803001d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetMsgDeny()
{
	CString result;
	InvokeHelper(0x6803001c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetMsgDeny(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803001c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CTrial::GetAllowExtend()
{
	BOOL result;
	InvokeHelper(0x6803001b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CTrial::SetAllowExtend(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x6803001b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CTrial::GetSignature()
{
	CString result;
	InvokeHelper(0x6803001a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetSignature(BSTR* newValue)
{
	static BYTE parms[] =
		VTS_PBSTR;
	InvokeHelper(0x6803001a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long CTrial::GetPopup()
{
	long result;
	InvokeHelper(0x68030019, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CTrial::SetPopup(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030019, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString CTrial::GetMsgEnd()
{
	CString result;
	InvokeHelper(0x68030018, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetMsgEnd(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030018, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

DATE CTrial::GetStopDate()
{
	DATE result;
	InvokeHelper(0x68030017, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

void CTrial::SetStopDate(DATE newValue)
{
	static BYTE parms[] =
		VTS_DATE;
	InvokeHelper(0x68030017, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString CTrial::GetCopyright()
{
	CString result;
	InvokeHelper(0x68030016, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetCopyright(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030016, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetVersion()
{
	CString result;
	InvokeHelper(0x68030015, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetVersion(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030015, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void CTrial::Stamp()
{
	InvokeHelper(0x60030034, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL CTrial::GetShowWelcome()
{
	BOOL result;
	InvokeHelper(0x68030014, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CTrial::SetShowWelcome(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x68030014, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH CTrial::GetPicture()
{
	LPDISPATCH result;
	InvokeHelper(0x68030013, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void CTrial::SetPicture(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x68030013, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString CTrial::GetTitle()
{
	CString result;
	InvokeHelper(0x68030012, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetTitle(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030012, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CTrial::ShowRegister()
{
	long result;
	InvokeHelper(0x60030036, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long CTrial::ShowRegisterEx()
{
	long result;
	InvokeHelper(0x60030037, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

void CTrial::Register()
{
	InvokeHelper(0x60030038, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL CTrial::Registered()
{
	BOOL result;
	InvokeHelper(0x60030039, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

unsigned long CTrial::GetRegForeColor()
{
	unsigned long result;
	InvokeHelper(0x68030011, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CTrial::SetRegForeColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030011, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CTrial::GetExtForeColor()
{
	unsigned long result;
	InvokeHelper(0x68030010, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CTrial::SetExtForeColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030010, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CTrial::GetRegBackColor()
{
	unsigned long result;
	InvokeHelper(0x6803000f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CTrial::SetRegBackColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6803000f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CTrial::GetExtBackColor()
{
	unsigned long result;
	InvokeHelper(0x6803000e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CTrial::SetExtBackColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6803000e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL CTrial::GetUseMessages()
{
	BOOL result;
	InvokeHelper(0x6803000d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CTrial::SetUseMessages(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x6803000d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CTrial::GetMsgFirst()
{
	CString result;
	InvokeHelper(0x6803000c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetMsgFirst(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetMsgWelcome()
{
	CString result;
	InvokeHelper(0x6803000b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetMsgWelcome(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetMsgTimeLeft()
{
	CString result;
	InvokeHelper(0x6803000a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetMsgTimeLeft(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CTrial::GetShowWizardImage()
{
	BOOL result;
	InvokeHelper(0x68030009, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CTrial::SetShowWizardImage(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x68030009, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CTrial::GetKey()
{
	CString result;
	InvokeHelper(0x68030008, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetKey(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030008, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CTrial::Status()
{
	long result;
	InvokeHelper(0x6003003d, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

CString CTrial::GetProgramID()
{
	CString result;
	InvokeHelper(0x68030007, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetProgramID(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030007, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetProgramCode()
{
	CString result;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetProgramCode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrial::GetRemoteProgramID()
{
	CString result;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CTrial::GetRemoteProgramCode()
{
	CString result;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CTrial::GetTrialTag()
{
	CString result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetTrialTag(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CTrial::GetRunning()
{
	BOOL result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CTrial::SetRunning(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CTrial::GetInstanceTag()
{
	CString result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrial::SetInstanceTag(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CTrial::GetInstances()
{
	long result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CTrial::SetInstances(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void CTrial::Quit()
{
	InvokeHelper(0x60030042, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTrialBuy properties

/////////////////////////////////////////////////////////////////////////////
// CTrialBuy operations

CString CTrialBuy::GetAuthCode()
{
	CString result;
	InvokeHelper(0x40030004, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetAuthCode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030004, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetAction()
{
	CString result;
	InvokeHelper(0x40030005, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetAction(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetResult()
{
	CString result;
	InvokeHelper(0x40030006, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetResult(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030006, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetReason()
{
	CString result;
	InvokeHelper(0x40030007, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetReason(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030007, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetOrderID()
{
	CString result;
	InvokeHelper(0x40030008, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetOrderID(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030008, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void CTrialBuy::SetMsgTitle(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030026, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetMsgTitle()
{
	CString result;
	InvokeHelper(0x68030026, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetMsgStart(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030025, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetMsgStart()
{
	CString result;
	InvokeHelper(0x68030025, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerFax(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030024, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerFax()
{
	CString result;
	InvokeHelper(0x68030024, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerMI(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030023, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerMI()
{
	CString result;
	InvokeHelper(0x68030023, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerLastname(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030022, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerLastname()
{
	CString result;
	InvokeHelper(0x68030022, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerFirstName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030021, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerFirstName()
{
	CString result;
	InvokeHelper(0x68030021, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetLive(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x68030020, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CTrialBuy::GetLive()
{
	BOOL result;
	InvokeHelper(0x68030020, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL CTrialBuy::OrderSubmit()
{
	BOOL result;
	InvokeHelper(0x60030027, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL CTrialBuy::OrderPrint(LPCTSTR Filename)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030029, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Filename);
	return result;
}

CString CTrialBuy::OrderSaveToFile(LPCTSTR Filename)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6003002a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		Filename);
	return result;
}

CString CTrialBuy::GetCreditCardNumber()
{
	CString result;
	InvokeHelper(0x6803001f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCreditCardNumber(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803001f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCreditCardType()
{
	CString result;
	InvokeHelper(0x6803001e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCreditCardType(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803001e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCreditCardExpMonth()
{
	CString result;
	InvokeHelper(0x6803001d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCreditCardExpMonth(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803001d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCreditCardExpYear()
{
	CString result;
	InvokeHelper(0x6803001c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCreditCardExpYear(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803001c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCreditCardHolderName()
{
	CString result;
	InvokeHelper(0x6803001b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCreditCardHolderName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803001b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerAddress()
{
	CString result;
	InvokeHelper(0x6803001a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerAddress(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803001a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerCity()
{
	CString result;
	InvokeHelper(0x68030019, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerCity(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030019, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerState()
{
	CString result;
	InvokeHelper(0x68030018, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerState(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030018, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerPostCode()
{
	CString result;
	InvokeHelper(0x68030017, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerPostCode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030017, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerCountry()
{
	CString result;
	InvokeHelper(0x68030016, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerCountry(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030016, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetProductName()
{
	CString result;
	InvokeHelper(0x68030015, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetProductName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030015, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetProductVersion()
{
	CString result;
	InvokeHelper(0x68030014, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetProductVersion(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030014, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetProductPrice()
{
	CString result;
	InvokeHelper(0x68030013, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetProductPrice(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030013, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetProductQty()
{
	CString result;
	InvokeHelper(0x68030012, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetProductQty(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030012, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetInqiuryCode()
{
	CString result;
	InvokeHelper(0x68030011, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetInqiuryCode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030011, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetProductID()
{
	CString result;
	InvokeHelper(0x68030010, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetProductID(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030010, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetUnlockCode()
{
	CString result;
	InvokeHelper(0x6803000f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetUnlockCode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CTrialBuy::CollectCustomerInfo(LPCTSTR Filename)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6003002d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Filename);
	return result;
}

BOOL CTrialBuy::CollectCardInfo()
{
	BOOL result;
	InvokeHelper(0x6003002e, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString CTrialBuy::GetVendorID()
{
	CString result;
	InvokeHelper(0x6803000e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetVendorID(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetVendorSupportMail()
{
	CString result;
	InvokeHelper(0x6803000d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetVendorSupportMail(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetVendorReceiptMail()
{
	CString result;
	InvokeHelper(0x6803000c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetVendorReceiptMail(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetVendorAddress()
{
	CString result;
	InvokeHelper(0x6803000b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetVendorAddress(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetVendorCity()
{
	CString result;
	InvokeHelper(0x6803000a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetVendorCity(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6803000a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetVendorState()
{
	CString result;
	InvokeHelper(0x68030009, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetVendorState(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030009, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetVendorMsg()
{
	CString result;
	InvokeHelper(0x68030008, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetVendorMsg(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030008, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetVendorPostcode()
{
	CString result;
	InvokeHelper(0x68030007, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetVendorPostcode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030007, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetVendorName()
{
	CString result;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetVendorName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetVendorCountry()
{
	CString result;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetVendorCountry(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerEmail()
{
	CString result;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerEmail(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CTrialBuy::GetCustomerTelephone()
{
	CString result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerTelephone(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void CTrialBuy::SaveCustomerInfo(LPCTSTR Filename)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030030, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Filename);
}

void CTrialBuy::LoadCustomerInfo(LPCTSTR Filename)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60030031, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Filename);
}

BOOL CTrialBuy::ValidateCustomerInfo()
{
	BOOL result;
	InvokeHelper(0x60030032, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL CTrialBuy::ValidateCardInfo()
{
	BOOL result;
	InvokeHelper(0x60030039, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString CTrialBuy::GetCustomerCompany()
{
	CString result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CTrialBuy::SetCustomerCompany(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CTrialBuy::Purchase(BSTR* Filename)
{
	BOOL result;
	static BYTE parms[] =
		VTS_PBSTR;
	InvokeHelper(0x6003003a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Filename);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _cLastError properties

/////////////////////////////////////////////////////////////////////////////
// _cLastError operations

void _cLastError::SetNumber(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _cLastError::GetNumber()
{
	long result;
	InvokeHelper(0x68030006, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _cLastError::SetErl(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _cLastError::GetErl()
{
	long result;
	InvokeHelper(0x68030005, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _cLastError::SetSource(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _cLastError::GetSource()
{
	CString result;
	InvokeHelper(0x68030004, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _cLastError::SetLastDLLError(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _cLastError::GetLastDLLError()
{
	long result;
	InvokeHelper(0x68030003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _cLastError::SetHelpFile(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _cLastError::GetHelpFile()
{
	CString result;
	InvokeHelper(0x68030002, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _cLastError::SetHelpContext(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _cLastError::GetHelpContext()
{
	long result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _cLastError::SetDescription(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _cLastError::GetDescription()
{
	CString result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _cLastError::PushError()
{
	InvokeHelper(0x60030007, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _cLastError::Raise()
{
	InvokeHelper(0x60030008, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _cLastError::Clear()
{
	InvokeHelper(0x60030009, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTrialEvents properties

/////////////////////////////////////////////////////////////////////////////
// CTrialEvents operations

void CTrialEvents::BeforeShow(LPDISPATCH* myWizard)
{
	static BYTE parms[] =
		VTS_PDISPATCH;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 myWizard);
}

void CTrialEvents::ActionCode(long* Action, BSTR* ProgID, BSTR* ProgCode, long* Code, long* YourResponse)
{
	static BYTE parms[] =
		VTS_PI4 VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PI4;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Action, ProgID, ProgCode, Code, YourResponse);
}

void CTrialEvents::Initialize()
{
	InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialEvents::Created()
{
	InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialEvents::Expired()
{
	InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialEvents::Invalid(long* ReasonCode, BSTR* MsgText)
{
	static BYTE parms[] =
		VTS_PI4 VTS_PBSTR;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ReasonCode, MsgText);
}

void CTrialEvents::Begin()
{
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialEvents::DateSetBack()
{
	InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialEvents::UserDecline()
{
	InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialEvents::Retail()
{
	InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialEvents::BadUnlock(BOOL* Cancel)
{
	static BYTE parms[] =
		VTS_PBOOL;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Cancel);
}

void CTrialEvents::Converted()
{
	InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialEvents::Removed()
{
	InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialEvents::Extended(long* ExtendAmount)
{
	static BYTE parms[] =
		VTS_PI4;
	InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ExtendAmount);
}

void CTrialEvents::Reset()
{
	InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CTrialEvents::CreateLicense(BSTR* Path)
{
	static BYTE parms[] =
		VTS_PBSTR;
	InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Path);
}


/////////////////////////////////////////////////////////////////////////////
// CBuyEvents properties

/////////////////////////////////////////////////////////////////////////////
// CBuyEvents operations

void CBuyEvents::Status(BSTR* Msg)
{
	static BYTE parms[] =
		VTS_PBSTR;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Msg);
}
