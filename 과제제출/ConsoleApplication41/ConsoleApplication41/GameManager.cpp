#include "GameManager.h"



GameManager::GameManager()
{
	m_Map = NULL;
}

void GameManager::GameTitle()
{
	int Select;
	cout << "===== 지뢰 찾기 =====" << endl;
	cout << "1. 게임 시작" << endl;
	cout << "2. 게임 종료" << endl;
	cout << "입력 : ";
	cin >> Select;
	switch (Select)
	{
	case GAMEMENU_START:
		SetPlayer();
		GameLevel();
		break;
	case GAMEMENU_EXIT:
		break;
	default:
		break;
	}
}

void GameManager::DeleteMap(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		delete[] m_Map[i];
	}
	delete[] m_Map;
}

void GameManager::SetMap(int x, int y)
{
	m_Map = new Map*[y];
	for (int i = 0; i < y; i++)
		m_Map[i] = new Map[x];
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			m_Map[i][j].InputCheck = false;
			m_Map[i][j].MineCheck = false;
			m_Map[i][j].Shape = "■";
		}
	}
	SetMine(x, y);
}

void GameManager::SetPlayer()
{
	m_Player.Shpae = "♠";
	m_Player.x = 0;
	m_Player.y = 0;
}

void GameManager::PlayerMove(bool& Flag, int x, int y)
{
	char ch;
	ch = getch();
	switch (ch)
	{
	case LEFT:
		if (m_Player.x - 1 >= 0)
		{
			m_DrawManager.ErasePoint(m_Map[m_Player.x][m_Player.y].Shape, m_Player.x, m_Player.y);
			m_Player.x -= 1;
		}
		break;
	case RIGHT:
		if (m_Player.x + 1 <= x-1)
		{
			m_DrawManager.ErasePoint(m_Map[m_Player.x][m_Player.y].Shape, m_Player.x, m_Player.y);
			m_Player.x += 1;
		}
		break;
	case UP:
		if (m_Player.y - 1 >= 0)
		{
			m_DrawManager.ErasePoint(m_Map[m_Player.x][m_Player.y].Shape, m_Player.x, m_Player.y);
			m_Player.y -= 1;
		}
		break;
	case DOWN:
		if (m_Player.y + 1 <= y-1)
		{
			m_DrawManager.ErasePoint(m_Map[m_Player.x][m_Player.y].Shape, m_Player.x, m_Player.y);
			m_Player.y += 1;
		}
		break;
	case ENTER:
		if (m_iFlagCount)
		{
			if (m_Map[m_Player.x][m_Player.y].InputCheck == false)
			{
				m_Map[m_Player.x][m_Player.y].Shape = "¶";
				m_iFlagCount--;
			}
		}
		break;
	case 'c':
	case 'C':
		if (m_Map[m_Player.x][m_Player.y].InputCheck == false)
			m_Map[m_Player.x][m_Player.y].Shape = "■";
		break;
	case SPACE:
		if (m_Map[m_Player.x][m_Player.y].MineCheck == true && m_Map[m_Player.x][m_Player.y].Shape != "¶")
		{
			cout << "지뢰 밟음!! 게임종료" << endl;
			system("pause");
			Flag = false;
		}
		else if (m_Map[m_Player.x][m_Player.y].MineCheck == false && m_Map[m_Player.x][m_Player.y].Shape != "¶")
			MineSearch(m_Player.x, m_Player.y, x, y);
		break;
	}
		m_DrawManager.DrawPoint(m_Player.Shpae, m_Player.x, m_Player.y);
}

void GameManager::SetMine(int x, int y)
{
	int Count = 0;
	int Sum = (x*y)*0.2;
	m_iFlagCount = Sum;
	while (Count < Sum - 1)
	{
		bool Check = true;
		int RandX = rand() % 10;
		int RandY = rand() % 10;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (m_Map[RandX][RandY].MineCheck == false)
					Check = false;
			}
		}
		if (Check == false)
		{
			m_Map[RandX][RandY].MineCheck = true;
			Count++;
		}
	}
}


