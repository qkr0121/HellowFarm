#pragma once
#include "Managers.h"
#include "Fence.h"

class Animals
{
protected:
	// 동물 종류
	string Name;

	// 동물 가격
	int price = 0;

	// 동물 최대 성장 단계
	int maxLevel;

	// 플레이어가 최대로 가질수 있는 동물 마리수
	int maxSize;

	// 플레이어가 현재 가지고 있는 동물 마리수
	int havAnimals;

	// 플레이어가 지을 수 있는 최대 울타리 개수
	int maxFence;

	// 플레이어가 현재 가지고 있는 울타리 개수
	int havFence;

	// 새끼동물이 최고 레벨로 성장하기까지 걸리는 시간
	int maxgrowTime;

	// 사용중인 울타리 개수
	int growingFence;

public:


	// 동물을 얻고 인벤토리에 추가합니다.
	/// num : 몇번째 울타리인지
	virtual void GetAudult(Animals* animals, int num);

	// 과일을 성장시킵니다.
	///virtual void Growth();

	// 해당 울타리를 초기화(nullptr) 합니다.
	virtual void InitializeFence(int num);

	// Set
	virtual void SethavAnimals(int i);
	// i번째 Tree 설정(추가)
	virtual void SetFence(int i, int y, int m, int d, int h);
	virtual void SethavFence();
	virtual void SetFenceLevel(int y, int m, int d, int h);
	// plantedField 추가 제거(true -> +1 , false -> -1)
	virtual void SetGrowingFence(bool tf);

	// Get
	virtual string GetName();
	virtual int GethavFence();
	virtual Fence* GetFence(int i);
	virtual int GetfenceLevel(int i);
	virtual void GetInitializeTime(int i);
	virtual int GethavAnimals();
	virtual int GetmaxLevel();
	virtual int GetmaxFence();
	virtual int GetPrice();
	
};