#if !defined(AFX_ALARM_H__7D4A5565_F509_11D2_B3FE_0080C8C277AA__INCLUDED_)
#define AFX_ALARM_H__7D4A5565_F509_11D2_B3FE_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Alarm.h : header file
//





class AlarmItem
{
     friend bifstream & operator >> ( bifstream & fin,  AlarmItem & data );
     friend bofstream & operator << ( bofstream & fout, AlarmItem & data );

public:
     int    tag;

     // alarm info
     int  alarmEnable;
     int  alarmHour;
     int  alarmMinute;
     string alarmMessage;
     string alarmRunApp;
     int alarmRunEnable;
  

     //
     //   throw in some extra fields
     //
     int    spare[5];

     AlarmItem ( void )
     {
          tag = 0;

            alarmEnable = 0;
            alarmHour = 0;
            alarmMinute = 0;
            alarmMessage = "";
            alarmRunApp = "";
            alarmRunEnable = 1;
      

          for ( int i = 0; i < sizeof ( spare ) / sizeof ( int ); i++ )
              spare[i] = 0;
     }
};



class Alarms
{
private:                    
    string fileName;

     LinkedList<AlarmItem *> ll;

     float version;

public:
     // class persistence
//     void Save ( void ); //string & );
 //    void Open ( string & );
 //    void Create ( string & );

     Alarms ( void );
    ~Alarms ( void );
};

extern Alarms a;




















/////////////////////////////////////////////////////////////////////////////
// CAlarm dialog

class CAlarm : public CDialog
{
// Construction
public:
	CAlarm(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAlarm)
	enum { IDD = IDD_ALARM };
	CButton	m_runApp;
	CComboBox	m_ampm;
	CDateTimeCtrl	m_enable;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlarm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAlarm)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALARM_H__7D4A5565_F509_11D2_B3FE_0080C8C277AA__INCLUDED_)
