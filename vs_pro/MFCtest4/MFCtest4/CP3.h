#pragma once
class CP3
{
public:
	CP3(int x = 0, int y = 0, int z = 0);
	~CP3();
	int x;
	int y;
	int z;
	CPoint toCPoint();
	CP3 operator -(const CP3& b);
	CP3 operator ^(const CP3& b);
	int operator *(const CP3& b);
};

