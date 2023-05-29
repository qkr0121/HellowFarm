#pragma once
#include "Fruits.h"


class Orange : public Fruits
{
private:

	// 나무 리스트
	Tree* tree[10];
public:
	// 생성자
	Orange();
	~Orange();


	// 농작물을 수확하여 저장합니다.
	virtual void PickFruits(Fruits* fruits, int num);

	// 해당 나무를 초기화 합니다.
	virtual void InitializeTree(int num, int y, int m, int d, int h);


	//Set
	// 가지고 있는 과일의 수를 변경합니다
	virtual void SethavFruits(int i);
	// i번째 Field 설정(추가)
	virtual void SetTree(int i, int y, int m, int d, int h);


	// havTree 추가 제거(true -> +1 , false -> -1)
	virtual void SethavTree(bool tf);

	// Tree 구조체의 growTime을 1증가시키고 level을 조정합니다.
	virtual void SetTreeLevel(int y, int m, int d, int h);



	//Get
	// Name 출력 메서드
	virtual string GetName();

	// havTree 반환 메서드
	virtual int GethavTree();

	// tree[i] 반환 메서드
	virtual Tree* GetTree(int i);

	// Tree 구조체의 Level 반환 메서드
	virtual int GettreeLevel(int i);

	// 열매가 초기화된 시간을 반환합니다.
	virtual void GetInitializeTime(int i);

	// havFruits 반환 메서드
	virtual int GethavFruits();

	// maxLevel을 반환합니다.
	virtual int GetmaxLevel();

	// maxTree를 반환합니다.
	virtual int GetmaxTree();

	virtual int GetPrice();

};