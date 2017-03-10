// PrefSoundsPropPage.cpp : implementation file
//

#include "stdafx.h"
#include "worldtime2000.h"
#include "PrefSoundsPropPage.h"
#include "RegData.h"
//#include "OnLineTimeView.h"
#include "sounds.h"
#include "htmlhelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrefSoundsPropPage property page

IMPLEMENT_DYNCREATE(CPrefSoundsPropPage, CPropertyPage)

CPrefSoundsPropPage::CPrefSoundsPropPage() : CPropertyPage(CPrefSoundsPropPage::IDD)
{
    /*
    r.GetKey ("PlayAlarm").word = m_alarm;
    r.GetKey ("PlayQuarter").word = m_quarter;
    r.GetKey ("PlayHour").word = m_hour;
    r.GetKey ("SoundAlarmFile").str = m_alarmFile;
    r.GetKey ("SoundQuarterFile").str = m_quarterFile;
    r.GetKey ("SoundHourFile").str = m_hourFile;
      */
	//{{AFX_DATA_INIT(CPrefSoundsPropPage)
	m_alarm = r.GetKey ("PlayAlarm").word; //FALSE;
	m_hour = r.GetKey ("PlayHour").word; //FALSE;
	m_quarter = r.GetKey ("PlayQuarter").word; //FALSE;
	m_quarterFile = r.GetKey("SoundQuarterFile").str.c_str(); //_T("");
	m_hourFile = r.GetKey("SoundHourFile").str.c_str(); //_T("");
	m_alarmFile = r.GetKey ("SoundAlarmFile").str.c_str(); //_T("");
	//}}AFX_DATA_INIT
}

CPrefSoundsPropPage::~CPrefSoundsPropPage()
{
}

void CPrefSoundsPropPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrefSoundsPropPage)
	DDX_Control(pDX, IDC_ALARMSOUND_FILE, m_alarmFileCtrl);
	DDX_Control(pDX, IDC_HOURSOUND_FILE, m_hourFileCtrl);
	DDX_Control(pDX, IDC_QUARTERSOUND_FILE, m_quarterFileCtrl);
	DDX_Check(pDX, IDC_SOUNDALARMON, m_alarm);
	DDX_Check(pDX, IDC_SOUNDHOURON, m_hour);
	DDX_Check(pDX, IDC_SOUNDQUARTERON, m_quarter);
	DDX_Text(pDX, IDC_QUARTERSOUND_FILE, m_quarterFile);
	DDX_Text(pDX, IDC_HOURSOUND_FILE, m_hourFile);
	DDX_Text(pDX, IDC_ALARMSOUND_FILE, m_alarmFile);
	//}}AFX_DATA_MAP
}

          
BEGIN_MESSAGE_MAP(CPrefSoundsPropPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPrefSoundsPropPage)
	ON_BN_CLICKED(IDC_SOUNDALARM, OnSoundalarm)
	ON_BN_CLICKED(IDC_SOUNDHOUR, OnSoundhour)
	ON_BN_CLICKED(IDC_SOUNDQUARTER, OnSoundquarter)
	ON_BN_CLICKED(IDC_ALARM_TEST, OnAlarmTest)
	ON_BN_CLICKED(IDC_HOUR_TEST, OnHourTest)
	ON_BN_CLICKED(IDC_QUARTER_TEST, OnQuarterTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrefSoundsPropPage message handlers

BOOL CPrefSoundsPropPage::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
    SetModified ( TRUE );
	
	return CPropertyPage::OnSetActive();
}

void CPrefSoundsPropPage::OnSoundalarm() 
{
	// TODO: Add your control notification handler code here
      char * filterBuf= "PCM Wave Files\0*.wav;*.cmo\0\0\0";
      CFileDialog openD ( TRUE );

      openD.m_ofn.lpstrFilter = filterBuf;
      openD.m_ofn.lpstrInitialDir = ".\\";
      openD.m_ofn.lpstrTitle = "Select Sound file";

     if ( openD.DoModal () == IDOK )
         m_alarmFile = openD.m_ofn.lpstrFile;	

     m_alarmFileCtrl.SetWindowText ( openD.m_ofn.lpstrFile );

}

void CPrefSoundsPropPage::OnSoundhour() 
{
	// TODO: Add your control notification handler code here
      char * filterBuf= "PCM Wave Files\0*.wav;*.cmo\0\0\0";
      CFileDialog openD ( TRUE );

      openD.m_ofn.lpstrFilter = filterBuf;
      openD.m_ofn.lpstrInitialDir = ".\\";
      openD.m_ofn.lpstrTitle = "Select Sound file";

     if ( openD.DoModal () == IDOK )
         m_hourFile = openD.m_ofn.lpstrFile;	

     m_hourFileCtrl.SetWindowText ( openD.m_ofn.lpstrFile );
}

void CPrefSoundsPropPage::OnSoundquarter() 
{
	// TODO: Add your control notification handler code here
      char * filterBuf= "PCM Wave Files\0*.wav;*.cmo\0\0\0";
      CFileDialog openD ( TRUE );

      openD.m_ofn.lpstrFilter = filterBuf;
      openD.m_ofn.lpstrInitialDir = ".\\";
      openD.m_ofn.lpstrTitle = "Select Sound file";

     if ( openD.DoModal () == IDOK )
         m_quarterFile = openD.m_ofn.lpstrFile;	

     m_quarterFileCtrl.SetWindowText ( openD.m_ofn.lpstrFile );
}

void CPrefSoundsPropPage::OnOK() 
{
	// TODO: Add your specialized code here and/or call the base class
    r.GetKey ("PlayAlarm").word = m_alarm;
    r.GetKey ("PlayQuarter").word = m_quarter;
    r.GetKey ("PlayHour").word = m_hour;
    r.GetKey ("SoundAlarmFile").str = m_alarmFile;
    r.GetKey ("SoundQuarterFile").str = m_quarterFile;
    r.GetKey ("SoundHourFile").str = m_hourFile;
//	r.SoundAlarm ( m_alarm );
//	r.SoundQuarter ( m_quarter );
//	r.SoundHour ( m_hour );
//    r.SoundAlarmFile (( string ) m_alarmFile );
  //  r.SoundQuarterFile (( string ) m_quarterFile );
//    r.SoundHourFile (( string ) m_hourFile );

//     mainView->Invalidate ( FALSE );

	CPropertyPage::OnOK();
}

BOOL CPrefSoundsPropPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
//    m_message.SetFontItalic ( TRUE );
	
     theApp.m_pSkin->ApplySkin((long)m_hWnd); // Apply contained skin to the main frame and its child windows

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPrefSoundsPropPage::OnAlarmTest() 
{
	// TODO: Add your control notification handler code here
    Playsound ( m_alarmFile, true );
	
}

void CPrefSoundsPropPage::OnHourTest() 
{
	// TODO: Add your control notification handler code here
    Playsound ( m_hourFile, true );
	
}

void CPrefSoundsPropPage::OnQuarterTest() 
{
	// TODO: Add your control notification handler code here
    Playsound ( m_quarterFile, true );
	
}

BOOL CPrefSoundsPropPage::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
    NMHDR* phdr = (NMHDR*)lParam;

    switch(phdr->code)
    {
        case PSN_HELP:
        {
//            HtmlHelp(NULL, "WorldTIme2003.chm::/preferences_sounds.htm", HH_DISPLAY_TOPIC, 0);
            return TRUE;
        break;
        }
    }

	
	return CPropertyPage::OnNotify(wParam, lParam, pResult);
}
