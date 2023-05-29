#include "Func.h"

int InputNum(int max);

// ó�� �ð� �Է� �Լ�
void SetTime(Character* player)
{
	int year;
	int month;
	int day;
	int hour;

	cout << "���� ��¥�� �Է����ּ���." << endl;

	cout << "�� : ";
	cin >> year;

	cout << "�� : ";
	month = InputNum(12);
	
	cout << "�� : ";
	day = InputNum(31);
	
	cout << "�ð�(���� 1�ô� 13��) : ";
	hour = InputNum(24);
	

	player->SetTime(year, month, day, hour);

	system("cls");
}

// Ÿ��Ʋ
void TitleDraw()
{
	// Ÿ��Ʋ
	cout << "                                                                                                " << endl;
	cout << "          ##  ##    ######    ##        ##                                                      " << endl;
	cout << "         ##  ##    ##        ##        ##                     #####    ##     ####    ###   ##  " << endl;
	cout << "         ######    ######    ##        ##                     ##      ## #    ##  #   ## # # #  " << endl;
	cout << "          ######    ######    ##        ##                    ####   ## # #   ####    ## # # #  " << endl;
	cout << "          ##  ##    ##        ######    ######  ##  # # #     ##    ##     #  ##  #   ##  #  #  " << endl;
	cout << "         ##  ##    ######    ######    ######   ##   # #      ##    ##     #  ##   #  ##     #  " << endl;
	cout << "                                                                                                " << endl;



}

// ���θ޴�
int MainMenu()
{
	int x = 45;
	int y = 11;
	GotoXY(x-2, y);
	cout << "> �� �� �� ��";
	GotoXY(x, y+2);
	cout << "�� �� �� ��";
	GotoXY(x+3, y+4);
	cout << "�� ��";

	while (1)
	{
		int key = KeyControl();
		switch (key)
		{
		case UP:
			if (y > 11)
			{
				// ���� ��ġ �����
				GotoXY(x - 2, y);
				cout << " ";
				// UP �� ��ġ�� > ���
				GotoXY(x - 2, y - 2);
				y -= 2;
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 15)
			{
				// ���� ��ġ �����
				GotoXY(x - 2, y);
				cout << " ";
				// DOWN �� ��ġ�� > ���
				GotoXY(x - 2, y + 2);
				y += 2;
				cout << ">";
			}
			break;
		case SUBMIT:
			return y-11;
			break;
		}
	}

}

void InfoMenu()
{
	system("cls");
	int temp;
	cout << "���� �޴�" << endl;
	cout << "�ڷ� ������ �ƹ� Ű�� �Է� �Ͻÿ� ...";
	_getch();
}

void InGameDraw()
{
	cout << "                                                                                                   " << endl;
	cout << "                                                                                                   " << endl;
	cout << "                                   @             3                                                 " << endl;
	cout << "      #                           @O@     ################                                  #      " << endl;
	cout << "      #               @@           @ /   #                #      @@                         #      " << endl;
	cout << "      #    @         @##@          |/    #                #  @@@         @      @      @    #      " << endl;
	cout << "      #   @O@         @@           # # # #              @@@@  # #       @O@    @O@    @O@   #      " << endl;
	cout << "      #    @ /        || /       #                    ####        #      @ /    @ /    @ /  #      " << endl;
	cout << "      #    |/         ||/        #             ###### #  #        #      |/     |/     |/   #      " << endl;
	cout << "      #### # # # # # # # # # # # #          ###      ### #        # # # # # # # # # # # # ###      " << endl;
	cout << "      ###                                ###            ###                                ##      " << endl;
	cout << "      ###                               #   ###            #                               ##      " << endl;
	cout << "   1  ###                               #   ###  5         #                               ##  2   " << endl;
	cout << "      ###                               #         # # #    #                               ##      " << endl;
	cout << "      ###                               #         #  ##    #                               ##      " << endl;
	cout << "      #### # # # # # # # # # # # #      #         #   #    #      # # # # # # # # # # # # ###      " << endl;
	cout << "      #                          #      ####################      #                 @@      #      " << endl;
	cout << "      #     @@          @        #                                #       @        @##@     #      " << endl;
	cout << "      #    @##@        @O@         # # # #                # # # #        @O@        @@      #      " << endl;
	cout << "      #     @@          @                #                #               @         || /    #      " << endl;
	cout << "      #     || /        |/               #                #               |/        ||/     #      " << endl;
	cout << "      #     ||/                           ################                                  #      " << endl;
	cout << "                                                 4                                                 " << endl;
	cout << "                                                                                                   " << endl;
}

