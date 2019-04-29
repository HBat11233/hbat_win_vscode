#include "stdafx.h"
#include "myRect.h"


myRect::myRect(size_t xleft, size_t ytop)
	:xleft(xleft),ytop(ytop),xright(xleft+150),ybottom(ytop+150)
{
	
}


myRect::~myRect()
{
}


void myRect::draw(HDC &hdc)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	HBRUSH hbr = (HBRUSH)GetStockObject(GRAY_BRUSH);
	Rectangle(hdc, xleft, ytop, xright, ybottom);
}


void myRect::up()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	ytop -= 5;
	ybottom -= 5;
}


void myRect::down()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	ytop += 5;
	ybottom += 5;
}


void myRect::left()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	xleft -= 5;
	xright -= 5;
}


void myRect::right()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	xleft += 5;
	xright += 5;
}
