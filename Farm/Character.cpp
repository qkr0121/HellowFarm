#include "Character.h"

// ������
Character::Character(string name, int hungry)
{
	Name = name;
	Hungry = hungry;
	money = 500000;

	water = 1;
	fertilizer = 1;
	food = 1;

	crops[0] = new Potato();
	crops[1] = new SweetPotato();
	crops[2] = new Carrot();

	fruits[0] = new Apple();
	fruits[1] = new Orange();

	animals[0] = new Pig();
	animals[1] = new Cow();

	for (int i = 0;i < 3;i++)
	{
		isFurniture[i] = false;
	}

}

Character::~Character()
{
	for (int i = 0; i < sizeof(crops) / sizeof(crops[0]); i++)
	{
		crops[i] = nullptr;
	}

	for (int i = 0; i < sizeof(fruits) / sizeof(fruits[0]); i++)
	{
		fruits[i] = nullptr;
	}

	for (int i = 0; i < sizeof(animals) / sizeof(animals[0]); i++)
	{
		animals[i] = nullptr;
	}
}

// �������� �����մϴ�.
void Character::BuyGrower(Character* player)
{
	int num = 0;
	int count = 0;

	cout << "� �������� �����Ͻðڽ��ϱ�? (���� 500��)" << endl;
	cout << "1. ��  2. ���  3. ����  4. �ڷΰ���" << endl;
	cout << "���� : ";
	cin >> num;

	cout << endl;
	cout << "��� �����ϽðԽ��ϱ�?" << endl;
	cout << "�Է� : ";
	cin >> count;

	// �÷��̾ ����� ���� ������ �ִٸ�
	if (player->money >= count * 500)
	{
		// �������� �߰��մϴ�.
		switch (num)
		{
		case 1:
			water = water + count;
			break;
		case 2:
			fertilizer = fertilizer + count;
			break;
		case 3:
			food = food + count;
			break;
		}
		player->money -= count * 500;
		cout << "���������� �����Ͽ����ϴ�." << endl;
	}
	// ������ ���� �ʴٸ�
	else
	{
		cout << "���� �����մϴ�." << endl;
	}

	_sleep(1000);
	
}

// ���۹�, ����, ������ �����ŵ�ϴ�.
void Character::UseGrowerCrops(Crops* crops, int x)
{
	// ������ �ִ� ���̶��
	if (x < crops->GethavField())
	{
		// �翡 ���۹��� �ɾ��� �ִٸ�
		if (crops->GetField(x) != nullptr)
		{
			// ���� ������ �ִٸ�
			if (water > 0)
			{
				// �ɾ��� �ִ� ���۹��� �����ŵ�ϴ�.
				crops->GetField(x)->growTime += 3;
				water--;
				cout << "�����߽��ϴ�." << endl;
				AddHour();
			}
		}
	}
		
	_sleep(1000);
}

void Character::UseGrowerFruits(Fruits* fruits, int x)
{
	// ������ �ִ� �����̶��
	if (x < fruits->GethavTree())
	{
		// ��Ḧ ������ �ִٸ�
		if (fertilizer > 0)
		{
			// ������ �����ŵ�ϴ�.
			fruits->GetTree(x)->growTime += 3;
			fertilizer--;
			cout << "�����߽��ϴ�." << endl;
			AddHour();
		}
	}
	
	_sleep(1000);
}

void Character::UseGrowerAnimals(Animals* animals, int x)
{
	int num = 0;

	cout << endl;

	while (1)
	{
		cout << "���° ��Ÿ���� ������ �����Ű�ðڽ��ϱ�?(0�� �ڷΰ���) : ";
		cin >> num;

		// ������ �ִ� ��Ÿ�����
		if (num > 0 && num <= animals->GethavFence())
		{
			// ��Ÿ���� �������ִٸ�
			if (animals->GetFence(num-1) != nullptr)
			{
				// ������ �����ŵ�ϴ�.
				animals->GetFence(num - 1)->growTime += 3;
				food--;
				cout << "�����߽��ϴ�." << endl;
				AddHour();
				break;
			}
			// ����ִٸ�
			else
			{
				cout << "��Ÿ���� ����ֽ��ϴ�.";
			}
		}
		// 0 �� �Է��ߴٸ� �ൿ�� �����ϴ�.
		else if (num == 0) break;
		// ��Ÿ���� ������ ���� �ʴٸ�
		else
		{
			cout << num << "��° ��Ÿ���� ������ ���� �ʽ��ϴ�." << endl;
		}
	}

	_sleep(1000);
}

