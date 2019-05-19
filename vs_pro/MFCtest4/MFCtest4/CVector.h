#pragma once

#include "CP3.h"
#include "CFace.h"

class CVector
{
public:
	CP3 vec;
public:
	CVector();
	CVector(CP3 p);
	CVector(CFace p);
	~CVector();
	bool init(CP3 p);
	bool init(CFace& p);
	CVector operator ^(const CVector& b);
	int operator *(const CVector& b);
};

