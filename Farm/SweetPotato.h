#pragma once
#include "Crops.h"


class SweetPotato : public Crops
{
private:
	// �� ����Ʈ
	Field* field[10];
public:
	// ������
	SweetPotato();
	~SweetPotato();


	// ���۹��� ��Ȯ�Ͽ� �����մϴ�.
	virtual void Harvest(Crops* crops, int num);

	// �ش� ���� �ʱ�ȭ(nullptr) �մϴ�.
	virtual void InitializeField(int num);


	// Set
	// i��° Field ����(�߰�)
	virtual void SetField(int i, int y, int m, int d, int h);

	// plantedField �߰� ����(true -> +1 , false -> -1)
	virtual void SetplantedField(bool tf);

	// field ����ü�� level�� �����մϴ�.
	virtual void SetFieldLevel(int y, int m, int d, int h);

	// ������ �ִ� ���۹��� ���� �����մϴ�
	virtual void SethavCrops(int i);

	// ������ �ִ� ���� ������ 1�߰��մϴ�.
	virtual void SethavField();


	//Get
	// Name ��� �޼���
	virtual string GetName();

	// havCrops ��ȯ �޼���
	virtual int GethavCrops();

	// havField ��ȯ �޼���
	virtual int GethavField();

	// Field ����ü�� Level ��ȯ �޼���
	virtual int GetfieldLevel(int i);

	// Field ��ȯ �޼���
	virtual Field* GetField(int i);

	// �ɾ��� �ð��� ��ȯ�մϴ�.
	virtual void GetplantedTime(int i);

	// maxLevel�� ��ȯ�մϴ�.
	virtual int GetmaxLevel();

	// maxField �� ��ȯ�մϴ�.
	virtual int GetmaxField();

	virtual int GetPrice();
};