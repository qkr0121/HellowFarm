#include "Carrot.h"

Carrot::Carrot()
{
	Name = "당근";
	price = 300;
	maxLevel = 2;

	maxSize = 100;
	havCrops = 10;
	maxField = 10;
	havField = 1;
	plantedField = 0;
	maxgrowTime = 9;

	for (int i = 0;i < maxField;i++)
	{
		field[i] = nullptr;
	}
}

Carrot::~Carrot()
{
	for (int i = 0; i < plantedField; i++)
	{
		delete field[i];
	}
}

// 수확을 하고 저장합니다.
void Carrot::Harvest(Crops* crops, int num)
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

	cout << "당근 " << count << "개를 획득하였습니다." << endl;
}

void Carrot::InitializeField(int num)
{
	field[num] = nullptr;
}

void Carrot::SetField(int i, int y, int m, int d, int h)
{
	field[i - 1] = new Field(y, m, d, h);
}

void Carrot::SetplantedField(bool tf)
{
	if (tf) plantedField++;
	else plantedField--;

	if (plantedField > 10) plantedField = 10;
	if (plantedField < 0) plantedField = 0;
}

void Carrot::SetFieldLevel(int y, int m, int d, int h)
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
			else if (field[i]->growTime >= (maxgrowTime / 3) * 2) field[i]->level = 2;
			// 성장한시간이 (maxgrowTime / 3) 이상이면 레벨을 1로 조정해줍니다.
			else if (field[i]->growTime >= (maxgrowTime / 3)) field[i]->level = 1;
		}
	}
}

void Carrot::SethavCrops(int i)
{
	havCrops = havCrops + i;
}

void Carrot::SethavField()
{
	havField++;
}

string Carrot::GetName()
{
	return Name;
}

int Carrot::GethavCrops()
{
	return havCrops;
}

int Carrot::GethavField()
{
	return havField;
}

int Carrot::GetfieldLevel(int i)
{
	return field[i]->level;
}

Field* Carrot::GetField(int i)
{
	return field[i];
}

void Carrot::GetplantedTime(int i)
{
	cout << "(" << field[i]->year << "년 "
		<< field[i]->month << "월 "
		<< field[i]->day << "일 "
		<< field[i]->hour << "시 에 심어짐)";
}

int Carrot::GetmaxLevel()
{
	return maxLevel;
}

int Carrot::GetmaxField()
{
	return maxField;
}

int Carrot::GetPrice()
{
	return price;
}

