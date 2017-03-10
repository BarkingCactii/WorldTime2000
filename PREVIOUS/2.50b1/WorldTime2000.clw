; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "worldtime2000.h"
LastPage=0

ClassCount=18
Class1=About
Class2=CAdd
Class3=CAddDisplay
Class4=CDelete
Class5=CDetails
Class6=CFeatures
Class7=Features
Class8=CHome
Class9=CMainFrame
Class10=CModify
Class11=CPreferences
Class12=CWorldTime2000App
Class13=CAboutDlg
Class14=CWorldTime2000View

ResourceCount=31
Resource1=IDR_SYSTEMTRAY
Resource2=IDR_DOCUMENTATION (English (Australia))
Resource3=IDR_MAINFRAME (English (U.S.))
Resource4=IDD_PREFERENCES
Resource5=IDD_ALARM
Resource6=IDD_DELETE
Resource7=IDD_MODIFY
Resource8=IDR_DOCUMENTATION
Class15=CAlarm
Resource9=IDD_ALARM (English (Australia))
Class16=CRegister
Resource10=IDD_MODIFY (English (Australia))
Resource11=IDD_MODIFY2 (English (Australia))
Resource12=IDD_HOME (English (Australia))
Resource13=IDD_REGISTER (English (Australia))
Resource14=IDD_Preferences (English (Australia))
Resource15=IDD_ADD_DISPLAY
Resource16=IDD_DELETE (English (Australia))
Resource17=IDD_PREFERENCES (English (Australia))
Resource18=IDR_CONTEXT (English (Australia))
Resource19=IDD_ADD_LOCATION
Resource20=IDR_PREFERENCES (English (Australia))
Resource21=IDD_LEGEND (English (Australia))
Resource22=IDD_ADD_DISPLAY1 (English (Australia))
Resource23=IDR_MAINFRAME
Resource24=IDR_CONTEXT
Resource25=IDD_ADD_DISPLAY (English (Australia))
Resource26=IDD_HOME
Resource27=IDR_MAINFRAME (English (Australia))
Resource28=IDR_PREFERENCES
Resource29=IDR_SYSTEMTRAY (English (Australia))
Class17=CLegend
Resource30=IDD_ADD_LOCATION (English (Australia))
Class18=whatif
Resource31=IDD_WHATIF (English (Australia))

[CLS:About]
Type=0
BaseClass=CHtmlView
HeaderFile=about.h
ImplementationFile=about.cpp
LastObject=About

[CLS:CAdd]
Type=0
BaseClass=CDialog
HeaderFile=Add.h
ImplementationFile=Add.cpp
LastObject=CAdd
Filter=D
VirtualFilter=dWC

[CLS:CAddDisplay]
Type=0
BaseClass=CDialog
HeaderFile=AddDisplay.h
ImplementationFile=AddDisplay.cpp
LastObject=IDCANCEL
Filter=D
VirtualFilter=dWC

[CLS:CDelete]
Type=0
BaseClass=CDialog
HeaderFile=delete.h
ImplementationFile=delete.cpp
LastObject=CDelete
Filter=D
VirtualFilter=dWC

[CLS:CDetails]
Type=0
BaseClass=CDialog
HeaderFile=Details.h
ImplementationFile=Details.cpp
LastObject=ID_BUTTON32782

[CLS:CFeatures]
Type=0
BaseClass=CDialog
HeaderFile=Features.h
ImplementationFile=Features.cpp
LastObject=CFeatures

[CLS:Features]
Type=0
BaseClass=CHtmlView
HeaderFile=Features.h
ImplementationFile=Features.cpp

[CLS:CHome]
Type=0
BaseClass=CDialog
HeaderFile=Home.h
ImplementationFile=Home.cpp
LastObject=CHome

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
LastObject=ID_VIEW_WHATIF
Filter=T
VirtualFilter=fWC

