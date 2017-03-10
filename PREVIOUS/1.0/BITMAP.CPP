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
    int x = frame.left;
    int y = frame.top;
    BITMAP bm;
    GetObject (sizeof (BITMAP), &bm);
    CPoint size (bm.bmWidth, bm.bmHeight);
    pDC->DPtoLP (&size);

    x += (( frame.right - frame.left ) - bm.bmWidth ) / 2;
    y += 2;

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

    // Create a second memory DC (dcAnd) and in it create an AND mask
    CDC dcAnd;
    dcAnd.CreateCompatibleDC (pDC);
    dcAnd.SetMapMode (pDC->GetMapMode ());

    CBitmap bitmapAnd;
    bitmapAnd.CreateBitmap (bm.bmWidth, bm.bmHeight, 1, 1, NULL);
    CBitmap* pOldBitmapAnd = dcAnd.SelectObject (&bitmapAnd);

    dcImage.SetBkColor (crColor);
    dcAnd.BitBlt (org.x, org.y, size.x, size.y, &dcImage, org.x, org.y, SRCCOPY);
//    dcAnd.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, &dcImage, org.x, org.y, size.x, size.y, SRCERASE);

    // Create a third memory DC (dcXor) and in it create an XOR mask
    CDC dcXor;
    dcXor.CreateCompatibleDC (pDC);
    dcXor.SetMapMode (pDC->GetMapMode ());

    CBitmap bitmapXor;
    bitmapXor.CreateCompatibleBitmap (&dcImage, bm.bmWidth, bm.bmHeight);
    CBitmap* pOldBitmapXor = dcXor.SelectObject (&bitmapXor);

    dcXor.BitBlt (org.x, org.y, size.x, size.y, &dcImage, org.x, org.y, SRCCOPY);
//    dcXor.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, &dcImage, org.x, org.y, size.x, size.y, SRCERASE);

    dcXor.BitBlt (org.x, org.y, size.x, size.y, &dcAnd, org.x, org.y, 0x220326);
//    dcXor.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, &dcAnd, org.x, org.y, size.x, size.y, 0x220326);

    // Copy the pixels in the destination rectangle to a temporary
    // memory DC (dcTemp)
    CDC dcTemp;
    dcTemp.CreateCompatibleDC (pDC);
    dcTemp.SetMapMode (pDC->GetMapMode ());

    CBitmap bitmapTemp;
    bitmapTemp.CreateCompatibleBitmap (&dcImage, bm.bmWidth, bm.bmHeight);
    CBitmap* pOldBitmapTemp = dcTemp.SelectObject (&bitmapTemp);

    dcTemp.BitBlt (org.x, org.y, size.x, size.y, pDC, x, y, SRCCOPY);
//    dcTemp.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, pDC, org.x, org.y, size.x, size.y, SRCERASE);

    // Generate the final image by applying the AND and XOR masks to
    // the image in the temporary memory DC
    dcTemp.BitBlt (org.x, org.y, size.x, size.y, &dcAnd, org.x, org.y, SRCAND);
//    dcTemp.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, &dcAnd, org.x, org.y, size.x, size.y, SRCAND);

    dcTemp.BitBlt (org.x, org.y, size.x, size.y, &dcXor, org.x, org.y, SRCINVERT);
//    dcTemp.StretchBlt (org.x, org.y, frame.right - frame.left, frame.bottom - frame.top, &dcXor, org.x, org.y, size.x, size.y, SRCINVERT);

    // Blit the resulting image to the screen
    pDC->BitBlt (x, y, size.x, size.y, &dcTemp, org.x, org.y, SRCCOPY);
//    pDC->StretchBlt (frame.left, frame.top, frame.right - frame.left, frame.bottom - frame.top, &dcTemp, x, y, size.x, size.y, SRCERASE);

    // Restore the default bitmaps
    dcTemp.SelectObject (pOldBitmapTemp);
    dcXor.SelectObject (pOldBitmapXor);
    dcAnd.SelectObject (pOldBitmapAnd);
    dcImage.SelectObject (pOldBitmapImage);
}