// ����ȭ�� ��� �� ���� �Լ�
void (*FpPrintMain())(Character*)
{
	SetColor(white, black);

	// Ŀ�� ��ġ
	int x = 3;
	int y = 11;

	// ������ ����
	GotoXY(0, 28);
	cout << "  1.����   2.������   3.����   4.����   5.��";

	SetColor(lightgreen, black);

	GotoXY(x, y);
	cout << "V";

	
	int out = 0;
	// Ű �Է��� �޽��ϴ�.
	while (out == 0)
	{
		int key = KeyControl();
		switch (key)
		{
		case UP:
			// x �� 49 �϶��� ���� ������ �� �ֽ��ϴ�.
			if (x == 49)
			{
				if (y > 1)
				{
					// ���� ��ġ �����
					GotoXY(x, y);
					cout << " ";
					// UP �� ��ġ�� V ���
					y -= 10;
					GotoXY(x, y);
					cout << "V";
				}
			}
			break;
		case DOWN:
			// x �� 49 �϶��� �Ʒ��� ������ �� �ֽ��ϴ�.
			if (x == 49)
			{
				if (y < 21)
				{
					// ���� ��ġ �����
					GotoXY(x, y);
					cout << " ";
					// Down �� ��ġ�� V ���
					y += 10;
					GotoXY(x, y);
					cout << "V";
				}
			}
			break;
		case LEFT:
			// y �� 11 �϶��� �������� �����ϼ� �ֽ��ϴ�.
			if (y == 11)
			{
				if (x > 3)
				{
					// ���� ��ġ�� V �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� V�� ǥ�����ݴϴ�.
					x -= 46;
					GotoXY(x, y);
					cout << "V";
				}
			}
			break;
		case RIGHT:
			// y �� 11 �϶��� ���������� �����ϼ� �ֽ��ϴ�.
			if (y == 11)
			{
				if (x < 95)
				{
					// ���� ��ġ�� V �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� V�� ǥ�����ݴϴ�.
					x += 46;
					GotoXY(x, y);
					cout << "V";
				}
			}
			break;
		// �ش� ��ȣ�� �����մϴ�.
		case SUBMIT:
			out = 1;
			break;
		}
	}

	int num = 0;

	//cout << "6. �ð������� ( 1�ð� )" << endl << endl;
	//cout << "7. ����" << endl << endl;

	// �Լ� ������ ����
	switch (x+y)
	{
	// 1�� ����
	case 14:
		return MoveFarm;
		break;
	// 2�� ����
	case 106:
		return MoveOrchard;
		break;
	// 3�� ����
	case 50:
		return MovePastrue;
		break;
	// 4�� ����
	case 70:
		return MoveShop;
		break;
	// 5�� ����
	case 60:
		return MoveHouse;
		break;
	default:
		break;
	}
	


	//fp[4] =
	//fp[5] = MoveHour;
	//fp[6]

}

