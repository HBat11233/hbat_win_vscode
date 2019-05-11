#pragma once

#include "CFace.h"

class earth
{
public:
	//经度等分n份
	int n;
	//维度等分m份
	//实际分为2*m份
	int m;
	//面的个数
	int len;
	//球半径
	int R;
	CFace* que;
public:
	earth();
	~earth();
	bool init(int n, int m, int R);
private:
	//建立除南北极坐标二维数组
	CP3** CreateCP3();
	//删除二维数组
	bool DeleteCP3(CP3** cp3);
	bool CreateCFace(CP3** cp3);
public:
	bool clear();
};

