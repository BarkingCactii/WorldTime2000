; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWorldTime2000View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WorldTime2000.h"
LastPage=0

ClassCount=8
Class1=CWorldTime2000App
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class2=CWorldTime2000View
Resource3=IDD_ADD
Resource4=IDD_FEATURES (English (U.S.))
Class5=CHome
Resource5=IDD_ABOUTBOX (English (U.S.))
Class6=CAdd
Resource6=IDR_MAINFRAME (English (U.S.))
Class7=CFeatures
Resource7=IDD_HOME
Class8=CAddDisplay
Resource8=IDD_ADD_DISPLAY

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
LastObject=IDC_HOME_LIST
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
Command4=ID_APP_ABOUT
Command5=ID_HELP_FUTURE
CommandCount=5

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_HOME
Command2=ID_FILE_ADD
Command3=ID_FILE_ADDTODISPLAY
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_HELP_FINDER
Command8=ID_APP_ABOUT
Command9=ID_HELP_FUTURE
CommandCount=9

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
Control1=IDC_STATIC,static,1342179331
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_HOME]
Type=1
Class=CHome
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_HOME_LIST,listbox,1352728833

[CLS:CHome]
Type=0
HeaderFile=Home.h
ImplementationFile=Home.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_HOME_LIST
VirtualFilter=dWC

[DLG:IDD_ADD]
Type=1
Class=CAdd
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_SLIDER1,msctls_trackbar32,1342242820
Control6=IDC_STATIC,button,1342177287
Control7=IDC_ADD_HOURS,static,1342308864

[CLS:CAdd]
Type=0
HeaderFile=Add.h
ImplementationFile=Add.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_ADD_HOURS

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
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ADD_DISPLAY_LIST,listbox,1352728833

[CLS:CAddDisplay]
Type=0
HeaderFile=AddDisplay.h
ImplementationFile=AddDisplay.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