[CLS:CModify]
Type=0
BaseClass=CDialog
HeaderFile=modify.h
ImplementationFile=modify.cpp
LastObject=IDCANCEL
Filter=D
VirtualFilter=dWC

[CLS:CPreferences]
Type=0
BaseClass=CDialog
HeaderFile=Preferences.h
ImplementationFile=Preferences.cpp
LastObject=CPreferences
Filter=D
VirtualFilter=dWC

[CLS:CWorldTime2000App]
Type=0
BaseClass=CWinApp
HeaderFile=WorldTime2000.h
ImplementationFile=WorldTime2000.cpp
Filter=N
VirtualFilter=AC
LastObject=CWorldTime2000App

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=WorldTime2000.cpp
ImplementationFile=WorldTime2000.cpp
LastObject=CAboutDlg

[CLS:CWorldTime2000View]
Type=0
BaseClass=CScrollView 
HeaderFile=WorldTime2000View.h
ImplementationFile=WorldTime2000View.cpp
LastObject=CWorldTime2000View
Filter=W
VirtualFilter=WC

[DLG:IDD_ADD_LOCATION]
Type=1
Class=CAdd
ControlCount=22
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_SLIDER1,msctls_trackbar32,1342242820
Control6=IDC_STATIC,button,1342177287
Control7=IDC_ADD_HOURS,static,1342308865
Control8=IDC_STATIC,button,1342177287
Control9=IDC_ADD_START_DAY,combobox,1344339970
Control10=IDC_ADD_START_FIRSTLAST,combobox,1344340994
Control11=IDC_ADD_START_MONTH,combobox,1344339970
Control12=IDC_STATIC,static,1342308864
Control13=IDC_ADD_END_DAY,combobox,1344339970
Control14=IDC_ADD_END_FIRSTLAST,combobox,1344339970
Control15=IDC_ADD_END_MONTH,combobox,1344339970
Control16=IDC_STATIC,static,1342308864
Control17=IDC_CHECK1,button,1342242851
Control18=IDC_STATIC,static,1342179331
Control19=IDC_EDIT2,edit,1350631552
Control20=IDC_STATIC,static,1342308864
Control21=IDC_STATIC,button,1342177287
Control22=IDC_STATIC,static,1342308352

[DLG:IDD_ADD_DISPLAY]
Type=1
Class=CAddDisplay
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=ID_DETAILS,button,1342242817
Control4=IDC_ADD_DISPLAY_LIST,SysListView32,1350631429
Control5=IDC_STATIC,static,1342179331
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_DELETE]
Type=1
Class=CDelete
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=ID_DETAILS,button,1342242817
Control4=IDC_DELETE,SysListView32,1350631429
Control5=IDC_STATIC,static,1342179331
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_FEATURES]
Type=1
Class=CFeatures

[DLG:IDD_HOME]
Type=1
Class=CHome
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342179331
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_HOME
Command2=ID_FILE_ADDTODISPLAY
Command3=ID_FILE_ADD
Command4=ID_FILE_MODIFY
Command5=ID_FILE_DELETE
Command6=ID_FILE_ALARMRESET
Command7=ID_FILE_PREFERENCES
Command8=ID_FILE_FONT
Command9=ID_HELP_FUTURE
Command10=ID_APP_ABOUT
CommandCount=10

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_HOME
Command2=ID_FILE_ADDTODISPLAY
Command3=ID_FILE_ADD
Command4=ID_FILE_MODIFY
Command5=ID_FILE_DELETE
Command6=ID_FILE_ALARMRESET
Command7=ID_FILE_PREFERENCES
Command8=ID_FILE_FONT
Command9=ID_APP_EXIT
Command10=ID_SHOW_TOOLBAR
Command11=ID_SHOW_STATUS_BAR
Command12=ID_HELP_CONTENTS
Command13=ID_HELP_FUTURE
Command14=ID_TIMESYNC
Command15=ID_ORDER
Command16=ID_REGISTER
Command17=ID_APP_ABOUT
CommandCount=17

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_ADD
Command2=ID_EDIT_COPY
Command3=ID_FILE_ADDTODISPLAY
Command4=ID_FILE_DELETE
Command5=ID_FILE_FONT
Command6=ID_FILE_HOME
Command7=ID_FILE_MODIFY
Command8=ID_FILE_PREFERENCES
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_HELP_CONTENTS
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_EDIT_COPY
Command16=ID_EDIT_PASTE
Command17=ID_FILE_ALARMRESET
Command18=ID_APP_EXIT
Command19=ID_EDIT_CUT
Command20=ID_EDIT_UNDO
CommandCount=20

