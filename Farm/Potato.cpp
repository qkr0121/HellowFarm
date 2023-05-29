#include "Potato.h"

Potato::Potato()
{
	Name = "감자";
	price = 200;
	maxLevel = 3;

	maxSize = 100;
	havCrops = 20;
	maxField = 10;
	havField = 2;
	plantedField = 0;
	maxgrowTime = 9;

	for (int i = 0;i < maxField;i++)
	{
		field[i] = nullptr;
	}
}

Potato::~Potato()
{
	for (int i = 0; i < maxField; i++)
	{
		delete field[i];
	}
}

// 수확을 하고 저장합니다.
void Potato::Harvest(Crops* crops, int num)
{
	// 0 ~ 99 사이의 랜덤한 수를 저장
	int per = rand() % 100;
	// 수확한 농작물을 저장합니다.
	int count = 0;

	// 40퍼 의 확률로
	if (per < 40)
	{
		// 감자를 2개 추가 합니다.
		crops->SethavCrops(2);
		count = 2;
	}
	// 40 퍼의 확률로
	else if (per < 80)
	{
		// 감자를 3개 추가합니다.
		crops->SethavCrops(3);
		count = 3;
	}
	// 나머지 20 퍼의 확률로
	else
	{
		// 감자를 4개 추가합니다.
		crops->SethavCrops(4);
		count = 4;
	}

	// 해당 밭을 nullptr(빝 밭) 으로 초기화합니다.
	crops->InitializeField(num - 1);

	cout << "감자 " << count << "개를 획득하였습니다." << endl;
}

void Potato::InitializeField(int num)
{
	field[num] = nullptr;
}

// Set
void Potato::SetField(int i, int y, int m, int d, int h)
{
	field[i - 1] = new Field(y, m, d, h);
}

void Potato::SetplantedField(bool tf)
{
	if (tf) plantedField++;
	else plantedField--;

	if (plantedField > 10) plantedField = 10;
	if (plantedField < 0) plantedField = 0;
}

void Potato::SetFieldLevel(int y, int m, int d, int h)
{
	for (int i = 0;i < havField;i++)
	{
		if (field[i] != nullptr)
		{
			// 농작물이 1시간 성장합니다.
			field[i]->growTime++;

			// 시간의 차에 따라 성장레벨을 조정합니다.
			// 성장한시간이 maxgrowTime 이상이면 레벨을 3으로 조정해줍니다.
			if (field[i]->growTime >= maxgrowTime) field[i]->level = 3;
			// 성장한시간이 (maxgrowTime / 3)*2 이상이면 레벨을 2로 조정해줍니다.
			else if (field[i]->growTime >= (maxgrowTime / 3)*2) field[i]->level = 2;
			// 성장한시간이 (maxgrowTime / 3) 이상이면 레벨을 1로 조정해줍니다.
			else if (field[i]->growTime >= (maxgrowTime / 3)) field[i]->level = 1;
		}
	}
}

void Potato::SethavCrops(int i)
{
	havCrops = havCrops + i;
}

void Potato::SethavField()
{
	havField++;
}

//Get
string Potato::GetName()
{
	return Name;
}

int Potato::GethavCrops()
{
	return havCrops;
}

// havField 반환 메서드
int Potato::GethavField()
{
	return havField;
}

int Potato::GetfieldLevel(int i)
{
	return field[i]->level;
}

Field* Potato::GetField(int i)
{
	return field[i];
}

void Potato::GetplantedTime(int i)
{
	cout << "(" << field[i]->year << "년 " 
		<< field[i]->month << "월 " 
		<< field[i]->day << "일 " 
		<< field[i]->hour << "시 에 심어짐)";
}

int Potato::GetmaxLevel()
{
	return maxLevel;
}

int Potato::GetmaxField()
{
	return maxField;
}

int Potato::GetPrice()
{
	return price;
}

