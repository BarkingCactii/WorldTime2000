#ifndef _REGDATA_H
#define _REGDATA_H

#include <string>
using namespace std;


//#define NUM_REGITEMS 4


struct RegistryItem
{
    string name;        // name as appears in list control

    DWORD  type;        // type of registry item REG_DWORD or REG_SZ
    // can be 1 of the following
    DWORD word;         // REG_DWORD value
    string str;         // REG_SZ value

//    RegInfo pathType;   // directory or not

//    int keyIndex;       // index to which Registry key handle this item belongs to
//    bool exists;        // true if key exists
  //  bool validPath;     // true if key contains a path and path exists

    /*
    RegistryItem ( void )
    {
        name = "";
        type = REG_SZ;
        str = "<not found>";
        word = 0;
//        pathType = NonPath;

//        exists = true;
    //    keyIndex = 0;
    } */
};      

// regData[0] contains the password

//extern RegistryItem regData[];
class RegistryCollection
{
private:
    int regDataSz;
    RegistryItem regData[50]; // 34
public:
    // Get functions
//    string FontName ( void ) { return regData[5].str; }
//    int FontSize ( void ) { return regData[6].word; }
//    int FontItalic ( void ) { return regData[7].word; }
//    int FontBold ( void ) { return regData[8].word; }
    
    int WinTop ( void ) { return regData[0].word; }
    int WinLeft ( void ) { return regData[1].word; }
    int WinBottom ( void ) { return regData[2].word; }
    int WinRight ( void ) { return regData[3].word; }
//    int WinScrollPos ( void ) { return regData[24].word; }
    string & FontName ( void ) { return regData[4].str; }
    int FontSize ( void) { return regData[5].word; }
    int FontItalic ( void) { return regData[6].word; }
    int FontBold ( void) { return regData[7].word; }
    COLORREF FontColor ( void ) { return regData[8].word; }

    int Show24Hour ( void) { return regData[9].word; }
    int ShowAM ( void) { return regData[10].word; }
    int ShowAll ( void ) { return regData[11].word; }
    int ShowDate ( void ) { return regData[12].word; }
    int ShowDST ( void ) { return regData[13].word; }

    int ShowDetailed ( void ) { return regData[14].word; }
//    int ManualView ( void ) { return regData[14].word; }
    int UpdateInterval ( void) { return regData[15].word; }
    string & MemberTemplate ( void ) { return regData[16].str; }
    string & MemberTemplate2 ( void ) { return regData[17].str; }
    string & MemberTemplate3 ( void ) { return regData[18].str; }

    // NEW ADDITIONS
    // display map in actual size of stretch to fit
//    int ActualSize ( void ) { return regData[17].word; }
    // rectanlge color displaying the time
//    int BackgroundColor ( void ) { return regData[18].word; }
    // use template rules to display highlighted location
    int UseTemplate ( void ) { return regData[19].word; }
    // show seconds in clock
    int ShowSeconds ( void ) { return regData[20].word; }
    // sound functions
    string & SoundQuarterFile ( void ) { return regData[21].str; }
    string & SoundHourFile ( void ) { return regData[22].str; }
    string & SoundAlarmFile ( void ) { return regData[23].str; }
    int SoundQuarter ( void ) { return regData[24].word; }
    int SoundHour ( void ) { return regData[25].word; }
    int SoundAlarm ( void ) { return regData[26].word; }
//    int ShowMarquee ( void ) { return regData[27].word; }
    string & SkinName ( void ) { return regData[28].str; }
    int AlwaysOnTop ( void ) { return regData[29].word; }
    int DayColor ( void ) { return regData[30].word; }
    int NightColor ( void ) { return regData[31].word; }
    int TwilightColor ( void ) { return regData[32].word; }
    int MainView ( void ) { return regData[33].word; }
    string & UpdateURL ( void ) { return regData[34].str; }
    int ListColor ( void ) { return regData[35].word; }

    // Put functions
    void WinTop ( int c ) { regData[0].word = c; }
    void WinLeft ( int c ) { regData[1].word = c; }
    void WinBottom ( int c ) { regData[2].word = c; }
    void WinRight ( int c ) { regData[3].word = c; }
    void FontName ( string & s ) { regData[4].str = s; }
    void FontSize ( int s ) { regData[5].word = s; }
    void FontItalic ( int s ) { regData[6].word = s; }
    void FontBold ( int s ) { regData[7].word = s; }
    void FontColor ( int s ) { regData[8].word = s; }

//    void WinScrollPos ( int x ) { regData[24].word = x; }
    void Show24Hour ( int show ) { regData[9].word = show; }
    void ShowAM ( int show ) { regData[10].word = show; }
    void ShowAll ( int show ) { regData[11].word = show; }
    void ShowDate ( int show ) { regData[12].word = show; }
    void ShowDST ( int show ) { regData[13].word = show; }

    void ShowDetailed ( int s) { regData[14].word = s; }
//    void ManualView ( int s) { regData[14].word = s; }
    void UpdateInterval ( int update ) { regData[15].word = update; }
    void MemberTemplate ( string & s ) { regData[16].str = s; }
    void MemberTemplate2 ( string & s ) { regData[17].str = s; }
    void MemberTemplate3 ( string & s ) { regData[18].str = s; }

    // display map in actual size of stretch to fit
//    void ActualSize ( int size ) { regData[17].word = size; }
    // rectanlge color displaying the time
//    void BackgroundColor ( int color ) { regData[18].word = color; }
    // use template rules to display highlighted location
    void UseTemplate ( int use ) { regData[19].word = use; }
    // show seconds in clock
    void ShowSeconds ( int show) { regData[20].word = show; }
    // sound functions
    void SoundQuarterFile ( string & file ) { regData[21].str = file; }
    void SoundHourFile ( string & file ) { regData[22].str = file; }
    void SoundAlarmFile ( string & file ) { regData[23].str = file; }
    void SoundQuarter ( int on ) { regData[24].word = on; }
    void SoundHour ( int on ) { regData[25].word = on; }
    void SoundAlarm ( int on ) { regData[26].word = on; }
//    void ShowMarquee ( int on ) { regData[27].word = on; }
    void SkinName ( string & file ) { regData[28].str = file; }
    void AlwaysOnTop ( int on ) { regData[29].word = on; }
    void DayColor ( int color ) { regData[30].word = color; }
    void NightColor ( int color ) { regData[31].word = color; }
    void TwilightColor ( int color ) { regData[32].word = color; }
    void MainView ( int on ) { regData[33].word = on; }
    void UpdateURL ( string & str ) { regData[34].str = str; }
    void ListColor ( int color ) { regData[35].word = color; }






    bool ReadRegistry ( void );
    bool WriteRegistry ( void );
    RegistryCollection ( void );
};


extern RegistryCollection r;


//void InitRegistryData ( void );
//bool ReadRegistry ( void );
//bool WriteRegistry ( void );

#endif
