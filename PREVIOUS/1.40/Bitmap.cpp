//***********************************************************************
//
//  BitmapDemo.cpp
//
//***********************************************************************

#include "stdafx.h"
#include "Bitmap.h"

/////////////////////////////////////////////////////////////////////////
// CMaskedBitmap member functions

void CMaskedBitmap::Draw (CDC* pDC, int x, int y)
{
        DEBUGLINE ( __FILE__, __LINE__ );
    BITMAP bm;
    GetObject (sizeof (BITMAP), &bm);
    CPoint size (bm.bmWidth, bm.bmHeight);
    pDC->DPtoLP (&size);

    CPoint org (0, 0);
    pDC->DPtoLP (&org);

    CDC dcMem;
    dcMem.CreateCompatibleDC (pDC);
    CBitmap* pOldBitmap = dcMem.SelectObject (this);
    dcMem.SetMapMode (pDC->GetMapMode ());

    pDC->BitBlt (x, y, size.x, size.y, &dcMem, org.x, org.y, SRCCOPY);

    dcMem.SelectObject (pOldBitmap);
}

void CMaskedBitmap::DrawTransparent (CDC* pDC, CRect frame, COLORREF crColor)
{
        DEBUGLINE ( __FILE__, __LINE__ );
//    int x = frame.left;
//    int y = frame.top;
    BITMAP bm;
    GetObject (sizeof (BITMAP), &bm);
//    CPoint size ( frame.right / 2, frame.bottom / 2);
    
//    bm.bmWidth = bm.bmHeight = frame.right;
    CPoint size (bm.bmWidth, bm.bmHeight);
    pDC->DPtoLP (&size);

//    x += (( frame.right - frame.left ) - bm.bmWidth ) / 2;
//    y += 2;

    // centre bitmap in rectabgle
//    CPoint dest (-((( frame.right - frame.left ) - bm.bmWidth ) / 2 ), -2);
//    pDC->DPtoLP (&dest);
    CPoint org ( 0, 0 );
    pDC->DPtoLP (&org);

    // Create a memory DC (dcImage) and select the bitmap into it
    CDC dcImage;
    dcImage.CreateCompatibleDC (pDC);
    CBitmap* pOldBitmapImage = dcImage.SelectObject (this);
    dcImage.SetMapMode (pDC->GetMapMode ());

    CDC dcStretch;
    dcStretch.CreateCompatibleDC (pDC);
    CBitmap bitmapStretch;
    bitmapStretch.CreateCompatibleBitmap (&dcImage, frame.right, frame.bottom);
//    bitmapStretch.CreateCompatibleBitmap (&dcImage, bm.bmWidth, bm.bmHeight);
//    CBitmap* pStretchBitmapImage = dcStretch.SelectObject (this);
    CBitmap * pStretchBitmapImage = dcStretch.SelectObject ( &bitmapStretch);
//    dcImage.SelectObject ( &bitmapStretch );

    dcStretch.StretchBlt ( frame.left, frame.top, frame.right, frame.bottom, &dcImage, 0, 0, 160, 160, SRCCOPY );//size.x, size.y, SRCCOPY ); //COPY);
//    pDC->BitBlt (org.x, org.y, frame.right, frame.bottom, &dcStretch, org.x, org.y, SRCCOPY);

//    pDC->StretchBlt ( frame.left, frame.top, frame.right, frame.bottom, &dcImage, 0, 0, 160, 160, SRCCOPY );//size.x, size.y, SRCCOPY ); //COPY);
//    dcStretch.BitBlt (org.x, org.y, frame.right, frame.bottom, &dcImage, org.x, org.y, SRCCOPY);
//    pDC->StretchBlt ( frame.left, frame.top, frame.right, frame.bottom, &dcImage, org.x, org.y, frame.right, frame.bottom, SRCCOPY );//size.x, size.y, SRCCOPY ); //COPY);
//    return;


    size.x = frame.right;
    size.y = frame.bottom;

    // Create a second memory DC (dcAnd) and in it create an AND mask
    CDC dcAnd;
    dcAnd.CreateCompatibleDC (pDC);
    dcAnd.SetMapMode (pDC->GetMapMode ());

    CBitmap bitmapAnd;
    bitmapAnd.CreateBitmap (frame.right, frame.bottom, 1, 1, NULL);
//    bitmapAnd.CreateBitmap (bm.bmWidth, bm.bmHeight, 1, 1, NULL);
    CBitmap* pOldBitmapAnd = dcAnd.SelectObject (&bitmapAnd);

    dcStretch.SetBkColor (crColor);
    dcAnd.BitBlt (org.x, org.y, size.x, size.y, &dcStretch, org.x, org.y, SRCCOPY);
//    dcAnd.StretchBlt ( frame.left, frame.top, frame.right, frame.bottom, &dcImage, org.x, org.y, size.x, size.y, SRCCOPY ); //COPY);
//    dcAnd.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, &dcImage, org.x, org.y, size.x, size.y, SRCERASE);

    // Create a third memory DC (dcXor) and in it create an XOR mask
    CDC dcXor;
    dcXor.CreateCompatibleDC (pDC);
    dcXor.SetMapMode (pDC->GetMapMode ());

    CBitmap bitmapXor;
    bitmapXor.CreateCompatibleBitmap (&dcStretch, frame.right, frame.bottom);
//    bitmapXor.CreateCompatibleBitmap (&dcStretch, bm.bmWidth, bm.bmHeight);
    CBitmap* pOldBitmapXor = dcXor.SelectObject (&bitmapXor);

    dcXor.BitBlt (org.x, org.y, size.x, size.y, &dcStretch, org.x, org.y, SRCCOPY);
//    dcXor.StretchBlt ( frame.left, frame.top, frame.right, frame.bottom, &dcImage, org.x, org.y, size.x, size.y, SRCCOPY ); //COPY);
//     dcXor.StretchBlt ( w, h, bm.bmWidth, bm.bmHeight, memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY ); //COPY);
//    dcXor.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, &dcImage, org.x, org.y, size.x, size.y, SRCERASE);

    dcXor.BitBlt (org.x, org.y, size.x, size.y, &dcAnd, org.x, org.y, 0x220326);
//    dcXor.StretchBlt ( frame.left, frame.top, frame.right, frame.bottom, &dcAnd, org.x, org.y, size.x, size.y, 0x220326 ); //COPY);
//    dcXor.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, &dcAnd, org.x, org.y, size.x, size.y, 0x220326);

    // Copy the pixels in the destination rectangle to a temporary
    // memory DC (dcTemp)
    CDC dcTemp;
    dcTemp.CreateCompatibleDC (pDC);
    dcTemp.SetMapMode (pDC->GetMapMode ());

    CBitmap bitmapTemp;
    bitmapTemp.CreateCompatibleBitmap (&dcStretch, frame.right, frame.bottom);
//  bitmapTemp.CreateCompatibleBitmap (&dcStretch, bm.bmWidth, bm.bmHeight);
    CBitmap* pOldBitmapTemp = dcTemp.SelectObject (&bitmapTemp);

    dcTemp.BitBlt (org.x, org.y, size.x, size.y, pDC, 0, 0, SRCCOPY);
//    dcTemp.StretchBlt ( frame.left, frame.top, frame.right, frame.bottom, pDC, org.x, org.y, size.x, size.y, SRCCOPY ); //COPY);
//    dcTemp.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, pDC, org.x, org.y, size.x, size.y, SRCERASE);

    // Generate the final image by applying the AND and XOR masks to
    // the image in the temporary memory DC
    dcTemp.BitBlt (org.x, org.y, size.x, size.y, &dcAnd, org.x, org.y, SRCAND);
//    dcTemp.StretchBlt (frame.left, frame.top, frame.right, frame.bottom, &dcAnd, org.x, org.y, size.x, size.y, SRCAND ); //COPY);
//    dcTemp.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, &dcAnd, org.x, org.y, size.x, size.y, SRCAND);

    dcTemp.BitBlt (org.x, org.y, size.x, size.y, &dcXor, org.x, org.y, SRCINVERT);
//    dcTemp.StretchBlt ( frame.left, frame.top, frame.right, frame.bottom, &dcXor, org.x, org.y, size.x, size.y, SRCINVERT ); //COPY);
//    dcTemp.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, &dcXor, org.x, org.y, size.x, size.y, SRCINVERT);

    // Blit the resulting image to the screen
//    pDC->BitBlt (x, y, size.x, size.y, &dcTemp, org.x, org.y, SRCCOPY);
    pDC->StretchBlt ( frame.left, frame.top, frame.right, frame.bottom, &dcTemp, org.x, org.y, size.x, size.y, SRCCOPY ); //COPY);
//    pDC->StretchBlt (frame.left, frame.top, frame.right - frame.left, frame.bottom - frame.top, &dcTemp, x, y, size.x, size.y, SRCERASE);

    // Restore the default bitmaps
    dcTemp.SelectObject (pOldBitmapTemp);
    dcXor.SelectObject (pOldBitmapXor);
    dcAnd.SelectObject (pOldBitmapAnd);
    dcStretch.SelectObject (pStretchBitmapImage);
    dcImage.SelectObject (pOldBitmapImage);
}
