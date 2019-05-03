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
	// �Ƿ��½�
	bool down;
	// �Ƿ�����
	bool left;
	// �Ƿ�����
	bool right;
	// �Ƿ���ת
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
	// �жϵ�ǰ�����Ƿ���
	// true�������
	bool stauts();
private:
	// ���Զ����������ֵ
	bool init();
	bool cleararr(int **tarr, int mlen);
public:
	bool leftButton();
	bool rightButton();
	bool upButton();
	bool downButton();
};