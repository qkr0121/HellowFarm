#pragma once
#include "Managers.h"
#include "FuncFarm.h"
#include "Time.h"
#include "Util.h"

// ó�� �ð� �Է� �Լ�
void SetTime(Character* player);

// Ÿ��Ʋ
void TitleDraw();

// ���θ޴�
int MainMenu();

// �����޴�
void InfoMenu();

// �ΰ��� ȭ��
void InGameDraw();

// ���� ȭ�� �Լ�
//void PrintMain(void(*fp)(Character*));
void (*FpPrintMain())(Character*);

// 1�� ���� ���� �Լ�, draw �Լ�
void MoveFarm(Character* player);
void MoveFarmDraw(Character* player);

// 2�� ������ ���� �Լ�
void MoveOrchard(Character* player);
void MoveOrchardDraw(Character* player);

// 3�� ���� ���� �Լ�
void MovePastrue(Character* player);
void MovePastrueDraw(Character* player);

// 4�� ���� ���� �Լ�
void MoveShop(Character* player);

// 5�� �� ���� �Լ�
void MoveHouse(Character* player);
void MoveHouseDraw(Character* player);
void DrawTV();
void DrawFurnace();
void DrawBed();

// 6�� �ѽð� �ڷ� �����ִ� �Լ�
void MoveHour(Character* player);

// 7�� ������ ���ư��� �Լ�
void MoveHome(Character* player);

// �Է��� �����ִ� �Լ� (�߸� �Է����� ��츦 �����ϱ�����) 
int InputNum(int max);

// �ε� ��� �Լ�
void Loading(const char* loadingTitle);