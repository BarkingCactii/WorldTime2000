#ifndef _Display_H
#define _Display_H

#include "bstream.h"
//#include "worldtime2000view.h"
#include "preferences.h"


//#define CREATENEW


#define REGISTERED	0x60
#define EXPIRED		0x61
#define RESET		0x62

#define VERSION 2.50f; //1.42f

class DisplayItem
{
     friend bifstream & operator >> ( bifstream & fin,  DisplayItem & data );
     friend bofstream & operator << ( bofstream & fout, DisplayItem & data );
     
     bool location;
public:
    int NumAlarms ( void ) { return 0; } // STUB
     short     tag;

     string label;
/*
     string	country;
     string	city;
     float	offset;
     short     countryCode;
     short     areaCode;
     
     short	dsEnable;
     
     short	dsStartWeek;
     short	dsStartDay;
     short	dsStartMonth;
     
     short	dsEndWeek;
     short	dsEndDay;
     short	dsEndMonth;
*/
     // alarm info
     short  alarmEnable;
     short  alarmHour;
     short  alarmMinute;
     string alarmMessage;
     string alarmRunApp;
     short alarmRunEnable;

     string & Label ( void ) { return label; }

     bool Location ( void ) { return location; }

	 DisplayItem ( void )
	 {

         tag = 0;
/*		 country = city = "";
		 offset = 0.0f;
           countryCode = 1;
           areaCode = 0;

		 dsEnable = 0;
 */
		 alarmEnable = 0;
		 alarmHour = 0;
		 alarmMinute = 0;
		 alarmMessage = "";
           alarmRunApp = "";
           alarmRunEnable = 0;

           label = "<none set>";
           location = true;

	 }
};



class Display
{
private:                    
     LinkedList<DisplayItem *> ll;
     LinkedList<short *> d;
     
     float version;
//	 DisplayItem home;
    DisplayItem home;     
public:
     short     lastTag;
//     Preferences p;
     CRect frameRect;
	 string registeredName;
	 string registeredCRC;
//	 ulong registeredCRC;

	 short terminatingDay;
	 short terminatingMonth;

	string fontName;
	short  fontSize;
	short fontItalic;
	short fontBold;

     short showHoursGMT;
     short showWhatIf;

     string skinName;

     bool showWallpaper;
     string wallpaperName;


//	short imageOn;
//	string imageName;

     DisplayItem * GetByTag ( short DisplayTag )
     {
          DisplayItem * aItem;
          for ( int i = 0; aItem = ll.Nth ( i ); i++ )
          {
               if ( aItem->tag == DisplayTag )
               {
                   return aItem;
               }
          }
          return 0;
     }


     float Version ( void ) { return version; }

	 int SizeDisplay ( void ) { return ll.Size(); }

     void Move ( int from, int to ) { ll.Move (from, to ); }

     short AlarmsPending ( void );

//     char * NameList ( int idx ) { if ( idx < ll.Size()) return ll.Nth ( idx )->name; else return ""; }
     float GMTOffset ( int idx );
     float OffsetList ( int idx );
     short OffsetDisplay ( int idx );
     
//     short selected; //Display;
//     string homeName;
     //        short _24hour;
     
     void ResetOffset ( void );
     							/*
     DisplayItem * GetCurrent ( void )
     {
          return ll.Nth ( view->selected );
//          return ll.Nth ( selected );
     }
     							  */

//     DisplayItem * GetDisplay ( int idx )
//     {
//          return ll.Nth ( idx );
//     }
     
	 DisplayItem * GetHome ( void ) { return &home; }

     
     void Delete ( int idx )
     {
          short * aItem;
          aItem = d.Nth ( idx );
          if ( aItem )
               d.Delete ( aItem );
     }
     
     short * Get ( int idx ) { return d.Nth ( idx ); }
     
     
     void AddDisplay ( short DisplayTag )
     {
          short * aItem;
          /*
          if ( whatDisplay == selected )
          {
          MessageBox ( NULL, "This Display is already set as the Home/Reference Display", NULL, MB_ICONEXCLAMATION );
          return;
     }*/
          for ( int i = 0; aItem = d.Nth ( i ); i++ )
          {
               if ( *aItem == DisplayTag )
               {
                    MessageBox ( NULL, "This Display is already being displayed", NULL, MB_ICONEXCLAMATION );
                    return;
               }
          }
          
          aItem = new short ( DisplayTag );
          d.Add ( aItem );
     }

     void Save ( void );

	Display ( void )
    {
        showWallpaper = false;
        wallpaperName = "";
    }
     
    ~Display ( void ) { }
};

extern Display d;

class List
{
public:
     int index;
     char * name;
};

extern List dayList[];
extern List weekList[];
extern List monthList[];

//extern int selectedbyTag;
//extern int selectedbyRow;
extern string selectedbystring;


#endif