[MNU:IDR_CONTEXT]
Type=1
Class=?
CommandCount=0

[DLG:IDD_ALARM]
Type=1
Class=CAlarm
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LOCATION,static,1342308864
Control4=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242859
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_STATIC,static,1342308864
Control7=IDC_AMPM,combobox,1344339970
Control8=IDC_STATIC,button,1342177287
Control9=IDC_BUTTON1,button,1342242816
Control10=IDC_CHECK1,button,1342245891
Control11=IDC_APP_NAME,static,1342308352

[CLS:CAlarm]
Type=0
HeaderFile=Alarm.h
ImplementationFile=Alarm.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON1

[CLS:CRegister]
Type=0
HeaderFile=Register.h
ImplementationFile=Register.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CRegister

[MNU:IDR_CONTEXT (English (Australia))]
Type=1
Class=?
CommandCount=0

[DLG:IDD_HOME (English (Australia))]
Type=1
Class=CHome
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342179331
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_ADD_LOCATION (English (Australia))]
Type=1
Class=CAdd
ControlCount=27
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_SLIDER1,msctls_trackbar32,1342242820
Control6=IDC_STATIC,button,1342177287
Control7=IDC_ADD_HOURS,static,1342308865
Control8=IDC_STATIC,button,1342177287
Control9=IDC_ADD_START_DAY,combobox,1344339970
Control10=IDC_ADD_START_FIRSTLAST,combobox,1344340994
Control11=IDC_ADD_START_MONTH,combobox,1344339970
Control12=IDC_STATIC,static,1342308864
Control13=IDC_ADD_END_DAY,combobox,1344339970
Control14=IDC_ADD_END_FIRSTLAST,combobox,1344339970
Control15=IDC_ADD_END_MONTH,combobox,1344339970
Control16=IDC_STATIC,static,1342308864
Control17=IDC_CHECK1,button,1342242851
Control18=IDC_STATIC,static,1342179331
Control19=IDC_EDIT2,edit,1350631552
Control20=IDC_STATIC,static,1342308864
Control21=IDC_STATIC,button,1342177287
Control22=IDC_STATIC,static,1342308352
Control23=IDC_EDIT3,edit,1350631552
Control24=IDC_STATIC,static,1342308864
Control25=IDC_EDIT4,edit,1350631552
Control26=IDC_STATIC,static,1342308864
Control27=IDC_STATIC,button,1342177287

[DLG:IDD_ADD_DISPLAY (English (Australia))]
Type=1
Class=CAddDisplay
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=ID_DETAILS,button,1342242817
Control4=IDC_ADD_DISPLAY_LIST,SysListView32,1350631429
Control5=IDC_STATIC,static,1342179331
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_Preferences (English (Australia))]
Type=1
Class=?
ControlCount=27
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CHECK1,button,1342242819
Control4=IDC_CHECK2,button,1342242819
Control5=IDC_HOME_COLOR,button,1342242816
Control6=IDC_HOME_SAMPLE,static,1342308865
Control7=IDC_LOCATION_COLOR,button,1342242816
Control8=IDC_SELECTED_COLOR,button,1342242816
Control9=IDC_SELECTED_SAMPLE,static,1342308865
Control10=IDC_LOCATION_SAMPLE,static,1342308865
Control11=IDC_STATIC,button,1342177287
Control12=IDC_BACKGROUND_COLOR,button,1342242816
Control13=IDC_BACKGROUND_SAMPLE,static,1342308865
Control14=IDC_STATIC,button,1342177287
Control15=IDC_CHECK3,button,1342245891
Control16=IDC_BACKGROUND_TEXTURE,button,1342242816
Control17=IDC_STATIC,button,1342177287
Control18=IDC_CHECK4,button,1342242819
Control19=IDC_EDIT1,edit,1350631552
Control20=IDC_STATIC,static,1342308864
Control21=IDC_SOUNDALARM,button,1342242816
Control22=IDC_SOUNDHOUR,button,1342242816
Control23=IDC_SOUNDQUARTER,button,1342242816
Control24=IDC_STATIC,button,1342177287
Control25=IDC_SOUNDALARMON,button,1342242819
Control26=IDC_SOUNDHOURON,button,1342242819
Control27=IDC_SOUNDQUARTERON,button,1342242819

