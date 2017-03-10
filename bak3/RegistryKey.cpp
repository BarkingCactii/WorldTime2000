#include "stdafx.h"
#include <io.h>
#include <sys\stat.h>
#include <afxinet.h>
#include "RegistryKey.h"
#include <strstream>

//
//  Cleanup is necessary when the class object points to a new physical key or destructs
//

void CRegistryKey::Close ( void )
{
    if ( m_validHandle )
    {
        RegCloseKey ( m_userDefinedHandle );
    }
}


bool CRegistryKey::SetValue ( const char * val, DWORD dwType, void * data )
{
    if ( m_validHandle == FALSE )
        return false;
    
    int dwSize = 0;
    if ( dwType == REG_DWORD )
        dwSize = sizeof ( DWORD );
    else
    if ( dwType == REG_SZ )
        dwSize = strlen (( char * ) data );
    else
        return false;

    if (( m_error = RegSetValueEx ( m_userDefinedHandle, val, 0, dwType, ( CONST BYTE * ) data, dwSize )) != ERROR_SUCCESS )
    {
        return false;
    }

    return true;
}
  

CRegistryKey::CRegistryKey ( HKEY predefinedKey, LPTSTR machineName )
{
    Connect ( predefinedKey, machineName );
}


bool CRegistryKey::Connect ( HKEY preDefinedHandle, string subKeyName, bool create, LPTSTR machineName, bool restorePrivilage )
{
    if ( preDefinedHandle == NULL )
        // no handle defined
        return FALSE;

    if ( m_validHandle == TRUE )
        // this object is already connected to a key, so abort
        return FALSE;

    m_preDefinedHandle = preDefinedHandle;
    m_subKeyName = subKeyName;

    // you cannot specify HKEY_CLASSES_ROOT or HKEY_CURRENT_USER for a remote registry
    // so lets check what to call now

    DWORD dwDisposition = 0;
    // changed this specifically for the control panel app
    if (( m_error =  RegOpenKeyEx ( m_preDefinedHandle, m_subKeyName.c_str(), 0, KEY_READ | KEY_SET_VALUE, &m_userDefinedHandle )) != ERROR_SUCCESS )
    {
        // failed to open, so if flagged for creation, do that
        if ( create == TRUE )
        {
            dwDisposition = 0;

            if (( m_error = RegCreateKeyEx( m_preDefinedHandle, m_subKeyName.c_str(), 0,"REG_SZ", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, &m_userDefinedHandle, &dwDisposition)) != ERROR_SUCCESS )
            {
                m_validHandle = FALSE;
            }
            else
            {
                if ( restorePrivilage == TRUE )
                {
                    RegCloseKey ( m_userDefinedHandle );
                    if (( m_error = RegCreateKeyEx( m_preDefinedHandle, m_subKeyName.c_str(), 0,"REG_SZ", REG_OPTION_BACKUP_RESTORE | REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, &m_userDefinedHandle, &dwDisposition)) != ERROR_SUCCESS )
                    {
                        m_validHandle = FALSE;
                        return FALSE;
                    }
                }

                m_validHandle = TRUE;
            }
        }
    }
    else
    {
        m_validHandle = TRUE;
    }
    return m_validHandle;
}


CRegistryKey::~CRegistryKey ( void )
{
    Close ();
}


bool CRegistryKey::Enum ( int idx )
{
    DWORD lpcbName, lpcbClass;
    FILETIME lpftLastWriteTime;

    LONG result = RegEnumKeyEx(
                    m_userDefinedHandle,                    // handle to key to enumerate
                    idx,                                    // index of subkey to enumerate
                    ( LPTSTR )(( LPCTSTR ) m_subKeyName.c_str() ),  // address of buffer for subkey name
                    &lpcbName,                              // address for size of subkey buffer
                    NULL,                                   // reserved
                    ( LPTSTR )( LPCTSTR ) m_className.c_str(),      // address of buffer for class string
                    &lpcbClass,                             // address for size of class buffer
                    &lpftLastWriteTime                      // address for time key last written to
                    );

    if ( result != ERROR_SUCCESS )
        return FALSE;

    return TRUE;
} 

bool CRegistryKey::QueryValue ( const char * keyName )
{
    if ( !keyName || keyName == "" )
        return false;

    DWORD bufLen = sizeof ( m_data );

    memset ( m_data, 0, sizeof ( m_data ));
    if (( m_error = RegQueryValueEx ( m_userDefinedHandle, keyName, NULL, &m_type, &m_data[0], &bufLen )) != ERROR_SUCCESS )
        return false;

    return true;
}

