#pragma once
#include "Managers.h"

// �ð��� ��Ÿ���� Ŭ����
class Time
{
protected:
	int Year;
	int Month;
	int Day;
	int Hour;
	string Season;

public:

	// ���� �˻�
	void SetSeason(int month);

	// �ð� ����
	void TimeCheck();

	// �ѽð� �߰�
	virtual void AddHour();

	// �� �ð� ���
	void PrintTime();

};