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
			cout << "��";
		cout << endl;
	}
	cout << "���� : ��� üũ" << endl;
	cout << "c,C : ��� ���" << endl;
	cout << "�����̽� : ����" << endl;
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
