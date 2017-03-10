// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// CTrialLicense wrapper class

class CTrialLicense : public COleDispatchDriver
{
public:
	CTrialLicense() {}		// Calls COleDispatchDriver default constructor
	CTrialLicense(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTrialLicense(const CTrialLicense& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void SetCustom3(LPCTSTR lpszNewValue);
	CString GetCustom3();
	void SetCustom2(LPCTSTR lpszNewValue);
	CString GetCustom2();
	void SetCustom1(LPCTSTR lpszNewValue);
	CString GetCustom1();
	void SetSerial(LPCTSTR lpszNewValue);
	CString GetSerial();
	void SetAddr2(LPCTSTR lpszNewValue);
	CString GetAddr2();
	void SetAddr1(LPCTSTR lpszNewValue);
	CString GetAddr1();
	void SetCompany(LPCTSTR lpszNewValue);
	CString GetCompany();
	void SetName(LPCTSTR lpszNewValue);
	CString GetName();
	void SetFilename(LPCTSTR lpszNewValue);
	CString GetFilename();
	void Fetch();
	void Store();
	BOOL Check();
	void Remove();
};
/////////////////////////////////////////////////////////////////////////////
// CTrial wrapper class

class CTrial : public COleDispatchDriver
{
public:
	CTrial() {}		// Calls COleDispatchDriver default constructor
	CTrial(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTrial(const CTrial& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetLicense();
	void SetRefLicense(LPDISPATCH newValue);
	LPDISPATCH GetBuy();
	void SetRefBuy(LPDISPATCH newValue);
	void SetAllowPurchase(BOOL bNewValue);
	BOOL GetAllowPurchase();
	void SetLabelHelp(LPCTSTR lpszNewValue);
	CString GetLabelHelp();
	void SetLabelUnlock(LPCTSTR lpszNewValue);
	CString GetLabelUnlock();
	void SetLabelReg(LPCTSTR lpszNewValue);
	CString GetLabelReg();
	void SetLabelBack(LPCTSTR lpszNewValue);
	CString GetLabelBack();
	void SetLabelNext(LPCTSTR lpszNewValue);
	CString GetLabelNext();
	void SetLabelCancel(LPCTSTR lpszNewValue);
	CString GetLabelCancel();
	void SetLabelOK(LPCTSTR lpszNewValue);
	CString GetLabelOK();
	CString GetMsgStart();
	void SetMsgStart(LPCTSTR lpszNewValue);
	CString GetCaption();
	void SetMsgExtend(LPCTSTR lpszNewValue);
	CString GetMsgExtend();
	void SetCaption(LPCTSTR lpszNewValue);
	long Check2();
	BOOL Check();
	void Remove();
	void Add();
	long TimeLeft();
	long GetDuration();
	void SetDuration(long nNewValue);
	long GetStyle();
	void SetStyle(long nNewValue);
	void About();
	void Reset();
	CString GetHelpFile();
	void SetHelpFile(LPCTSTR lpszNewValue);
	CString GetMsgAllow();
	void SetMsgAllow(LPCTSTR lpszNewValue);
	CString GetMsgBadUnlock();
	void SetMsgBadUnlock(LPCTSTR lpszNewValue);
	CString GetMsgDeny();
	void SetMsgDeny(LPCTSTR lpszNewValue);
	BOOL GetAllowExtend();
	void SetAllowExtend(BOOL bNewValue);
	CString GetSignature();
	void SetSignature(BSTR* newValue);
	long GetPopup();
	void SetPopup(long nNewValue);
	CString GetMsgEnd();
	void SetMsgEnd(LPCTSTR lpszNewValue);
	DATE GetStopDate();
	void SetStopDate(DATE newValue);
	CString GetCopyright();
	void SetCopyright(LPCTSTR lpszNewValue);
	CString GetVersion();
	void SetVersion(LPCTSTR lpszNewValue);
	void Stamp();
	BOOL GetShowWelcome();
	void SetShowWelcome(BOOL bNewValue);
	LPDISPATCH GetPicture();
	void SetPicture(LPDISPATCH newValue);
	CString GetTitle();
	void SetTitle(LPCTSTR lpszNewValue);
	long ShowRegister();
	long ShowRegisterEx();
	void Register();
	BOOL Registered();
	unsigned long GetRegForeColor();
	void SetRegForeColor(unsigned long newValue);
	unsigned long GetExtForeColor();
	void SetExtForeColor(unsigned long newValue);
	unsigned long GetRegBackColor();
	void SetRegBackColor(unsigned long newValue);
	unsigned long GetExtBackColor();
	void SetExtBackColor(unsigned long newValue);
	BOOL GetUseMessages();
	void SetUseMessages(BOOL bNewValue);
	CString GetMsgFirst();
	void SetMsgFirst(LPCTSTR lpszNewValue);
	CString GetMsgWelcome();
	void SetMsgWelcome(LPCTSTR lpszNewValue);
	CString GetMsgTimeLeft();
	void SetMsgTimeLeft(LPCTSTR lpszNewValue);
	BOOL GetShowWizardImage();
	void SetShowWizardImage(BOOL bNewValue);
	CString GetKey();
	void SetKey(LPCTSTR lpszNewValue);
	long Status();
	CString GetProgramID();
	void SetProgramID(LPCTSTR lpszNewValue);
	CString GetProgramCode();
	void SetProgramCode(LPCTSTR lpszNewValue);
	CString GetRemoteProgramID();
	CString GetRemoteProgramCode();
	CString GetTrialTag();
	void SetTrialTag(LPCTSTR lpszNewValue);
	BOOL GetRunning();
	void SetRunning(BOOL bNewValue);
	CString GetInstanceTag();
	void SetInstanceTag(LPCTSTR lpszNewValue);
	long GetInstances();
	void SetInstances(long nNewValue);
	void Quit();
};
/////////////////////////////////////////////////////////////////////////////
// CTrialBuy wrapper class

class CTrialBuy : public COleDispatchDriver
{
public:
	CTrialBuy() {}		// Calls COleDispatchDriver default constructor
	CTrialBuy(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTrialBuy(const CTrialBuy& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetAuthCode();
	void SetAuthCode(LPCTSTR lpszNewValue);
	CString GetAction();
	void SetAction(LPCTSTR lpszNewValue);
	CString GetResult();
	void SetResult(LPCTSTR lpszNewValue);
	CString GetReason();
	void SetReason(LPCTSTR lpszNewValue);
	CString GetOrderID();
	void SetOrderID(LPCTSTR lpszNewValue);
	void SetMsgTitle(LPCTSTR lpszNewValue);
	CString GetMsgTitle();
	void SetMsgStart(LPCTSTR lpszNewValue);
	CString GetMsgStart();
	void SetCustomerFax(LPCTSTR lpszNewValue);
	CString GetCustomerFax();
	void SetCustomerMI(LPCTSTR lpszNewValue);
	CString GetCustomerMI();
	void SetCustomerLastname(LPCTSTR lpszNewValue);
	CString GetCustomerLastname();
	void SetCustomerFirstName(LPCTSTR lpszNewValue);
	CString GetCustomerFirstName();
	void SetLive(BOOL bNewValue);
	BOOL GetLive();
	BOOL OrderSubmit();
	BOOL OrderPrint(LPCTSTR Filename);
	CString OrderSaveToFile(LPCTSTR Filename);
	CString GetCreditCardNumber();
	void SetCreditCardNumber(LPCTSTR lpszNewValue);
	CString GetCreditCardType();
	void SetCreditCardType(LPCTSTR lpszNewValue);
	CString GetCreditCardExpMonth();
	void SetCreditCardExpMonth(LPCTSTR lpszNewValue);
	CString GetCreditCardExpYear();
	void SetCreditCardExpYear(LPCTSTR lpszNewValue);
	CString GetCreditCardHolderName();
	void SetCreditCardHolderName(LPCTSTR lpszNewValue);
	CString GetCustomerAddress();
	void SetCustomerAddress(LPCTSTR lpszNewValue);
	CString GetCustomerCity();
	void SetCustomerCity(LPCTSTR lpszNewValue);
	CString GetCustomerState();
	void SetCustomerState(LPCTSTR lpszNewValue);
	CString GetCustomerPostCode();
	void SetCustomerPostCode(LPCTSTR lpszNewValue);
	CString GetCustomerCountry();
	void SetCustomerCountry(LPCTSTR lpszNewValue);
	CString GetProductName();
	void SetProductName(LPCTSTR lpszNewValue);
	CString GetProductVersion();
	void SetProductVersion(LPCTSTR lpszNewValue);
	CString GetProductPrice();
	void SetProductPrice(LPCTSTR lpszNewValue);
	CString GetProductQty();
	void SetProductQty(LPCTSTR lpszNewValue);
	CString GetInqiuryCode();
	void SetInqiuryCode(LPCTSTR lpszNewValue);
	CString GetProductID();
	void SetProductID(LPCTSTR lpszNewValue);
	CString GetUnlockCode();
	void SetUnlockCode(LPCTSTR lpszNewValue);
	BOOL CollectCustomerInfo(LPCTSTR Filename);
	BOOL CollectCardInfo();
	CString GetVendorID();
	void SetVendorID(LPCTSTR lpszNewValue);
	CString GetVendorSupportMail();
	void SetVendorSupportMail(LPCTSTR lpszNewValue);
	CString GetVendorReceiptMail();
	void SetVendorReceiptMail(LPCTSTR lpszNewValue);
	CString GetVendorAddress();
	void SetVendorAddress(LPCTSTR lpszNewValue);
	CString GetVendorCity();
	void SetVendorCity(LPCTSTR lpszNewValue);
	CString GetVendorState();
	void SetVendorState(LPCTSTR lpszNewValue);
	CString GetVendorMsg();
	void SetVendorMsg(LPCTSTR lpszNewValue);
	CString GetVendorPostcode();
	void SetVendorPostcode(LPCTSTR lpszNewValue);
	CString GetVendorName();
	void SetVendorName(LPCTSTR lpszNewValue);
	CString GetVendorCountry();
	void SetVendorCountry(LPCTSTR lpszNewValue);
	CString GetCustomerEmail();
	void SetCustomerEmail(LPCTSTR lpszNewValue);
	CString GetCustomerTelephone();
	void SetCustomerTelephone(LPCTSTR lpszNewValue);
	void SaveCustomerInfo(LPCTSTR Filename);
	void LoadCustomerInfo(LPCTSTR Filename);
	BOOL ValidateCustomerInfo();
	BOOL ValidateCardInfo();
	CString GetCustomerCompany();
	void SetCustomerCompany(LPCTSTR lpszNewValue);
	BOOL Purchase(BSTR* Filename);
};
/////////////////////////////////////////////////////////////////////////////
// _cLastError wrapper class

class _cLastError : public COleDispatchDriver
{
public:
	_cLastError() {}		// Calls COleDispatchDriver default constructor
	_cLastError(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_cLastError(const _cLastError& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void SetNumber(long nNewValue);
	long GetNumber();
	void SetErl(long nNewValue);
	long GetErl();
	void SetSource(LPCTSTR lpszNewValue);
	CString GetSource();
	void SetLastDLLError(long nNewValue);
	long GetLastDLLError();
	void SetHelpFile(LPCTSTR lpszNewValue);
	CString GetHelpFile();
	void SetHelpContext(long nNewValue);
	long GetHelpContext();
	void SetDescription(LPCTSTR lpszNewValue);
	CString GetDescription();
	void PushError();
	void Raise();
	void Clear();
};
/////////////////////////////////////////////////////////////////////////////
// CTrialEvents wrapper class

class CTrialEvents : public COleDispatchDriver
{
public:
	CTrialEvents() {}		// Calls COleDispatchDriver default constructor
	CTrialEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTrialEvents(const CTrialEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void BeforeShow(LPDISPATCH* myWizard);
	void ActionCode(long* Action, BSTR* ProgID, BSTR* ProgCode, long* Code, long* YourResponse);
	void Initialize();
	void Created();
	void Expired();
	void Invalid(long* ReasonCode, BSTR* MsgText);
	void Begin();
	void DateSetBack();
	void UserDecline();
	void Retail();
	void BadUnlock(BOOL* Cancel);
	void Converted();
	void Removed();
	void Extended(long* ExtendAmount);
	void Reset();
	void CreateLicense(BSTR* Path);
};
/////////////////////////////////////////////////////////////////////////////
// CBuyEvents wrapper class

class CBuyEvents : public COleDispatchDriver
{
public:
	CBuyEvents() {}		// Calls COleDispatchDriver default constructor
	CBuyEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CBuyEvents(const CBuyEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void Status(BSTR* Msg);
};
