#include "Managers.h"
#include "Character.h"
#include "Func.h"
#include "Time.h"
#include "Util.h"

int main()
{
	Init();
	int mm;

	while (1)
	{
		system("cls");
		TitleDraw();
		mm = MainMenu();
		if (mm == 0)
			break;
		else if (mm == 2)
			InfoMenu();
		else if (mm == 4)
			return 0;
	}

	// �����Լ� ���尪 �Է�
	srand(GetTickCount64());

	// ĳ����Ŭ���� ����
	Character* player;


	// �̸�
	string Name;

	// �Լ�������
	void(*fp)(Character*) = MoveFarm;

	// ������ ��ȣ ���� ����
	int num = 0;

	// -------- ���� ���� -------------

	system("cls");

	cout << endl;
	cout << "TextFarm �� ���Ű��� ȯ���մϴ�!!!" << endl;
	cout << "������ �����ϱ� ���� ��� ������ �Է����ּ���..." << endl << endl;

	// �̸� �Է¹ޱ�
	cout << "����� �̸��� �����ΰ���?" << endl;
	cout << "�̸� : ";
	cin >> Name;
	
	// player ����
	player = new Character(Name, 100);

	// ���ӽ��۰� �ð� �����ϱ�
	SetTime(player);


	while (1)
	{
		system("cls");
		SetColor(white, black);

		// �ΰ��� ȭ�� ���
		InGameDraw();

		// �÷��̾� ����â �� �κ��丮 ���
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		player->PrintPlayerInfo();
		player->PrintTime();

		// ����ȭ�� ��� �� ������ ��ȣ ����
		fp = FpPrintMain();
		
		//printf("%p", fp);

		// ���� Ȥ�� ����
		if (num == 7) break;
		// ������ ��ȣ�� (Move)�Լ� ȣ��
		else fp(player);

		// ����������(Move�Լ����� ������) �Լ� ȣ�� Ȥ�� �ڷΰ���
		//if(num != 7) fpSub[num - 1](player);
		
	}

	system("cls");
	cout << "������ �����մϴ� . . . ." << endl;
	


	//player->AddPotato();
	//player->PrintName();
	//player->SellPotato();

	// ������ ����
	delete player;

	return 0;
}