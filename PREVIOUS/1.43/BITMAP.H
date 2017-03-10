//***********************************************************************
//
//  BitmapDemo.h
//
//***********************************************************************

#ifndef _BITMAP_H
#define _BITMAP_H

class CMaskedBitmap : public CBitmap
{
public:
    virtual void Draw (CDC*, int, int);
    virtual void DrawTransparent (CDC*, CRect, COLORREF);
//    virtual void DrawTransparent (CDC*, int, int, COLORREF);
};

#endif