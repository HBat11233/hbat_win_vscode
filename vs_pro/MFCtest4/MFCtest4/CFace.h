#pragma once

#include "CP3.h"
#include <utility>

class CFace
{
public:
	//点、边的个数
	int En;
	//点集
	CP3* point;
	//边集
	std::pair<int, int> *Eque;
public:
	CFace();
	~CFace();
	bool SetEn(int en);
	bool clear();
	bool SetPoint(CP3*);
	bool SetPair(std::pair<int, int>*);
	bool DrawCFace(CDC* pDC);
};

