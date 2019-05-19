#include "pch.h"
#include "CP3.h"


CP3::CP3(double x, double y, double z)
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

CP3 CP3::operator -(const CP3& b)
{
	CP3 t;
	t.x = x - b.x;
	t.y = y - b.y;
	t.z = z - b.z;
	return t;
}

CP3 CP3::operator ^(const CP3& b)
{
	CP3 t;
	t.x = y * b.z - z * b.y;
	t.y = z * b.x - x * b.z;
	t.z = x * b.y - y * b.x;
	return t;
}

int CP3::operator *(const CP3& b)
{
	return x * b.x + y * b.y + z * b.z;
}
