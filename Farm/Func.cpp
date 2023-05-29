#include "Func.h"

int InputNum(int max);

// 처음 시간 입력 함수
void SetTime(Character* player)
{
	int year;
	int month;
	int day;
	int hour;

	cout << "현재 날짜를 입력해주세요." << endl;

	cout << "년 : ";
	cin >> year;

	cout << "월 : ";
	month = InputNum(12);
	
	cout << "일 : ";
	day = InputNum(31);
	
	cout << "시간(오후 1시는 13로) : ";
	hour = InputNum(24);
	

	player->SetTime(year, month, day, hour);

	system("cls");
}

// 타이틀
void TitleDraw()
{
	// 타이틀
	cout << "                                                                                                " << endl;
	cout << "          ##  ##    ######    ##        ##                                                      " << endl;
	cout << "         ##  ##    ##        ##        ##                     #####    ##     ####    ###   ##  " << endl;
	cout << "         ######    ######    ##        ##                     ##      ## #    ##  #   ## # # #  " << endl;
	cout << "          ######    ######    ##        ##                    ####   ## # #   ####    ## # # #  " << endl;
	cout << "          ##  ##    ##        ######    ######  ##  # # #     ##    ##     #  ##  #   ##  #  #  " << endl;
	cout << "         ##  ##    ######    ######    ######   ##   # #      ##    ##     #  ##   #  ##     #  " << endl;
	cout << "                                                                                                " << endl;



}

