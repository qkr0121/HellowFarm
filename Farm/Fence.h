#pragma once
#include "Managers.h"

// 울타리의 정보를 나타내는 구조체
struct Fence
{
public:

	// 울타리에 새끼동물이 들어간 시간
	int year, month, day, hour;

	// 새끼동물 단계
	int level;

	// 새끼동물이 성장한 시간
	int growTime;


	Fence(int y, int m, int d, int h)
	{
		year = y;
		month = m;
		day = d;
		hour = h;
		level = 0;
		growTime = 0;
	}
};