#include "stdafx.h"
#include "myRect.h"


myRect::myRect(HWND &hWnd)
	:v(100),lv(0),rv(0),hWnd(hWnd),xLeft(0),xRight(100),yBottom(100),yTop(0)
{
	SetRect(&data, 0, 0, 100, 100);
}


myRect::~myRect()
{
}

VOID myRect::run(HDC &pDC)
{
	HBRUSH hbr= (HBRUSH)GetStockObject(GRAY_BRUSH);
	 yTop+= v,  xLeft += lv, yBottom += v,  xRight+= lv;
	 xLeft -= rv, xRight -= rv;
	SetRect(&data, xLeft,yTop,xRight,yBottom);
	v = 100, lv = 0, rv = 0;
	FillRect(pDC, &data, hbr);
}

VOID myRect::messagel(BOOL p)
{
	if (!p)return;
	rv += 100;
}


VOID myRect::messaged(BOOL p)
{
	if (!p)return;
	v += 100;
}

VOID myRect::messager(BOOL p)
{
	if (!p)return;
	lv += 100;
}