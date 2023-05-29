#pragma once
#include "Managers.h"
#include "Fence.h"

class Animals
{
protected:
	// ���� ����
	string Name;

	// ���� ����
	int price = 0;

	// ���� �ִ� ���� �ܰ�
	int maxLevel;

	// �÷��̾ �ִ�� ������ �ִ� ���� ������
	int maxSize;

	// �÷��̾ ���� ������ �ִ� ���� ������
	int havAnimals;

	// �÷��̾ ���� �� �ִ� �ִ� ��Ÿ�� ����
	int maxFence;

	// �÷��̾ ���� ������ �ִ� ��Ÿ�� ����
	int havFence;

	// ���������� �ְ� ������ �����ϱ���� �ɸ��� �ð�
	int maxgrowTime;

	// ������� ��Ÿ�� ����
	int growingFence;

public:


	// ������ ��� �κ��丮�� �߰��մϴ�.
	/// num : ���° ��Ÿ������
	virtual void GetAudult(Animals* animals, int num);

	// ������ �����ŵ�ϴ�.
	///virtual void Growth();

	// �ش� ��Ÿ���� �ʱ�ȭ(nullptr) �մϴ�.
	virtual void InitializeFence(int num);

	// Set
	virtual void SethavAnimals(int i);
	// i��° Tree ����(�߰�)
	virtual void SetFence(int i, int y, int m, int d, int h);
	virtual void SethavFence();
	virtual void SetFenceLevel(int y, int m, int d, int h);
	// plantedField �߰� ����(true -> +1 , false -> -1)
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