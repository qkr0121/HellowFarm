#pragma once
#include "Managers.h"
#include "Crops.h"
#include "Potato.h"
#include "SweetPotato.h"
#include "Carrot.h"
#include "Fruits.h"
#include "Apple.h"
#include "Orange.h"
#include "Animals.h"
#include "Pig.h"
#include "Cow.h"
#include "Time.h"
#include "Field.h"
#include "Util.h"
#include<list>

class Crops;
class Potato;
class SweetPotato;
class Carrot;

class Character : public Time
{
private:
	string Name;
	int Hungry;
	int money;
	
	// 성장제
	int water;
	int fertilizer;
	int food;

	// 농작물 객체
	Crops* crops[3];

	// 과일 객체
	Fruits* fruits[2];

	// 동물 객체
	Animals* animals[2];

	// 집 가구 유무
	bool isFurniture[3];
	
public:

	Character(string name, int hungry = 100);
	~Character();

	// 성장제를 구입합니다.
	void BuyGrower(Character* player);

	// 농작물을 성장시킵니다.
	void UseGrowerCrops(Crops* crops, int x);
	// 과일을 성장시킵니다.
	void UseGrowerFruits(Fruits* fruits, int x);
	// 동물을 성장시킵니다.
	void UseGrowerAnimals(Animals* animals, int x);



	// Crops
	// 농작물을 심습니다.
	void PlantField(Crops* crops, int x);

	// 농작물을 수확합니다.
	void HarvestField(Crops* crops, int x);

	// 밭을 추가합니다.(상점)
	void AddField(Crops* crops);

	// 농작물을 판매합니다.(상점)
	void SellCrops(Crops* crops);

	// Fruits
	// 나무를 심습니다.(상점)
	void PlantTree(Fruits* fruits);

	// 열매를 판매합니다.(상점)
	void SellFruits(Fruits* fruits);

	// 나무의 열매를 땁니다.
	void PickFruits(Fruits* fruits, int x);

	// Animals
	// 새끼동물을 울타리에 넣습니다.
	void GrowAnimals(Animals* animals, int x);

	// 성장한 동물을 얻습니다.
	void GetAdultAnimals(Animals* animals, int x);

	// 울타리를 얻습니다.(상점)
	void BuyFence(Animals* animals);

	// 동물을 판매합니다.
	void SellAnimals(Animals* animals);

	// 가구와 상호작용
	// 식탁
	void Table();
	// tv
	void TV(bool isUse);
	// 화로
	void Furnace(bool isUse);
	// 침대
	void Bed(bool isUse);

	//Time
	// 한시간을 추가합니다.
	virtual void AddHour();


	// Set
	// 시간 설정 메서드
	void SetTime(int year, int month, int day, int hour);

	// 성장제
	void SetWater(int i);
	void SetFertilizer(int i);
	void SetFood(int i);

	// Get
	// 플레이어 이름 반환 메서드
	string GetName();
	// money 반환
	int GetMoney();

	// 성장제 반환
	int GetWater();
	int GetFertilizer();
	int GetFood();

	// Year, Month, Day, Hour 반환
	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHour();

	// Crop* 반환
	Crops* GetCrops(int i);

	// Fruits* 반환
	Fruits* GetFruits(int i);

	// Animals* 반환
	Animals* GetAnimals(int i);

	// isFurniture반환
	bool GetisFurniture(int i);

	// Print
	// 플레이어 정보 출력 메서드
	void PrintPlayerInfo();

	// 플레이어의 배고픔을 출력합니다.
	void PrintPlayerHungry();


	//----

	//// Items을(를) 통해 상속됨
	//virtual void Sell() override;
	//virtual void Buy() override;

};

