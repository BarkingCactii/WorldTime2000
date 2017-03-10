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
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

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
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc09 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "WorldTime2000 - Win32 Release"
# Name "WorldTime2000 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\about.cpp
# End Source File
# Begin Source File

SOURCE=.\Add.cpp
# End Source File
# Begin Source File

SOURCE=.\AddDisplay.cpp
# End Source File
# Begin Source File

SOURCE=.\Bstream.cpp
# End Source File
# Begin Source File

SOURCE=.\delete.cpp
# End Source File
# Begin Source File

SOURCE=.\Features.cpp
# End Source File
# Begin Source File

SOURCE=.\help.cpp
# End Source File
# Begin Source File

SOURCE=.\Home.cpp
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

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Str.cpp
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

SOURCE=.\about.h
# End Source File
# Begin Source File

SOURCE=.\Add.h
# End Source File
# Begin Source File

SOURCE=.\AddDisplay.h
# End Source File
# Begin Source File

SOURCE=.\Bstream.h
# End Source File
# Begin Source File

SOURCE=.\delete.h
# End Source File
# Begin Source File

SOURCE=.\Features.h
# End Source File
# Begin Source File

SOURCE=.\help.h
# End Source File
# Begin Source File

SOURCE=.\Home.h
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

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Str.h
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

SOURCE=.\res\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\13.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\14.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\15.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\17.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\18.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\19.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\20.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\21.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\22.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\23.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\24.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\a.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim10.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim11.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim12.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim13.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim14.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim15.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim16.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim17.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim19.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim20.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim21.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim22.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim23.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim24.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim25.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim3.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim4.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim5.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim6.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim7.ico
# End Source File
# Begin Source File

SOURCE=.\res\anim8.ico
# End Source File
# Begin Source File

SOURCE=.\res\b.ico
# End Source File
# Begin Source File

SOURCE=.\res\ani\background.BMP
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\bitmap25.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\bmp00005.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Earth.ico
# End Source File
# Begin Source File

SOURCE=.\res\ani\file_add.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ani\file_mod.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sphere\frame1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00002.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00003.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00004.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00005.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon10.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon11.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon12.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon13.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon14.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon15.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon16.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon17.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon18.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon19.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon3.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon4.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon5.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon6.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon7.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon8.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon9.ico
# End Source File
# Begin Source File

SOURCE=.\res\sun.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
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
# Begin Group "Help Files"

# PROP Default_Filter "cnt;rtf"
# Begin Source File

SOURCE=.\hlp\AfxCore.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AppExit.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw2.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw4.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurHelp.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCopy.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCut.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditPast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditUndo.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileNew.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileOpen.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FilePrnt.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileSave.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpSBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpTBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecFirst.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecLast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecNext.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecPrev.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmax.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\ScMenu.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmin.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\WorldTime2000.cnt

!IF  "$(CFG)" == "WorldTime2000 - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Release
InputPath=.\hlp\WorldTime2000.cnt
InputName=WorldTime2000

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ELSEIF  "$(CFG)" == "WorldTime2000 - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Debug
InputPath=.\hlp\WorldTime2000.cnt
InputName=WorldTime2000

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\about.htm
# End Source File
# Begin Source File

SOURCE=".\res\BetaNews_Com - Inside Information On Products Not Yet Released.htm"
# End Source File
# Begin Source File

SOURCE=.\res\Desssden.htm
# End Source File
# Begin Source File

SOURCE=".\res\eXTReMe Tracking.htm"
# End Source File
# Begin Source File

SOURCE=.\features.htm
# End Source File
# Begin Source File

SOURCE=.\help.htm
# End Source File
# Begin Source File

SOURCE=.\history.htm
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\res\worldtime.htm
# End Source File
# End Target
# End Project
