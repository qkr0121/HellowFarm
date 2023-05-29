#pragma once
#include "Managers.h"
#include "FuncFarm.h"
#include "Time.h"
#include "Util.h"

// 처음 시간 입력 함수
void SetTime(Character* player);

// 타이틀
void TitleDraw();

// 메인메뉴
int MainMenu();

// 정보메뉴
void InfoMenu();

// 인게임 화면
void InGameDraw();

// 메인 화면 함수
//void PrintMain(void(*fp)(Character*));
void (*FpPrintMain())(Character*);

// 1번 목장 선택 함수, draw 함수
void MoveFarm(Character* player);
void MoveFarmDraw(Character* player);

// 2번 과수원 선택 함수
void MoveOrchard(Character* player);
void MoveOrchardDraw(Character* player);

// 3번 목장 선택 함수
void MovePastrue(Character* player);
void MovePastrueDraw(Character* player);

// 4번 상점 선택 함수
void MoveShop(Character* player);

// 5번 집 선택 함수
void MoveHouse(Character* player);
void MoveHouseDraw(Character* player);
void DrawTV();
void DrawFurnace();
void DrawBed();

// 6번 한시간 뒤로 보내주는 함수
void MoveHour(Character* player);

// 7번 집으로 돌아가는 함수
void MoveHome(Character* player);

// 입력을 도와주는 함수 (잘못 입력했을 경우를 방지하기위해) 
int InputNum(int max);

// 로딩 출력 함수
void Loading(const char* loadingTitle);