void GameManager::GameLevel()
{
	system("cls");
	int Select;
	bool Flag = true;
	cout << "1. 초급 난이도" << endl;
	cout << "2. 중급 난이도" << endl;
	cout << "3. 고급 난이도" << endl;
	cout << "입력 : ";
	cin >> Select;
	switch (Select)
	{
	case GAMELEVEL_LOW:
		SetMap(LOW_MAP_X, LOW_MAP_Y);
		m_DrawManager.DrawMap(LOW_MAP_X, LOW_MAP_Y);
		m_DrawManager.DrawPoint(m_Player.Shpae, m_Player.x, m_Player.y);
		while (1)
		{
			PlayerMove(Flag, LOW_MAP_X, LOW_MAP_Y);
			if (WinCheck(LOW_MAP_X, LOW_MAP_Y) == true)
			{
				cout << "승리!!" << endl;
				DeleteMap(LOW_MAP_X, LOW_MAP_Y);
				return;
			}
			if (Flag == false)
			{
				DeleteMap(LOW_MAP_X, LOW_MAP_Y);
				return;
			}
		}
		break;
	case GAMELEVEL_NORMAL:
		SetMap(NORMAL_MAP_X, NORMAL_MAP_Y);
		m_DrawManager.DrawMap(NORMAL_MAP_X, NORMAL_MAP_Y);
		m_DrawManager.DrawPoint(m_Player.Shpae, m_Player.x, m_Player.y);
		while (1)
		{
			PlayerMove(Flag, NORMAL_MAP_X, NORMAL_MAP_Y);
			if (WinCheck(NORMAL_MAP_X, NORMAL_MAP_Y) == true)
			{
				cout << "승리!!" << endl;
				DeleteMap(NORMAL_MAP_X, NORMAL_MAP_Y);
				return;
			}
			if (Flag == false)
			{
				DeleteMap(NORMAL_MAP_X, NORMAL_MAP_Y);
				return;
			}
		}
		break;
	case GAMELEVEL_HIGH:
		SetMap(HIGH_MAP_X, HIGH_MAP_Y);
		m_DrawManager.DrawMap(HIGH_MAP_X, HIGH_MAP_Y);
		m_DrawManager.DrawPoint(m_Player.Shpae, m_Player.x, m_Player.y);
		while (1)
		{
			PlayerMove(Flag, HIGH_MAP_X, HIGH_MAP_Y);
			if (WinCheck(HIGH_MAP_X, HIGH_MAP_Y) == true)
			{
				cout << "승리!!" << endl;
				DeleteMap(HIGH_MAP_X, HIGH_MAP_Y);
				return;
			}
			if (Flag == false)
			{
				DeleteMap(HIGH_MAP_X, HIGH_MAP_Y);
				return;
			}
		}
		break;
	default:
		break;
	}
}

void GameManager::MineSearch(int x, int y, int Mapx, int Mapy)
{
	int MineCount = 0;
	if (x > 0 && x < Mapx - 1 && y>0 && y < Mapy - 1)
	{
		if (m_Map[x - 1][y - 1].MineCheck == true)
			MineCount++;
		if (m_Map[x - 1][y].MineCheck == true)
			MineCount++;
		if (m_Map[x - 1][y + 1].MineCheck == true)
			MineCount++;
		if (m_Map[x][y - 1].MineCheck == true)
			MineCount++;
		if (m_Map[x][y + 1].MineCheck == true)
			MineCount++;
		if (m_Map[x + 1][y - 1].MineCheck == true)
			MineCount++;
		if (m_Map[x + 1][y].MineCheck == true)
			MineCount++;
		if (m_Map[x + 1][y + 1].MineCheck == true)
			MineCount++;
	}
	else if (x == 0 && y == 0)
	{
		if (m_Map[x + 1][y].MineCheck == true)
			MineCount++;
		if (m_Map[x][y + 1].MineCheck == true)
			MineCount++;
		if (m_Map[x + 1][y + 1].MineCheck == true)
			MineCount++;
	}
	else if (x == Mapx - 1 && y == 0)
	{
		if (m_Map[x - 1][y].MineCheck == true)
			MineCount++;
		if (m_Map[x][y + 1].MineCheck == true)
			MineCount++;
		if (m_Map[x - 1][y + 1].MineCheck == true)
			MineCount++;
	}
	else if (x == 0 && y == Mapy-1)
	{
		if (m_Map[x + 1][y].MineCheck == true)
			MineCount++;
		if (m_Map[x][y - 1].MineCheck == true)
			MineCount++;
		if (m_Map[x + 1][y - 1].MineCheck == true)
			MineCount++;
	}
	else if (x == Mapx-1 && y == Mapy-1)
	{
		if (m_Map[x - 1][y].MineCheck == true)
			MineCount++;
		if (m_Map[x][y - 1].MineCheck == true)
			MineCount++;
		if (m_Map[x - 1][y - 1].MineCheck == true)
			MineCount++;
	}
	if (MineCount == 0 && m_Map[x][y].MineCheck == false)
	{
		m_Map[x][y].Shape = "□";
		m_Map[x][y].InputCheck = true;
		m_DrawManager.DrawPoint(m_Map[x][y].Shape, x, y);
	}
	else if (MineCount != 0 && m_Map[x][y].MineCheck == false)
	{
		m_Map[x][y].Shape = to_string(MineCount);
		m_Map[x][y].InputCheck = true;
		m_DrawManager.DrawPoint(m_Map[x][y].Shape, x, y);
	}
	else
		return;
	if (MineCount == 0 && x + 1 <= Mapx - 1 && m_Map[x + 1][y].InputCheck == false)//오른쪽
		MineSearch(x + 1, y, Mapx, Mapy);
	if (MineCount == 0 && x - 1 >= 0 && m_Map[x - 1][y].InputCheck == false)//왼쪽
		MineSearch(x - 1, y, Mapx, Mapy);
	if (MineCount == 0 && y - 1 >= 0 && m_Map[x][y - 1].InputCheck == false)//위쪽
		MineSearch(x, y - 1, Mapx, Mapy);
	if (MineCount == 0 && y + 1 <= Mapy - 1 && m_Map[x][y + 1].InputCheck == false)//아래쪽
		MineSearch(x, y + 1, Mapx, Mapy);
}

bool GameManager::WinCheck(int x, int y)
{
	int InputCount = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (m_Map[i][j].InputCheck == true)
				InputCount++;
		}
	}
	if ((x*y) - InputCount == (x*y)*0.2)
		return true;
	return false;
}

GameManager::~GameManager()
{
}
