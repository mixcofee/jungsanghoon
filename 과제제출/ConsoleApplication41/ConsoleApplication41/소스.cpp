#include"GameManager.h"

void main()
{
	srand(time(NULL));
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc=201;
	GameManager gamemanager;
	gamemanager.GameTitle();
}