#pragma once
#include "Managers.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define GROW 5

enum
{
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

void Init();

void GotoXY(int x, int y);

int KeyControl();

// 텍스트 색변경
void SetColor(int forground, int background);