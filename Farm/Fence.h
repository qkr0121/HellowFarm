#pragma once
#include "Managers.h"

// ��Ÿ���� ������ ��Ÿ���� ����ü
struct Fence
{
public:

	// ��Ÿ���� ���������� �� �ð�
	int year, month, day, hour;

	// �������� �ܰ�
	int level;

	// ���������� ������ �ð�
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