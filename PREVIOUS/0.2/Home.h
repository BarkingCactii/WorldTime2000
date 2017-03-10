#if !defined(AFX_HOME_H__48875361_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_)
#define AFX_HOME_H__48875361_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Home.h : header file
//

#include "bstream.h"
#include "worldtime2000view.h"

struct LocationItem
{
        String	name;
        short	offset;
};

class Locations
{
private:
        LinkedList<LocationItem *> l;
        LinkedList<short *> d;

        short version;

public:
        int Size ( void ) { return l.Size(); }

        char * NameList ( int idx ) { if ( idx < l.Size()) return l.Nth ( idx )->name; else return ""; }
        int OffsetList ( int idx ) { if ( idx < l.Size()) return l.Nth ( idx )->offset; else return 0; }

        short OffsetDisplay ( int idx ) { if ( idx < d.Size()) return *d.Nth ( idx ); else return 0; }

        short selected; //Location;
		String homeName;
        short _24hour;

	 	void ResetOffset ( void )
		{
			view->selected = 0;
//	 		view->offset = OffsetList ( currentLocation );
		}

        LocationItem * GetCurrent ( void )
        {
	        return l.Nth ( selected );
        }

        LocationItem * GetLocation ( int idx )
        {
	        return l.Nth ( idx );
        }

        void Delete ( int idx )
        {
//            l.Delete ( l.Nth ( idx ));

			short * aItem;
			aItem = d.Nth ( idx );
			if ( aItem )
				d.Delete ( aItem );
			/*
            short * aItem;
            for ( int i = 0; aItem = d.Nth ( i ); i++ )
            {
                    if ( *aItem == idx )
                    {
                            d.Delete ( aItem );
                    }
            }
			*/
        }

        short * Get ( int idx ) { return d.Nth ( idx ); }

        void Add ( LocationItem * aItem )
        {
                l.Add ( aItem );
        }

        void AddDisplay ( short whatLocation )
        {
	        short * aItem;
/*
			if ( whatLocation == selected )
			{
            MessageBox ( NULL, "This location is already set as the Home/Reference location", NULL, MB_ICONEXCLAMATION );
			return;
		}*/
             for ( int i = 0; aItem = d.Nth ( i ); i++ )
             {
                     if ( *aItem == whatLocation )
                     {
                             MessageBox ( NULL, "This location is already being displayed", NULL, MB_ICONEXCLAMATION );
                             return;
                     }
             }

             aItem = new short ( whatLocation );
             d.Add ( aItem );
        }

        Locations ( void )
        {
                version = 1;
                selected = 0;
				homeName = "Home";
                    _24hour = 0;
//#define CREATENEW
#ifndef CREATENEW
                bifstream bin ( "WorldTime2000.dat" );

                short	numLocations;
                bin >> version >> selected >> numLocations >> homeName >> _24hour;

                for ( int i = 0; i < numLocations; i++ )
                {
                        LocationItem * aItem = new LocationItem;
                        bin >> aItem->name >> aItem->offset;
                        l.Add ( aItem );
                }

                short numDisplays;

                bin >> numDisplays;
                for ( i = 0; i < numDisplays; i++ )
                {
                        short * aItem = new short;
                        bin >> *aItem;
                        d.Add ( aItem );
                }

                bin.close ();
#else
                                ifstream fin ( "default.dat" );
                                while ( !fin.eof() )
                                {
                                        char buf[255];
                                        fin.getline ( buf, sizeof ( buf ));

                                        if ( strlen ( buf ) == 0)
                                                break;

                                        buf[24] = 0;
                    LocationItem * aItem = new LocationItem;
                                        sscanf ( &buf[25], "%d", &aItem->offset );

                                        aItem->name = buf;
                                        l.Add ( aItem );
                                }
                                fin.close ();
#endif
        }

       ~Locations ( void )
        {
                bofstream bout ( "WorldTime2000.dat" );

                bout << version << selected << ( short ) l.Size() << homeName << _24hour;

                for ( int i = 0; i < l.Size(); i++ )
                {
                        LocationItem * aItem = l.Nth ( i );
                        bout << aItem->name << aItem->offset;
                }

                bout << ( short ) d.Size();
                for ( i = 0; i < d.Size(); i++ )
                {
                        short * aItem = d.Nth ( i );
                        bout << *aItem;
                }

                bout.close();
        }
};

extern Locations locations;



/////////////////////////////////////////////////////////////////////////////
// CHome dialog

class CHome : public CDialog
{
        // Construction
public:
        CHome(CWnd* pParent = NULL);   // standard constructor

        // Dialog Data
        //{{AFX_DATA(CHome)
	enum { IDD = IDD_HOME };
	CEdit	m_name;
	//}}AFX_DATA


        // Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CHome)
protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

        // Implementation
protected:

        // Generated message map functions
        //{{AFX_MSG(CHome)
        afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
        virtual BOOL OnInitDialog();
        virtual void OnOK();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.





#endif // !defined(AFX_HOME_H__48875361_DF7D_11D2_B3FD_0080C8C277AA__INCLUDED_)
