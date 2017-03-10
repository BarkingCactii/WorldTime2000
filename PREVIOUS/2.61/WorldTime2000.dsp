# Microsoft Developer Studio Project File - Name="WorldTime2000" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=WorldTime2000 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WorldTime2000.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WorldTime2000.mak" CFG="WorldTime2000 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WorldTime2000 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "WorldTime2000 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WorldTime2000 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 winmm.lib dsound.lib htmlhelp.lib /nologo /subsystem:windows /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=.\build.exe
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WorldTime2000 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc09 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib dsound.lib htmlhelp.lib /nologo /subsystem:windows /profile /debug /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=.\build.exe
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "WorldTime2000 - Win32 Release"
# Name "WorldTime2000 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Add.cpp
# End Source File
# Begin Source File

SOURCE=.\AddDisplay.cpp
# End Source File
# Begin Source File

SOURCE=.\Alarm.cpp
# End Source File
# Begin Source File

SOURCE=.\Bitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\Bstream.cpp
# End Source File
# Begin Source File

SOURCE=.\delete.cpp
# End Source File
# Begin Source File

SOURCE=.\Home.cpp
# End Source File
# Begin Source File

SOURCE=.\Legend.cpp
# End Source File
# Begin Source File

SOURCE=.\List.cpp
# End Source File
# Begin Source File

SOURCE=.\location.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\modify.cpp
# End Source File
# Begin Source File

SOURCE=.\Preferences.cpp
# End Source File
# Begin Source File

SOURCE=.\sounds.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Str.cpp
# End Source File
# Begin Source File

SOURCE=.\TRAYICON.CPP
# End Source File
# Begin Source File

SOURCE=.\whatif.cpp
# End Source File
# Begin Source File

SOURCE=.\WorldTime2000.cpp
# End Source File
# Begin Source File

SOURCE=.\WorldTime2000.rc
# End Source File
# Begin Source File

SOURCE=.\WorldTime2000View.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Add.h
# End Source File
# Begin Source File

SOURCE=.\AddDisplay.h
# End Source File
# Begin Source File

SOURCE=.\Alarm.h
# End Source File
# Begin Source File

SOURCE=.\Bitmap.h
# End Source File
# Begin Source File

SOURCE=.\Bstream.h
# End Source File
# Begin Source File

SOURCE=.\delete.h
# End Source File
# Begin Source File

SOURCE=.\Home.h
# End Source File
# Begin Source File

SOURCE=.\Legend.h
# End Source File
# Begin Source File

SOURCE=.\List.h
# End Source File
# Begin Source File

SOURCE=.\location.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\modify.h
# End Source File
# Begin Source File

SOURCE=.\Preferences.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h

!IF  "$(CFG)" == "WorldTime2000 - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=WorldTime2000
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "WorldTime2000 - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=WorldTime2000
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sounds.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Str.h
# End Source File
# Begin Source File

SOURCE=.\TRAYICON.H
# End Source File
# Begin Source File

SOURCE=.\whatif.h
# End Source File
# Begin Source File

SOURCE=.\WorldTime2000.h
# End Source File
# Begin Source File

SOURCE=.\WorldTime2000View.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\add.ico
# End Source File
# Begin Source File

SOURCE=.\res\alarm.ico
# End Source File
# Begin Source File

SOURCE=.\res\alarmoff.ico
# End Source File
# Begin Source File

SOURCE=.\res\b.ico
# End Source File
# Begin Source File

SOURCE=.\res\B8.ico
# End Source File
# Begin Source File

SOURCE=.\htm\backgroud.gif
# End Source File
# Begin Source File

SOURCE=.\res\ani\background.BMP
# End Source File
# Begin Source File

SOURCE=.\htm\background.gif
# End Source File
# Begin Source File

SOURCE=.\htm\background.jpg
# End Source File
# Begin Source File

SOURCE=.\res\baseicon.ico
# End Source File
# Begin Source File

SOURCE=.\res\Book.ico
# End Source File
# Begin Source File

SOURCE=.\res\clock.ico
# End Source File
# Begin Source File

SOURCE=.\res\delete.ico
# End Source File
# Begin Source File

SOURCE=.\res\doc.ico
# End Source File
# Begin Source File

SOURCE=.\res\docs.ico
# End Source File
# Begin Source File

SOURCE=.\res\dstoff.ico
# End Source File
# Begin Source File

SOURCE=.\res\dston.ico
# End Source File
# Begin Source File

SOURCE=.\res\dston1.ico
# End Source File
# Begin Source File

SOURCE=.\res\dston2.ico
# End Source File
# Begin Source File

SOURCE=.\res\dston3.ico
# End Source File
# Begin Source File

SOURCE=.\res\Earth.ico
# End Source File
# Begin Source File

SOURCE=.\res\ani\file_add.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\file_ala.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\file_mod.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\home.ico
# End Source File
# Begin Source File

SOURCE=.\res\homelocation.ico
# End Source File
# Begin Source File

SOURCE=.\res\idr_main.ico
# End Source File
# Begin Source File

SOURCE=.\res\modify.ico
# End Source File
# Begin Source File

SOURCE=.\res\pencil.ico
# End Source File
# Begin Source File

SOURCE=.\res\Planet.ico
# End Source File
# Begin Source File

SOURCE=.\RES\preferen.ico
# End Source File
# Begin Source File

SOURCE=.\res\preferences.ico
# End Source File
# Begin Source File

SOURCE=.\res\Reach.ico
# End Source File
# Begin Source File

SOURCE=.\res\ref.ico
# End Source File
# Begin Source File

SOURCE=.\res\Sandstone.bmp
# End Source File
# Begin Source File

SOURCE=.\htm\snap.gif
# End Source File
# Begin Source File

SOURCE=.\snap.gif
# End Source File
# Begin Source File

SOURCE=.\htm\SNAP2.GIF
# End Source File
# Begin Source File

SOURCE=.\snap2.gif
# End Source File
# Begin Source File

SOURCE=.\res\stop.ico
# End Source File
# Begin Source File

SOURCE=.\res\sun.ico
# End Source File
# Begin Source File

SOURCE=.\res\toaster.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar_cold.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar_hot.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tray.ico
# End Source File
# Begin Source File

SOURCE=.\htm\tray1.gif
# End Source File
# Begin Source File

SOURCE=.\tray1.gif
# End Source File
# Begin Source File

SOURCE=.\htm\TRAY2.GIF
# End Source File
# Begin Source File

SOURCE=.\tray2.gif
# End Source File
# Begin Source File

SOURCE=.\RES\whatif.ico
# End Source File
# Begin Source File

SOURCE=.\res\world3.ico
# End Source File
# Begin Source File

SOURCE=.\res\worldtime.gif
# End Source File
# Begin Source File

SOURCE=.\worldtime.gif
# End Source File
# Begin Source File

SOURCE=.\res\worldtime.JPG
# End Source File
# Begin Source File

SOURCE=.\worldtime.jpg
# End Source File
# Begin Source File

SOURCE=.\res\WorldTime2000.ico
# End Source File
# Begin Source File

SOURCE=.\res\WorldTime2000.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
