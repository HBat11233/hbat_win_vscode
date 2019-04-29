#pragma once
class myRect
{
private:
	size_t xleft;
	size_t xright;
	size_t ytop;
	size_t ybottom;
public:
	myRect(size_t xleft, size_t ytop);
	~myRect();
	void draw(HDC &hdc);
	void up();
	void down();
	void left();
	void right();
};

