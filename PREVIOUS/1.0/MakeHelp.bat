@echo off
goto :done

REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by WORLDTIME2000.HPJ. >"hlp\WorldTime2000.hm"
echo. >>"hlp\WorldTime2000.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\WorldTime2000.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\WorldTime2000.hm"
echo. >>"hlp\WorldTime2000.hm"
echo // Prompts (IDP_*) >>"hlp\WorldTime2000.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\WorldTime2000.hm"
echo. >>"hlp\WorldTime2000.hm"
echo // Resources (IDR_*) >>"hlp\WorldTime2000.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\WorldTime2000.hm"
echo. >>"hlp\WorldTime2000.hm"
echo // Dialogs (IDD_*) >>"hlp\WorldTime2000.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\WorldTime2000.hm"
echo. >>"hlp\WorldTime2000.hm"
echo // Frame Controls (IDW_*) >>"hlp\WorldTime2000.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\WorldTime2000.hm"
REM -- Make help for Project WORLDTIME2000


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\WorldTime2000.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\WorldTime2000.hlp" goto :Error
if not exist "hlp\WorldTime2000.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\WorldTime2000.hlp" Debug
if exist Debug\nul copy "hlp\WorldTime2000.cnt" Debug
if exist Release\nul copy "hlp\WorldTime2000.hlp" Release
if exist Release\nul copy "hlp\WorldTime2000.cnt" Release
echo.
goto :done

:Error
echo hlp\WorldTime2000.hpj(1) : error: Problem encountered creating help file

:done
echo.