// ���۹��� �ɽ��ϴ�.
void Character::PlantField(Crops* crops, int x)
{		
	// ������ �ִ� ���̶��
	if (x < crops->GethavField())
	{
		//������ �ִ� ���� ����ٸ�
		if (crops->GetField(x) == nullptr)
		{
			// num ��° �翡 ���۹��� �ɽ��ϴ�.
			crops->SetField(x+1, Year, Month, Day, Hour);
			crops->SetplantedField(true);
			crops->SethavCrops(-1);
			AddHour();				
		}
	}
}

// ���۹��� ��Ȯ�մϴ�.
void Character::HarvestField(Crops* crops, int x)
{
	// ������ �ִ� ���̶��
	if (x < crops->GethavField())
	{
		// �翡 ���۹��� �ɾ��� �ִٸ�
		if (crops->GetField(x) != nullptr)
		{
			// �ɾ��� �ִ� ���۹��� ������ maxLevel�̶��
			if (crops->GetfieldLevel(x) == crops->GetmaxLevel())
			{
				// ���۹��� ��Ȯ�մϴ�.
				crops->Harvest(crops, x+1);
				crops->SetplantedField(false);
				AddHour();
			}
		}
	}
	
	_sleep(1000);
}

// ���� �߰��մϴ�.(����)
void Character::AddField(Crops* crops)
{
	int num = 0;

	cout << crops->GetName() << "���� �߰��Ͻðڽ��ϱ�? ( ���� : 5000�� )" << endl;
	cout << "������ �ִ� �� �� : " << crops->GethavField() << "��" << endl;
	cout << "1. ��, 2. �ƴϿ�  : ";
	cin >> num;

	// 1�� �Է��Ѵٸ�
	if (num == 1)
	{
		// ������ �ִ� ���� ����ϴٸ�
		if (money >= 5000)
		{
			// ������ �ִ� ���� ���� �ִ� ���� ���� ���� �ʴ´ٸ�
			if (crops->GethavField() < crops->GetmaxField())
			{
				// (havField+1)��° ���� �߰��մϴ�.
				crops->SethavField();
				// ������ �ִ� ���� 5000�� �Ҹ� �մϴ�.
				money -= 5000;
				cout << "���������� �����Ͽ����ϴ�." << endl;
			}
			// �ִ� ���� ���� �Ѱų� ���ٸ�
			else
			{
				cout << "�� �̻� ������ ���� �� �����ϴ�.";
			}

		}
		// ������� �ʴٸ�
		else
		{
			cout << "���� ����� ������ ���� �ʽ��ϴ�.";
		}
	}
	// 2�� �ٸ����� �Է��Ѵٸ�
	else
	{
		cout << "�����ʱ�ȭ������ ���ư��ϴ�." << endl;
	}

	_sleep(1000);
}

// ���۹��� �Ǹ��մϴ�(����)
void Character::SellCrops(Crops* crops)
{
	int count=0;
	
	while (1)
	{
		cout << "������ �ִ� " << crops->GetName() << "���� : " << crops->GethavCrops() << endl;
		cout << "��� �Ǹ��Ͻðڽ��ϱ�?(0���� �ڷΰ���)" <<endl;
		cout << "�Է� : ";
		cin >> count;
	
		// �Ǹ��Ϸ��� �������� ���� ������ �������
		if (count < crops->GethavCrops())
		{
			// ������ �Ǹ��մϴ�.
			money += count * crops->GetPrice();
			crops->SethavCrops((-1) * count);
			cout << "���������� ������ �Ǹ��Ͽ����ϴ�." << endl;
			cout << "������ �Ǹ��Ͽ� �� " << count * crops->GetPrice() << "���� ������ϴ�." << endl;
			break;
		}
		// �������
		else
		{
			cout << "������ �ִ� ������ ������� �ʽ��ϴ�." << endl << endl;
		}
	}
	
	_sleep(1000);
}

