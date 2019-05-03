#include "stdafx.h"
#include "CMap.h"


CMap::CMap()
{
}


CMap::~CMap()
{
}


bool CMap::init(int xx,int yy)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	x = xx;
	y = yy;
	score = 0;
	for (int i = 0; i < XLEN; i++)
		for (int j = 0; j < YLEN; j++)
			blackOrWrite[i][j] = false;
	int xlen = x / XLEN, ylen = y / YLEN;
	for (int i = 0; i < XLEN; ++i)
		for (int j = 0; j < YLEN; ++j)
			SetRect(*(unitBlock + i) + j, i*xlen, j*ylen, (i + 1)*xlen, (j + 1)*ylen);
	return false;
}

// false:�ɹ���true:ʧ��
// (x[i],y[i])����Ԫ��
int CMap::draw(HDC hdc, HBRUSH hbr,int x[],int y[],int len)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	RECT All;
	SetRect(&All, 0, 0, this->x, this->y);
	HBRUSH thbr = CreateSolidBrush(RGB(0, 255, 255));
	FillRect(hdc, &All,thbr);
	
	//��ʼ�����ݣ��ж��Ƿ���������һ��
	score+=deleteLine();
	WCHAR buf[265];
	TextOut(hdc, 500, 20, buf, wsprintf(buf, TEXT("%d"), score));
	TextOut(hdc, 490, 140, TEXT("input"), strlen("input"));
	TextOut(hdc, 490, 160, TEXT("Enter"), strlen("Enter"));
	TextOut(hdc, 490, 180, TEXT("new"), strlen("new"));
	TextOut(hdc, 490, 200, TEXT("game"), strlen("game"));
	int returnInt = 0;
	// �ж��µľ����Ƿ���Ի��ƣ������Է���true
	for (int i = 0; i < len; ++i)
	{
		bool bj = true;
		if (x[i] < 0)						bj = false, returnInt |= JC_REIGHT;
		if (x[i] >= XLEN)					bj = false, returnInt |= JC_LEFT;
		if (y[i] < 0)						bj = false, returnInt |= JC_TOP;
		if (y[i] >= YLEN)					bj = false, returnInt |= JC_BOTTOM;
		if (bj&&blackOrWrite[x[i]][y[i]])	bj = false, returnInt |= JC_BOOL;
	}
	//�����ƶ���Ԫ��
	if (!returnInt)
		for (int i = 0; i < len; ++i)
			FillRect(hdc, *(unitBlock+x[i])+y[i], hbr);
	//���ƹ̶���Ԫ��
	for (int i = 0; i < XLEN; ++i)
		for (int j = 0; j < YLEN; ++j)
			if(blackOrWrite[i][j])
				FillRect(hdc, *(unitBlock + i) + j, hbr);
	return returnInt;
}


// false:�ɹ�,true:ʧ��
//�����
bool CMap::add(int x[],int y[],int len)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	for (int i = 0; i < len; ++i)
		if (blackOrWrite[x[i]][y[i]])return true;
	for (int i = 0; i < len; ++i)
		blackOrWrite[x[i]][y[i]] = true;
	return false;
}

// false:�ɹ�,true:ʧ��
//��Ӳ�����
bool CMap::add(HDC hdc, HBRUSH hbr, int x[], int y[], int len)
{
	bool ans = add(x, y, len);
	draw(hdc, hbr, x, y, len);
	return ans;
}

int CMap::deleteLine()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	int num = 0;
	for (int i = 0; i < YLEN; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < XLEN; ++j)
			if (blackOrWrite[j][i])
				cnt++;
		if (cnt == XLEN)
		{
			num += XLEN;
			for (int k = i; k > 0; --k)
				for (int j = 0; j < XLEN; ++j)
					blackOrWrite[j][k] = blackOrWrite[j][k-1];
			for (int j = 0; j < XLEN; ++j)
				blackOrWrite[j][0] = false;
		}

	}
	return num;
}


// �ж���Ϸ�Ƿ������true������
bool CMap::stauts(int x[],int y[],int mlen)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	int ans = false;
	for (int i = 0; i < mlen; ++i)
		if (blackOrWrite[x[i]][y[i]])
			ans = true;
	return ans;
}


// ��Ϸ����
void CMap::gameOver(HDC hdc, HBRUSH hbr)
{
	// TODO: �ڴ˴����ʵ�ִ���.

	const int xl = 22;
	const int yl = 14;
	const int ox = 1;
	const int oy = 7;

	//��յ�Ԫ��
	for (int i = 1; i < 1 + xl; ++i)
		for (int j = 6; j < 6 + yl+2; ++j)
			blackOrWrite[i][j] = false;
	//����gameover
	int d[yl][11] =
	{
		{1,2, 7,12,15,18,19,20,21,21,21},
		{0,3, 6, 8,12,13,14,15,18,18,18},
		{0,6, 8,12,13,14,15,18,19,20,20},
		{0,2, 3, 6, 7, 8,11,13,14,16,18},
		{0,3, 5, 9,11,16,18,18,18,18,18},
		{1,2, 5, 9,11,16,18,19,20,21,21},
		{2,2, 4, 6, 8,10,12,14,16,18,20},
		{1,1, 3, 5, 7, 9,11,13,15,17,19},
		{2,6,10,12,13,14,15,17,18,19,20},
		{1,3, 6,10,12,17,20,20,20,20,20},
		{0,4, 7, 9,12,13,14,17,18,19,20},
		{0,4, 7, 9,12,17,18,18,18,18,18},
		{1,3, 7, 9,12,17,19,19,19,19,19},
		{2,8,12,13,14,15,17,20,20,20,20}
	};
	for (int i = 0; i < yl; ++i)
		for (int j = 0; j < 11; ++j)
			blackOrWrite[ox + d[i][j]][oy + i]=true;
	draw(hdc, hbr,NULL,NULL,0);
}