// 메인메뉴
int MainMenu()
{
	int x = 45;
	int y = 11;
	GotoXY(x-2, y);
	cout << "> 게 임 시 작";
	GotoXY(x, y+2);
	cout << "게 임 정 보";
	GotoXY(x+3, y+4);
	cout << "종 료";

	while (1)
	{
		int key = KeyControl();
		switch (key)
		{
		case UP:
			if (y > 11)
			{
				// 원래 위치 지우고
				GotoXY(x - 2, y);
				cout << " ";
				// UP 한 위치에 > 출력
				GotoXY(x - 2, y - 2);
				y -= 2;
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 15)
			{
				// 원래 위치 지우고
				GotoXY(x - 2, y);
				cout << " ";
				// DOWN 한 위치에 > 출력
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
	cout << "설명 메뉴" << endl;
	cout << "뒤로 가려면 아무 키나 입력 하시오 ...";
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

// 메인화면 출력 및 선택 함수
void (*FpPrintMain())(Character*)
{
	SetColor(white, black);

	// 커서 위치
	int x = 3;
	int y = 11;

	// 선택지 설명
	GotoXY(0, 28);
	cout << "  1.농장   2.과수원   3.목장   4.상점   5.집";

	SetColor(lightgreen, black);

	GotoXY(x, y);
	cout << "V";

	
	int out = 0;
	// 키 입력을 받습니다.
	while (out == 0)
	{
		int key = KeyControl();
		switch (key)
		{
		case UP:
			// x 가 49 일때만 위로 움직일 수 있습니다.
			if (x == 49)
			{
				if (y > 1)
				{
					// 원래 위치 지우고
					GotoXY(x, y);
					cout << " ";
					// UP 한 위치에 V 출력
					y -= 10;
					GotoXY(x, y);
					cout << "V";
				}
			}
			break;
		case DOWN:
			// x 가 49 일때만 아래로 움직일 수 있습니다.
			if (x == 49)
			{
				if (y < 21)
				{
					// 원래 위치 지우고
					GotoXY(x, y);
					cout << " ";
					// Down 한 위치에 V 출력
					y += 10;
					GotoXY(x, y);
					cout << "V";
				}
			}
			break;
		case LEFT:
			// y 가 11 일때만 왼쪽으로 움직일수 있습니다.
			if (y == 11)
			{
				if (x > 3)
				{
					// 원래 위치의 V 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 V를 표시해줍니다.
					x -= 46;
					GotoXY(x, y);
					cout << "V";
				}
			}
			break;
		case RIGHT:
			// y 가 11 일때만 오른쪽으로 움직일수 있습니다.
			if (y == 11)
			{
				if (x < 95)
				{
					// 원래 위치의 V 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 V를 표시해줍니다.
					x += 46;
					GotoXY(x, y);
					cout << "V";
				}
			}
			break;
		// 해당 번호를 선택합니다.
		case SUBMIT:
			out = 1;
			break;
		}
	}

	int num = 0;

	//cout << "6. 시간보내기 ( 1시간 )" << endl << endl;
	//cout << "7. 종료" << endl << endl;

	// 함수 포인터 설정
	switch (x+y)
	{
	// 1번 선택
	case 14:
		return MoveFarm;
		break;
	// 2번 선택
	case 106:
		return MoveOrchard;
		break;
	// 3번 선택
	case 50:
		return MovePastrue;
		break;
	// 4번 선택
	case 70:
		return MoveShop;
		break;
	// 5번 선택
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

// 1. 농장으로 이동 및 출력 함수, 드로우 함수
void MoveFarm(Character* player)
{
	system("cls");
	int out = 0;

	while (out == 0)
	{
		SetColor(white, black);

		MoveFarmDraw(player);

		// 플레이어 정보창 및 인벤토리 출력
		GotoXY(0, 24);
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		player->PrintPlayerInfo();
		player->PrintTime();

		// 커서 좌표 변수
		int x = 7;
		int y = 6;

		int keyout = 0;
		int act = 0;

		// 현재 커서위치를 표시해 줍니다.
		SetColor(green, black);
		GotoXY(x, y);
		cout << "^";

		// 키 입력을 받습니다.
		while (keyout == 0)
		{
			int key = KeyControl();
			switch (key)
			{
			case UP:
				// y 가 6보다 클때만 위로 움직일 수 있습니다.
				if (y > 6)
				{
					// 원래 위치 지우고
					GotoXY(x, y);
					cout << " ";
					// UP 한 위치에 ^ 출력
					y -= 8;
					GotoXY(x, y);
					cout << "^";
				}

				break;
			case DOWN:
				// y 가  22 보다 아래에 있을 경우에만 아래로 움직일 수 있습니다.
				if (y < 22)
				{
					// 원래 위치 지우고
					GotoXY(x, y);
					cout << " ";
					// Down 한 위치에 ^ 출력
					y += 8;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case LEFT:
				// x 가 94 이면 70으로 이동합니다.
				if (x == 94)
				{
					// 원래 위치의 ^ 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 ^를 표시해줍니다.
					x = 70;
					GotoXY(x, y);
					cout << "^";
				}
				// x 가 7 이상 일 때만 왼쪽으로 움직을 수 있습니다.
				else if (x > 7)
				{
					// 원래 위치의 ^ 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 ^를 표시해줍니다.
					x -= 7;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case RIGHT:
				// x 가 70 보다 작을 경우에만 오른쪽으로 움직일 수 있습니다.
				if (x < 70)
				{
					// 원래 위치의 ^ 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 ^를 표시해줍니다.
					x += 7;
					GotoXY(x, y);
					cout << "^";
				}
				// x 가 70 일 경우에는 94로 이동합니다.
				else if (x == 70)
				{
					// y 가 14 일 경우에는 94까지 움직일 수 있습니다.
					if (y == 14)
					{
						// 원래 위치의 ^ 를 지웁니다.
						GotoXY(x, y);
						cout << " ";
						// x 의 위치를 조정하고 다시 ^를 표시해줍니다.
						x = 94;
						GotoXY(x, y);
						cout << "^";
					}
				}
				break;
				// 심기 혹은 수확하는 행동을 합니다.
			case SUBMIT:
				// x 가 94 이면 메인으로 갑니다.
				if (x == 94)
				{

				}
				// 심어져 있다면 행동을 시도합니다.
				else if (player->GetCrops((y - 6) / 8)->GetField((x - 5) / 7) != nullptr)
				{
					act = 2;
				}
				else
					act = 1;
				keyout = 1;
				break;
				// 성장재를 사용합니다.
			case GROW:
				//player->AddHour();
				act = 3;
				keyout = 1;
				break;
			}
		}


		// 해당 밭과 상호작용을 합니다.
		switch (y)
		{
			// 감자 밭
		case 6:
			ContinueFarm(player, player->GetCrops(0), x, act);
			break;
			// 고구마 밭 과 메인
		case 14:
			// x 가 94 면 메인으로 갑니다.
			if(x != 94)
				ContinueFarm(player, player->GetCrops(1), x, act);
			else
			{
				MoveHome(player);
				out = 1;
			}
			break;
			// 당근 밭
		case 22:
			ContinueFarm(player, player->GetCrops(2), x, act);
			break;
		}
	}
}

void MoveFarmDraw(Character* player)
{
	cout << "   __감자밭__________________________________________________________________                      " << endl;
	cout << "  #  *****                                                                  #     @                " << endl;
	cout << "  #  *   *                                                                  #    @O@               " << endl;
	cout << "  #  *   *                                                                  #     @ /              " << endl;
	cout << "  #  *   *                                                                  #     |/               " << endl;
	cout << "  #__*****__________________________________________________________________# # # # #      @       " << endl;
	cout << "  #                                                                                   #   @O@      " << endl;
	cout << "  #                                                                                   #    @ /     " << endl;
	cout << "  #__고구마밭________________________________________________________________          #    |/     " << endl;
	cout << "  #  *****                                                                  #           # # # # # #" << endl;
	cout << "  #  *   *                                                                  #                      " << endl;
	cout << "  #  *   *                                                                  #                      " << endl;
	cout << "  #  *   *                                                                  #                      " << endl;
	cout << "  #__*****__________________________________________________________________#                 H    " << endl;
	cout << "  #                                                                                                " << endl;
	cout << "  #                                                                                                " << endl;
	cout << "  #__당근밭__________________________________________________________________           # # # # # #" << endl;
	cout << "  #  *****                                                                  #          #    @@     " << endl;
	cout << "  #  *   *                                                                  #          #   @##@    " << endl;
	cout << "  #  *   *                                                                  #          #    @@     " << endl;
	cout << "  #  *   *                                                                  #          #    || /   " << endl;
	cout << "  #  *****__________________________________________________________________#          #    ||/    " << endl;
	cout << "  #                                                                                    #           " << endl;
	cout << "  #_________________________________________________________________________# # # # # #            " << endl;

	int x = 5;
	int y = 1;

	// 현재 가지고 있는 감자 밭을 그려줍니다.
	for (int i = 0;i < player->GetCrops(0)->GethavField();i++)
	{
		x = 5 + (i * 7);

		// 밭을 그립니다.
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
		// 심어져 있다면
		if (player->GetCrops(0)->GetField(i) != nullptr)
		{
			GotoXY(x + 2, y + 2);
			// 농작물의 단계를 출력합니다.
			cout << player->GetCrops(0)->GetfieldLevel(i);
		}
		SetColor(white, black);

	}

	x = 5;
	y = 9;
	// 현재 가지고 있는 고구마 밭을 그려줍니다.
	for (int i = 0;i < player->GetCrops(1)->GethavField();i++)
	{
		x = 5 + (i * 7);

		// 밭을 그립니다.
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
		// 심어져 있는 농작물의 단계를 표시합니다.
		if (player->GetCrops(1)->GetField(i) != nullptr)
		{
			GotoXY(x + 2, y + 2);
			// 농작물의 단계를 출력합니다.
			cout << player->GetCrops(1)->GetfieldLevel(i);
		}
		SetColor(white, black);

	}

	x = 5;
	y = 17;
	// 현재 가지고 있는 당근 밭을 그려줍니다.
	for (int i = 0;i < player->GetCrops(2)->GethavField();i++)
	{
		x = 5 + (i * 7);

		// 밭을 그립니다.
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

		// 심어져 있는 농작물의 단계를 표시합니다.
		if (player->GetCrops(2)->GetField(i) != nullptr)
		{
			GotoXY(x + 2, y + 2);
			// 농작물의 단계를 출력합니다.
			cout << player->GetCrops(2)->GetfieldLevel(i);
		}
		SetColor(white, black);

	}

	// 농작물 인벤토리를 출력합니다.
	GotoXY(0, 27);
	cout << "  " << player->GetCrops(0)->GetName() << " : " << player->GetCrops(0)->GethavCrops() << "개   ";
	cout << "  " << player->GetCrops(1)->GetName() << " : " << player->GetCrops(1)->GethavCrops() << "개" << endl;
	cout << "  " << player->GetCrops(2)->GetName() << " : " << player->GetCrops(2)->GethavCrops() << "개   ";
	cout << "  물 : " << player->GetWater() << "개";
}

// 2. 과수원으로 이동과 출력 함수
void MoveOrchard(Character* player)
{
	system("cls");
	int out = 0;

	while (out == 0)
	{
		SetColor(white, black);

		MoveOrchardDraw(player);

		// 플레이어 정보창 및 인벤토리 출력

		GotoXY(0, 24);
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		player->PrintPlayerInfo();
		player->PrintTime();

		// 커서 좌표 변수
		int x = 28;
		int y = 8;

		int keyout = 0;
		int act = 0;
		SetColor(green, black);

		// 키 입력을 받습니다.
		while (keyout == 0)
		{
			int key = KeyControl();
			switch (key)
			{
			case UP:
				// y 가 8보다 클때만 위로 움직일 수 있습니다.
				if (y > 8)
				{
					// 원래 위치 지우고
					GotoXY(x, y);
					cout << " ";
					// UP 한 위치에 ^ 출력
					y -= 11;
					GotoXY(x, y);
					cout << "^";
				}

				break;
			case DOWN:
				// y 가  19 보다 아래에 있을 경우에만 아래로 움직일 수 있습니다.
				if (y < 19)
				{
					// 원래 위치 지우고
					GotoXY(x, y);
					cout << " ";
					// Down 한 위치에 ^ 출력
					y += 11;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case LEFT:
				// x 가 28 이면 6으로 y는 15 로 이동합니다.
				if (x == 28)
				{
					// 원래 위치의 ^ 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 ^를 표시해줍니다.
					x = 6;
					y = 15;
					GotoXY(x, y);
					cout << "^";
				}
				// x 가 28 이상 일 때만 왼쪽으로 움직을 수 있습니다.
				else if (x > 28)
				{
					// 원래 위치의 ^ 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 ^를 표시해줍니다.
					x -= 7;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case RIGHT:
				// x 가 6 일 경우에는 28로 y 는 8 로 이동합니다.
				if (x == 6)
				{
					// 원래 위치의 ^ 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 ^를 표시해줍니다.
					x = 28;
					y = 8;
					GotoXY(x, y);
					cout << "^";	
				}
				// x 가 91 보다 작을 경우에만 오른쪽으로 움직일 수 있습니다.
				else if (x < 91)
				{
					// 원래 위치의 ^ 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 ^를 표시해줍니다.
					x += 7;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			// 행동을 합니다.
			case SUBMIT:
				// x가 6이면 메인으로 갑니다.
				if (x == 6)
				{

				}
				// 수확을 시도합니다.
				else if (player->GetFruits((y-8)/11)->GetTree((x-28)/7) != nullptr)
				{
					act = 2;
				}
				keyout = 1;
				break;
			// 성장재를 사용합니다.
			case GROW:
				player->AddHour();
				//act = 3;
				keyout = 1;
				break;
			}
		}

		// 해당 나무와 상호작용을 합니다.
		switch (y)
		{
			// 사과나무
		case 8:
			ContinueOrchard(player, player->GetFruits(0), x, act);
			break;
			// 메인화면
		case 15:
			MoveHome(player);
			out = 1;
			break;
			// 오렌지 나무
		case 19:
			ContinueOrchard(player, player->GetFruits(1), x, act);
			break;
		}
	}
}

void MoveOrchardDraw(Character* player)
{
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  " << endl;
	cout << "                        __사과나무______________________________________________________________#  " << endl;
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
	cout << "                        __오렌지나무____________________________________________________________#  " << endl;
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

	// 현재 가지고 있는 사과나무를 그려줍니다.
	for (int i = 0;i < player->GetFruits(0)->GethavTree(); i++)
	{
		x = 26 + (i * 7);

		// 나무를 그립니다.
		GotoXY(x, y);
		cout << " @@@ ";
		GotoXY(x, y + 1);
		cout << "@@@@@";
		GotoXY(x, y + 2);
		cout << "  |  ";
		GotoXY(x, y + 3);
		cout << "__|__";

		SetColor(lightred, black);

		// 심어져 있다면
		if (player->GetFruits(0)->GetTree(i) != nullptr)
		{
			GotoXY(x + 2, y - 1);
			// 과일의 단계를 출력합니다.
			cout << player->GetFruits(0)->GettreeLevel(i);
		}
		SetColor(white, black);

	}

	x = 26;
	y = 15;
	// 현재 가지고 있는 오렌지나무를 그려줍니다.
	for (int i = 0;i < player->GetFruits(1)->GethavTree();i++)
	{
		x = 26 + (i * 7);

		// 나무를 그립니다.
		GotoXY(x, y);
		cout << " @@@ ";
		GotoXY(x, y + 1);
		cout << "@@@@@";
		GotoXY(x, y + 2);
		cout << "  |  ";
		GotoXY(x, y + 3);
		cout << "__|__";

		SetColor(yellow, black);

		// 심어져 있다면
		if (player->GetFruits(1)->GetTree(i) != nullptr)
		{
			GotoXY(x + 2, y - 1);
			// 과일의 단계를 출력합니다.
			cout << player->GetFruits(1)->GettreeLevel(i);
		}
		SetColor(white, black);

	}

	// 열매 인벤토리를 출력합니다.
	GotoXY(0, 27);
	cout << "  " << player->GetFruits(0)->GetName() << " : " << player->GetFruits(0)->GethavFruits() << "개   ";
	cout << "  " << player->GetFruits(1)->GetName() << " : " << player->GetFruits(1)->GethavFruits() << "개" << endl;
	cout << "  비료 : " << player->GetFertilizer() << "개";
}

// 3. 목장으로 이동과 출력 함수
void MovePastrue(Character* player)
{
	int num = 0;

	// 목장 선택
	system("cls");
	int out = 0;

	while (out == 0)
	{
		SetColor(white, black);

		MovePastrueDraw(player);

		// 플레이어 정보창 및 인벤토리 출력
		GotoXY(0, 24);
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		player->PrintPlayerInfo();
		player->PrintTime();

		// 커서 좌표 변수
		int x = 16;
		int y = 7;

		int keyout = 0;
		int act = 0;
		SetColor(green, black);

		// 키 입력을 받습니다.
		while (keyout == 0)
		{
			int key = KeyControl();
			switch (key)
			{
			case UP:
				// y 가 22일 경우 15 로 이동합니다.
				if (y == 22)
				{
					// 원래 위치 지우고
					GotoXY(x, y);
					cout << " ";
					// UP 한 위치에 ^ 출력
					y = 15;
					GotoXY(x, y);
					cout << "^";
				}
				// y 가 7보다 클때만 위로 움직일 수 있습니다.
				else if (y > 7)
				{
					// 원래 위치 지우고
					GotoXY(x, y);
					cout << " ";
					// UP 한 위치에 ^ 출력
					y -= 8;
					GotoXY(x, y);
					cout << "^";
				}

				break;
			case DOWN:
				// y 가 15 일 경우 x=51 y=22 로 이동합니다.
				if (y == 15)
				{
					// 원래 위치 지우고
					GotoXY(x, y);
					cout << " ";
					// Down 한 위치에 ^ 출력
					x = 51;
					y = 22;
					GotoXY(x, y);
					cout << "^";
				}
				// y 가  15 보다 아래에 있을 경우에만 아래로 움직일 수 있습니다.
				else if (y < 15)
				{
					// 원래 위치 지우고
					GotoXY(x, y);
					cout << " ";
					// Down 한 위치에 ^ 출력
					y += 8;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case LEFT:
				// x 가 16 이상 일 때만 왼쪽으로 움직을 수 있습니다.
				if (x > 16)
				{
					// 원래 위치의 ^ 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 ^를 표시해줍니다.
					x -= 7;
					GotoXY(x, y);
					cout << "^";
				}
				break;
			case RIGHT:
				// x 가 79 보다 작을 경우에만 오른쪽으로 움직일 수 있습니다.
				if (x < 79)
				{
					// 원래 위치의 ^ 를 지웁니다.
					GotoXY(x, y);
					cout << " ";
					// x 의 위치를 조정하고 다시 ^를 표시해줍니다.
					x += 7;
					GotoXY(x, y);
					cout << "^";
				}
				break;
				// 행동을 합니다.
			case SUBMIT:
				// y가 22이면 메인으로 갑니다.
				if (y == 22)
				{

				}
				// 돼지가 울타리에 있다면 있다면 행동을 시도합니다.
				else if (player->GetAnimals((y - 7) / 8)->GetFence((x - 16) / 7) != nullptr)
				{
					act = 2;
				}
				else
					act = 1;
				keyout = 1;
				break;
				// 성장재를 사용합니다.
			case GROW:
				player->AddHour();
				//act = 3;
				keyout = 1;
				break;
			}
		}

		// 해당 울타리와 상호작용을 합니다.
		switch (y)
		{
			// 돼지목장
		case 7:
			ContinuePasture(player, player->GetAnimals(0), x, act);
			break;
			// 소 목장
		case 15:
			ContinuePasture(player, player->GetAnimals(1), x, act);
			break;
			// 메인화면
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
	cout << "#           __돼지목장_______________________________________________________________           #  " << endl;
	cout << "#    # # # #  _____                                                                 # # # #     #  " << endl;
	cout << "#   #      #  |   |                                                                 #      #    #  " << endl;
	cout << "#   #      #  |   |                                                                 #      #    #  " << endl;
	cout << "#   #      #__|   |_________________________________________________________________#      #    #  " << endl;
	cout << "#   #           ^                                                                          #    #  " << endl;
	cout << "#   #                                                                                      #    #  " << endl;
	cout << "#   #                                                                                      #    #  " << endl;
	cout << "#   #       __소목장_________________________________________________________________      #    #  " << endl;
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

	// 현재 가지고 있는 돼지목장를 그려줍니다.
	for (int i = 0;i < player->GetAnimals(0)->GethavFence(); i++)
	{
		x = 14 + (i * 7);

		// 울타리를 그립니다.
		GotoXY(x, y);
		cout << "_____";
		GotoXY(x, y + 1);
		cout << "|   |";
		GotoXY(x, y + 2);
		cout << "|   |";
		GotoXY(x, y + 3);
		cout << "|   |";

		SetColor(lightred, black);

		// 울타리에 동물이 있다면
		if (player->GetAnimals(0)->GetFence(i) != nullptr)
		{
			GotoXY(x + 2, y + 2);
			// 울타리 안의 동물의 단계를 출력합니다.
			cout << player->GetAnimals(0)->GetfenceLevel(i);
		}
		SetColor(white, black);

	}

	x = 14;
	y = 11;

	// 현재 가지고 있는 소목장를 그려줍니다.
	for (int i = 0;i < player->GetAnimals(1)->GethavFence(); i++)
	{
		x = 14 + (i * 7);

		// 울타리를 그립니다.
		GotoXY(x, y);
		cout << "_____";
		GotoXY(x, y + 1);
		cout << "|   |";
		GotoXY(x, y + 2);
		cout << "|   |";
		GotoXY(x, y + 3);
		cout << "|   |";

		SetColor(lightpurple, black);

		// 울타리에 동물이 있다면
		if (player->GetAnimals(1)->GetFence(i) != nullptr)
		{
			GotoXY(x + 2, y + 2);
			// 울타리 안의 동물의 단계를 출력합니다.
			cout << player->GetAnimals(1)->GetfenceLevel(i);
		}
		SetColor(white, black);

	}

	// 동물 인벤토리를 출력합니다.
	GotoXY(0, 27);
	cout << "  " << player->GetAnimals(0)->GetName() << " : " << player->GetAnimals(0)->GethavAnimals() << "마리   ";
	cout << "  " << player->GetAnimals(1)->GetName() << " : " << player->GetAnimals(1)->GethavAnimals() << "마리" << endl;
	cout << "  먹이 : " << player->GetFertilizer() << "개";
}

// 4. 상점으로 이동과 출력 함수
void MoveShop(Character* player)
{
	system("cls");
	Loading("상 점 으 로 . .");
	system("cls");

	int num = 0;

	while (1)
	{
		cout << endl;
		player->PrintTime();
		cout << endl;
		cout << player->GetName() << "이(가) 가지고 있는 돈 : " << player->GetMoney() << "원" << endl;
		cout << endl;
		cout << "[ 상 점 ]" << endl;
		cout << "1. 구매" << endl;
		cout << "2. 판매" << endl;
		cout << "3. 뒤로가기" << endl;
		cout << "선택 : ";

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

		// 3. 뒤로가기를 선택했을 경우
		if (num == 3)
		{
			Loading("메인메뉴로..");
			break;
		}

		system("cls");
	}
}

// 5. 집으로 이동과 출력함수
void MoveHouse(Character* player)
{
	int out = 0;

	while (out == 0)
	{
		system("cls");
		SetColor(white, black);
		MoveHouseDraw(player);

		// 플레이어 정보창 및 인벤토리 출력
		GotoXY(0, 24);
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		player->PrintPlayerInfo();
		player->PrintTime();

		// 커서 좌표 변수
		int x = 46;
		int y = 11;

		int keyout = 0;
		int act = 0;

		SetColor(lightgreen, black);
		// 현재 커서를 출력합니다.
		GotoXY(46, 11);
		cout << "V";

		// 키 입력을 받습니다.
		while (keyout == 0)
		{
			int key = KeyControl();
			switch (key)
			{
			case UP:
				// x 가 46 일때만 위로 움직일 수 있습니다.
				if (x == 46)
				{
					if (y > 1)
					{
						// 원래 위치 지우고
						GotoXY(x, y);
						cout << " ";
						// UP 한 위치에 V 출력
						y -= 10;
						GotoXY(x, y);
						cout << "V";
					}
				}
				break;
			case DOWN:
				// x 가 46 일때만 아래로 움직일 수 있습니다.
				if (x == 46)
				{
					if (y < 21)
					{
						// 원래 위치 지우고
						GotoXY(x, y);
						cout << " ";
						// Down 한 위치에 V 출력
						y += 10;
						GotoXY(x, y);
						cout << "V";
					}
				}
				break;
			case LEFT:
				// y 가 11 일때만 왼쪽으로 움직일수 있습니다.
				if (y == 11)
				{
					if (x > 19)
					{
						// 원래 위치의 V 를 지웁니다.
						GotoXY(x, y);
						cout << " ";
						// x 의 위치를 조정하고 다시 V를 표시해줍니다.
						x -= 27;
						GotoXY(x, y);
						cout << "V";
					}
				}
				break;
			case RIGHT:
				// y 가 11 일때만 오른쪽으로 움직일수 있습니다.
				if (y == 11)
				{
					if (x < 73)
					{
						// 원래 위치의 V 를 지웁니다.
						GotoXY(x, y);
						cout << " ";
						// x 의 위치를 조정하고 다시 V를 표시해줍니다.
						x += 27;
						GotoXY(x, y);
						cout << "V";
					}
				}
				break;
				// 해당 번호를 선택합니다.
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
		
		// 해당 가구와 상호작용을 합니다.
		switch (act)
		{
			// tv
		case 0:
			player->TV(player->GetisFurniture(0));
			break;
			// 화로
		case 1:
			player->Furnace(player->GetisFurniture(1));
			break;
			// 침대
		case 2:
			player->Bed(player->GetisFurniture(2));
			break;
			// 식탁
		case 3:
			player->Table();
			break;
			// 메인으로
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

	// tv를 그립니다.
	// tv를 소요하고 있다면
	if (player->GetisFurniture(0))
		SetColor(white, black);
	else
		SetColor(darkgray, black);
	DrawTV();

	// 화로를 그립니다.
	// 화로를 소요하고 있다면
	if (player->GetisFurniture(1))
		SetColor(white, black);
	else
		SetColor(darkgray, black);
	DrawFurnace();

	// 침대를 그립니다.
	// 침대를 소요하고 있다면
	if (player->GetisFurniture(2))
		SetColor(white, black);
	else
		SetColor(darkgray, black);
	DrawBed();

	GotoXY(2, 2);
	SetColor(yellow, black);
	cout << "소지금 : " << player->GetMoney() << "원";

	SetColor(white, black);
}

void DrawTV()
{
	// tv 를 그립니다.
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
	// 화로
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
	// 침대
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

// 6. 한시간 뒤로 보내주는 함수 (게임 Tip 많이 넣기)
void MoveHour(Character* player)
{
	player->AddHour();
	system("cls");

	cout << endl;
	cout << "게임 Tip. 집에 가면 게임에 대한 설명서를 읽을 수 있습니다." << endl << endl;

	Loading(". . . . 시간 보내는중 . . . .");

	system("cls");
}

// 8. 집으로 돌아가는 함수
void MoveHome(Character* player)
{
}

// 입력을 도와주는 함수 (잘못 입력했을 경우를 방지하기위해) 
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
			cout << "잘못 입력했습니다." << endl;
			cout << "다시 입력해주세요." << endl;
			cout << endl;
			cout << "다시 입력 : ";
		}
	}

	return num;
}

// 로딩 출력 함수
void Loading(const char* loadingTitle)
{
	system("cls");

	cout << endl;

	// 로딩화면 띄우기
	for (int i = 0; i < strlen(loadingTitle); i++)
	{
		cout << *(loadingTitle + i);
		_sleep(100);
	}

	system("cls");
}
