#ifndef _LOCATION_H
#define _LOCATION_H

#include "bstream.h"
//#include "worldtime2000view.h"
#include "preferences.h"


class LocationItem
{
        friend bifstream & operator >> ( bifstream & fin,  LocationItem & data );
        friend bofstream & operator << ( bofstream & fout, LocationItem & data );

public:
    String	name;
        float	offset;

        short	dsEnable;

        short	dsStartWeek;
        short	dsStartDay;
        short	dsStartMonth;

        short	dsEndWeek;
        short	dsEndDay;
        short	dsEndMonth;
};



class Locations
{
private:
        LinkedList<LocationItem *> ll;
        LinkedList<short *> d;

        short version;

public:
		Preferences p;
		CRect frameRect;

        int Size ( void ) { return ll.Size(); }

        char * NameList ( int idx ) { if ( idx < ll.Size()) return ll.Nth ( idx )->name; else return ""; }
        float GMTOffset ( int idx );
        float OffsetList ( int idx );
        short OffsetDisplay ( int idx ) { if ( idx < d.Size()) return *d.Nth ( idx ); else return 0; }

        short selected; //Location;
                String homeName;
//        short _24hour;

                void ResetOffset ( void );

        LocationItem * GetCurrent ( void )
        {
                return ll.Nth ( selected );
        }

        LocationItem * GetLocation ( int idx )
        {
                return ll.Nth ( idx );
        }

		void DeleteList ( int idx )
		{
			LocationItem * li;
			li = ll.Nth ( idx );
			if ( li )
				ll.Delete ( li );

			// if its in the display list, then delete it too
            short * aItem;

			for ( int i = 0; i < d.Size(); i++ )
			{
				aItem = d.Nth ( i );
				if ( aItem )
				{
					if ( *aItem == idx )
						d.Delete ( aItem );
				}
			}
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
                ll.Add ( aItem );
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

        Locations ( void );

       ~Locations ( void );
};

extern Locations l;

class List
{
public:
	int index;
	char * name;
};

extern List dayList[];
extern List weekList[];
extern List monthList[];

#endif
