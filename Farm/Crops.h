#pragma once
#include "Managers.h"
#include "Field.h"

class Crops
{
protected:

	// 농작물 종류
	string Name;

	// 농작물 가격
	int price = 0;

	// 농작물 최대 성장 단계
	int maxLevel;

	// 플레이어가 최대로 가질수 있는 농작물 개수
	int maxSize;

	// 플레이어가 현재 가지고 있는 농작물 개수
	int havCrops;

	// 플레이어가 심을 수 있는 최대 농작물 밭의 개수
	int maxField;

	// 플레이어가 현재 가지고 있는 농작물 밭의 개수
	int havField;

	// 농작물이 심어져 있는 밭의 개수
	int plantedField;

	// 농작물이 최고 레벨로 성장하기까지 걸리는 시간
	int maxgrowTime;
	
public:
	Crops();

	// 농작물 재배하고 인벤토리에 추가합니다.
	virtual void Harvest(Crops* crops, int num);
	
	// 농작물 성장시킵니다.
	virtual void Growth();
	
	// 해당 밭을 초기화(nullptr) 합니다.
	virtual void InitializeField(int num);

	// Set
	// i번째 Field 설정(추가)
	virtual void SetField(int i, int y, int m, int d, int h);
	virtual void SetplantedField(bool tf);
	virtual void SetFieldLevel(int y, int m , int d, int h);
	virtual void SethavCrops(int i);
	virtual void SethavField();

	// Get
	virtual string GetName();
	virtual int GethavCrops();
	virtual int GethavField();
	virtual int GetfieldLevel(int i);
	virtual Field* GetField(int i);
	virtual void GetplantedTime(int i);
	virtual int GetmaxLevel();
	virtual int GetmaxField();
	virtual int GetPrice();

};