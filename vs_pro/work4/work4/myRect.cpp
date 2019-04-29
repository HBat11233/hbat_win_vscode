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
	// TODO: 在此处添加实现代码.
	HBRUSH hbr = (HBRUSH)GetStockObject(GRAY_BRUSH);
	Rectangle(hdc, xleft, ytop, xright, ybottom);
}


void myRect::up()
{
	// TODO: 在此处添加实现代码.
	ytop -= 5;
	ybottom -= 5;
}


void myRect::down()
{
	// TODO: 在此处添加实现代码.
	ytop += 5;
	ybottom += 5;
}


void myRect::left()
{
	// TODO: 在此处添加实现代码.
	xleft -= 5;
	xright -= 5;
}


void myRect::right()
{
	// TODO: 在此处添加实现代码.
	xleft += 5;
	xright += 5;
}
