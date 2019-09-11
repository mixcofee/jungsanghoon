#include"GameManager.h"


DrawManager::DrawManager()
{
}

void DrawManager::DrawMap(int x, int y)
{
	system("cls");
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			cout << "■";
		cout << endl;
	}
	cout << "엔터 : 깃발 체크" << endl;
	cout << "c,C : 깃발 취소" << endl;
	cout << "스페이스 : 선택" << endl;
}

void DrawManager::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void DrawManager::ErasePoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

DrawManager::~DrawManager()
{
}
