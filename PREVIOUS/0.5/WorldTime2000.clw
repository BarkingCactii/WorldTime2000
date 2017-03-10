; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAddDisplay
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WorldTime2000.h"
LastPage=0

ClassCount=10
Class1=CWorldTime2000App
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=10
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class2=CWorldTime2000View
Resource3=IDD_ABOUTBOX (English (U.S.))
Resource4=IDD_Preferences
Class5=CHome
Resource5=IDD_FEATURES (English (U.S.))
Class6=CAdd
Resource6=IDD_ADD_DISPLAY
Class7=CFeatures
Resource7=IDR_MAINFRAME (English (U.S.))
Class8=CAddDisplay
Resource8=IDD_ADD_LOCATION
Class9=CPreferences
Resource9=IDD_HOME
Class10=CDetails
Resource10=IDD_DETAILS

[CLS:CWorldTime2000App]
Type=0
HeaderFile=WorldTime2000.h
ImplementationFile=WorldTime2000.cpp
Filter=N

[CLS:CWorldTime2000View]
Type=0
HeaderFile=WorldTime2000View.h
ImplementationFile=WorldTime2000View.cpp
Filter=N
LastObject=CWorldTime2000View

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_FILE_PREFERENCES
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=WorldTime2000.cpp
ImplementationFile=WorldTime2000.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_HELP_FINDER
Command14=ID_APP_ABOUT
CommandCount=14
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=15
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE
Command14=ID_CONTEXT_HELP
Command15=ID_HELP


[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_ADDTODISPLAY
Command2=ID_FILE_HOME
Command3=ID_FILE_ADD
Command4=ID_HELP_FUTURE
Command5=ID_FILE_PREFERENCES
Command6=ID_APP_ABOUT
CommandCount=6

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_HOME
Command2=ID_FILE_ADD
Command3=ID_FILE_ADDTODISPLAY
Command4=ID_FILE_PREFERENCES
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_HELP_FINDER
Command9=ID_APP_ABOUT
Command10=ID_HELP_FUTURE
CommandCount=10

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_EDIT_PASTE
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_CUT
Command10=ID_EDIT_UNDO
Command11=ID_CONTEXT_HELP
Command12=ID_HELP
CommandCount=12

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342179331

[DLG:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_HOME]
Type=1
Class=CHome
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308864

[CLS:CHome]
Type=0
HeaderFile=Home.h
ImplementationFile=Home.cpp
BaseClass=CDialog
Filter=D
LastObject=CHome
VirtualFilter=dWC

[CLS:CAdd]
Type=0
HeaderFile=Add.h
ImplementationFile=Add.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAdd

[DLG:IDD_FEATURES (English (U.S.))]
Type=1
Class=CFeatures
ControlCount=2
Control1=65535,static,1342308352
Control2=IDOK,button,1342373889

[CLS:CFeatures]
Type=0
HeaderFile=Features.h
ImplementationFile=Features.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_ADD_DISPLAY]
Type=1
Class=CAddDisplay
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ADD_DISPLAY_LIST,listbox,1352728833
Control4=ID_DETAILS,button,1342242817

[CLS:CAddDisplay]
Type=0
HeaderFile=AddDisplay.h
ImplementationFile=AddDisplay.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_DETAILS

[DLG:IDD_Preferences]
Type=1
Class=CPreferences
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CHECK1,button,1342242819
Control4=IDC_CHECK2,button,1342242819

[CLS:CPreferences]
Type=0
HeaderFile=Preferences.h
ImplementationFile=Preferences.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPreferences

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

[DLG:IDD_DETAILS]
Type=1
Class=CDetails
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_DETAILS1,static,1342308864
Control4=IDC_DETAILS2,static,1342308864
Control5=IDC_DETAILS3,static,1342308864
Control6=IDC_DETAILS4,static,1342308864
Control7=IDC_DETAILS5,static,1342308864

[CLS:CDetails]
Type=0
HeaderFile=Details.h
ImplementationFile=Details.cpp
BaseClass=CDialog
Filter=D
LastObject=CDetails
VirtualFilter=dWC

