#include "Character.h"

// 생성자
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

// 성장제를 구입합니다.
void Character::BuyGrower(Character* player)
{
	int num = 0;
	int count = 0;

	cout << "어떤 성장제를 구입하시겠습니까? (개당 500원)" << endl;
	cout << "1. 물  2. 비료  3. 먹이  4. 뒤로가기" << endl;
	cout << "선택 : ";
	cin >> num;

	cout << endl;
	cout << "몇개를 구입하시게습니까?" << endl;
	cout << "입력 : ";
	cin >> count;

	// 플레이어가 충분한 돈을 가지고 있다면
	if (player->money >= count * 500)
	{
		// 성장제를 추가합니다.
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
		cout << "성공적으로 구매하였습니다." << endl;
	}
	// 가지고 있지 않다면
	else
	{
		cout << "돈이 부족합니다." << endl;
	}

	_sleep(1000);
	
}

// 농작물, 과일, 동물을 성장시킵니다.
void Character::UseGrowerCrops(Crops* crops, int x)
{
	// 가지고 있는 밭이라면
	if (x < crops->GethavField())
	{
		// 밭에 농작물이 심어져 있다면
		if (crops->GetField(x) != nullptr)
		{
			// 물을 가지고 있다면
			if (water > 0)
			{
				// 심어져 있는 농작물을 성장시킵니다.
				crops->GetField(x)->growTime += 3;
				water--;
				cout << "성장했습니다." << endl;
				AddHour();
			}
		}
	}
		
	_sleep(1000);
}

