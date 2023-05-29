#pragma once
#include "Managers.h"

// 나무의 정보를 나타내는 구조체
struct Tree
{
public:

	// 나무가 심어진 시간(열매가 초기화된 시간)
	int year, month, day, hour;

	// 나무 단계
	int level;

	// 열매가 성장한 시간
	int growTime;


	Tree(int y, int m, int d, int h)
	{
		year = y;
		month = m;
		day = d;
		hour = h;
		level = 0;
		growTime = 0;
	}
};