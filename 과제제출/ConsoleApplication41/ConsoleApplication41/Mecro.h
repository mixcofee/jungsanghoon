#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<time.h>
#include"conio.h"
#include<crtdbg.h>
using namespace std;

#define LOW_MAP_X 10
#define LOW_MAP_Y 10
#define NORMAL_MAP_X 20
#define NORMAL_MAP_Y 20
#define HIGH_MAP_X 30
#define HIGH_MAP_Y 30
#define LEFT   75    
#define RIGHT  77    
#define UP     72  
#define DOWN   80 
#define SPACE 32
#define ENTER 13


inline void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
