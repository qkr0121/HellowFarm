#include "Cow.h"

Cow::Cow()
{
	Name = "소";
	price = 3000;

	maxLevel = 3;
	maxSize = 300;
	havAnimals = 2;
	maxFence = 10;
	havFence = 1;
	maxgrowTime = 30;
	growingFence = 0;

	for (int i = 0;i < maxFence;i++)
	{
		fence[i] = nullptr;
	}
}

Cow::~Cow()
{
	for (int i = 0; i < maxFence; i++)
	{
		delete fence[i];
	}
}

// 동물을 얻고 저장
void Cow::GetAudult(Animals* animals, int num)
{
	// 동물을 한마리 추가합니다.
	animals->SethavAnimals(1);

	// 해당 울타리를 nullptr(빈 울타리) 로 초기화합니다
	animals->InitializeFence(num - 1);

	cout << "소 1마리를 획득하였습니다." << endl;
}

void Cow::InitializeFence(int num)
{
	fence[num] = nullptr;
}

// Set
void Cow::SetFence(int i, int y, int m, int d, int h)
{
	fence[i - 1] = new Fence(y, m, d, h);
}

void Cow::SetGrowingFence(bool tf)
{
	if (tf) growingFence++;
	else growingFence--;

	if (growingFence > 10) growingFence = 10;
	if (growingFence < 0) growingFence = 0;
}

void Cow::SethavAnimals(int i)
{
	havAnimals = havAnimals + i;
}

void Cow::SethavFence()
{
	havFence++;
}

void Cow::SetFenceLevel(int y, int m, int d, int h)
{
	for (int i = 0;i < havFence;i++)
	{
		if (fence[i] != nullptr)
		{
			// 농작물이 1시간 성장합니다.
			fence[i]->growTime++;

			// 시간의 차에 따라 성장레벨을 조정합니다.
			// 성장한시간이 maxgrowTime 이상이면 레벨을 3으로 조정해줍니다.
			if (fence[i]->growTime >= maxgrowTime) fence[i]->level = 3;
			// 성장한시간이 (maxgrowTime / 3)*2 이상이면 레벨을 2로 조정해줍니다.
			else if (fence[i]->growTime >= (maxgrowTime / 3) * 2) fence[i]->level = 2;
			// 성장한시간이 (maxgrowTime / 3) 이상이면 레벨을 1로 조정해줍니다.
			else if (fence[i]->growTime >= (maxgrowTime / 3)) fence[i]->level = 1;
		}
	}
}


// Get
string Cow::GetName()
{
	return Name;
}

int Cow::GethavFence()
{
	return havFence;
}

Fence* Cow::GetFence(int i)
{
	return fence[i];
}

int Cow::GetfenceLevel(int i)
{
	return fence[i]->level;
}

void Cow::GetInitializeTime(int i)
{
	cout << "(" << fence[i]->year << "년 "
		<< fence[i]->month << "월 "
		<< fence[i]->day << "일 "
		<< fence[i]->hour << "시)";
}

int Cow::GethavAnimals()
{
	return havAnimals;
}

int Cow::GetmaxLevel()
{
	return maxLevel;
}

int Cow::GetmaxFence()
{
	return maxFence;
}

int Cow::GetPrice()
{
	return price;
}