void Character::UseGrowerFruits(Fruits* fruits, int x)
{
	// 가지고 있는 나무이라면
	if (x < fruits->GethavTree())
	{
		// 비료를 가지고 있다면
		if (fertilizer > 0)
		{
			// 나무를 성장시킵니다.
			fruits->GetTree(x)->growTime += 3;
			fertilizer--;
			cout << "성장했습니다." << endl;
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
		cout << "몇번째 울타리의 동물을 성장시키시겠습니까?(0은 뒤로가기) : ";
		cin >> num;

		// 가지고 있는 울타리라면
		if (num > 0 && num <= animals->GethavFence())
		{
			// 울타리에 동물이있다면
			if (animals->GetFence(num-1) != nullptr)
			{
				// 동물을 성장시킵니다.
				animals->GetFence(num - 1)->growTime += 3;
				food--;
				cout << "성장했습니다." << endl;
				AddHour();
				break;
			}
			// 비어있다면
			else
			{
				cout << "울타리가 비어있습니다.";
			}
		}
		// 0 을 입력했다면 행동을 끝냅니다.
		else if (num == 0) break;
		// 울타리를 가지고 있지 않다면
		else
		{
			cout << num << "번째 울타리를 가지고 있지 않습니다." << endl;
		}
	}

	_sleep(1000);
}

// 농작물을 심습니다.
void Character::PlantField(Crops* crops, int x)
{		
	// 가지고 있는 밭이라면
	if (x < crops->GethavField())
	{
		//가지고 있는 밭이 비었다면
		if (crops->GetField(x) == nullptr)
		{
			// num 번째 밭에 농작물을 심습니다.
			crops->SetField(x+1, Year, Month, Day, Hour);
			crops->SetplantedField(true);
			crops->SethavCrops(-1);
			AddHour();				
		}
	}
}

// 농작물을 수확합니다.
void Character::HarvestField(Crops* crops, int x)
{
	// 가지고 있는 밭이라면
	if (x < crops->GethavField())
	{
		// 밭에 농작물이 심어져 있다면
		if (crops->GetField(x) != nullptr)
		{
			// 심어져 있는 농작물의 레벨이 maxLevel이라면
			if (crops->GetfieldLevel(x) == crops->GetmaxLevel())
			{
				// 농작물을 수확합니다.
				crops->Harvest(crops, x+1);
				crops->SetplantedField(false);
				AddHour();
			}
		}
	}
	
	_sleep(1000);
}

// 밭을 추가합니다.(상점)
void Character::AddField(Crops* crops)
{
	int num = 0;

	cout << crops->GetName() << "밭을 추가하시겠습니까? ( 가격 : 5000원 )" << endl;
	cout << "가지고 있는 밭 수 : " << crops->GethavField() << "개" << endl;
	cout << "1. 예, 2. 아니오  : ";
	cin >> num;

	// 1을 입력한다면
	if (num == 1)
	{
		// 가지고 있는 돈이 충분하다면
		if (money >= 5000)
		{
			// 가지고 있는 밭의 수가 최대 밭의 수를 넘지 않는다면
			if (crops->GethavField() < crops->GetmaxField())
			{
				// (havField+1)번째 밭을 추가합니다.
				crops->SethavField();
				// 가지고 있는 돈을 5000원 소모 합니다.
				money -= 5000;
				cout << "성공적으로 구매하였습니다." << endl;
			}
			// 최대 밭의 수를 넘거나 같다면
			else
			{
				cout << "더 이상 나무를 심을 수 없습니다.";
			}

		}
		// 충분하지 않다면
		else
		{
			cout << "돈을 충분히 가지고 있지 않습니다.";
		}
	}
	// 2나 다른수를 입력한다면
	else
	{
		cout << "상점초기화면으로 돌아갑니다." << endl;
	}

	_sleep(1000);
}

// 농작물을 판매합니다(상점)
void Character::SellCrops(Crops* crops)
{
	int count=0;
	
	while (1)
	{
		cout << "가지고 있는 " << crops->GetName() << "개수 : " << crops->GethavCrops() << endl;
		cout << "몇개를 판매하시겠습니까?(0번은 뒤로가기)" <<endl;
		cout << "입력 : ";
		cin >> count;
	
		// 판매하려는 개수보다 가진 개수가 적을경우
		if (count < crops->GethavCrops())
		{
			// 물건을 판매합니다.
			money += count * crops->GetPrice();
			crops->SethavCrops((-1) * count);
			cout << "성공적으로 물건을 판매하였습니다." << endl;
			cout << "물건을 판매하여 총 " << count * crops->GetPrice() << "원을 얻었습니다." << endl;
			break;
		}
		// 많을경우
		else
		{
			cout << "가지고 있는 물건이 충분하지 않습니다." << endl << endl;
		}
	}
	
	_sleep(1000);
}

// 나무를 심습니다(상점).
void Character::PlantTree(Fruits* fruits)
{
	int num = 0;

	cout << fruits->GetName() << "나무를 심으시겠습니까? ( 가격 : 10000원 )" << endl;
	cout << "가지고 있는 나무 수 : " << fruits->GethavTree() << "그루" << endl;
	cout << "1. 예, 2. 아니오  : ";
	cin >> num;

	// 1을 입력한다면
	if (num == 1)
	{
		// 가지고 있는 돈이 충분하다면
		if (money >= 10000)
		{
			// 가지고 있는 나무의 수가 최대 나무의 수를 넘지 않는다면
			if (fruits->GethavTree() < fruits->GetmaxTree())
			{
				// (havTree+1)번째 나무를 심습니다.
				fruits->SetTree((fruits->GethavTree() + 1), Year, Month, Day, Hour);
				// havTree 를 1 증가시킵니다.
				fruits->SethavTree(true);
				// 가지고 있는 돈을 10000원 소모 합니다.
				money -= 10000;
				cout << "성공적으로 구매하였습니다." << endl;
			}
			// 최대 나무의 수를 넘거나 같다면
			else
			{
				cout << "더 이상 나무를 심을 수 없습니다.";
			}

		}
		// 충분하지 않다면
		else
		{
			cout << "돈을 충분히 가지고 있지 않습니다.";
		}
	}
	// 2나 다른수를 입력한다면
	else
	{
		cout << "상점초기화면으로 돌아갑니다." << endl;
	}

	_sleep(1000);
}

// 열매를 판매합니다.
void Character::SellFruits(Fruits* fruits)
{
	int count = 0;

	while (1)
	{
		cout << "가지고 있는 " << fruits->GetName() << "개수 : " << fruits->GethavFruits() << endl;
		cout << "몇개를 판매하시겠습니까?(0번은 뒤로가기)" << endl;
		cout << "입력 : ";
		cin >> count;

		// 판매하려는 개수보다 가진 개수가 적을경우
		if (count < fruits->GethavFruits())
		{
			// 물건을 판매합니다.
			money += count * fruits->GetPrice();
			fruits->SethavFruits((-1) * count);
			cout << "성공적으로 물건을 판매하였습니다." << endl;
			cout << "물건을 판매하여 총 " << count * fruits->GetPrice() << "원을 얻었습니다." << endl;
			break;
		}
		// 많을경우
		else
		{
			cout << "가지고 있는 물건이 충분하지 않습니다." << endl << endl;
		}
	}

	_sleep(1000);
}

// 열매를 땁니다.
void Character::PickFruits(Fruits* fruits, int x)
{
	// 가지고 있는 나무라면
	if (x < fruits->GethavTree())
	{
		// 심어져 있는 나무(열매)의 레벨이 maxLevel이라면
		if (fruits->GettreeLevel(x) == fruits->GetmaxLevel())
		{
			// 열매를 수확합니다.
			fruits->PickFruits(fruits, x+1);
			AddHour();
			// 해당 나무를 초기화합니다.(시간을 열매를 딴 시점으로 초기화한다)
			fruits->InitializeTree(x, Year, Month, Day, Hour);
		}
	}	
}

// 새끼 동물을 울타리에 넣습니다.
void Character::GrowAnimals(Animals* animals, int x)
{
	// 가지고 있는 울타리라면
	if (x < animals->GethavFence())
	{
		//가지고 있는 울타리가 비어있고 동물이 2마리 이상있어야합니다.
		if (animals->GetFence(x) == nullptr && animals->GethavAnimals() >= 2)
		{
			// num 번째 울타리에 새끼동물을 넣습니다.
			animals->SetFence(x+1, Year, Month, Day, Hour);
			animals->SetGrowingFence(true);
			AddHour();
		}
	}
	
}

// 성장한 동물을 얻습니다.
void Character::GetAdultAnimals(Animals* animals, int x)
{

	// 가지고 있는 울타리라면
	if (x < animals->GethavFence())
	{
		// 울타리에 동물이 있다면
		if (animals->GetFence(x) != nullptr)
		{
			// 동물의 레벨이 maxLevel이라면
			if (animals->GetfenceLevel(x) == animals->GetmaxLevel())
			{
				// 동물을 수확합니다.
				animals->GetAudult(animals, x+1);
				animals->SetGrowingFence(false);
				AddHour();
			}
		}
	}

	_sleep(1000);
}

// 울타리를 삽니다.(상점)
void Character::BuyFence(Animals* animals)
{
	int num = 0;

	cout << animals->GetName() << "울타리를 추가하시겠습니까? ( 가격 : 20000원 )" << endl;
	cout << "가지고 있는 울타리 수 : " << animals->GethavFence() << "개" << endl;
	cout << "1. 예, 2. 아니오  : ";
	cin >> num;

	// 1을 입력한다면
	if (num == 1)
	{
		// 가지고 있는 돈이 충분하다면
		if (money >= 20000)
		{
			// 가지고 있는 울타리의 수가 최대 울타리의 수를 넘지 않는다면
			if (animals->GethavFence() < animals->GetmaxFence())
			{
				// (havFence+1)번째 울타리를 추가합니다.
				animals->SethavFence();
				// 가지고 있는 돈을 20000원 소모 합니다.
				money -= 20000;
				cout << "성공적으로 구매하였습니다." << endl;
			}
			// 최대 울타리의 수를 넘거나 같다면
			else
			{
				cout << "더 이상 울타리를 지을 수 없습니다.";
			}

		}
		// 충분하지 않다면
		else
		{
			cout << "돈을 충분히 가지고 있지 않습니다.";
		}
	}
	// 2나 다른수를 입력한다면
	else
	{
		cout << "상점초기화면으로 돌아갑니다." << endl;
	}

	_sleep(1000);
}

// 동물을 판매합니다.(상점)
void Character::SellAnimals(Animals* animals)
{
	int count = 0;

	while (1)
	{
		cout << "가지고 있는 " << animals->GetName() << "개수 : " << animals->GethavAnimals() << endl;
		cout << "몇개를 판매하시겠습니까?(0번은 뒤로가기)" << endl;
		cout << "입력 : ";
		cin >> count;

		// 판매하려는 개수보다 가진 개수가 적을경우
		if (count < animals->GethavAnimals())
		{
			// 물건을 판매합니다.
			money += count * animals->GetPrice();
			animals->SethavAnimals((-1) * count);
			cout << "성공적으로 물건을 판매하였습니다." << endl;
			cout << "물건을 판매하여 총 " << count * animals->GetPrice() << "원을 얻었습니다." << endl;
			break;
		}
		// 많을경우
		else
		{
			cout << "가지고 있는 물건이 충분하지 않습니다." << endl << endl;
		}
	}

	_sleep(1000);
}

void Character::Table()
{
	int num = 0;
	SetColor(white, black);
	GotoXY(0, 26);
	cout << "무엇을 드시겠습니까?(1.감자,2.고구마,3.당근,4.사과,5.오렌지)" << endl;
	cout << "선택 : ";
	cin >> num;

	if (num <= 3)
	{
		Hungry += 5;
		crops[num - 1]->SethavCrops(-1);
		cout << "배고픔이 5 찼습니다.(남은개수 : " << crops[num-1]->GethavCrops() << "개)";
	}
	else if (num <= 5)
	{
		Hungry += 2;
		fruits[num - 4]->SethavFruits(-1);
		cout << "배고픔이 2 찼습니다.(남은개수 : " << fruits[num-4]->GethavFruits() << "개)";
	}
	else
		cout << "잘못선택하셨습니다.";
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
		cout << "해당 가구를 가지고 있지 않습니다. 구입하시겠습니까?(100000)" << endl;
		cout << "1.예, 2.아니오 : ";
		cin >> num;
		if (num == 1)
		{
			if (money >= 100000)
			{
				cout << "구입하셨습니다.";
				money -= 100000;
				isFurniture[0] = true;
			}
			else
			{
				cout << "돈이 부족합니다.";
			}
			_sleep(1000);
			return;
		}
		else
			return;
	}

	// tv 시청 가능 시간 조정
	int time = (Hungry / 2) - 10;
	if (time < 0) 
		time = 0;

	cout << "몇시간 TV를 시청하시겠습니까?(최대 : " << time << "시간)" << endl;
	cin >> num;
	// tv를 시청합니다.
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
		cout << "TV를 시청할 수 없습니다.";
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
		cout << "해당 가구를 가지고 있지 않습니다. 구입하시겠습니까?(100000)" << endl;
		cout << "1.예, 2.아니오 : ";
		cin >> num;
		if (num == 1)
		{
			if (money >= 100000)
			{
				cout << "구입하셨습니다.";
				money -= 100000;
				isFurniture[1] = true;
			}
			else
				cout << "돈이 부족합니다.";

			_sleep(1000);
			return;
		}
		else
			return;
	}

	cout << "무엇을 구워드시겠습니까?(1.돼지, 2.소)" << endl;
	cout << "선택 : ";
	cin >> num;

	if (num <= 2)
	{
		Hungry += 10;
		animals[num - 1]->SethavAnimals(-1);
		cout << "배고픔이 10 찼습니다.(남은 마리수 : " << animals[num-1]->GethavAnimals() << "마리";
	}
	else
		cout << "잘못선택하셨습니다.";
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
		cout << "해당 가구를 가지고 있지 않습니다. 구입하시겠습니까?(100000)" << endl;
		cout << "1.예, 2.아니오 : ";
		cin >> num;
		if (num == 1)
		{
			if (money >= 100000)
			{
				cout << "구입하셨습니다.";
				money -= 100000;
				isFurniture[2] = true;
			}
			else
				cout << "돈이 부족합니다.";

			_sleep(1000);
			return;
		}
		else
			return;
	}

	// 잠을 잡니다.
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
		cout << "잠을 잘 수 있는 시간이 아닙니다.";
		_sleep(1000);
	}

	SetColor(white, black);

}

// 한시간을 추가합니다.
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
// 플레이어 시간 설정 메서드
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
// 플레이어 이름 반환 메서드
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

// Year, Month, Day, Hour 반환
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

// Crop* 반환
Crops* Character::GetCrops(int i)
{
	return crops[i];
}

// Fruits* 반환
Fruits* Character::GetFruits(int i)
{
	return fruits[i];
}

// Animals* 반환
Animals* Character::GetAnimals(int i)
{
	return animals[i];
}

bool Character::GetisFurniture(int i)
{
	return isFurniture[i];
}

// 플레이어 정보 출력 메서드
void Character::PrintPlayerInfo()
{
	cout << "  이름 : " << Name << "    배고픔 : ";
	PrintPlayerHungry();
	cout << "               ";
}

// 플레이어의 배고픔을 출력합니다.
void Character::PrintPlayerHungry()
{
	int hun = Hungry / 10;
	for (int i = 0; i < hun; i++)
	{
		cout << "★";
	}
	for (int i = hun; i < 10; i++)
	{
		cout << "☆";
	}
}



	//(*potato.begin())->printName();