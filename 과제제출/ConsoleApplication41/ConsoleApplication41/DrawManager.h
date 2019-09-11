#pragma once
#include"Mecro.h"
class DrawManager
{
private:

public:
	void DrawMap(int x, int y);
	void DrawPoint(string str, int x, int y);
	void ErasePoint(string str, int x, int y);
	DrawManager();
	~DrawManager();
};

