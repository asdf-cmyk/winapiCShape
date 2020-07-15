// Win32Project2.cpp : Defines the entry point for the application.
//

#include "..\stdafx.h"
#include "..\Win32Project2.h"
#include "..\Resource.h"
#include "CShape.h"
#include "Rect.h"
#include "Circle.h"
#include <vector>

using namespace std;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

												// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void DrawGrid(HDC, int, int, int, int, int);
void DrawCircle(HDC, double, double, double);
int DrawFlower(HDC, int, int, int, int);
void DrawStar(HDC, int, int, int);
POINT crammer(POINT, POINT, POINT, POINT);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WIN32PROJECT2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT2));

	MSG msg;

	// Main message loop:
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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT2));
	wcex.hCursor = LoadCursor(nullptr, IDC_CROSS);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN32PROJECT2);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(/*wcex.hInstance*/NULL, MAKEINTRESOURCE(IDI_QUESTION));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, /*szTitle*/_T("두 번째 윈도우"), WS_OVERLAPPEDWINDOW,
		200, 200, 1200, 800, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	static int count, yPos, x, y, r3;
	static int mx, my;
	//RECT rt = { 0, yPos, 1000, 500 };
	static RECT rectView;
	static POINT rectP[4];
	static vector<CShape> vCont;

	switch (message)
	{
	case WM_CREATE:
		GetClientRect(hWnd, &rectView);
		x = (rectView.left + rectView.right) / 2;
		y = (rectView.top + rectView.bottom) / 2;
		break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
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
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...

		/*HPEN hPen, oldPen, hPen2;
		hPen = CreatePen(PS_DOT, 1, RGB(0, 255, 0));
		oldPen = (HPEN)SelectObject(hdc, hPen);

		HBRUSH hBrush, oldBrush;
		hBrush = CreateSolidBrush(RGB(0, 255, 0));
		oldBrush = (HBRUSH)SelectObject(hdc, hBrush);*/

		//WCHAR str[15] = L"가나다라abcd";
		/*TCHAR str2[15] = _T("가나다라abcd");
		TextOut(hdc, 100, 100, str2, _tcslen(str2));
		RECT rc;
		rc.left = 450;
		rc.top = 0;
		rc.right = 550;
		rc.bottom = 100;
		SetTextColor(hdc, RGB(255, 0, 255));
		DrawText(hdc, str2, _tcslen(str2), &rc,
		DT_SINGLELINE | DT_LEFT);*/

		//TextOut(hdc, 0, yPos, str, _tcslen(str));
		/*Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
		DrawText(hdc, str, _tcslen(str), &rt, DT_LEFT);
		DrawText(hdc, str, _tcslen(str), &rt, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		DrawText(hdc, str, _tcslen(str), &rt, DT_SINGLELINE | DT_BOTTOM | DT_RIGHT);*/

		//GetTextExtentPoint(hdc, str, _tcslen(str), &size);
		//SetCaretPos(size.cx, yPos);

		//r3 = DrawFlower(hdc, x, y, 50, 8);
		//DrawGrid(hdc, 100, 100, 1000, 500, 50);
		//SelectObject(hdc, oldBrush);
		//DeleteObject(hBrush);

		//hPen2 = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		//SelectObject(hdc, hPen2);
		//SelectObject(hdc, GetStockObject(NULL_BRUSH));
		//DrawStar(hdc, 600, 350, 300);

		//SelectObject(hdc, oldPen);
		//DeleteObject(hPen);
		//DeleteObject(hPen2);
		for (int i=0; i<vCont.size(); i++)
		{
			switch (vCont[i].getType())
			{
			case 1:
				rectP[0] = { vCont[i].getPoint()[0] - vCont[i].getRadius(),
					vCont[i].getPoint()[1] - vCont[i].getRadius() };
				rectP[1] = { vCont[i].getPoint()[0] + vCont[i].getRadius(),
					vCont[i].getPoint()[1] - vCont[i].getRadius() };
				rectP[2] = { vCont[i].getPoint()[0] + vCont[i].getRadius(),
					vCont[i].getPoint()[1] + vCont[i].getRadius() };
				rectP[3] = { vCont[i].getPoint()[0] - vCont[i].getRadius(),
					vCont[i].getPoint()[1] + vCont[i].getRadius() };
				/*Rectangle(hdc,
					vCont[i].getPoint()[0] - vCont[i].getRadius(),
					vCont[i].getPoint()[1] - vCont[i].getRadius(),
					vCont[i].getPoint()[0] + vCont[i].getRadius(),
					vCont[i].getPoint()[1] + vCont[i].getRadius());*/
				Polygon(hdc, rectP, 4);
				break;
			case 2:
				Ellipse(hdc,
					vCont[i].getPoint()[0] - vCont[i].getRadius(),
					vCont[i].getPoint()[1] - vCont[i].getRadius(),
					vCont[i].getPoint()[0] + vCont[i].getRadius(),
					vCont[i].getPoint()[1] + vCont[i].getRadius());
				break;
			}
			SetTimer(hWnd, 1, 30, NULL);
		} // for end
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_LBUTTONDOWN:
	{
		{
			mx = LOWORD(lParam);
			my = HIWORD(lParam);
			CShape poly;
			int tmpN = poly.mkRand(3);
			switch (tmpN)
			{
			case 1:
				poly = Rect(mx, my);
				break;
			case 2:
				poly = Circle(mx, my);
				break;
			}
			vCont.push_back(poly);
			/*if (tmpN == 1)
			{
				Rect s = Rect(mx, my);
				vCont.push_back(s);
			}
			else if (tmpN == 2)
			{
				Circle s = Circle(mx, my);
				vCont.push_back(s);
			}*/
			//SetTimer(hWnd, 1, 30, NULL);
		}
		InvalidateRgn(hWnd, NULL, TRUE);
	}
	break;
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1:
			for (int i = 0; i<vCont.size(); i++)
			{
				vCont[i].getPoint()[0] +=
					vCont[i].getSpeed()[0] * vCont[i].getVector()[0];
				if(vCont[i].getPoint()[0]+vCont[i].getRadius() > rectView.right ||
					vCont[i].getPoint()[0]-vCont[i].getRadius() < rectView.left)
					vCont[i].getVector()[0] *= -1;
				
				vCont[i].getPoint()[1] +=
					vCont[i].getSpeed()[1] * vCont[i].getVector()[1];
				if (vCont[i].getPoint()[1]+vCont[i].getRadius() > rectView.bottom ||
					vCont[i].getPoint()[1]-vCont[i].getRadius() < rectView.top)
					vCont[i].getVector()[1] *= -1;
			} // for end
			break;
		}
	}
	InvalidateRgn(hWnd, NULL, TRUE);
	break;
	case WM_KEYDOWN:
	{
		int pos = 30;
		switch (wParam)
		{
		case VK_LEFT:
			SetTimer(hWnd, 1, 70, NULL);
			break;
		case VK_UP:
			SetTimer(hWnd, 2, 200, NULL);
			break;
		case VK_RIGHT:
			x += pos;
			if (x + (pos + r3) > rectView.right) x -= pos;
			break;
		case VK_DOWN:
			y += pos;
			if (y + (pos + r3) > rectView.bottom) y -= pos;
			break;
		}
		InvalidateRgn(hWnd, NULL, TRUE);
	}
	break;
	case WM_CHAR:
	{
		InvalidateRgn(hWnd, NULL, TRUE);
	}
	break;
	case WM_DESTROY:
		HideCaret(hWnd);
		DestroyCaret();
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
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

