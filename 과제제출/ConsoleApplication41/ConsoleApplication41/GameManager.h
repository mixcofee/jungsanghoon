#pragma once
#include"Mecro.h"
#include"DrawManager.h"
enum GAMEMENU
{
	GAMEMENU_START = 1,
	GAMEMENU_EXIT
};

enum GAMELEVEL
{
	GAMELEVEL_LOW = 1,
	GAMELEVEL_NORMAL,
	GAMELEVEL_HIGH
};
struct Player
{
	string Shpae;
	int x, y;
};

struct Map
{
	string Shape;
	bool MineCheck;
	bool InputCheck;
};
class GameManager
{
private:
	int m_iFlagCount;
	DrawManager m_DrawManager;
	Player m_Player;
	Map** m_Map;
public:
	void GameTitle();
	void GameLevel();
	void SetMap(int x, int y);
	void PlayerMove(bool& Flag, int x, int y);
	void SetMine(int x, int y);
	void SetPlayer();
	void MineSearch(int x, int y, int Mapx, int Mapy);
	void DeleteMap(int x, int y);
	bool WinCheck(int x, int y);
	GameManager();
	~GameManager();
};

