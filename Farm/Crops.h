#pragma once
#include "Managers.h"
#include "Field.h"

class Crops
{
protected:

	// ���۹� ����
	string Name;

	// ���۹� ����
	int price = 0;

	// ���۹� �ִ� ���� �ܰ�
	int maxLevel;

	// �÷��̾ �ִ�� ������ �ִ� ���۹� ����
	int maxSize;

	// �÷��̾ ���� ������ �ִ� ���۹� ����
	int havCrops;

	// �÷��̾ ���� �� �ִ� �ִ� ���۹� ���� ����
	int maxField;

	// �÷��̾ ���� ������ �ִ� ���۹� ���� ����
	int havField;

	// ���۹��� �ɾ��� �ִ� ���� ����
	int plantedField;

	// ���۹��� �ְ� ������ �����ϱ���� �ɸ��� �ð�
	int maxgrowTime;
	
public:
	Crops();

	// ���۹� ����ϰ� �κ��丮�� �߰��մϴ�.
	virtual void Harvest(Crops* crops, int num);
	
	// ���۹� �����ŵ�ϴ�.
	virtual void Growth();
	
	// �ش� ���� �ʱ�ȭ(nullptr) �մϴ�.
	virtual void InitializeField(int num);

	// Set
	// i��° Field ����(�߰�)
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