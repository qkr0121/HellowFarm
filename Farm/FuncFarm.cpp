#include "FuncFarm.h"

// MoveFarm에서 이어지는 함수
void ContinueFarm(Character* player, Crops* crops, int x, int act)
{
	// 선택한 작물이 몇번째 작물인지 x 에 저장합니다.
	x = (x - 5) / 7;

	// 행동을 합니다.
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

// MoveOrchard 에서 이어지는 함수
void ContinueOrchard(Character* player, Fruits* fruits, int x, int act)
{
	// 선택한 나무가 몇번째 나무인지 x 에 저장합니다.
	x = (x - 28) / 7;

	// 행동
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

// MovePasture 에서 이어지는 함수
void ContinuePasture(Character* player, Animals* animals, int x, int act)
{
	// 선택한 울타리가 몇번째 울타리인지 x 에 저장합니다.
	x = (x - 16) / 7;

	// 행동
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

// MoveShop 에서 이어지는 함수(구매)
void ContinueShopBuy(Character* player)
{

	int choose;
	bool MF;

	// 원하는 행동을 선택합니다.
	cout << "무엇을 구매 하시겠습니까?" << endl;
	cout << "1. 감자 밭" << endl;
	cout << "2. 고구마 밭" << endl;
	cout << "3. 당근 밭" << endl << endl;

	cout << "4. 사과 나무" << endl;
	cout << "5. 오렌지 나무" << endl << endl;

	cout << "6. 돼지 울타리" << endl;
	cout << "7. 소 울타리" << endl << endl;

	cout << "8. 성장재" << endl << endl;
	
	cout << "11.뒤로가기" << endl;
	cout << "선택 : ";
	choose = InputNum(11);
	cout << "------------------------------" << endl << endl;

	// 선택한 행동을 합니다.
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
		cout << "상점 처음화면으로 이동하겠습니다." << endl;
		_sleep(1000);
	}

	player->AddHour();
	system("cls");
}

// MoveShop 에서 이어지는 함수 (판매)
void ContinueShopSell(Character* player)
{
	int choose;
	bool MF;

	cout << endl;
	cout << "무엇을 판매 하시겠습니까?" << endl;
	cout << "1. 감자" << endl;
	cout << "2. 고구마" << endl;
	cout << "3. 당근" << endl << endl;

	cout << "4. 사과" << endl;
	cout << "5. 오렌지" << endl << endl;

	cout << "6. 돼지" << endl;
	cout << "7. 소" << endl << endl;

	cout << "8. 뒤로가기" << endl;
	cout << "선택 : ";
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
		cout << "상점 처음화면으로 이동하겠습니다." << endl;
		_sleep(1000);
	}


	player->AddHour();

	system("cls");

}
