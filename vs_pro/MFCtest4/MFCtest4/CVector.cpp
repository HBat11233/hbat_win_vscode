#include "pch.h"
#include "CVector.h"


CVector::CVector()
	:vec(CP3(0,0,0))
{
}

CVector::CVector(CP3 p)
	:vec(p)
{
}

CVector::CVector(CFace p)
{
	init(p);
}

CVector::~CVector()
{
}

bool CVector::init(CP3 p)
{
	vec = p;
	return false;
}

bool CVector::init(CFace& p)
{
	CP3 v01 = p.point[1] - p.point[0];
	CP3 v02 = p.point[2] - p.point[0];
	vec = v01 ^ v02;
	return false;
}

CVector CVector::operator ^(const CVector& p)
{
	return CVector(vec ^ p.vec);
}

int CVector::operator *(const CVector& p)
{
	return vec * p.vec;
}
