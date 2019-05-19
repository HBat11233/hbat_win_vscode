#pragma once
class CP3
{
public:
	CP3(double x = 0, double y = 0, double z = 0);
	~CP3();
	double x;
	double y;
	double z;
	CPoint toCPoint();
	CP3 operator -(const CP3& b);
	CP3 operator ^(const CP3& b);
	int operator *(const CP3& b);
};

