#pragma once
#include "CMap.h"

// **
// **
#define STY1 1
// *
// ***
#define STY2 2
//   *
// ***
#define STY3 3
//  *
// ***
#define STY4 4
// ****
#define STY5 5






class Cunit
{
private:
	int **arr;
	int len;
	CMap *Hmap; 
	// 是否下降
	bool down;
	// 是否左移
	bool left;
	// 是否右移
	bool right;
	// 是否旋转
	bool up;
public:
	Cunit();
	~Cunit();
	bool init(int style, CMap *Hmap, int **m = NULL, int mlen = 0);
	void clear();
	bool run(HDC hdc, HBRUSH hbr);	
	bool leftButton(HDC hdc, HBRUSH hbr);
	bool rightButton(HDC hdc, HBRUSH hbr);
	bool downButton(HDC hdc, HBRUSH hbr);
	bool upButton(HDC hdc, HBRUSH hbr);
	// 判断当前方块是否存活
	// true：不存活
	bool stauts();
private:
	// 非自定义变量赋初值
	bool init();
	bool cleararr(int **tarr, int mlen);
public:
	bool leftButton();
	bool rightButton();
	bool upButton();
	bool downButton();
};