// 实验1.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "实验1.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
LPCWSTR stringToLPCWSTR(std::string orig);      // string转LPCWSTR

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
    LoadStringW(hInstance, IDC_MY1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY1));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY1);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW|WS_VSCROLL|WS_HSCROLL,
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
	static int 行间距,iVscrollPos,cyChar,cxChar,cxCaps;
	static int cxClient, cyClient;
	TEXTMETRIC tm;
	std::string str;
	LPCWSTR lpc;
	const int 滚动条长度 = 150;
	const int 滚动条起点 = 1;
	const int 行间距最大 = 10;

    switch (message)
    {
	case WM_CREATE:
		{
			HDC hdc = GetDC(hWnd);
			GetTextMetrics(hdc, &tm);
			cxChar = tm.tmAveCharWidth;
			cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2)*cxChar / 2;
			cyChar = tm.tmHeight + tm.tmExternalLeading;
			行间距 = 1;
			SetScrollRange(hWnd, SB_HORZ, 滚动条起点, 行间距最大, TRUE);
			SetScrollPos(hWnd, SB_HORZ, 0, TRUE);
			iVscrollPos = 1;
			SetScrollRange(hWnd, SB_VERT, 滚动条起点, 滚动条长度, TRUE);
			SetScrollPos(hWnd, SB_VERT, 0, TRUE);
			//InvalidateRect(hWnd, NULL, TRUE);   //不知道为啥没用
			ReleaseDC(hWnd, hdc);
			MoveWindow(hWnd, 0, 0, 640, 480, TRUE);
		}
		break;
	case WM_SIZE: 
		{
			cxClient = LOWORD(lParam);
			cyClient = HIWORD(lParam); 
		}
		break;
	case WM_HSCROLL:
		{
			switch (LOWORD(wParam))
			{
			case SB_LINELEFT:
				行间距--;
				break;
			case SB_LINERIGHT:
				行间距++;
				break;
			case SB_PAGELEFT:
				行间距 -= cyClient / cyChar;
				break;
			case SB_PAGERIGHT:
				行间距 += cyClient / cyChar;
				break;
			case SB_THUMBTRACK:
				行间距 = HIWORD(wParam);
				break;
			}

			行间距 = max(滚动条起点, min(行间距, 10));

			//iVscrollPos = max(0, min(iVscrollPos, NUMLINES - 1));
			if (行间距 != GetScrollPos(hWnd, SB_HORZ))
			{
				SetScrollPos(hWnd, SB_HORZ, 行间距, TRUE);
				InvalidateRect(hWnd, NULL, TRUE);
			}
		}
		break;
	case WM_VSCROLL: 
		{
			switch (LOWORD(wParam))
			{
			case SB_LINEUP:
				iVscrollPos--;
				break;
			case SB_LINEDOWN:
				iVscrollPos++;
				break;
			case SB_PAGEUP:
				iVscrollPos -= cyClient / cyChar;
				break;
			case SB_PAGEDOWN:
				iVscrollPos += cyClient / cyChar;
				break;
			case SB_THUMBTRACK:
				iVscrollPos = HIWORD(wParam);
				break;
			}

			iVscrollPos = max(滚动条起点, min(iVscrollPos, 滚动条长度));

			//iVscrollPos = max(0, min(iVscrollPos, NUMLINES - 1));
			if (iVscrollPos != GetScrollPos(hWnd, SB_VERT))
			{
				SetScrollPos(hWnd, SB_VERT, iVscrollPos, TRUE);
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
			int i,j;
			for (i = 0; i < cyClient / (cyChar+行间距) && i + iVscrollPos <= 150; ++i)
			{
				str = std::string("Hello World: ")+std::to_string(i+iVscrollPos);
				lpc = stringToLPCWSTR(str);
				int length = lstrlen(lpc);
				//TextOut(hdc, 0, i*cyChar+i*行间距*cyChar, lpc, length);
			}
			i = 0;
			str = std::string("1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNMM,./;'[]\-=`");
			int max行字符数 = cxClient / ((cxChar+cxCaps)/2);
			for (j = 0; j*max行字符数 + max行字符数 < str.size(); ++j,++i)
			{
				lpc = stringToLPCWSTR(str.substr(j*max行字符数, max行字符数));
				int length = lstrlen(lpc);
				TextOut(hdc, 0, i*cyChar + i * 行间距*cyChar - (i + iVscrollPos - 1), lpc, length);
			}
			lpc = stringToLPCWSTR(str.substr(j*max行字符数, str.size()- j * max行字符数));
			int length = lstrlen(lpc);
			TextOut(hdc, 0, i*cyChar + i * 行间距*cyChar - (i + iVscrollPos - 1), lpc, length);
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

LPCWSTR stringToLPCWSTR(std::string orig)
{
	wchar_t *wcstring = 0;
	try
	{
		size_t origsize = orig.length() + 1;
		const size_t newsize = 100;
		size_t convertedChars = 0;
		if (orig == "")
		{
			wcstring = (wchar_t *)malloc(0);
			mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
		}
		else
		{
			wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length() - 1));
			mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
		}
	}
	catch (std::exception e) {}return wcstring;
}