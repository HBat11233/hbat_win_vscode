#pragma once
class myRect
{
private:
	RECT data;
	int xLeft;   // ���Ͻ�x
	int yTop;    // ���Ͻ�y
	int xRight;  // ���½�x
	int yBottom;  // ���½�y
	size_t v;
	size_t lv;
	size_t rv;
	HWND &hWnd;
public:
	myRect(HWND&);
	~myRect();
	VOID run(HDC&);
	VOID messagel(BOOL);
	VOID messager(BOOL);
	VOID messaged(BOOL);
};

