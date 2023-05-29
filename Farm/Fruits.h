#pragma once
#include "Managers.h"
#include "Tree.h"


class Fruits
{
protected:

	// ���� ����
	string Name;

	// ���� ����
	int price = 0;

	// ���� �ִ� ���� �ܰ�
	int maxLevel;

	// �÷��̾ �ִ�� ������ �ִ� ���� ����
	int maxSize;

	// �÷��̾ ���� ������ �ִ� ���� ����
	int havFruits;

	// �÷��̾ ���� �� �ִ� �ִ� ���� ���� ����
	int maxTree;

	// �÷��̾ ���� ������ �ִ� ���� ���� ����
	int havTree;

	// ������ ��Ȯ���� �� �ִ�� ������ �ִ� ������ ����
	int maxNum;

	// ������ �ְ� ������ �����ϱ���� �ɸ��� �ð�
	int maxgrowTime;

public:

	// ������ ���� �κ��丮�� �߰��մϴ�.
	/// num : ���° ��������
	/// maxNum : ���Ű� ������ �ִ밳��
	virtual void PickFruits(Fruits* fruits, int num);

	// ������ �����ŵ�ϴ�.
	///virtual void Growth();

	// �ش� ������ �ʱ�ȭ �մϴ�.
	virtual void InitializeTree(int num, int y, int m, int d, int h);

	// Set
	virtual void SethavFruits(int i);
	// i��° Tree ����(�߰�)
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