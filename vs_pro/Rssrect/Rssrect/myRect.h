#pragma once
class myRect
{
private:
	RECT data;
	int xLeft;   // вСио╫гx
	int yTop;    // вСио╫гy
	int xRight;  // сроб╫гx
	int yBottom;  // сроб╫гy
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

