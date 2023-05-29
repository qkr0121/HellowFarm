#pragma once
#include "Character.h"
#include "Func.h"

// Func.h 에서 이어지는 함수들

class Character;
class Potato;

// 1 번 MoveFarm 에서 이어지는 함수
void ContinueFarm(Character* player, Crops* crops, int x, int act);

// 2번 MoveOrchard 에서 이어지는 함수
void ContinueOrchard(Character* player, Fruits* fruits, int x, int act);

// 3번 MovePasture 에서 이어지는 함수
void ContinuePasture(Character* player, Animals* animals, int x, int act);

// 4번 MoveShop 에서 구매를 선택했을 경우
void ContinueShopBuy(Character* player);
// 4번 MoveShop 에서 판매를 선택했을 경우
void ContinueShopSell(Character* player);