[DLG:IDD_DELETE (English (Australia))]
Type=1
Class=CDelete
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=ID_DETAILS,button,1342242817
Control4=IDC_DELETE,SysListView32,1350631429
Control5=IDC_STATIC,static,1342179331
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_MODIFY (English (Australia))]
Type=1
Class=?
ControlCount=28
Control1=IDOK,button,1342251009
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_SLIDER1,msctls_trackbar32,1342242820
Control6=IDC_STATIC,button,1342177287
Control7=IDC_ADD_HOURS,static,1342308865
Control8=IDC_STATIC,button,1342177287
Control9=IDC_ADD_START_DAY,combobox,1344339970
Control10=IDC_ADD_START_FIRSTLAST,combobox,1344340994
Control11=IDC_ADD_START_MONTH,combobox,1344339970
Control12=IDC_STATIC,static,1342308864
Control13=IDC_ADD_END_DAY,combobox,1344339970
Control14=IDC_ADD_END_FIRSTLAST,combobox,1344339970
Control15=IDC_ADD_END_MONTH,combobox,1344339970
Control16=IDC_STATIC,static,1342308864
Control17=IDC_CHECK1,button,1342242851
Control18=IDC_STATIC,static,1342179331
Control19=IDC_EDIT2,edit,1350631552
Control20=IDC_STATIC,static,1342308864
Control21=IDC_STATIC,button,1342177287
Control22=IDC_STATIC,static,1342308352
Control23=IDC_MODIFY_LIST,SysListView32,1350631429
Control24=IDC_EDIT3,edit,1350631552
Control25=IDC_STATIC,static,1342308864
Control26=IDC_EDIT4,edit,1350631552
Control27=IDC_STATIC,static,1342308864
Control28=IDC_STATIC,button,1342177287

[DLG:IDD_ALARM (English (Australia))]
Type=1
Class=CAlarm
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LOCATION,static,1342308864
Control4=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242859
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_STATIC,static,1342308864
Control7=IDC_AMPM,combobox,1344339970
Control8=IDC_STATIC,button,1342177287
Control9=IDC_BUTTON1,button,1342242816
Control10=IDC_CHECK1,button,1342245891
Control11=IDC_APP_NAME,static,1342308352

[DLG:IDD_REGISTER (English (Australia))]
Type=1
Class=?
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_REGISTER_NAME,edit,1350631552
Control4=IDC_STATIC,static,1342308864
Control5=IDC_REGISTER_KEY,edit,1350631552
Control6=IDC_STATIC,static,1342308864

