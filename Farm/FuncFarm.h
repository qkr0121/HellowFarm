#pragma once
#include "Character.h"
#include "Func.h"

// Func.h ���� �̾����� �Լ���

class Character;
class Potato;

// 1 �� MoveFarm ���� �̾����� �Լ�
void ContinueFarm(Character* player, Crops* crops, int x, int act);

// 2�� MoveOrchard ���� �̾����� �Լ�
void ContinueOrchard(Character* player, Fruits* fruits, int x, int act);

// 3�� MovePasture ���� �̾����� �Լ�
void ContinuePasture(Character* player, Animals* animals, int x, int act);

// 4�� MoveShop ���� ���Ÿ� �������� ���
void ContinueShopBuy(Character* player);
// 4�� MoveShop ���� �ǸŸ� �������� ���
void ContinueShopSell(Character* player);

