#pragma once
#include "Managers.h"

// 밭에 심어진 농작물의 정보를 나타내기 위한 구조체
struct Field
{
public:

	// 농작물이 심어진 시간
	int year, month, day, hour;

	// 농작물 단계
	int level;

	// 농작물이 성장한 시간
	int growTime;

	Field(int y, int m, int d, int h)
	{
		year = y;
		month = m;
		day = d;
		hour = h;
		level = 0;
		growTime = 0;
	}
};