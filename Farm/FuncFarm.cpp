#include "FuncFarm.h"

// MoveFarm���� �̾����� �Լ�
void ContinueFarm(Character* player, Crops* crops, int x, int act)
{
	// ������ �۹��� ���° �۹����� x �� �����մϴ�.
	x = (x - 5) / 7;

	// �ൿ�� �մϴ�.
	switch (act)
	{
	case 1:
		player->PlantField(crops, x);
		break;
	case 2:
		player->HarvestField(crops, x);
		break;
	case 3:
		player->UseGrowerCrops(crops, x);
		break;
	default:
		break;
	}


	system("cls");
}

// MoveOrchard ���� �̾����� �Լ�
void ContinueOrchard(Character* player, Fruits* fruits, int x, int act)
{
	// ������ ������ ���° �������� x �� �����մϴ�.
	x = (x - 28) / 7;

	// �ൿ
	switch (act)
	{
	case 2:
		player->PickFruits(fruits, x);
		break;
	case 3:
		player->UseGrowerFruits(fruits, x);
		break;
	default:
		break;
	}

	system("cls");
	
}

// MovePasture ���� �̾����� �Լ�
void ContinuePasture(Character* player, Animals* animals, int x, int act)
{
	// ������ ��Ÿ���� ���° ��Ÿ������ x �� �����մϴ�.
	x = (x - 16) / 7;

	// �ൿ
	switch (act)
	{
	case 1:
		player->GrowAnimals(animals, x);
		break;
	case 2:
		player->GetAdultAnimals(animals, x);
		break;
	case 3:
		player->UseGrowerAnimals(animals, x);
		break;
	default:
		break;
	}


	system("cls");
}

// MoveShop ���� �̾����� �Լ�(����)
void ContinueShopBuy(Character* player)
{

	int choose;
	bool MF;

	// ���ϴ� �ൿ�� �����մϴ�.
	cout << "������ ���� �Ͻðڽ��ϱ�?" << endl;
	cout << "1. ���� ��" << endl;
	cout << "2. ���� ��" << endl;
	cout << "3. ��� ��" << endl << endl;

	cout << "4. ��� ����" << endl;
	cout << "5. ������ ����" << endl << endl;

	cout << "6. ���� ��Ÿ��" << endl;
	cout << "7. �� ��Ÿ��" << endl << endl;

	cout << "8. ������" << endl << endl;
	
	cout << "11.�ڷΰ���" << endl;
	cout << "���� : ";
	choose = InputNum(11);
	cout << "------------------------------" << endl << endl;

	// ������ �ൿ�� �մϴ�.
	if (choose <= 3)
		player->AddField(player->GetCrops(choose - 1));
	else if (choose <= 5)
		player->PlantTree(player->GetFruits(choose - 4));
	else if (choose <= 7)
		player->BuyFence(player->GetAnimals(choose - 6));
	else if(choose == 8)
		player->BuyGrower(player);
	else
	{
		cout << "���� ó��ȭ������ �̵��ϰڽ��ϴ�." << endl;
		_sleep(1000);
	}

	player->AddHour();
	system("cls");
}

// MoveShop ���� �̾����� �Լ� (�Ǹ�)
void ContinueShopSell(Character* player)
{
	int choose;
	bool MF;

	cout << endl;
	cout << "������ �Ǹ� �Ͻðڽ��ϱ�?" << endl;
	cout << "1. ����" << endl;
	cout << "2. ����" << endl;
	cout << "3. ���" << endl << endl;

	cout << "4. ���" << endl;
	cout << "5. ������" << endl << endl;

	cout << "6. ����" << endl;
	cout << "7. ��" << endl << endl;

	cout << "8. �ڷΰ���" << endl;
	cout << "���� : ";
	choose = InputNum(8);
	cout << endl;
	
	if (choose <= 3)
		player->SellCrops(player->GetCrops(choose - 1));
	else if (choose <= 5)
		player->SellFruits(player->GetFruits(choose - 4));
	else if (choose <= 7)
		player->SellAnimals(player->GetAnimals(choose - 6));
	else if (choose == 8)
	{
		cout << "���� ó��ȭ������ �̵��ϰڽ��ϴ�." << endl;
		_sleep(1000);
	}


	player->AddHour();

	system("cls");

}
