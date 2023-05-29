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

	// 랜덤함수 씨드값 입력
	srand(GetTickCount64());

	// 캐릭터클래스 생성
	Character* player;


	// 이름
	string Name;

	// 함수포인터
	void(*fp)(Character*) = MoveFarm;

	// 선택한 번호 받을 변수
	int num = 0;

	// -------- 게임 시작 -------------

	system("cls");

	cout << endl;
	cout << "TextFarm 에 오신것을 환영합니다!!!" << endl;
	cout << "게임을 시작하기 전에 몇가지 정보를 입력해주세요..." << endl << endl;

	// 이름 입력받기
	cout << "당신의 이름은 무엇인가요?" << endl;
	cout << "이름 : ";
	cin >> Name;
	
	// player 생성
	player = new Character(Name, 100);

	// 게임시작과 시간 세팅하기
	SetTime(player);


	while (1)
	{
		system("cls");
		SetColor(white, black);

		// 인게임 화면 출력
		InGameDraw();

		// 플레이어 정보창 및 인벤토리 출력
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		player->PrintPlayerInfo();
		player->PrintTime();

		// 메인화면 출력 및 선택한 번호 저장
		fp = FpPrintMain();
		
		//printf("%p", fp);

		// 종료 혹은 진행
		if (num == 7) break;
		// 선택한 번호로 (Move)함수 호출
		else fp(player);

		// 서브포인터(Move함수에서 선택한) 함수 호출 혹은 뒤로가기
		//if(num != 7) fpSub[num - 1](player);
		
	}

	system("cls");
	cout << "게임을 종료합니다 . . . ." << endl;
	


	//player->AddPotato();
	//player->PrintName();
	//player->SellPotato();

	// 포인터 해제
	delete player;

	return 0;
}