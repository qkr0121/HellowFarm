#pragma once
#include "Managers.h"

// 시간을 나타내는 클래스
class Time
{
protected:
	int Year;
	int Month;
	int Day;
	int Hour;
	string Season;

public:

	// 계절 검사
	void SetSeason(int month);

	// 시간 조정
	void TimeCheck();

	// 한시간 추가
	virtual void AddHour();

	// 현 시각 출력
	void PrintTime();

};