[MNU:IDR_MAINFRAME (English (Australia))]
Type=1
Class=?
Command1=ID_FILE_HOME
Command2=ID_FILE_ADDTODISPLAY
Command3=ID_FILE_ADD
Command4=ID_FILE_MODIFY
Command5=ID_FILE_DELETE
Command6=ID_CONTEXT_WHATIF
Command7=ID_FILE_ALARMRESET
Command8=ID_FILE_PREFERENCES
Command9=ID_FILE_FONT
Command10=ID_FILE_SAVE
Command11=ID_APP_EXIT
Command12=ID_SHOW_TOOLBAR
Command13=ID_SHOW_STATUS_BAR
Command14=ID_VIEW_GMT
Command15=ID_VIEW_WHATIF
Command16=ID_SORT_NAME
Command17=ID_SORT_COUNTRY
Command18=ID_SORT_TIME
Command19=ID_HELP_CONTENTS
Command20=ID_HELP_LEGEND
Command21=ID_HELP_FUTURE
Command22=ID_ORDER
Command23=ID_APP_ABOUT
CommandCount=23

[TB:IDR_MAINFRAME (English (Australia))]
Type=1
Class=?
Command1=ID_FILE_HOME
Command2=ID_FILE_ADDTODISPLAY
Command3=ID_FILE_ADD
Command4=ID_FILE_MODIFY
Command5=ID_FILE_DELETE
Command6=ID_FILE_ALARMRESET
Command7=ID_FILE_PREFERENCES
Command8=ID_FILE_FONT
Command9=ID_HELP_FUTURE
Command10=ID_APP_ABOUT
CommandCount=10

[ACL:IDR_MAINFRAME (English (Australia))]
Type=1
Class=?
Command1=ID_FILE_ADD
Command2=ID_EDIT_COPY
Command3=ID_FILE_ADDTODISPLAY
Command4=ID_FILE_DELETE
Command5=ID_FILE_FONT
Command6=ID_FILE_HOME
Command7=ID_FILE_MODIFY
Command8=ID_FILE_PREFERENCES
Command9=ID_FILE_SAVE
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_HELP_CONTENTS
Command14=ID_NEXT_PANE
Command15=ID_PREV_PANE
Command16=ID_EDIT_COPY
Command17=ID_EDIT_PASTE
Command18=ID_FILE_ALARMRESET
Command19=ID_CONTEXT_WHATIF
Command20=ID_APP_EXIT
Command21=ID_EDIT_CUT
Command22=ID_EDIT_UNDO
CommandCount=22

[DLG:IDD_ADD_DISPLAY1 (English (Australia))]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ADD_DISPLAY_LIST,listbox,1352728833
Control4=ID_DETAILS,button,1342242817

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_HOME
Command2=ID_FILE_ADDTODISPLAY
Command3=ID_FILE_ADD
Command4=ID_FILE_MODIFY
Command5=ID_FILE_DELETE
Command6=ID_FILE_ALARMRESET
Command7=ID_FILE_PREFERENCES
Command8=ID_FILE_FONT
Command9=ID_FILE_SAVE
Command10=ID_APP_EXIT
Command11=ID_SHOW_TOOLBAR
Command12=ID_SHOW_STATUS_BAR
Command13=ID_VIEW_GMT
Command14=ID_SORT_NAME
Command15=ID_SORT_COUNTRY
Command16=ID_SORT_TIME
Command17=ID_HELP_CONTENTS
Command18=ID_HELP_FUTURE
Command19=ID_TIMESYNC
Command20=ID_ORDER
Command21=ID_APP_ABOUT
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_ADD
Command2=ID_EDIT_COPY
Command3=ID_FILE_ADDTODISPLAY
Command4=ID_FILE_DELETE
Command5=ID_FILE_FONT
Command6=ID_FILE_HOME
Command7=ID_FILE_MODIFY
Command8=ID_FILE_PREFERENCES
Command9=ID_FILE_SAVE
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_HELP_CONTENTS
Command14=ID_NEXT_PANE
Command15=ID_PREV_PANE
Command16=ID_EDIT_COPY
Command17=ID_EDIT_PASTE
Command18=ID_FILE_ALARMRESET
Command19=ID_APP_EXIT
Command20=ID_EDIT_CUT
Command21=ID_EDIT_UNDO
CommandCount=21

