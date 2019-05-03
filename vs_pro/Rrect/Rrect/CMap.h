#pragma once


#define JC_AC       0		//�ɹ�
#define JC_BOOL     1		//�����
#define JC_LEFT		1<<1	//�����
#define JC_REIGHT	1<<2	//�����
#define JC_TOP		1<<3	//�����
#define JC_BOTTOM	1<<4	//�����
#define XLEN		24		//����涨��λ��
#define YLEN		32		//����涨��λ��


//����˹���������
class CMap
{
private:
	//�����
	int x;
	//�����
	int y;
	//���浥Ԫ��״̬
	bool blackOrWrite[XLEN][YLEN];
	//��Ԫ�����
	RECT unitBlock[XLEN][YLEN];
public:
	CMap();
	~CMap();
	bool init(int x,int y);
	// false:�ɹ�,true:ʧ��	
	int draw(HDC hdc, HBRUSH hbr, int x[], int y[], int len);
	bool add(int x[], int y[], int len);
	bool add(HDC hdc, HBRUSH hbr, int x[], int y[], int len);
	int deleteLine();
private:
	//�÷�
	unsigned long score;
public:
	// ��Ϸ����	
	bool stauts(int x[], int y[], int mlen);
	void gameOver(HDC hdc, HBRUSH hbr);
};

