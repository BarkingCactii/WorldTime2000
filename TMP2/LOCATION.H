#ifndef _LOCATION_H
#define _LOCATION_H

#include "bstream.h"
//#include "worldtime2000view.h"
#include "preferences.h"

//#define CREATENEW


#define REGISTERED	0x60
#define EXPIRED		0x61
#define RESET		0x62

#define VERSION 1.42f

class LocationItem
{
     friend bifstream & operator >> ( bifstream & fin,  LocationItem & data );
     friend bofstream & operator << ( bofstream & fout, LocationItem & data );
     
public:
//     String	name;
     short     tag;

     String	country;
     String	city;
     float	offset;
     
     short	dsEnable;
     
     short	dsStartWeek;
     short	dsStartDay;
     short	dsStartMonth;
     
     short	dsEndWeek;
     short	dsEndDay;
     short	dsEndMonth;

     // alarm info
     short  alarmEnable;
     short  alarmHour;
     short  alarmMinute;
	 String	alarmMessage;

	 LocationItem ( void )
	 {
		 country = city = "";
		 offset = 0.0f;

		 dsEnable = 0;

		 alarmEnable = 0;
		 alarmHour = 0;
		 alarmMinute = 0;
		 alarmMessage = "";
	 }
};



class Locations
{
private:
     LinkedList<LocationItem *> ll;
     LinkedList<short *> d;
     
     float version;
	 LocationItem home;
     
public:
     short     lastTag;
     Preferences p;
     CRect frameRect;
	 String registeredName;
	 String registeredCRC;
//	 ulong registeredCRC;

	 short terminatingDay;
	 short terminatingMonth;

	String fontName;
	short  fontSize;
	short fontItalic;
	short fontBold;

//	short imageOn;
//	String imageName;

     float Version ( void ) { return version; }

     int Size ( void ) { return ll.Size(); }
	 int SizeDisplay ( void ) { return d.Size(); }

     void Move ( int from, int to ) { d.Move (from, to ); }

     short Tag ( int idx ) { if ( idx < ll.Size()) return ll.Nth ( idx )->tag; else return -1; }
     char * CountryList ( int idx ) { if ( idx < ll.Size()) return ll.Nth ( idx )->country; else return ""; }
     char * CityList ( int idx ) { if ( idx < ll.Size()) return ll.Nth ( idx )->city; else return ""; }
//     char * NameList ( int idx ) { if ( idx < ll.Size()) return ll.Nth ( idx )->name; else return ""; }
     float GMTOffset ( int idx );
     float OffsetList ( int idx );
     short OffsetDisplay ( int idx );
     
//     short selected; //Location;
//     String homeName;
     //        short _24hour;
     
     void ResetOffset ( void );
     							/*
     LocationItem * GetCurrent ( void )
     {
          return ll.Nth ( view->selected );
//          return ll.Nth ( selected );
     }
     							  */
     LocationItem * GetLocationbyTag ( int tag )
     {
          int  size = ll.Size ();

          for ( int i = 0; i < size; i++ )
          {
               LocationItem * li;
               li = ll.Nth ( tag );
               if ( li )
               {
                    if ( li->tag == tag )
                         return li;
               }
          }
          return 0;

     }

     LocationItem * GetLocation ( int idx )
     {
          return ll.Nth ( idx );
     }
     
	 LocationItem * GetHome ( void ) { return &home; }

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
