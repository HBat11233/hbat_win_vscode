#include "pch.h"
#include "CP3.h"


CP3::CP3(int x,int y,int z)
	:x(x),y(y),z(z)
{
}


CP3::~CP3()
{
}


CPoint CP3::toCPoint()
{
	// TODO: 在此处添加实现代码.
	return CPoint(x,y);
}
