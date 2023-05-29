#include "Pig.h"

Pig::Pig()
{
	Name = "����";
	price = 1000;

	maxLevel = 3;
	maxSize = 300;
	havAnimals = 2;
	maxFence = 10;
	havFence = 1;
	maxgrowTime = 15;
	growingFence = 0;

	for (int i = 0;i < maxFence;i++)
	{
		fence[i] = nullptr;
	}
}

Pig::~Pig()
{
	for (int i = 0; i < maxFence; i++)
	{
		delete fence[i];
	}
}

// ������ ��� ����
void Pig::GetAudult(Animals* animals, int num)
{
	// ������ �Ѹ��� �߰��մϴ�.
	animals->SethavAnimals(1);

	// �ش� ��Ÿ���� nullptr(�� ��Ÿ��) �� �ʱ�ȭ�մϴ�
	animals->InitializeFence(num - 1);

	cout << "���� 1������ ȹ���Ͽ����ϴ�." << endl;
}

void Pig::InitializeFence(int num)
{
	fence[num] = nullptr;
}

// Set
void Pig::SetFence(int i, int y, int m, int d, int h)
{
	fence[i - 1] = new Fence(y, m, d, h);
}

void Pig::SetGrowingFence(bool tf)
{
	if (tf) growingFence++;
	else growingFence--;

	if (growingFence > 10) growingFence = 10;
	if (growingFence < 0) growingFence = 0;
}

void Pig::SethavAnimals(int i)
{
	havAnimals = havAnimals + i;
}

void Pig::SethavFence()
{
	havFence++;
}

void Pig::SetFenceLevel(int y, int m, int d, int h)
{
	for (int i = 0;i < havFence;i++)
	{
		if (fence[i] != nullptr)
		{
			// ���۹��� 1�ð� �����մϴ�.
			fence[i]->growTime++;

			// �ð��� ���� ���� ���巹���� �����մϴ�.
			// �����ѽð��� maxgrowTime �̻��̸� ������ 3���� �������ݴϴ�.
			if (fence[i]->growTime >= maxgrowTime) fence[i]->level = 3;
			// �����ѽð��� (maxgrowTime / 3)*2 �̻��̸� ������ 2�� �������ݴϴ�.
			else if (fence[i]->growTime >= (maxgrowTime / 3) * 2) fence[i]->level = 2;
			// �����ѽð��� (maxgrowTime / 3) �̻��̸� ������ 1�� �������ݴϴ�.
			else if (fence[i]->growTime >= (maxgrowTime / 3)) fence[i]->level = 1;
		}
	}
}


// Get
string Pig::GetName()
{
	return Name;
}

int Pig::GethavFence()
{
	return havFence;
}

Fence* Pig::GetFence(int i)
{
	return fence[i];
}

int Pig::GetfenceLevel(int i)
{
	return fence[i]->level;
}

void Pig::GetInitializeTime(int i)
{
	cout << "(" << fence[i]->year << "�� "
		<< fence[i]->month << "�� "
		<< fence[i]->day << "�� "
		<< fence[i]->hour << "��)";
}

int Pig::GethavAnimals()
{
	return havAnimals;
}

int Pig::GetmaxLevel()
{
	return maxLevel;
}

int Pig::GetmaxFence()
{
	return maxFence;
}

int Pig::GetPrice()
{
	return price;
}
