#pragma once
#include "Managers.h"

// ������ ������ ��Ÿ���� ����ü
struct Tree
{
public:

	// ������ �ɾ��� �ð�(���Ű� �ʱ�ȭ�� �ð�)
	int year, month, day, hour;

	// ���� �ܰ�
	int level;

	// ���Ű� ������ �ð�
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