// ������ �ɽ��ϴ�(����).
void Character::PlantTree(Fruits* fruits)
{
	int num = 0;

	cout << fruits->GetName() << "������ �����ðڽ��ϱ�? ( ���� : 10000�� )" << endl;
	cout << "������ �ִ� ���� �� : " << fruits->GethavTree() << "�׷�" << endl;
	cout << "1. ��, 2. �ƴϿ�  : ";
	cin >> num;

	// 1�� �Է��Ѵٸ�
	if (num == 1)
	{
		// ������ �ִ� ���� ����ϴٸ�
		if (money >= 10000)
		{
			// ������ �ִ� ������ ���� �ִ� ������ ���� ���� �ʴ´ٸ�
			if (fruits->GethavTree() < fruits->GetmaxTree())
			{
				// (havTree+1)��° ������ �ɽ��ϴ�.
				fruits->SetTree((fruits->GethavTree() + 1), Year, Month, Day, Hour);
				// havTree �� 1 ������ŵ�ϴ�.
				fruits->SethavTree(true);
				// ������ �ִ� ���� 10000�� �Ҹ� �մϴ�.
				money -= 10000;
				cout << "���������� �����Ͽ����ϴ�." << endl;
			}
			// �ִ� ������ ���� �Ѱų� ���ٸ�
			else
			{
				cout << "�� �̻� ������ ���� �� �����ϴ�.";
			}

		}
		// ������� �ʴٸ�
		else
		{
			cout << "���� ����� ������ ���� �ʽ��ϴ�.";
		}
	}
	// 2�� �ٸ����� �Է��Ѵٸ�
	else
	{
		cout << "�����ʱ�ȭ������ ���ư��ϴ�." << endl;
	}

	_sleep(1000);
}

// ���Ÿ� �Ǹ��մϴ�.
void Character::SellFruits(Fruits* fruits)
{
	int count = 0;

	while (1)
	{
		cout << "������ �ִ� " << fruits->GetName() << "���� : " << fruits->GethavFruits() << endl;
		cout << "��� �Ǹ��Ͻðڽ��ϱ�?(0���� �ڷΰ���)" << endl;
		cout << "�Է� : ";
		cin >> count;

		// �Ǹ��Ϸ��� �������� ���� ������ �������
		if (count < fruits->GethavFruits())
		{
			// ������ �Ǹ��մϴ�.
			money += count * fruits->GetPrice();
			fruits->SethavFruits((-1) * count);
			cout << "���������� ������ �Ǹ��Ͽ����ϴ�." << endl;
			cout << "������ �Ǹ��Ͽ� �� " << count * fruits->GetPrice() << "���� ������ϴ�." << endl;
			break;
		}
		// �������
		else
		{
			cout << "������ �ִ� ������ ������� �ʽ��ϴ�." << endl << endl;
		}
	}

	_sleep(1000);
}

// ���Ÿ� ���ϴ�.
void Character::PickFruits(Fruits* fruits, int x)
{
	// ������ �ִ� �������
	if (x < fruits->GethavTree())
	{
		// �ɾ��� �ִ� ����(����)�� ������ maxLevel�̶��
		if (fruits->GettreeLevel(x) == fruits->GetmaxLevel())
		{
			// ���Ÿ� ��Ȯ�մϴ�.
			fruits->PickFruits(fruits, x+1);
			AddHour();
			// �ش� ������ �ʱ�ȭ�մϴ�.(�ð��� ���Ÿ� �� �������� �ʱ�ȭ�Ѵ�)
			fruits->InitializeTree(x, Year, Month, Day, Hour);
		}
	}	
}

