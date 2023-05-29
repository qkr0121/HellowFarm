#pragma once
#include "Fruits.h"


class Orange : public Fruits
{
private:

	// ���� ����Ʈ
	Tree* tree[10];
public:
	// ������
	Orange();
	~Orange();


	// ���۹��� ��Ȯ�Ͽ� �����մϴ�.
	virtual void PickFruits(Fruits* fruits, int num);

	// �ش� ������ �ʱ�ȭ �մϴ�.
	virtual void InitializeTree(int num, int y, int m, int d, int h);


	//Set
	// ������ �ִ� ������ ���� �����մϴ�
	virtual void SethavFruits(int i);
	// i��° Field ����(�߰�)
	virtual void SetTree(int i, int y, int m, int d, int h);


	// havTree �߰� ����(true -> +1 , false -> -1)
	virtual void SethavTree(bool tf);

	// Tree ����ü�� growTime�� 1������Ű�� level�� �����մϴ�.
	virtual void SetTreeLevel(int y, int m, int d, int h);



	//Get
	// Name ��� �޼���
	virtual string GetName();

	// havTree ��ȯ �޼���
	virtual int GethavTree();

	// tree[i] ��ȯ �޼���
	virtual Tree* GetTree(int i);

	// Tree ����ü�� Level ��ȯ �޼���
	virtual int GettreeLevel(int i);

	// ���Ű� �ʱ�ȭ�� �ð��� ��ȯ�մϴ�.
	virtual void GetInitializeTime(int i);

	// havFruits ��ȯ �޼���
	virtual int GethavFruits();

	// maxLevel�� ��ȯ�մϴ�.
	virtual int GetmaxLevel();

	// maxTree�� ��ȯ�մϴ�.
	virtual int GetmaxTree();

	virtual int GetPrice();

};