[DLG:IDD_PREFERENCES]
Type=1
Class=CPreferences
ControlCount=34
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CHECK1,button,1342242819
Control4=IDC_CHECK2,button,1342242819
Control5=IDC_HOME_COLOR,button,1342242816
Control6=IDC_HOME_SAMPLE,static,1342308865
Control7=IDC_LOCATION_COLOR,button,1342242816
Control8=IDC_SELECTED_COLOR,button,1342242816
Control9=IDC_SELECTED_SAMPLE,static,1342308865
Control10=IDC_LOCATION_SAMPLE,static,1342308865
Control11=IDC_STATIC,button,1342177287
Control12=IDC_BACKGROUND_COLOR,button,1342242816
Control13=IDC_BACKGROUND_SAMPLE,static,1342308865
Control14=IDC_STATIC,button,1342177287
Control15=IDC_CHECK3,button,1342245891
Control16=IDC_BACKGROUND_TEXTURE,button,1342242816
Control17=IDC_STATIC,button,1342177287
Control18=IDC_CHECK4,button,1342242819
Control19=IDC_EDIT1,edit,1350631552
Control20=IDC_STATIC,static,1342308864
Control21=IDC_SOUNDALARM,button,1342242816
Control22=IDC_SOUNDHOUR,button,1342242816
Control23=IDC_SOUNDQUARTER,button,1342242816
Control24=IDC_STATIC,button,1342177287
Control25=IDC_SOUNDALARMON,button,1342242819
Control26=IDC_SOUNDHOURON,button,1342242819
Control27=IDC_SOUNDQUARTERON,button,1342242819
Control28=IDC_STATIC,static,1342179331
Control29=IDC_STATIC,button,1342177287
Control30=IDC_STATIC,static,1342308352
Control31=IDC_CHECK5,button,1342242819
Control32=IDC_STATIC,button,1342177287
Control33=IDC_CHECK6,button,1342242819
Control34=IDC_STATIC,static,1342308352

[MNU:IDR_PREFERENCES]
Type=1
Class=?
CommandCount=0

[MNU:IDR_DOCUMENTATION]
Type=1
Class=?
CommandCount=0

[MNU:IDR_PREFERENCES (English (Australia))]
Type=1
Class=?
CommandCount=0

[MNU:IDR_DOCUMENTATION (English (Australia))]
Type=1
Class=?
CommandCount=0

[DLG:IDD_PREFERENCES (English (Australia))]
Type=1
Class=CPreferences
ControlCount=35
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CHECK1,button,1342242819
Control4=IDC_CHECK2,button,1342242819
Control5=IDC_HOME_COLOR,button,1342242816
Control6=IDC_HOME_SAMPLE,static,1342308865
Control7=IDC_LOCATION_COLOR,button,1342242816
Control8=IDC_SELECTED_COLOR,button,1342242816
Control9=IDC_SELECTED_SAMPLE,static,1342308865
Control10=IDC_LOCATION_SAMPLE,static,1342308865
Control11=IDC_STATIC,button,1342177287
Control12=IDC_BACKGROUND_COLOR,button,1342242816
Control13=IDC_BACKGROUND_SAMPLE,static,1342308865
Control14=IDC_STATIC,button,1342177287
Control15=IDC_CHECK3,button,1342245891
Control16=IDC_BACKGROUND_TEXTURE,button,1342242816
Control17=IDC_STATIC,button,1342177287
Control18=IDC_CHECK4,button,1342242819
Control19=IDC_EDIT1,edit,1350631552
Control20=IDC_STATIC,static,1342308864
Control21=IDC_SOUNDALARM,button,1342242816
Control22=IDC_SOUNDHOUR,button,1342242816
Control23=IDC_SOUNDQUARTER,button,1342242816
Control24=IDC_STATIC,button,1342177287
Control25=IDC_SOUNDALARMON,button,1342242819
Control26=IDC_SOUNDHOURON,button,1342242819
Control27=IDC_SOUNDQUARTERON,button,1342242819
Control28=IDC_STATIC,static,1342179331
Control29=IDC_STATIC,button,1342177287
Control30=IDC_STATIC,static,1342308352
Control31=IDC_CHECK5,button,1342242819
Control32=IDC_STATIC,button,1342177287
Control33=IDC_CHECK6,button,1342242819
Control34=IDC_STATIC,static,1342308352
Control35=IDC_CHECK8,button,1342242819

