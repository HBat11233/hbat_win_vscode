// sindraw.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "sindraw.h"

#define MAX_LOADSTRING 100
#define NUM 10000
#define PI 3.1415926
#define NUMLINES 50

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名


void dfs(int n, HDC &hdc, INT cxClient, INT cyClient, POINT apt[], POINT &pos);
void DrawSin(HDC &hdc, INT cxClient, INT cyClient, POINT apt[], POINT &pos);

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 在此处放置代码。

	// 初始化全局字符串
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_SINDRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SINDRAW));

	MSG msg;

	// 主消息循环:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SINDRAW));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_SINDRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 将实例句柄存储在全局变量中

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_VSCROLL,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int cxClient, cyClient, cyChar, iVertPos;
	POINT apt[NUM];
	SCROLLINFO si;
	TEXTMETRIC tm;

	switch (message)
	{
	case WM_CREATE:
	{
		HDC hdc = GetDC(hWnd);
		GetTextMetrics(hdc, &tm);
		cyChar = tm.tmHeight + tm.tmExternalLeading;
		MoveWindow(hWnd, 0, 0, 640, 480, TRUE);
		ReleaseDC(hWnd, hdc);
	}
	break;
	case WM_SIZE:
	{
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		si.cbSize = sizeof(si);
		si.fMask = SIF_RANGE | SIF_PAGE;

		si.nMin = 0;
		si.nMax = NUMLINES - 1;
		si.nPage = cyClient / cyChar;
		SetScrollInfo(hWnd, SB_VERT, &si, TRUE);
	}
	break;
	case WM_VSCROLL:
	{
		si.cbSize = sizeof(si);
		si.fMask = SIF_ALL;
		GetScrollInfo(hWnd, SB_VERT, &si);
		iVertPos = si.nPos;
		switch (LOWORD(wParam))
		{
		case SB_TOP:
		{
			si.nPos = si.nMin;
		}
		break;
		case SB_BOTTOM:
		{
			si.nPos = si.nMax;
		}
		break;
		case SB_LINEUP:
		{
			si.nPos -= 1;
		}
		break;
		case SB_LINEDOWN:
		{
			si.nPos += 1;
		}
		break;
		case SB_PAGEUP:
		{
			si.nPos -= si.nPage;
		}
		break;
		case SB_PAGEDOWN:
		{
			si.nPos += si.nPage;
		}
		break;
		case SB_THUMBTRACK:
		{
			si.nPos = si.nTrackPos;
		}
		break;
		}

		si.fMask = SIF_POS;
		SetScrollInfo(hWnd, SB_VERT, &si, TRUE);
		GetScrollInfo(hWnd, SB_VERT, &si);

		if (si.nPos != iVertPos)
		{
			iVertPos = si.nPos;
			InvalidateRect(hWnd, NULL, TRUE);
		}
	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此处添加使用 hdc 的任何绘图代码...
		POINT pos;
		pos.x = 0, pos.y = 0;
		dfs(iVertPos, hdc, cxClient, cyClient, apt, pos);
		/*
		MoveToEx(hdc, 0, cyClient / 2, NULL);
		LineTo(hdc, cxClient, cyClient / 2);

		for (int i = 0; i <= cxClient; ++i)
		{
			apt[i].x = i;
			apt[i].y = LONG(abs((sin(i * (2 * PI / cxClient)) - 1)*(cyClient / 2)));
		}
		Polyline(hdc, apt, cxClient+1);
		*/
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void dfs(int n, HDC &hdc, INT cxClient, INT cyClient, POINT apt[], POINT &pos)
{
	if (n == 0)
		DrawSin(hdc, cxClient, cyClient, apt, pos);
	else
	{
		POINT temp = pos;
		dfs(n - 1, hdc, cxClient / 2, cyClient / 2, apt, temp);
		temp.x += cxClient / 2;
		dfs(n - 1, hdc, cxClient / 2, cyClient / 2, apt, temp);
		temp.y += cyClient / 2;
		dfs(n - 1, hdc, cxClient / 2, cyClient / 2, apt, temp);
		temp.x -= cxClient / 2;
		dfs(n - 1, hdc, cxClient / 2, cyClient / 2, apt, temp);
	}

}

void DrawSin(HDC &hdc, INT cxClient, INT cyClient, POINT apt[], POINT &pos)
{
	MoveToEx(hdc, pos.x + 0, pos.y + cyClient / 2, NULL);
	LineTo(hdc, pos.x + cxClient, pos.y + cyClient / 2);

	for (int i = 0; i <= cxClient; ++i)
	{
		apt[i].x = i + pos.x;
		apt[i].y = LONG(abs((sin(i * (2 * PI / cxClient)) - 1)*(cyClient / 2))) + pos.y;
	}
	Polyline(hdc, apt, cxClient + 1);
}