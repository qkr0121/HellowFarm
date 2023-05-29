#include "Carrot.h"

Carrot::Carrot()
{
	Name = "���";
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

// ��Ȯ�� �ϰ� �����մϴ�.
void Carrot::Harvest(Crops* crops, int num)
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

	cout << "��� " << count << "���� ȹ���Ͽ����ϴ�." << endl;
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
			// ���۹��� 1�ð� �����մϴ�.
			field[i]->growTime++;

			// �ð��� ���� ���� ���巹���� �����մϴ�.
			// �����ѽð��� maxgrowTime �̻��̸� ������ 3���� �������ݴϴ�.
			if (field[i]->growTime >= maxgrowTime) field[i]->level = 3;
			// �����ѽð��� (maxgrowTime / 3)*2 �̻��̸� ������ 2�� �������ݴϴ�.
			else if (field[i]->growTime >= (maxgrowTime / 3) * 2) field[i]->level = 2;
			// �����ѽð��� (maxgrowTime / 3) �̻��̸� ������ 1�� �������ݴϴ�.
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
	cout << "(" << field[i]->year << "�� "
		<< field[i]->month << "�� "
		<< field[i]->day << "�� "
		<< field[i]->hour << "�� �� �ɾ���)";
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

