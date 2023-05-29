#pragma once
#include "Managers.h"
#include "Tree.h"


class Fruits
{
protected:

	// 과일 종류
	string Name;

	// 과일 가격
	int price = 0;

	// 과일 최대 성장 단계
	int maxLevel;

	// 플레이어가 최대로 가질수 있는 과일 개수
	int maxSize;

	// 플레이어가 현재 가지고 있는 과일 개수
	int havFruits;

	// 플레이어가 심을 수 있는 최대 과일 나무 개수
	int maxTree;

	// 플레이어가 현재 가지고 있는 과일 나무 개수
	int havTree;

	// 과일을 수확했을 때 최대로 얻을수 있는 과일의 개수
	int maxNum;

	// 과일이 최고 레벨로 성장하기까지 걸리는 시간
	int maxgrowTime;

public:

	// 과일을 따고 인벤토리에 추가합니다.
	/// num : 몇번째 나무인지
	/// maxNum : 열매가 나오는 최대개수
	virtual void PickFruits(Fruits* fruits, int num);

	// 과일을 성장시킵니다.
	///virtual void Growth();

	// 해당 나무를 초기화 합니다.
	virtual void InitializeTree(int num, int y, int m, int d, int h);

	// Set
	virtual void SethavFruits(int i);
	// i번째 Tree 설정(추가)
	virtual void SetTree(int i, int y, int m, int d, int h);
	virtual void SethavTree(bool tf);
	virtual void SetTreeLevel(int y, int m, int d, int h);

	// Get
	virtual string GetName();
	virtual int GethavTree();
	virtual Tree* GetTree(int i);
	virtual int GettreeLevel(int i);
	virtual void GetInitializeTime(int i);
	virtual int GethavFruits();
	virtual int GetmaxLevel();
	virtual int GetmaxTree();
	virtual int GetPrice();


};