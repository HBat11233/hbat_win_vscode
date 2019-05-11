// finatest.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "finatest.h"

#define MAX_LOADSTRING 100

wchar_t  buttonname[6][5] =
{
	TEXT("矩形"),
	TEXT("椭圆"),
	TEXT("红色"),
	TEXT("黑色"),
	TEXT("绿色"),
	TEXT("动态菜单")

};
int mymessage = 0;

#define B_rect 1
#define B_ellipse 2
#define B_red 4
#define B_black 8
#define B_green 16
#define B_meun 32

HMENU hmenu;


// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About1(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About2(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_FINATEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_FINATEST));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FINATEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_FINATEST);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
	const int buttonlen = 6;
	static HWND hwndbutton[buttonlen];
	static int cxchar, cychar;
	static int cxclient=640, cyclient=480;
	static int by = cyclient / 8, dy = (cyclient - 6 * by) / 10, bx = cxclient / 5;
    switch (message)
    {
	case WM_CREATE:
		{
			MoveWindow(hWnd, 0, 0, cxclient, cyclient,true);
			cxchar = LOWORD(GetDialogBaseUnits());
			cychar = HIWORD(GetDialogBaseUnits());
			hmenu = LoadMenu(hInst, MAKEINTRESOURCEW(IDR_MENU1));
			hmenu = GetSubMenu(hmenu, 0);
			for (int i = 0; i < buttonlen; ++i)
				hwndbutton[i] = CreateWindow(TEXT("button"),
					buttonname[i],
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					cxchar, (dy+by )*i,
					bx, by,
					hWnd, (HMENU)i,
					((LPCREATESTRUCT)lParam)->hInstance, NULL);

		}
		break;
	case WM_SIZE:
		cxclient = LOWORD(lParam);
		cyclient = HIWORD(lParam);
		by = cyclient / 8, dy = (cyclient - 6 * by) / 5, bx = cxclient / 5;
		for (int i = 0; i < buttonlen; ++i)
			MoveWindow(hwndbutton[i], cxchar, (dy + by) * i, bx, by, true);
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
			case 0:
				mymessage ^= 1;
				InvalidateRect(hWnd, NULL, true);
				break;
			case 1:
				mymessage ^= 2;
				InvalidateRect(hWnd, NULL, true);
				break;
			case 2:
				mymessage ^= 4;
				if (mymessage & 8)
					mymessage ^= 8;
				if (mymessage & 16)
					mymessage ^= 16;
				InvalidateRect(hWnd, NULL, true);
				break;
			case 3:
				mymessage ^= 8;
				if (mymessage & 4)
					mymessage ^= 4;
				if (mymessage & 16)
					mymessage ^= 16;
				InvalidateRect(hWnd, NULL, true);
				break;
			case 4:
				mymessage ^= 16;
				if (mymessage & 4)
					mymessage ^= 4;
				if (mymessage & 8)
					mymessage ^= 8;
				InvalidateRect(hWnd, NULL, true);
				break;
			case 5:
				mymessage ^= 32;
				TrackPopupMenu(hmenu, NULL, cxclient / 3, 0, 0, hWnd, NULL);
				AppendMenu(hmenu, MF_STRING, 10, TEXT("add"));
				InvalidateRect(hWnd, NULL, true);
				break;
			case ID_FUN_32772:
			{
				HWND t = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, About1);
				ShowWindow(t, SW_SHOW);
			}
				break;
			case ID_FUN_32773:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, About2);
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
			HBRUSH hbr = NULL;
			if (mymessage & B_black)
			{
				hbr = CreateSolidBrush(RGB(0, 0, 0));
				SelectObject(hdc, hbr);
			}
			if (mymessage & B_red)
			{
				hbr = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, hbr);
			}
			if (mymessage & B_green)
			{
				hbr = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, hbr);
			}
			if (mymessage & B_rect)
				Rectangle(hdc, cxclient / 4, cyclient / 4, cxclient * 3 / 4, cyclient * 3 / 4);
			if (mymessage & B_ellipse)
				Ellipse(hdc, cxclient / 4, cyclient / 4, cxclient * 3 / 4, cyclient * 3 / 4);
			if (mymessage & B_black)
				DeleteObject(hbr);
			if (mymessage & B_red)
				DeleteObject(hbr);
			if (mymessage & B_green)
				DeleteObject(hbr);
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

INT_PTR CALLBACK About1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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

INT_PTR CALLBACK About2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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