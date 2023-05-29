#pragma once
#include "Managers.h"

// �翡 �ɾ��� ���۹��� ������ ��Ÿ���� ���� ����ü
struct Field
{
public:

	// ���۹��� �ɾ��� �ð�
	int year, month, day, hour;

	// ���۹� �ܰ�
	int level;

	// ���۹��� ������ �ð�
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