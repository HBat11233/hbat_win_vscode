#pragma once

#include "CP3.h"
#include <utility>

class CFace
{
public:
	//�㡢�ߵĸ���
	int En;
	//�㼯
	CP3* point;
	//�߼�
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

