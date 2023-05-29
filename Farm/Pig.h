#pragma once
#include "Animals.h"

class Pig : public Animals
{
private:
	Fence* fence[10];

public:

	// 생성자
	Pig();
	~Pig();


	// 동물을 얻고 인벤토리에 추가합니다.
	/// num : 몇번째 울타리인지
	virtual void GetAudult(Animals* animals, int num);

	// 해당 울타리를 초기화(nullptr) 합니다.
	virtual void InitializeFence(int num);


	// Set
	// i번째 Fence 설정(추가)
	virtual void SetFence(int i, int y, int m, int d, int h);

	// growingFence 추가 제거(true -> +1 , false -> -1)
	virtual void SetGrowingFence(bool tf);

	// 가지고 있는 동물 마리수 설정
	virtual void SethavAnimals(int i);

	// 가지고 있는 울타리수 설정
	virtual void SethavFence();

	// fence 구조체의 level 을 조정합니다. 
	virtual void SetFenceLevel(int y, int m, int d, int h);



	//Get
	// Name 출력 메서드
	virtual string GetName();

	// havFence 반환 메서드
	virtual int GethavFence();

	// fence[i] 반환 메서드
	virtual Fence* GetFence(int i);

	// Fence 구조체의 Level 반환 메서드
	virtual int GetfenceLevel(int i);

	// 새끼동물 성장을 시작한 시간을 반환합니다.
	virtual void GetInitializeTime(int i);

	// havAnimals 반환 메서드
	virtual int GethavAnimals();

	// maxLevel을 반환합니다.
	virtual int GetmaxLevel();

	// maxFence를 반환합니다.
	virtual int GetmaxFence();

	virtual int GetPrice();

};