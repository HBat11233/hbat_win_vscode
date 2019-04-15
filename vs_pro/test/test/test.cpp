// test.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "test.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

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
	LoadStringW(hInstance, IDC_TEST, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST));

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TEST);
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

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
	static int 客户区高, 客户区宽, 矩阵宽, 矩阵高, 字宽, 字高, 鼠标x, 鼠标y, 字符串起点x, 字符串起点y;
	static bool 鼠标按下;
	static int 矩阵坐标x[5][5], 矩阵坐标y[5][5];
	static HBRUSH 画刷;
	static HPEN 行画笔, 列画笔;
	TEXTMETRIC tm;


	switch (message)
	{
	case WM_CREATE:
	{
		HDC hdc = GetDC(hWnd);
		MoveWindow(hWnd, 0, 0, 960, 540, TRUE);
		GetTextMetrics(hdc, &tm);
		字宽 = tm.tmAveCharWidth;
		字高 = tm.tmHeight + tm.tmExternalLeading;
		行画笔 = CreatePen(PS_DASH, 0, RGB(255, 0, 0));
		列画笔 = CreatePen(PS_DOT, 0, RGB(255, 0, 0));
	}
	break;
	case WM_SIZE:
	{
		客户区宽 = LOWORD(lParam);
		客户区高 = HIWORD(lParam);
		矩阵高 = 客户区高 / 5;
		矩阵宽 = 客户区宽 / 5;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (i == j && j == 0)continue;
				else if (j == 0)
				{
					矩阵坐标x[i][j] = 0;
					矩阵坐标y[i][j] = 矩阵坐标y[i - 1][j] + 矩阵高;
				}
				else
				{
					矩阵坐标x[i][j] = 矩阵坐标x[i][j - 1] + 矩阵宽;
					矩阵坐标y[i][j] = 矩阵坐标y[i][j - 1];
				}
			}
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
	case WM_LBUTTONDOWN:
		鼠标x = LOWORD(lParam);
		鼠标y = HIWORD(lParam);
		for (int i = 0; i < 客户区宽; i += 字宽 * 1.2)
		{
			if (i > 鼠标x)
			{
				字符串起点x = i - 字宽 * 1.2;
				break;
			}
		}
		for (int i = 0; i < 客户区高; i += 字高 * 1.5)
		{
			if (i > 鼠标y)
			{
				字符串起点y = i - 字高 * 1.5;
				break;
			}
			鼠标按下 = true;
			InvalidateRect(hWnd, nullptr, TRUE);
		}
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此处添加使用 hdc 的任何绘图代码...
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
			{
				int x = 矩阵宽 + 矩阵坐标x[i][j], y = 矩阵高 + 矩阵坐标y[i][j];
				Rectangle(hdc, 矩阵坐标x[i][j], 矩阵坐标y[i][j], x, y);
			}
		画刷 = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, 画刷);
		for (int i = 0; i < 5; ++i)
		{
			int x = 矩阵宽 + 矩阵坐标x[i][i], y = 矩阵高 + 矩阵坐标y[i][i];
			Rectangle(hdc, 矩阵坐标x[i][i], 矩阵坐标y[i][i], x, y);
			if (i == 2)continue;
			x = 矩阵宽 + 矩阵坐标x[i][4 - i], y = 矩阵高 + 矩阵坐标y[i][4 - i];
			Rectangle(hdc, 矩阵坐标x[i][4 - i], 矩阵坐标y[i][4 - i], x, y);
		}
		SelectObject(hdc, 列画笔);
		for (int i = 0; i < 客户区宽; i += 字宽 * 1.2)
		{
			MoveToEx(hdc, i, 0, NULL);
			LineTo(hdc, i, 客户区高);
		}
		SelectObject(hdc, 行画笔);
		for (int i = 0; i < 客户区高; i += 字高 * 1.5)
		{
			MoveToEx(hdc,0,i, NULL);
			LineTo(hdc, 客户区宽,i);
		}
		SetBkMode(hdc, TRANSPARENT);
		int x = 字符串起点x, y = 字符串起点y;
		TextOut(hdc, x, y, TEXT("H"), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽*1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT("E"), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽 * 1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT("L"), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽 * 1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT("L"), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽 * 1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT("O"), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽 * 1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT(" "), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽 * 1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT("W"), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽 * 1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT("O"), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽 * 1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT("R"), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽 * 1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT("L"), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽 * 1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT("D"), 1);
		y = y + (x + 字宽 * 1.2 >= 客户区宽 ? 字高 * 1.5 : 0);
		x = x + (x + 字宽 * 1.2 >= 客户区宽 ? -x : 字宽 * 1.2);
		TextOut(hdc, x, y, TEXT("!"), 1);

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
