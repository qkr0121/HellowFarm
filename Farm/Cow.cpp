#include "Cow.h"

Cow::Cow()
{
	Name = "��";
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

// ������ ��� ����
void Cow::GetAudult(Animals* animals, int num)
{
	// ������ �Ѹ��� �߰��մϴ�.
	animals->SethavAnimals(1);

	// �ش� ��Ÿ���� nullptr(�� ��Ÿ��) �� �ʱ�ȭ�մϴ�
	animals->InitializeFence(num - 1);

	cout << "�� 1������ ȹ���Ͽ����ϴ�." << endl;
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
	cout << "(" << fence[i]->year << "�� "
		<< fence[i]->month << "�� "
		<< fence[i]->day << "�� "
		<< fence[i]->hour << "��)";
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
