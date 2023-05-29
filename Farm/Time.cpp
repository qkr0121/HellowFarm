#include "Time.h"


// 계절검사
void Time::SetSeason(int month)
{
	if (month > 2  && month < 6) Season = "봄";
	else if (month > 5 && month < 9) Season = "여름";
	else if (month > 8 && month < 12) Season = "가을";
	else if (month == 12 || (month > 0 && month < 3)) Season = "겨울";
}

// 시간 조정
void Time::TimeCheck()
{
	// 24시 를 초과하였을 경우
	if (Hour > 24)
	{
		// 31일 이었을 경우
		if ((Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) && (Day == 31))
		{
			// 12월 이었을 경우
			if (Month == 12)
			{
				Year++;
				Month = 1;
			}
			else Month++;
			Day = 1;
		}
		// 30일 이었을 경우
		else if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && (Day == 30))
		{
			Month++;
			Day = 1;
		}
		// 2월 28일 이었을 경우
		else if (Month == 2 && Day == 28)
		{
			Month++;
			Day = 1;
		}
		else Day++;

		Hour = Hour - 24;
	}

	// 계절 조정
	SetSeason(Month);
}

// 한시간 추가
void Time::AddHour()
{
}

// 현 시간 출력
void Time::PrintTime()
{
	cout << Year << "년 " << Month << "월 " << Day << "일 " << Hour << "시 계절 : " << Season << endl;
}
