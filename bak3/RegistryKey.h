#ifndef _REGISTRYKEY_H
#define _REGISTRYKEY_H

#include <string>
using namespace std;


/*       

  Registry key access functionality

1. Read key
2. Modify key
3. Search
4. Traverse

  Testing
5. Create

Predefined keys ( these keys are always open )

HKEY_LOCAL_MACHINE
HKEY_USERS
HKEY_CLASSES_ROOT
HKEY_CURRENT_USER

*/

#define MAX_KEYSZ 255

class CRegistryKey
{

private:

    HKEY m_preDefinedHandle;
    HKEY m_userDefinedHandle;
    bool m_validHandle;       // once a valid handle has been obtained, lock all key request functionality
    string  m_subKeyName;
    string  m_className;
    string  m_fileName;       // filename given when saved to disk
    string  m_errorText;      // if an error occurs, the message text is stored here

    DWORD   m_type;           // what type of value this key stores ( if any )
    BYTE    m_data[MAX_KEYSZ];// the actual data associated with this key ( if any )
    LONG    m_error;          // error code returned by last registry api function
public:
    // use the handle from an existing instance of CRegistryKey as an argument for an external function
    operator HKEY () { return m_userDefinedHandle; }

    // traverse the list according to idx
    bool Enum ( int idx );

    string & SubKeyName ( void ) { return m_subKeyName; }
    string & ClassName ( void ) { return m_className; }

    //  Get the value for the specified key
    bool QueryValue ( const char * keyName );
    DWORD   GetValueType ( void ) { return m_type; }
    BYTE *  GetValue ( void ) { return m_data; }
    bool SetValue ( const char * val, DWORD, void * );
    LONG    GetError ( void ) { return m_error; }

    // connect this object to a physical key in the registry
    // only one connection is allowed to ensure integrity when keys are restored from file
    // and to ensure saved keys are not lost
    bool Connect ( HKEY predefinedKey, string subKeyName, bool create = FALSE, LPTSTR machineName = NULL, bool restorePrivilage = FALSE );

    // close the key and release resources if handle valid, public for testing only
    void Close ( void );


    CRegistryKey ( void ) { m_validHandle = FALSE; }
    // connect to the registry of local or remote machine. Local is NULL
    CRegistryKey ( HKEY predefinedKey, LPTSTR machineName = NULL );
   ~CRegistryKey ( void );
};

#endif