// ���� ������ ��Ÿ���� �ֽ��ϴ�.
void Character::GrowAnimals(Animals* animals, int x)
{
	// ������ �ִ� ��Ÿ�����
	if (x < animals->GethavFence())
	{
		//������ �ִ� ��Ÿ���� ����ְ� ������ 2���� �̻��־���մϴ�.
		if (animals->GetFence(x) == nullptr && animals->GethavAnimals() >= 2)
		{
			// num ��° ��Ÿ���� ���������� �ֽ��ϴ�.
			animals->SetFence(x+1, Year, Month, Day, Hour);
			animals->SetGrowingFence(true);
			AddHour();
		}
	}
	
}

// ������ ������ ����ϴ�.
void Character::GetAdultAnimals(Animals* animals, int x)
{

	// ������ �ִ� ��Ÿ�����
	if (x < animals->GethavFence())
	{
		// ��Ÿ���� ������ �ִٸ�
		if (animals->GetFence(x) != nullptr)
		{
			// ������ ������ maxLevel�̶��
			if (animals->GetfenceLevel(x) == animals->GetmaxLevel())
			{
				// ������ ��Ȯ�մϴ�.
				animals->GetAudult(animals, x+1);
				animals->SetGrowingFence(false);
				AddHour();
			}
		}
	}

	_sleep(1000);
}

// ��Ÿ���� ��ϴ�.(����)
void Character::BuyFence(Animals* animals)
{
	int num = 0;

	cout << animals->GetName() << "��Ÿ���� �߰��Ͻðڽ��ϱ�? ( ���� : 20000�� )" << endl;
	cout << "������ �ִ� ��Ÿ�� �� : " << animals->GethavFence() << "��" << endl;
	cout << "1. ��, 2. �ƴϿ�  : ";
	cin >> num;

	// 1�� �Է��Ѵٸ�
	if (num == 1)
	{
		// ������ �ִ� ���� ����ϴٸ�
		if (money >= 20000)
		{
			// ������ �ִ� ��Ÿ���� ���� �ִ� ��Ÿ���� ���� ���� �ʴ´ٸ�
			if (animals->GethavFence() < animals->GetmaxFence())
			{
				// (havFence+1)��° ��Ÿ���� �߰��մϴ�.
				animals->SethavFence();
				// ������ �ִ� ���� 20000�� �Ҹ� �մϴ�.
				money -= 20000;
				cout << "���������� �����Ͽ����ϴ�." << endl;
			}
			// �ִ� ��Ÿ���� ���� �Ѱų� ���ٸ�
			else
			{
				cout << "�� �̻� ��Ÿ���� ���� �� �����ϴ�.";
			}

		}
		// ������� �ʴٸ�
		else
		{
			cout << "���� ����� ������ ���� �ʽ��ϴ�.";
		}
	}
	// 2�� �ٸ����� �Է��Ѵٸ�
	else
	{
		cout << "�����ʱ�ȭ������ ���ư��ϴ�." << endl;
	}

	_sleep(1000);
}

// ������ �Ǹ��մϴ�.(����)
void Character::SellAnimals(Animals* animals)
{
	int count = 0;

	while (1)
	{
		cout << "������ �ִ� " << animals->GetName() << "���� : " << animals->GethavAnimals() << endl;
		cout << "��� �Ǹ��Ͻðڽ��ϱ�?(0���� �ڷΰ���)" << endl;
		cout << "�Է� : ";
		cin >> count;

		// �Ǹ��Ϸ��� �������� ���� ������ �������
		if (count < animals->GethavAnimals())
		{
			// ������ �Ǹ��մϴ�.
			money += count * animals->GetPrice();
			animals->SethavAnimals((-1) * count);
			cout << "���������� ������ �Ǹ��Ͽ����ϴ�." << endl;
			cout << "������ �Ǹ��Ͽ� �� " << count * animals->GetPrice() << "���� ������ϴ�." << endl;
			break;
		}
		// �������
		else
		{
			cout << "������ �ִ� ������ ������� �ʽ��ϴ�." << endl << endl;
		}
	}

	_sleep(1000);
}