[DLG:IDD_MODIFY]
Type=1
Class=?
ControlCount=23
Control1=IDOK,button,1342251009
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_SLIDER1,msctls_trackbar32,1342242820
Control6=IDC_STATIC,button,1342177287
Control7=IDC_ADD_HOURS,static,1342308865
Control8=IDC_STATIC,button,1342177287
Control9=IDC_ADD_START_DAY,combobox,1344339970
Control10=IDC_ADD_START_FIRSTLAST,combobox,1344340994
Control11=IDC_ADD_START_MONTH,combobox,1344339970
Control12=IDC_STATIC,static,1342308864
Control13=IDC_ADD_END_DAY,combobox,1344339970
Control14=IDC_ADD_END_FIRSTLAST,combobox,1344339970
Control15=IDC_ADD_END_MONTH,combobox,1344339970
Control16=IDC_STATIC,static,1342308864
Control17=IDC_CHECK1,button,1342242851
Control18=IDC_STATIC,static,1342179331
Control19=IDC_EDIT2,edit,1350631552
Control20=IDC_STATIC,static,1342308864
Control21=IDC_STATIC,button,1342177287
Control22=IDC_STATIC,static,1342308352
Control23=IDC_MODIFY_LIST,SysListView32,1350631429

[DLG:IDD_MODIFY2 (English (Australia))]
Type=1
Class=?
ControlCount=22
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_SLIDER1,msctls_trackbar32,1342242820
Control6=IDC_STATIC,button,1342177287
Control7=IDC_ADD_HOURS,static,1342308865
Control8=IDC_STATIC,button,1342177287
Control9=IDC_ADD_START_DAY,combobox,1344339970
Control10=IDC_ADD_START_FIRSTLAST,combobox,1344340994
Control11=IDC_ADD_START_MONTH,combobox,1344339970
Control12=IDC_STATIC,static,1342308864
Control13=IDC_ADD_END_DAY,combobox,1344339970
Control14=IDC_ADD_END_FIRSTLAST,combobox,1344339970
Control15=IDC_ADD_END_MONTH,combobox,1344339970
Control16=IDC_STATIC,static,1342308864
Control17=IDC_STATIC,static,1342308864
Control18=IDC_CHECK1,button,1342242851
Control19=IDC_STATIC,static,1342179331
Control20=IDC_STATIC,button,1342177287
Control21=IDC_STATIC,static,1342308352
Control22=IDC_MODIFY_LIST,SysListView32,1350631429

[MNU:IDR_SYSTEMTRAY (English (Australia))]
Type=1
Class=?
CommandCount=0

[MNU:IDR_SYSTEMTRAY]
Type=1
Class=?
CommandCount=0

[DLG:IDD_LEGEND (English (Australia))]
Type=1
Class=CLegend
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342179331
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342179331
Control6=IDC_STATIC,static,1342179331
Control7=IDC_STATIC,static,1342179331
Control8=IDC_STATIC,static,1342179331
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342179331
Control14=IDC_STATIC,static,1342308352

[CLS:CLegend]
Type=0
HeaderFile=Legend.h
ImplementationFile=Legend.cpp
BaseClass=CDialog
Filter=D
LastObject=CLegend

[DLG:IDD_WHATIF (English (Australia))]
Type=1
Class=whatif
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TIME,SysDateTimePick32,1342242857
Control4=IDC_DATE,SysDateTimePick32,1342242853
Control5=IDC_LOCATION,static,1342308352

[CLS:whatif]
Type=0
HeaderFile=whatif.h
ImplementationFile=whatif.cpp
BaseClass=CDialog
Filter=D
LastObject=whatif
VirtualFilter=dWC

