#pragma once
#include "Animals.h"

class Pig : public Animals
{
private:
	Fence* fence[10];

public:

	// ������
	Pig();
	~Pig();


	// ������ ��� �κ��丮�� �߰��մϴ�.
	/// num : ���° ��Ÿ������
	virtual void GetAudult(Animals* animals, int num);

	// �ش� ��Ÿ���� �ʱ�ȭ(nullptr) �մϴ�.
	virtual void InitializeFence(int num);


	// Set
	// i��° Fence ����(�߰�)
	virtual void SetFence(int i, int y, int m, int d, int h);

	// growingFence �߰� ����(true -> +1 , false -> -1)
	virtual void SetGrowingFence(bool tf);

	// ������ �ִ� ���� ������ ����
	virtual void SethavAnimals(int i);

	// ������ �ִ� ��Ÿ���� ����
	virtual void SethavFence();

	// fence ����ü�� level �� �����մϴ�. 
	virtual void SetFenceLevel(int y, int m, int d, int h);



	//Get
	// Name ��� �޼���
	virtual string GetName();

	// havFence ��ȯ �޼���
	virtual int GethavFence();

	// fence[i] ��ȯ �޼���
	virtual Fence* GetFence(int i);

	// Fence ����ü�� Level ��ȯ �޼���
	virtual int GetfenceLevel(int i);

	// �������� ������ ������ �ð��� ��ȯ�մϴ�.
	virtual void GetInitializeTime(int i);

	// havAnimals ��ȯ �޼���
	virtual int GethavAnimals();

	// maxLevel�� ��ȯ�մϴ�.
	virtual int GetmaxLevel();

	// maxFence�� ��ȯ�մϴ�.
	virtual int GetmaxFence();

	virtual int GetPrice();

};