void Character::Table()
{
	int num = 0;
	SetColor(white, black);
	GotoXY(0, 26);
	cout << "������ ��ðڽ��ϱ�?(1.����,2.����,3.���,4.���,5.������)" << endl;
	cout << "���� : ";
	cin >> num;

	if (num <= 3)
	{
		Hungry += 5;
		crops[num - 1]->SethavCrops(-1);
		cout << "������� 5 á���ϴ�.(�������� : " << crops[num-1]->GethavCrops() << "��)";
	}
	else if (num <= 5)
	{
		Hungry += 2;
		fruits[num - 4]->SethavFruits(-1);
		cout << "������� 2 á���ϴ�.(�������� : " << fruits[num-4]->GethavFruits() << "��)";
	}
	else
		cout << "�߸������ϼ̽��ϴ�.";
	if (Hungry > 100)
		Hungry = 100;
	_sleep(1000);
}

void Character::TV(bool isUse)
{
	int num = 0;
	SetColor(white, black);
	GotoXY(0, 26);
	if (isUse == false)
	{
		cout << "�ش� ������ ������ ���� �ʽ��ϴ�. �����Ͻðڽ��ϱ�?(100000)" << endl;
		cout << "1.��, 2.�ƴϿ� : ";
		cin >> num;
		if (num == 1)
		{
			if (money >= 100000)
			{
				cout << "�����ϼ̽��ϴ�.";
				money -= 100000;
				isFurniture[0] = true;
			}
			else
			{
				cout << "���� �����մϴ�.";
			}
			_sleep(1000);
			return;
		}
		else
			return;
	}

	// tv ��û ���� �ð� ����
	int time = (Hungry / 2) - 10;
	if (time < 0) 
		time = 0;

	cout << "��ð� TV�� ��û�Ͻðڽ��ϱ�?(�ִ� : " << time << "�ð�)" << endl;
	cin >> num;
	// tv�� ��û�մϴ�.
	if (num <= time)
	{
		SetColor(lightred, black);
		GotoXY(47,3);
		for (int i = 0;i < 3;i++)
		{
			cout << "HA ";
			_sleep(1000);
		}
		for (int i = 0;i < num;i++)
		{
			AddHour();
		}
	}
	else 
	{
		cout << "TV�� ��û�� �� �����ϴ�.";
		_sleep(1000);
	}

	SetColor(white, black);

}

void Character::Furnace(bool isUse)
{
	int num = 0;
	SetColor(white, black);
	GotoXY(0, 26);
	if (isUse == false)
	{
		cout << "�ش� ������ ������ ���� �ʽ��ϴ�. �����Ͻðڽ��ϱ�?(100000)" << endl;
		cout << "1.��, 2.�ƴϿ� : ";
		cin >> num;
		if (num == 1)
		{
			if (money >= 100000)
			{
				cout << "�����ϼ̽��ϴ�.";
				money -= 100000;
				isFurniture[1] = true;
			}
			else
				cout << "���� �����մϴ�.";

			_sleep(1000);
			return;
		}
		else
			return;
	}

	cout << "������ ������ðڽ��ϱ�?(1.����, 2.��)" << endl;
	cout << "���� : ";
	cin >> num;

	if (num <= 2)
	{
		Hungry += 10;
		animals[num - 1]->SethavAnimals(-1);
		cout << "������� 10 á���ϴ�.(���� ������ : " << animals[num-1]->GethavAnimals() << "����";
	}
	else
		cout << "�߸������ϼ̽��ϴ�.";
	if (Hungry > 100)
		Hungry = 100;
	_sleep(1000);
}

