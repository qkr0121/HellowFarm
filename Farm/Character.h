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
	
	// ������
	int water;
	int fertilizer;
	int food;

	// ���۹� ��ü
	Crops* crops[3];

	// ���� ��ü
	Fruits* fruits[2];

	// ���� ��ü
	Animals* animals[2];

	// �� ���� ����
	bool isFurniture[3];
	
public:

	Character(string name, int hungry = 100);
	~Character();

	// �������� �����մϴ�.
	void BuyGrower(Character* player);

	// ���۹��� �����ŵ�ϴ�.
	void UseGrowerCrops(Crops* crops, int x);
	// ������ �����ŵ�ϴ�.
	void UseGrowerFruits(Fruits* fruits, int x);
	// ������ �����ŵ�ϴ�.
	void UseGrowerAnimals(Animals* animals, int x);



	// Crops
	// ���۹��� �ɽ��ϴ�.
	void PlantField(Crops* crops, int x);

	// ���۹��� ��Ȯ�մϴ�.
	void HarvestField(Crops* crops, int x);

	// ���� �߰��մϴ�.(����)
	void AddField(Crops* crops);

	// ���۹��� �Ǹ��մϴ�.(����)
	void SellCrops(Crops* crops);

	// Fruits
	// ������ �ɽ��ϴ�.(����)
	void PlantTree(Fruits* fruits);

	// ���Ÿ� �Ǹ��մϴ�.(����)
	void SellFruits(Fruits* fruits);

	// ������ ���Ÿ� ���ϴ�.
	void PickFruits(Fruits* fruits, int x);

	// Animals
	// ���������� ��Ÿ���� �ֽ��ϴ�.
	void GrowAnimals(Animals* animals, int x);

	// ������ ������ ����ϴ�.
	void GetAdultAnimals(Animals* animals, int x);

	// ��Ÿ���� ����ϴ�.(����)
	void BuyFence(Animals* animals);

	// ������ �Ǹ��մϴ�.
	void SellAnimals(Animals* animals);

	// ������ ��ȣ�ۿ�
	// ��Ź
	void Table();
	// tv
	void TV(bool isUse);
	// ȭ��
	void Furnace(bool isUse);
	// ħ��
	void Bed(bool isUse);

	//Time
	// �ѽð��� �߰��մϴ�.
	virtual void AddHour();


	// Set
	// �ð� ���� �޼���
	void SetTime(int year, int month, int day, int hour);

	// ������
	void SetWater(int i);
	void SetFertilizer(int i);
	void SetFood(int i);

	// Get
	// �÷��̾� �̸� ��ȯ �޼���
	string GetName();
	// money ��ȯ
	int GetMoney();

	// ������ ��ȯ
	int GetWater();
	int GetFertilizer();
	int GetFood();

	// Year, Month, Day, Hour ��ȯ
	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHour();

	// Crop* ��ȯ
	Crops* GetCrops(int i);

	// Fruits* ��ȯ
	Fruits* GetFruits(int i);

	// Animals* ��ȯ
	Animals* GetAnimals(int i);

	// isFurniture��ȯ
	bool GetisFurniture(int i);

	// Print
	// �÷��̾� ���� ��� �޼���
	void PrintPlayerInfo();

	// �÷��̾��� ������� ����մϴ�.
	void PrintPlayerHungry();


	//----

	//// Items��(��) ���� ��ӵ�
	//virtual void Sell() override;
	//virtual void Buy() override;

};

