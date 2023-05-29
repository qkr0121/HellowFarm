#include "Time.h"


// �����˻�
void Time::SetSeason(int month)
{
	if (month > 2  && month < 6) Season = "��";
	else if (month > 5 && month < 9) Season = "����";
	else if (month > 8 && month < 12) Season = "����";
	else if (month == 12 || (month > 0 && month < 3)) Season = "�ܿ�";
}

// �ð� ����
void Time::TimeCheck()
{
	// 24�� �� �ʰ��Ͽ��� ���
	if (Hour > 24)
	{
		// 31�� �̾��� ���
		if ((Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) && (Day == 31))
		{
			// 12�� �̾��� ���
			if (Month == 12)
			{
				Year++;
				Month = 1;
			}
			else Month++;
			Day = 1;
		}
		// 30�� �̾��� ���
		else if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && (Day == 30))
		{
			Month++;
			Day = 1;
		}
		// 2�� 28�� �̾��� ���
		else if (Month == 2 && Day == 28)
		{
			Month++;
			Day = 1;
		}
		else Day++;

		Hour = Hour - 24;
	}

	// ���� ����
	SetSeason(Month);
}

// �ѽð� �߰�
void Time::AddHour()
{
}

// �� �ð� ���
void Time::PrintTime()
{
	cout << Year << "�� " << Month << "�� " << Day << "�� " << Hour << "�� ���� : " << Season << endl;
}
