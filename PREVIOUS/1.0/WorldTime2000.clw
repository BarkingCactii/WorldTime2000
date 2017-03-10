; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWorldTime2000View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "worldtime2000.h"
LastPage=0

ClassCount=16
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

ResourceCount=10
Resource1=IDD_DELETE
Resource2=IDD_Preferences
Resource3=IDR_CONTEXT
Resource4=IDD_MODIFY
Resource5=IDD_HOME
Resource6=IDD_ADD_DISPLAY
Resource7=IDR_MAINFRAME (English (U.S.))
Resource8=IDD_ALARM
Class15=CAlarm
Resource9=IDD_ADD_LOCATION
Class16=CRegister
Resource10=IDD_REGISTER

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
LastObject=IDC_CHECK1
Filter=D
VirtualFilter=dWC

[CLS:CAddDisplay]
Type=0
BaseClass=CDialog
HeaderFile=AddDisplay.h
ImplementationFile=AddDisplay.cpp
LastObject=CAddDisplay

[CLS:CDelete]
Type=0
BaseClass=CDialog
HeaderFile=delete.h
ImplementationFile=delete.cpp
LastObject=CDelete

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
LastObject=ID_REGISTER
Filter=T
VirtualFilter=fWC

[CLS:CModify]
Type=0
BaseClass=CDialog
HeaderFile=modify.h
ImplementationFile=modify.cpp
LastObject=CModify
Filter=D
VirtualFilter=dWC

[CLS:CPreferences]
Type=0
BaseClass=CDialog
HeaderFile=Preferences.h
ImplementationFile=Preferences.cpp
LastObject=IDC_BACKGROUND_COLOR
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
BaseClass=CWnd 
HeaderFile=WorldTime2000View.h
ImplementationFile=WorldTime2000View.cpp
LastObject=CWorldTime2000View
Filter=W
VirtualFilter=WC

[DLG:IDD_ADD_LOCATION]
Type=1
Class=CAdd
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_SLIDER1,msctls_trackbar32,1342242820
Control6=IDC_STATIC,button,1342177287
Control7=IDC_ADD_HOURS,static,1342308865
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342179331
Control10=IDC_ADD_START_DAY,combobox,1344339970
Control11=IDC_ADD_START_FIRSTLAST,combobox,1344340994
Control12=IDC_ADD_START_MONTH,combobox,1344339970
Control13=IDC_STATIC,static,1342308864
Control14=IDC_ADD_END_DAY,combobox,1344339970
Control15=IDC_ADD_END_FIRSTLAST,combobox,1344339970
Control16=IDC_ADD_END_MONTH,combobox,1344339970
Control17=IDC_STATIC,static,1342308864
Control18=IDC_STATIC,static,1342308864
Control19=IDC_CHECK1,button,1342242851

[DLG:IDD_ADD_DISPLAY]
Type=1
Class=CAddDisplay
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ADD_DISPLAY_LIST,listbox,1352728833
Control4=ID_DETAILS,button,1342242817

[DLG:IDD_DELETE]
Type=1
Class=CDelete
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ADD_DISPLAY_LIST,listbox,1352728833
Control4=ID_DETAILS,button,1342242817

[DLG:IDD_FEATURES]
Type=1
Class=CFeatures

[DLG:IDD_HOME]
Type=1
Class=CHome
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308864

[DLG:IDD_MODIFY]
Type=1
Class=CModify
ControlCount=20
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_SLIDER1,msctls_trackbar32,1342242820
Control6=IDC_STATIC,button,1342177287
Control7=IDC_ADD_HOURS,static,1342308865
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342179331
Control10=IDC_ADD_START_DAY,combobox,1344339970
Control11=IDC_ADD_START_FIRSTLAST,combobox,1344340994
Control12=IDC_ADD_START_MONTH,combobox,1344339970
Control13=IDC_STATIC,static,1342308864
Control14=IDC_ADD_END_DAY,combobox,1344339970
Control15=IDC_ADD_END_FIRSTLAST,combobox,1344339970
Control16=IDC_ADD_END_MONTH,combobox,1344339970
Control17=IDC_STATIC,static,1342308864
Control18=IDC_STATIC,static,1342308864
Control19=IDC_CHECK1,button,1342242851
Control20=IDC_MODIFY_LIST,listbox,1352728833

[DLG:IDD_Preferences]
Type=1
Class=CPreferences
ControlCount=13
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
Command6=ID_FILE_PREFERENCES
Command7=ID_HELP_FUTURE
Command8=ID_APP_ABOUT
Command9=ID_BUTTON32782
CommandCount=9

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
Command8=ID_APP_EXIT
Command9=ID_SHOW_TOOLBAR
Command10=ID_SHOW_STATUS_BAR
Command11=ID_HELP_CONTENTS
Command12=ID_HELP_FUTURE
Command13=ID_REGISTER
Command14=ID_APP_ABOUT
CommandCount=14

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_ADD
Command2=ID_EDIT_COPY
Command3=ID_FILE_ADDTODISPLAY
Command4=ID_FILE_DELETE
Command5=ID_FILE_HOME
Command6=ID_FILE_MODIFY
Command7=ID_FILE_ALARMRESET
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_HELP_CONTENTS
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_APP_EXIT
Command17=ID_EDIT_CUT
Command18=ID_EDIT_UNDO
CommandCount=18

[MNU:IDR_CONTEXT]
Type=1
Class=?
CommandCount=0

[DLG:IDD_ALARM]
Type=1
Class=CAlarm
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_HOUR,edit,1350631552
Control4=IDC_MINUTE,edit,1350631552
Control5=IDC_ENABLE,button,1342242819
Control6=IDC_STATIC,static,1342308865
Control7=IDC_STATIC,static,1342308864
Control8=IDC_STATIC,static,1342308864
Control9=IDC_LOCATION,static,1342308864

[CLS:CAlarm]
Type=0
HeaderFile=Alarm.h
ImplementationFile=Alarm.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAlarm

[DLG:IDD_REGISTER]
Type=1
Class=CRegister
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_REGISTER_NAME,edit,1350631552
Control4=IDC_STATIC,static,1342308864
Control5=IDC_REGISTER_KEY,edit,1350631552
Control6=IDC_STATIC,static,1342308864

[CLS:CRegister]
Type=0
HeaderFile=Register.h
ImplementationFile=Register.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CRegister

