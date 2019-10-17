#include<windows.h>
#include<math.h>
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("FixcelCircle");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

int rad = 100;
int centerX = 300;
int centerY = 300;
int posX = 0;
int posY = 0;
int Hour = 0;
int Minute = 0;
int Second = 0;
int circleNum = 0;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	SYSTEMTIME st;
	static TCHAR sTime[128];

	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 1000, NULL);
		SetTimer(hWnd, 2, 100, NULL);
		SendMessage(hWnd, WM_TIMER, 1, 0);

	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			GetLocalTime(&st);
			wsprintf(sTime, TEXT("지금 시간은 %d:%d:%d 입니다."), st.wHour, st.wMinute, st.wSecond);
			Hour = (st.wHour %= 12);
			if (Hour == 0)
				Hour = 1;
			Minute = st.wMinute;
			Second = st.wSecond;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 2:
			circleNum++;
			if (circleNum == 360)
				circleNum = 0;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 200, 130, sTime, lstrlen(sTime));

		// 시계의 원틀
		for (int i = 0; i < 360; i += 6)
		{
			posX = centerX + rad * cosf(i * (3.14 / 180));
			posY = centerY + rad * sinf(i * (3.14 / 180));
			SetPixel(hdc, posX, posY, (0, 255, 0));
		}
		// 분침칸
		for (int i = 0; i < 360; i += 30)
		{
			posX = centerX + (rad - 10)* cosf(i* (3.14 / 180));
			posY = centerY + (rad - 10)* sinf(i* (3.14 / 180));
			MoveToEx(hdc, posX, posY, NULL);
			posX = centerX + rad * cosf(i* (3.14 / 180));
			posY = centerY + rad * sinf(i* (3.14 / 180));
			LineTo(hdc, posX, posY);
		}
		//시계 중앙원
		Ellipse(hdc, centerX - 5, centerY - 5, centerX + 5, centerY + 5);

		// 시침
		MoveToEx(hdc, centerX, centerY, NULL);
		posX = centerX + (rad - 50)*cosf((Hour - 15) * 30 * (3.14 / 180));
		posY = centerY + (rad - 50)*sinf((Hour - 15) * 30 * (3.14 / 180));
		LineTo(hdc, posX, posY);

		// 분침
		MoveToEx(hdc, centerX, centerY, NULL);
		posX = centerX + (rad - 20)*cosf((Minute - 15) * 6 * (3.14 / 180));
		posY = centerY + (rad - 20)*sinf((Minute - 15) * 6 * (3.14 / 180));
		LineTo(hdc, posX, posY);

		// 초침
		MoveToEx(hdc, centerX, centerY, NULL);
		posX = centerX + (rad - 10)*cosf((Second - 15) * 6 * (3.14 / 180));
		posY = centerY + (rad - 10)*sinf((Second - 15) * 6 * (3.14 / 180));
		LineTo(hdc, posX, posY);

		// 시계틀에 자동으로 도는 원형
		posX = centerX + rad * cosf(circleNum * 6 * (3.14 / 180));
		posY = centerY + rad * sinf(circleNum * 6 * (3.14 / 180));
		Ellipse(hdc, posX - 10, posY - 10, posX + 10, posY + 10);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		KillTimer(hWnd, 1);
		KillTimer(hWnd, 2);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