// 1. �������� �̵� �� ��� �Լ�, ��ο� �Լ�
void MoveFarm(Character* player)
{
	system("cls");
	int out = 0;

	while (out == 0)
	{
		SetColor(white, black);

		MoveFarmDraw(player);

		// �÷��̾� ����â �� �κ��丮 ���
		GotoXY(0, 24);
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		player->PrintPlayerInfo();
		player->PrintTime();

		// Ŀ�� ��ǥ ����
		int x = 7;
		int y = 6;

		int keyout = 0;
		int act = 0;

		// ���� Ŀ����ġ�� ǥ���� �ݴϴ�.
		SetColor(green, black);
		GotoXY(x, y);
		cout << "^";

		// Ű �Է��� �޽��ϴ�.
		while (keyout == 0)
		{
			int key = KeyControl();
			switch (key)
			{
			case UP:
				// y �� 6���� Ŭ���� ���� ������ �� �ֽ��ϴ�.
				if (y > 6)
				{
					// ���� ��ġ �����
					GotoXY(x, y);
					cout << " ";
					// UP �� ��ġ�� ^ ���
					y -= 8;
					GotoXY(x, y);
					cout << "^";
				}

				break;
			case DOWN:
				// y ��  22 ���� �Ʒ��� ���� ��쿡�� �Ʒ��� ������ �� �ֽ��ϴ�.
				if (y < 22)
				{
					// ���� ��ġ �����
					GotoXY(x, y);
					cout << " ";
					// Down �� ��ġ�� ^ ���
					y += 8;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case LEFT:
				// x �� 94 �̸� 70���� �̵��մϴ�.
				if (x == 94)
				{
					// ���� ��ġ�� ^ �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� ^�� ǥ�����ݴϴ�.
					x = 70;
					GotoXY(x, y);
					cout << "^";
				}
				// x �� 7 �̻� �� ���� �������� ������ �� �ֽ��ϴ�.
				else if (x > 7)
				{
					// ���� ��ġ�� ^ �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� ^�� ǥ�����ݴϴ�.
					x -= 7;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case RIGHT:
				// x �� 70 ���� ���� ��쿡�� ���������� ������ �� �ֽ��ϴ�.
				if (x < 70)
				{
					// ���� ��ġ�� ^ �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� ^�� ǥ�����ݴϴ�.
					x += 7;
					GotoXY(x, y);
					cout << "^";
				}
				// x �� 70 �� ��쿡�� 94�� �̵��մϴ�.
				else if (x == 70)
				{
					// y �� 14 �� ��쿡�� 94���� ������ �� �ֽ��ϴ�.
					if (y == 14)
					{
						// ���� ��ġ�� ^ �� ����ϴ�.
						GotoXY(x, y);
						cout << " ";
						// x �� ��ġ�� �����ϰ� �ٽ� ^�� ǥ�����ݴϴ�.
						x = 94;
						GotoXY(x, y);
						cout << "^";
					}
				}
				break;
				// �ɱ� Ȥ�� ��Ȯ�ϴ� �ൿ�� �մϴ�.
			case SUBMIT:
				// x �� 94 �̸� �������� ���ϴ�.
				if (x == 94)
				{

				}
				// �ɾ��� �ִٸ� �ൿ�� �õ��մϴ�.
				else if (player->GetCrops((y - 6) / 8)->GetField((x - 5) / 7) != nullptr)
				{
					act = 2;
				}
				else
					act = 1;
				keyout = 1;
				break;
				// �����縦 ����մϴ�.
			case GROW:
				//player->AddHour();
				act = 3;
				keyout = 1;
				break;
			}
		}


		// �ش� ��� ��ȣ�ۿ��� �մϴ�.
		switch (y)
		{
			// ���� ��
		case 6:
			ContinueFarm(player, player->GetCrops(0), x, act);
			break;
			// ���� �� �� ����
		case 14:
			// x �� 94 �� �������� ���ϴ�.
			if(x != 94)
				ContinueFarm(player, player->GetCrops(1), x, act);
			else
			{
				MoveHome(player);
				out = 1;
			}
			break;
			// ��� ��
		case 22:
			ContinueFarm(player, player->GetCrops(2), x, act);
			break;
		}
	}
}

void MoveFarmDraw(Character* player)
{
	cout << "   __���ڹ�__________________________________________________________________                      " << endl;
	cout << "  #  *****                                                                  #     @                " << endl;
	cout << "  #  *   *                                                                  #    @O@               " << endl;
	cout << "  #  *   *                                                                  #     @ /              " << endl;
	cout << "  #  *   *                                                                  #     |/               " << endl;
	cout << "  #__*****__________________________________________________________________# # # # #      @       " << endl;
	cout << "  #                                                                                   #   @O@      " << endl;
	cout << "  #                                                                                   #    @ /     " << endl;
	cout << "  #__������________________________________________________________________          #    |/     " << endl;
	cout << "  #  *****                                                                  #           # # # # # #" << endl;
	cout << "  #  *   *                                                                  #                      " << endl;
	cout << "  #  *   *                                                                  #                      " << endl;
	cout << "  #  *   *                                                                  #                      " << endl;
	cout << "  #__*****__________________________________________________________________#                 H    " << endl;
	cout << "  #                                                                                                " << endl;
	cout << "  #                                                                                                " << endl;
	cout << "  #__��ٹ�__________________________________________________________________           # # # # # #" << endl;
	cout << "  #  *****                                                                  #          #    @@     " << endl;
	cout << "  #  *   *                                                                  #          #   @##@    " << endl;
	cout << "  #  *   *                                                                  #          #    @@     " << endl;
	cout << "  #  *   *                                                                  #          #    || /   " << endl;
	cout << "  #  *****__________________________________________________________________#          #    ||/    " << endl;
	cout << "  #                                                                                    #           " << endl;
	cout << "  #_________________________________________________________________________# # # # # #            " << endl;

	int x = 5;
	int y = 1;

	// ���� ������ �ִ� ���� ���� �׷��ݴϴ�.
	for (int i = 0;i < player->GetCrops(0)->GethavField();i++)
	{
		x = 5 + (i * 7);

		// ���� �׸��ϴ�.
		GotoXY(x, y);
		cout << "*****";
		GotoXY(x, y + 1);
		cout << "*   *";
		GotoXY(x, y + 2);
		cout << "*   *";
		GotoXY(x, y + 3);
		cout << "*   *";
		GotoXY(x, y + 4);
		cout << "*****";

		SetColor(yellow, black);
		// �ɾ��� �ִٸ�
		if (player->GetCrops(0)->GetField(i) != nullptr)
		{
			GotoXY(x + 2, y + 2);
			// ���۹��� �ܰ踦 ����մϴ�.
			cout << player->GetCrops(0)->GetfieldLevel(i);
		}
		SetColor(white, black);

	}

	x = 5;
	y = 9;
	// ���� ������ �ִ� ���� ���� �׷��ݴϴ�.
	for (int i = 0;i < player->GetCrops(1)->GethavField();i++)
	{
		x = 5 + (i * 7);

		// ���� �׸��ϴ�.
		GotoXY(x, y);
		cout << "*****";
		GotoXY(x, y + 1);
		cout << "*   *";
		GotoXY(x, y + 2);
		cout << "*   *";
		GotoXY(x, y + 3);
		cout << "*   *";
		GotoXY(x, y + 4);
		cout << "*****";

		SetColor(purple, black);
		// �ɾ��� �ִ� ���۹��� �ܰ踦 ǥ���մϴ�.
		if (player->GetCrops(1)->GetField(i) != nullptr)
		{
			GotoXY(x + 2, y + 2);
			// ���۹��� �ܰ踦 ����մϴ�.
			cout << player->GetCrops(1)->GetfieldLevel(i);
		}
		SetColor(white, black);

	}

	x = 5;
	y = 17;
	// ���� ������ �ִ� ��� ���� �׷��ݴϴ�.
	for (int i = 0;i < player->GetCrops(2)->GethavField();i++)
	{
		x = 5 + (i * 7);

		// ���� �׸��ϴ�.
		GotoXY(x, y);
		cout << "*****";
		GotoXY(x, y + 1);
		cout << "*   *";
		GotoXY(x, y + 2);
		cout << "*   *";
		GotoXY(x, y + 3);
		cout << "*   *";
		GotoXY(x, y + 4);
		cout << "*****";

		SetColor(lightred, black);

		// �ɾ��� �ִ� ���۹��� �ܰ踦 ǥ���մϴ�.
		if (player->GetCrops(2)->GetField(i) != nullptr)
		{
			GotoXY(x + 2, y + 2);
			// ���۹��� �ܰ踦 ����մϴ�.
			cout << player->GetCrops(2)->GetfieldLevel(i);
		}
		SetColor(white, black);

	}

	// ���۹� �κ��丮�� ����մϴ�.
	GotoXY(0, 27);
	cout << "  " << player->GetCrops(0)->GetName() << " : " << player->GetCrops(0)->GethavCrops() << "��   ";
	cout << "  " << player->GetCrops(1)->GetName() << " : " << player->GetCrops(1)->GethavCrops() << "��" << endl;
	cout << "  " << player->GetCrops(2)->GetName() << " : " << player->GetCrops(2)->GethavCrops() << "��   ";
	cout << "  �� : " << player->GetWater() << "��";
}

// 2. ���������� �̵��� ��� �Լ�
void MoveOrchard(Character* player)
{
	system("cls");
	int out = 0;

	while (out == 0)
	{
		SetColor(white, black);

		MoveOrchardDraw(player);

		// �÷��̾� ����â �� �κ��丮 ���

		GotoXY(0, 24);
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		player->PrintPlayerInfo();
		player->PrintTime();

		// Ŀ�� ��ǥ ����
		int x = 28;
		int y = 8;

		int keyout = 0;
		int act = 0;
		SetColor(green, black);

		// Ű �Է��� �޽��ϴ�.
		while (keyout == 0)
		{
			int key = KeyControl();
			switch (key)
			{
			case UP:
				// y �� 8���� Ŭ���� ���� ������ �� �ֽ��ϴ�.
				if (y > 8)
				{
					// ���� ��ġ �����
					GotoXY(x, y);
					cout << " ";
					// UP �� ��ġ�� ^ ���
					y -= 11;
					GotoXY(x, y);
					cout << "^";
				}

				break;
			case DOWN:
				// y ��  19 ���� �Ʒ��� ���� ��쿡�� �Ʒ��� ������ �� �ֽ��ϴ�.
				if (y < 19)
				{
					// ���� ��ġ �����
					GotoXY(x, y);
					cout << " ";
					// Down �� ��ġ�� ^ ���
					y += 11;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case LEFT:
				// x �� 28 �̸� 6���� y�� 15 �� �̵��մϴ�.
				if (x == 28)
				{
					// ���� ��ġ�� ^ �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� ^�� ǥ�����ݴϴ�.
					x = 6;
					y = 15;
					GotoXY(x, y);
					cout << "^";
				}
				// x �� 28 �̻� �� ���� �������� ������ �� �ֽ��ϴ�.
				else if (x > 28)
				{
					// ���� ��ġ�� ^ �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� ^�� ǥ�����ݴϴ�.
					x -= 7;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case RIGHT:
				// x �� 6 �� ��쿡�� 28�� y �� 8 �� �̵��մϴ�.
				if (x == 6)
				{
					// ���� ��ġ�� ^ �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� ^�� ǥ�����ݴϴ�.
					x = 28;
					y = 8;
					GotoXY(x, y);
					cout << "^";	
				}
				// x �� 91 ���� ���� ��쿡�� ���������� ������ �� �ֽ��ϴ�.
				else if (x < 91)
				{
					// ���� ��ġ�� ^ �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� ^�� ǥ�����ݴϴ�.
					x += 7;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			// �ൿ�� �մϴ�.
			case SUBMIT:
				// x�� 6�̸� �������� ���ϴ�.
				if (x == 6)
				{

				}
				// ��Ȯ�� �õ��մϴ�.
				else if (player->GetFruits((y-8)/11)->GetTree((x-28)/7) != nullptr)
				{
					act = 2;
				}
				keyout = 1;
				break;
			// �����縦 ����մϴ�.
			case GROW:
				player->AddHour();
				//act = 3;
				keyout = 1;
				break;
			}
		}

		// �ش� ������ ��ȣ�ۿ��� �մϴ�.
		switch (y)
		{
			// �������
		case 8:
			ContinueOrchard(player, player->GetFruits(0), x, act);
			break;
			// ����ȭ��
		case 15:
			MoveHome(player);
			out = 1;
			break;
			// ������ ����
		case 19:
			ContinueOrchard(player, player->GetFruits(1), x, act);
			break;
		}
	}
}

void MoveOrchardDraw(Character* player)
{
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  " << endl;
	cout << "                        __�������______________________________________________________________#  " << endl;
	cout << "                       #                                                                        #  " << endl;
	cout << "                 @     #                                                                        #  " << endl;
	cout << "                @O@    #                                                                        #  " << endl;
	cout << "                 @ /   #                                                                        #  " << endl;
	cout << "                 |/    #                                                                        #  " << endl;
	cout << "     @         # # # # #________________________________________________________________________#  " << endl;
	cout << "    @O@      #              ^                                                                   #  " << endl;
	cout << "     @ /     #                                                                                  #  " << endl;
	cout << "     |/      #                                                                                  #  " << endl;
	cout << "# # # # # # #                                                                                   #  " << endl;
	cout << "                        __����������____________________________________________________________#  " << endl;
	cout << "                       #                                                                        #  " << endl;
	cout << "     H                 #                                                                        #  " << endl;
	cout << "                       #                                                                        #  " << endl;
	cout << "                       #                                                                        #  " << endl;
	cout << "                       #                                                                        #  " << endl;
	cout << "# # # # # # #          #________________________________________________________________________#  " << endl;
	cout << "             #                                                                                  #  " << endl;
	cout << "             #                                                                                  #  " << endl;
	cout << "             #                                                                                  #  " << endl;
	cout << "             #                                                                                  #  " << endl;
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  " << endl;

	int x = 26;
	int y = 4;

	// ���� ������ �ִ� ��������� �׷��ݴϴ�.
	for (int i = 0;i < player->GetFruits(0)->GethavTree(); i++)
	{
		x = 26 + (i * 7);

		// ������ �׸��ϴ�.
		GotoXY(x, y);
		cout << " @@@ ";
		GotoXY(x, y + 1);
		cout << "@@@@@";
		GotoXY(x, y + 2);
		cout << "  |  ";
		GotoXY(x, y + 3);
		cout << "__|__";

		SetColor(lightred, black);

		// �ɾ��� �ִٸ�
		if (player->GetFruits(0)->GetTree(i) != nullptr)
		{
			GotoXY(x + 2, y - 1);
			// ������ �ܰ踦 ����մϴ�.
			cout << player->GetFruits(0)->GettreeLevel(i);
		}
		SetColor(white, black);

	}

	x = 26;
	y = 15;
	// ���� ������ �ִ� ������������ �׷��ݴϴ�.
	for (int i = 0;i < player->GetFruits(1)->GethavTree();i++)
	{
		x = 26 + (i * 7);

		// ������ �׸��ϴ�.
		GotoXY(x, y);
		cout << " @@@ ";
		GotoXY(x, y + 1);
		cout << "@@@@@";
		GotoXY(x, y + 2);
		cout << "  |  ";
		GotoXY(x, y + 3);
		cout << "__|__";

		SetColor(yellow, black);

		// �ɾ��� �ִٸ�
		if (player->GetFruits(1)->GetTree(i) != nullptr)
		{
			GotoXY(x + 2, y - 1);
			// ������ �ܰ踦 ����մϴ�.
			cout << player->GetFruits(1)->GettreeLevel(i);
		}
		SetColor(white, black);

	}

	// ���� �κ��丮�� ����մϴ�.
	GotoXY(0, 27);
	cout << "  " << player->GetFruits(0)->GetName() << " : " << player->GetFruits(0)->GethavFruits() << "��   ";
	cout << "  " << player->GetFruits(1)->GetName() << " : " << player->GetFruits(1)->GethavFruits() << "��" << endl;
	cout << "  ��� : " << player->GetFertilizer() << "��";
}

// 3. �������� �̵��� ��� �Լ�
void MovePastrue(Character* player)
{
	int num = 0;

	// ���� ����
	system("cls");
	int out = 0;

	while (out == 0)
	{
		SetColor(white, black);

		MovePastrueDraw(player);

		// �÷��̾� ����â �� �κ��丮 ���
		GotoXY(0, 24);
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		player->PrintPlayerInfo();
		player->PrintTime();

		// Ŀ�� ��ǥ ����
		int x = 16;
		int y = 7;

		int keyout = 0;
		int act = 0;
		SetColor(green, black);

		// Ű �Է��� �޽��ϴ�.
		while (keyout == 0)
		{
			int key = KeyControl();
			switch (key)
			{
			case UP:
				// y �� 22�� ��� 15 �� �̵��մϴ�.
				if (y == 22)
				{
					// ���� ��ġ �����
					GotoXY(x, y);
					cout << " ";
					// UP �� ��ġ�� ^ ���
					y = 15;
					GotoXY(x, y);
					cout << "^";
				}
				// y �� 7���� Ŭ���� ���� ������ �� �ֽ��ϴ�.
				else if (y > 7)
				{
					// ���� ��ġ �����
					GotoXY(x, y);
					cout << " ";
					// UP �� ��ġ�� ^ ���
					y -= 8;
					GotoXY(x, y);
					cout << "^";
				}

				break;
			case DOWN:
				// y �� 15 �� ��� x=51 y=22 �� �̵��մϴ�.
				if (y == 15)
				{
					// ���� ��ġ �����
					GotoXY(x, y);
					cout << " ";
					// Down �� ��ġ�� ^ ���
					x = 51;
					y = 22;
					GotoXY(x, y);
					cout << "^";
				}
				// y ��  15 ���� �Ʒ��� ���� ��쿡�� �Ʒ��� ������ �� �ֽ��ϴ�.
				else if (y < 15)
				{
					// ���� ��ġ �����
					GotoXY(x, y);
					cout << " ";
					// Down �� ��ġ�� ^ ���
					y += 8;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case LEFT:
				// x �� 16 �̻� �� ���� �������� ������ �� �ֽ��ϴ�.
				if (x > 16)
				{
					// ���� ��ġ�� ^ �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� ^�� ǥ�����ݴϴ�.
					x -= 7;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case RIGHT:
				// x �� 79 ���� ���� ��쿡�� ���������� ������ �� �ֽ��ϴ�.
				if (x < 79)
				{
					// ���� ��ġ�� ^ �� ����ϴ�.
					GotoXY(x, y);
					cout << " ";
					// x �� ��ġ�� �����ϰ� �ٽ� ^�� ǥ�����ݴϴ�.
					x += 7;
					GotoXY(x, y);
					cout << "^";
				}
				break;
				// �ൿ�� �մϴ�.
			case SUBMIT:
				// y�� 22�̸� �������� ���ϴ�.
				if (y == 22)
				{

				}
				// ������ ��Ÿ���� �ִٸ� �ִٸ� �ൿ�� �õ��մϴ�.
				else if (player->GetAnimals((y - 7) / 8)->GetFence((x - 16) / 7) != nullptr)
				{
					act = 2;
				}
				else
					act = 1;
				keyout = 1;
				break;
				// �����縦 ����մϴ�.
			case GROW:
				player->AddHour();
				//act = 3;
				keyout = 1;
				break;
			}
		}

		// �ش� ��Ÿ���� ��ȣ�ۿ��� �մϴ�.
		switch (y)
		{
			// ��������
		case 7:
			ContinuePasture(player, player->GetAnimals(0), x, act);
			break;
			// �� ����
		case 15:
			ContinuePasture(player, player->GetAnimals(1), x, act);
			break;
			// ����ȭ��
		case 22:
			MoveHome(player);
			out = 1;
			break;
		}
	}
}

void MovePastrueDraw(Character* player)
{
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  " << endl;
	cout << "#                                                                                               #  " << endl;
	cout << "#           __��������_______________________________________________________________           #  " << endl;
	cout << "#    # # # #  _____                                                                 # # # #     #  " << endl;
	cout << "#   #      #  |   |                                                                 #      #    #  " << endl;
	cout << "#   #      #  |   |                                                                 #      #    #  " << endl;
	cout << "#   #      #__|   |_________________________________________________________________#      #    #  " << endl;
	cout << "#   #           ^                                                                          #    #  " << endl;
	cout << "#   #                                                                                      #    #  " << endl;
	cout << "#   #                                                                                      #    #  " << endl;
	cout << "#   #       __�Ҹ���_________________________________________________________________      #    #  " << endl;
	cout << "#   #      #  _____                                                                 #      #    #  " << endl;
	cout << "#   #      #  |   |                                                                 #      #    #  " << endl;
	cout << "#   #      #  |   |                                                                 #      #    #  " << endl;
	cout << "#   #      #__|   |_________________________________________________________________#      #    #  " << endl;
	cout << "#   #                                                                                      #    #  " << endl;
	cout << "#   #                                                                                      #    #  " << endl;
	cout << "#   #                                                                                      #    #  " << endl;
	cout << "#    # # # # # # # # # # # # # # # # # #                       # # # # # # # # # # # # # # #    #  " << endl;
	cout << "#     @        @       @       @       #                     #     @       @       @       @    #  " << endl;
	cout << "#    @O@      @O@     @O@     @O@      #                     #    @O@     @O@     @O@     @O@   #  " << endl;
	cout << "#     @ /      @ /     @ /     @ /     #           H         #     @ /     @ /     @ /     @ /  #  " << endl;
	cout << "#     |/       |/      |/      |/      #                     #     |/      |/      |/      |/   #  " << endl;
	cout << "# # # # # # # # # # # # # # # # # # # #                       # # # # # # # # # # # # # # # # # #  " << endl;

	int x = 14;
	int y = 3;

	// ���� ������ �ִ� �������带 �׷��ݴϴ�.
	for (int i = 0;i < player->GetAnimals(0)->GethavFence(); i++)
	{
		x = 14 + (i * 7);

		// ��Ÿ���� �׸��ϴ�.
		GotoXY(x, y);
		cout << "_____";
		GotoXY(x, y + 1);
		cout << "|   |";
		GotoXY(x, y + 2);
		cout << "|   |";
		GotoXY(x, y + 3);
		cout << "|   |";

		SetColor(lightred, black);

		// ��Ÿ���� ������ �ִٸ�
		if (player->GetAnimals(0)->GetFence(i) != nullptr)
		{
			GotoXY(x + 2, y + 2);
			// ��Ÿ�� ���� ������ �ܰ踦 ����մϴ�.
			cout << player->GetAnimals(0)->GetfenceLevel(i);
		}
		SetColor(white, black);

	}

	x = 14;
	y = 11;

	// ���� ������ �ִ� �Ҹ��带 �׷��ݴϴ�.
	for (int i = 0;i < player->GetAnimals(1)->GethavFence(); i++)
	{
		x = 14 + (i * 7);

		// ��Ÿ���� �׸��ϴ�.
		GotoXY(x, y);
		cout << "_____";
		GotoXY(x, y + 1);
		cout << "|   |";
		GotoXY(x, y + 2);
		cout << "|   |";
		GotoXY(x, y + 3);
		cout << "|   |";

		SetColor(lightpurple, black);

		// ��Ÿ���� ������ �ִٸ�
		if (player->GetAnimals(1)->GetFence(i) != nullptr)
		{
			GotoXY(x + 2, y + 2);
			// ��Ÿ�� ���� ������ �ܰ踦 ����մϴ�.
			cout << player->GetAnimals(1)->GetfenceLevel(i);
		}
		SetColor(white, black);

	}

	// ���� �κ��丮�� ����մϴ�.
	GotoXY(0, 27);
	cout << "  " << player->GetAnimals(0)->GetName() << " : " << player->GetAnimals(0)->GethavAnimals() << "����   ";
	cout << "  " << player->GetAnimals(1)->GetName() << " : " << player->GetAnimals(1)->GethavAnimals() << "����" << endl;
	cout << "  ���� : " << player->GetFertilizer() << "��";
}

// 4. �������� �̵��� ��� �Լ�
void MoveShop(Character* player)
{
	system("cls");
	Loading("�� �� �� �� . .");
	system("cls");

	int num = 0;

	while (1)
	{
		cout << endl;
		player->PrintTime();
		cout << endl;
		cout << player->GetName() << "��(��) ������ �ִ� �� : " << player->GetMoney() << "��" << endl;
		cout << endl;
		cout << "[ �� �� ]" << endl;
		cout << "1. ����" << endl;
		cout << "2. �Ǹ�" << endl;
		cout << "3. �ڷΰ���" << endl;
		cout << "���� : ";

		num = InputNum(3);
		cout << "------------------------------" << endl << endl;

		switch (num)
		{
		case 1:
			ContinueShopBuy(player);
			break;
		case 2:
			ContinueShopSell(player);
			break;
		default:
			break;
		}

		// 3. �ڷΰ��⸦ �������� ���
		if (num == 3)
		{
			Loading("���θ޴���..");
			break;
		}

		system("cls");
	}
}

// 5. ������ �̵��� ����Լ�
void MoveHouse(Character* player)
{
	int out = 0;

	while (out == 0)
	{
		system("cls");
		SetColor(white, black);
		MoveHouseDraw(player);

		// �÷��̾� ����â �� �κ��丮 ���
		GotoXY(0, 24);
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		player->PrintPlayerInfo();
		player->PrintTime();

		// Ŀ�� ��ǥ ����
		int x = 46;
		int y = 11;

		int keyout = 0;
		int act = 0;

		SetColor(lightgreen, black);
		// ���� Ŀ���� ����մϴ�.
		GotoXY(46, 11);
		cout << "V";

		// Ű �Է��� �޽��ϴ�.
		while (keyout == 0)
		{
			int key = KeyControl();
			switch (key)
			{
			case UP:
				// x �� 46 �϶��� ���� ������ �� �ֽ��ϴ�.
				if (x == 46)
				{
					if (y > 1)
					{
						// ���� ��ġ �����
						GotoXY(x, y);
						cout << " ";
						// UP �� ��ġ�� V ���
						y -= 10;
						GotoXY(x, y);
						cout << "V";
					}
				}
				break;
			case DOWN:
				// x �� 46 �϶��� �Ʒ��� ������ �� �ֽ��ϴ�.
				if (x == 46)
				{
					if (y < 21)
					{
						// ���� ��ġ �����
						GotoXY(x, y);
						cout << " ";
						// Down �� ��ġ�� V ���
						y += 10;
						GotoXY(x, y);
						cout << "V";
					}
				}
				break;
			case LEFT:
				// y �� 11 �϶��� �������� �����ϼ� �ֽ��ϴ�.
				if (y == 11)
				{
					if (x > 19)
					{
						// ���� ��ġ�� V �� ����ϴ�.
						GotoXY(x, y);
						cout << " ";
						// x �� ��ġ�� �����ϰ� �ٽ� V�� ǥ�����ݴϴ�.
						x -= 27;
						GotoXY(x, y);
						cout << "V";
					}
				}
				break;
			case RIGHT:
				// y �� 11 �϶��� ���������� �����ϼ� �ֽ��ϴ�.
				if (y == 11)
				{
					if (x < 73)
					{
						// ���� ��ġ�� V �� ����ϴ�.
						GotoXY(x, y);
						cout << " ";
						// x �� ��ġ�� �����ϰ� �ٽ� V�� ǥ�����ݴϴ�.
						x += 27;
						GotoXY(x, y);
						cout << "V";
					}
				}
				break;
				// �ش� ��ȣ�� �����մϴ�.
			case SUBMIT:
				if (x == 19)
					act = 1;
				else if (x == 46)
				{
					if (y == 1)
						act = 0;
					else if (y == 11)
						act = 3;
					else if (y == 21)
						act = 4;
				}
				else
					act = 2;
				keyout = 1;
				break;
			}
		}
		
		// �ش� ������ ��ȣ�ۿ��� �մϴ�.
		switch (act)
		{
			// tv
		case 0:
			player->TV(player->GetisFurniture(0));
			break;
			// ȭ��
		case 1:
			player->Furnace(player->GetisFurniture(1));
			break;
			// ħ��
		case 2:
			player->Bed(player->GetisFurniture(2));
			break;
			// ��Ź
		case 3:
			player->Table();
			break;
			// ��������
		case 4:
			out = 1;
			break;
		}
	}


}

void MoveHouseDraw(Character* player)
{
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  " << endl;
	cout << "#                                                                                               #  " << endl;
	cout << "#                                            ***********                                        #  " << endl;
	cout << "#                                            *         *                          # # # # # # # #  " << endl;
	cout << "#                                            ***********                          #             #  " << endl;
	cout << "# ######                                          ^                               # # # # # # # #  " << endl;
	cout << "###### #                                                                         #              #  " << endl;
	cout << "#    # #                                                                        #               #  " << endl;
	cout << "#    # #                                                                       #               ##  " << endl;
	cout << "#    # #                                                                      #               # #  " << endl;
	cout << "#    # ## # # # #                                                            #               #  #  " << endl;
	cout << "#    # #      #  #                                                          # # # # # # # # #   #  " << endl;
	cout << "#    # #    #    #                       ####################               #               #   #  " << endl;
	cout << "######    #      #                      #####################               #               #   #  " << endl;
	cout << "# # # # #    #   #                     #################### #                                   #  " << endl;
	cout << "#       #   #  # #                     # #                # #                                   #  " << endl;
	cout << "#       #  # & # #                     # #                # #                                   #  " << endl;
	cout << "#       #  # & #                       #                  #                                     #  " << endl;
	cout << "#       #  # #                                                                                  #  " << endl;
	cout << "#       #  #                                                                                    #  " << endl;
	cout << "# # # # ##                             # # # # # # # # #                                        #  " << endl;
	cout << "#                                    #    # # # # #     #                                       #  " << endl;
	cout << "#                                   #   #     H    #   #                                        #  " << endl;
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  " << endl;

	// tv�� �׸��ϴ�.
	// tv�� �ҿ��ϰ� �ִٸ�
	if (player->GetisFurniture(0))
		SetColor(white, black);
	else
		SetColor(darkgray, black);
	DrawTV();

	// ȭ�θ� �׸��ϴ�.
	// ȭ�θ� �ҿ��ϰ� �ִٸ�
	if (player->GetisFurniture(1))
		SetColor(white, black);
	else
		SetColor(darkgray, black);
	DrawFurnace();

	// ħ�븦 �׸��ϴ�.
	// ħ�븦 �ҿ��ϰ� �ִٸ�
	if (player->GetisFurniture(2))
		SetColor(white, black);
	else
		SetColor(darkgray, black);
	DrawBed();

	GotoXY(2, 2);
	SetColor(yellow, black);
	cout << "������ : " << player->GetMoney() << "��";

	SetColor(white, black);
}

void DrawTV()
{
	// tv �� �׸��ϴ�.
	GotoXY(45, 2);
	cout << "***********";
	GotoXY(45, 3);
	cout << "*         *";
	GotoXY(45, 4);
	cout << "***********";
	GotoXY(45, 5);
	cout << "     ^     ";
}
void DrawFurnace()
{
	// ȭ��
	GotoXY(1, 5);
	cout << " ######          ";
	GotoXY(1, 6);
	cout << "##### #          ";
	GotoXY(1, 7);
	cout << "    # #          ";
	GotoXY(1, 8);
	cout << "    # #          ";
	GotoXY(1, 9);
	cout << "    # #          ";
	GotoXY(1, 10);
	cout << "    # ## # # # # ";
	GotoXY(1, 11);
	cout << "    # #      #  #";
	GotoXY(1, 12);
	cout << "    # #    #    #";
	GotoXY(1, 13);
	cout << "#####    #      #";
	GotoXY(1, 14);
	cout << " # # # #    #   #";
	GotoXY(1, 15);
	cout << "       #   #  # #";
	GotoXY(1, 16);
	cout << "       #  # & # #";
	GotoXY(1, 17);
	cout << "       #  # & #  ";
	GotoXY(1, 18);
	cout << "       #  # #    ";
	GotoXY(1, 19);
	cout << "       #  #      ";
	GotoXY(1, 20);
	cout << " # # # ##        ";
	SetColor(lightred, black);
	GotoXY(13, 16);
	cout << "&";
	GotoXY(13, 17);
	cout << "&";
	SetColor(white, black);
}
void DrawBed()
{
	// ħ��
	GotoXY(76, 3);
	cout << "      # # # # # # # ";
	GotoXY(76, 4);
	cout << "      #             ";
	GotoXY(76, 5);
	cout << "      # # # # # # # ";
	GotoXY(76, 6);
	cout << "     #              ";
	GotoXY(76, 7);
	cout << "    #               ";
	GotoXY(76, 8);
	cout << "   #               #";
	GotoXY(76, 9);
	cout << "  #               # ";
	GotoXY(76, 10);
	cout << " #               #  ";
	GotoXY(76, 11);
	cout << "# # # # # # # # #   ";
	GotoXY(76, 12);
	cout << "#               #   ";
	GotoXY(76, 13);
	cout << "#               #   ";
}

// 6. �ѽð� �ڷ� �����ִ� �Լ� (���� Tip ���� �ֱ�)
void MoveHour(Character* player)
{
	player->AddHour();
	system("cls");

	cout << endl;
	cout << "���� Tip. ���� ���� ���ӿ� ���� ������ ���� �� �ֽ��ϴ�." << endl << endl;

	Loading(". . . . �ð� �������� . . . .");

	system("cls");
}

// 8. ������ ���ư��� �Լ�
void MoveHome(Character* player)
{
}

// �Է��� �����ִ� �Լ� (�߸� �Է����� ��츦 �����ϱ�����) 
int InputNum(int max)
{
	int num;
	while (1)
	{
		cin >> num;
		if (num > 0 && num < max + 1) break;
		else
		{
			cout << endl;
			cout << "�߸� �Է��߽��ϴ�." << endl;
			cout << "�ٽ� �Է����ּ���." << endl;
			cout << endl;
			cout << "�ٽ� �Է� : ";
		}
	}

	return num;
}

// �ε� ��� �Լ�
void Loading(const char* loadingTitle)
{
	system("cls");

	cout << endl;

	// �ε�ȭ�� ����
	for (int i = 0; i < strlen(loadingTitle); i++)
	{
		cout << *(loadingTitle + i);
		_sleep(100);
	}

	system("cls");
}
