#include "pch.h"
#include "CFace.h"


CFace::CFace()
	:En(0),point(NULL),Eque(NULL)
{
}


CFace::~CFace()
{
	clear();
}

bool CFace::SetEn(int en)
{
	if (En == en)return false;
	clear();
	En = en;
	point = new CP3[En];
	Eque = new std::pair<int, int>[En];
	return false;
}

bool CFace::clear()
{
	if (point != NULL)
	{
		delete[] point;
		point = NULL;
	}
	if (Eque != NULL)
	{
		delete[] Eque;
		Eque = NULL;
	}
	return false;
}

bool CFace::SetPoint(CP3* p)
{
	for (int i = 0; i < En; ++i)
		point[i] = p[i];
	return false;
}

bool CFace::SetPair(std::pair<int, int>* p)
{
	for (int i = 0; i < En; ++i)
		Eque[i] = p[i];
	return false;
}