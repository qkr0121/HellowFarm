#pragma once
#include "Crops.h"

class Potato : public Crops
{
private:

	// 밭 리스트
	Field* field[10];
public:
	// 생성자
	Potato();
	~Potato();


	// 농작물을 수확하여 저장합니다.
	virtual void Harvest(Crops* crops, int num);

	// 해당 밭을 초기화(nullptr) 합니다.
	virtual void InitializeField(int num);


	//Set
	// i번째 Field 설정(추가)
	virtual void SetField(int i, int y, int m, int d, int h);

	// plantedField 추가 제거(true -> +1 , false -> -1)
	virtual void SetplantedField(bool tf);

	// field 구조체의 level을 조정합니다.
	virtual void SetFieldLevel(int y, int m, int d, int h);

	// 가지고 있는 농작물의 수를 변경합니다
	virtual void SethavCrops(int i);

	// 가지고 있는 밭의 개수를 1추가합니다.
	virtual void SethavField();


	//Get
	// Name 출력 메서드
	virtual string GetName();
	
	// havCrops 반환 메서드
	virtual int GethavCrops();

	// havField 반환 메서드
	virtual int GethavField();

	// Field 구조체의 Level 반환 메서드
	virtual int GetfieldLevel(int i);

	// Field 반환 메서드
	virtual Field* GetField(int i);

	// 심어진 시간을 반환합니다.
	virtual void GetplantedTime(int i);

	// maxLevel을 반환합니다.
	virtual int GetmaxLevel();

	// maxField 를 반환합니다.
	virtual int GetmaxField();

	virtual int GetPrice();
};