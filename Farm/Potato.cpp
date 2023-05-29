#include "Potato.h"

Potato::Potato()
{
	Name = "����";
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

// ��Ȯ�� �ϰ� �����մϴ�.
void Potato::Harvest(Crops* crops, int num)
{
	// 0 ~ 99 ������ ������ ���� ����
	int per = rand() % 100;
	// ��Ȯ�� ���۹��� �����մϴ�.
	int count = 0;

	// 40�� �� Ȯ����
	if (per < 40)
	{
		// ���ڸ� 2�� �߰� �մϴ�.
		crops->SethavCrops(2);
		count = 2;
	}
	// 40 ���� Ȯ����
	else if (per < 80)
	{
		// ���ڸ� 3�� �߰��մϴ�.
		crops->SethavCrops(3);
		count = 3;
	}
	// ������ 20 ���� Ȯ����
	else
	{
		// ���ڸ� 4�� �߰��մϴ�.
		crops->SethavCrops(4);
		count = 4;
	}

	// �ش� ���� nullptr(�� ��) ���� �ʱ�ȭ�մϴ�.
	crops->InitializeField(num - 1);

	cout << "���� " << count << "���� ȹ���Ͽ����ϴ�." << endl;
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
			// ���۹��� 1�ð� �����մϴ�.
			field[i]->growTime++;

			// �ð��� ���� ���� ���巹���� �����մϴ�.
			// �����ѽð��� maxgrowTime �̻��̸� ������ 3���� �������ݴϴ�.
			if (field[i]->growTime >= maxgrowTime) field[i]->level = 3;
			// �����ѽð��� (maxgrowTime / 3)*2 �̻��̸� ������ 2�� �������ݴϴ�.
			else if (field[i]->growTime >= (maxgrowTime / 3)*2) field[i]->level = 2;
			// �����ѽð��� (maxgrowTime / 3) �̻��̸� ������ 1�� �������ݴϴ�.
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

// havField ��ȯ �޼���
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
	cout << "(" << field[i]->year << "�� " 
		<< field[i]->month << "�� " 
		<< field[i]->day << "�� " 
		<< field[i]->hour << "�� �� �ɾ���)";
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

