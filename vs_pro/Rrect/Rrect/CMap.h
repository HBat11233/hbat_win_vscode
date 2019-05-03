#pragma once


#define JC_AC       0		//成功
#define JC_BOOL     1		//已填充
#define JC_LEFT		1<<1	//左溢出
#define JC_REIGHT	1<<2	//右溢出
#define JC_TOP		1<<3	//上溢出
#define JC_BOTTOM	1<<4	//下溢出
#define XLEN		24		//桌面规定单位宽
#define YLEN		32		//桌面规定单位高


//俄罗斯方块的桌面
class CMap
{
private:
	//桌面宽
	int x;
	//桌面高
	int y;
	//桌面单元块状态
	bool blackOrWrite[XLEN][YLEN];
	//单元块矩阵
	RECT unitBlock[XLEN][YLEN];
public:
	CMap();
	~CMap();
	bool init(int x,int y);
	// false:成功,true:失败	
	int draw(HDC hdc, HBRUSH hbr, int x[], int y[], int len);
	bool add(int x[], int y[], int len);
	bool add(HDC hdc, HBRUSH hbr, int x[], int y[], int len);
	int deleteLine();
private:
	//得分
	unsigned long score;
public:
	// 游戏结束	
	bool stauts(int x[], int y[], int mlen);
	void gameOver(HDC hdc, HBRUSH hbr);
};

