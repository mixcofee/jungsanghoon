#include<Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("HelloWorld");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdSnow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdSnow);
	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x = 100;
	static int y = 100;
	static bool Check = true;

	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			if (x > 50)
				x -= 1;
			break;
		case VK_RIGHT:
			if (x < 170)
				x += 1;
			break;
		case VK_UP:
			if (y > 50)
				y -= 1;
			break;
		case VK_DOWN:
			if (y < 170)
				y += 1;
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
		
	case WM_MOUSEMOVE:
		if (LOWORD(lParam) > 50 && LOWORD(lParam) < 170)
			x = LOWORD(lParam);
		if (HIWORD(lParam) > 50 && HIWORD(lParam) < 170)
			y = HIWORD(lParam);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;

	case WM_LBUTTONDOWN:
		if (MessageBox(hWnd, TEXT("마우스 좌클릭"),TEXT("도형 변경"), MB_OKCANCEL) == IDOK)
		{
			if (Check == true)
				Check = false;
			else
				Check = true;
		}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, 20, 20, 200, 200);
		if (Check == true)
			Ellipse(hdc, x - 30, y - 30, x + 30, y + 30);
		else
			Rectangle(hdc, x - 30, y - 30, x + 30, y + 30);
		EndPaint(hWnd, &ps);
		return 0;
		
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