void DrawGrid(HDC hdc, int left, int top, int right, int bottom, int num)
{
	for (int i = 0; i <= ((right - left) / num); i++)
	{
		MoveToEx(hdc, left + i*num, top, NULL);
		LineTo(hdc, left + i*num, bottom);
	}
	for (int i = 0; i <= ((bottom - top) / num); i++)
	{
		MoveToEx(hdc, left, top + i*num, NULL);
		LineTo(hdc, right, top + i*num);
	}
}

void DrawCircle(HDC hdc, double centerX, double centerY, double r1)
{
	Ellipse(hdc, centerX - r1, centerY - r1, centerX + r1, centerY + r1);
}

int DrawFlower(HDC hdc, int centerX, int centerY, int r1, int petal)
{
	DrawCircle(hdc, centerX, centerY, r1);

	double sinT = sin(2 * acos(0.0) / 180 * (180 / petal));
	double r2 = (r1 * sinT) / (1 - sinT);
	for (int i = 0; i < petal; i++)
		DrawCircle(hdc,
			centerX + (r1 + r2)*cos((2 * acos(0.0) / 180 * (90 - (360 / petal)*i))),
			centerY + (r1 + r2)*sin((2 * acos(0.0) / 180 * (90 - (360 / petal)*i))),
			r2);
	return r1 + r2;
}

void DrawStar(HDC hdc, int x, int y, int r)
{
	POINT starP[10];

	for (int i = 0; i < 5; i++)
		starP[0 + 2 * i] =
	{ long(double(x) + r*cos(2 * acos(0.0) / 180 * (90 - 72 * i))),
		long(double(y) - r*sin(2 * acos(0.0) / 180 * (90 - 72 * i))) };

	for (int i = 0; i < 5; i++)
		starP[1 + 2 * i] =
		crammer(starP[(0 + 2 * i) % 10], starP[(4 + 2 * i) % 10],
			starP[(2 + 2 * i) % 10], starP[(8 + 2 * i) % 10]);

	Polygon(hdc, starP, 10);
}

POINT crammer(POINT p1, POINT p2, POINT p3, POINT p4)
{
	long a, b, c, d, e, f;

	a = p1.y - p2.y;
	b = -(p1.x - p2.x);
	c = p3.y - p4.y;
	d = -(p3.x - p4.x);
	/*e = a*p1.x + b*p1.y;
	f = c*p3.x + d*p3.y;*/
	e = a*p4.x + b*p4.y;
	f = c*p3.x + d*p3.y;

	return{ (e*d - b*f) / (a*d - b*c),
		(a*f - e*c) / (a*d - b*c) };
}