void Character::Bed(bool isUse)
{
	int num = 0;
	SetColor(white, black);
	GotoXY(0, 26);
	if (isUse == false)
	{
		cout << "�ش� ������ ������ ���� �ʽ��ϴ�. �����Ͻðڽ��ϱ�?(100000)" << endl;
		cout << "1.��, 2.�ƴϿ� : ";
		cin >> num;
		if (num == 1)
		{
			if (money >= 100000)
			{
				cout << "�����ϼ̽��ϴ�.";
				money -= 100000;
				isFurniture[2] = true;
			}
			else
				cout << "���� �����մϴ�.";

			_sleep(1000);
			return;
		}
		else
			return;
	}

	// ���� ��ϴ�.
	if (Hour > 21 || Hour < 3)
	{
		SetColor(lightred, black);
		GotoXY(79, 4);
		cout << "Z";
		_sleep(1000);
		GotoXY(78, 3);
		cout << "Z";
		_sleep(1000);
		GotoXY(77, 2);
		cout << "Z";
		_sleep(1000);

		for (int i = 0;i < 7;i++)
		{
			AddHour();
		}
		Hungry += 14;
	}
	else
	{
		cout << "���� �� �� �ִ� �ð��� �ƴմϴ�.";
		_sleep(1000);
	}

	SetColor(white, black);

}

// �ѽð��� �߰��մϴ�.
void Character::AddHour()
{
	Hour++;
	Hungry -= 2;
	TimeCheck();

	for (int i = 0; i < sizeof(crops) / sizeof(crops[0]); i++)
	{
		crops[i]->SetFieldLevel(Year, Month, Day, Hour);
	}
	for (int i = 0; i < sizeof(fruits) / sizeof(fruits[0]); i++)
	{
		fruits[i]->SetTreeLevel(Year, Month, Day, Hour);
	}
	for (int i = 0; i < sizeof(animals) / sizeof(animals[0]); i++)
	{
		animals[i]->SetFenceLevel(Year, Month, Day, Hour);
	}

}

// Set
// �÷��̾� �ð� ���� �޼���
void Character::SetTime(int year, int month, int day, int hour)
{
	Year = year;
	Month = month;
	Day = day;
	Hour = hour;

	SetSeason(Month);
}

void Character::SetWater(int i)
{
	water = water + i;
}

void Character::SetFertilizer(int i)
{
	fertilizer = fertilizer+ i;
}

void Character::SetFood(int i)
{
	food = food + i;
}

// Get
// �÷��̾� �̸� ��ȯ �޼���
string Character::GetName()
{
	return Name;
}

int Character::GetMoney()
{
	return money;
}

int Character::GetWater()
{
	return water;
}

int Character::GetFertilizer()
{
	return fertilizer;
}

int Character::GetFood()
{
	return food;
}

// Year, Month, Day, Hour ��ȯ
int Character::GetYear()
{
	return Year;
}

int Character::GetMonth()
{
	return Month;
}

int Character::GetDay()
{
	return Day;
}

int Character::GetHour()
{
	return Hour;
}

// Crop* ��ȯ
Crops* Character::GetCrops(int i)
{
	return crops[i];
}

// Fruits* ��ȯ
Fruits* Character::GetFruits(int i)
{
	return fruits[i];
}

// Animals* ��ȯ
Animals* Character::GetAnimals(int i)
{
	return animals[i];
}

bool Character::GetisFurniture(int i)
{
	return isFurniture[i];
}

// �÷��̾� ���� ��� �޼���
void Character::PrintPlayerInfo()
{
	cout << "  �̸� : " << Name << "    ����� : ";
	PrintPlayerHungry();
	cout << "               ";
}

// �÷��̾��� ������� ����մϴ�.
void Character::PrintPlayerHungry()
{
	int hun = Hungry / 10;
	for (int i = 0; i < hun; i++)
	{
		cout << "��";
	}
	for (int i = hun; i < 10; i++)
	{
		cout << "��";
	}
}



	//(*potato.begin())->printName();