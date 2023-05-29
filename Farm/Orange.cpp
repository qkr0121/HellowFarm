#include "Orange.h"

Orange::Orange()
{
    Name = "오렌지";
    price = 50;

    maxLevel = 3;
    maxSize = 300;
    havFruits = 0;
    maxTree = 10;
    havTree = 0;
    maxNum = 4;
    maxgrowTime = 15;

    for (int i = 0;i < maxTree;i++)
    {
        tree[i] = nullptr;
    }
}

Orange::~Orange()
{
    for (int i = 0; i < maxTree; i++)
    {
        delete tree[i];
    }
}

// 랜덤으로 오렌지를 얻습니다.
void Orange::PickFruits(Fruits* fruits, int num)
{
    // 0 ~ 99 사이의 랜덤한 수를 저장
    int per = rand() % 100;
    // 수확한 열매 개수
    int count = 0;

    // 40퍼 의 확률로
    if (per < 40)
    {
        // 사과를 maxNum-2개 추가 합니다.
        fruits->SethavFruits(maxNum - 2);
        count = maxNum - 2;
    }
    // 40 퍼의 확률로
    else if (per < 80)
    {
        // 사과를 maxNum-1개 추가 합니다.
        fruits->SethavFruits(maxNum - 1);
        count = maxNum - 1;
    }
    // 나머지 20 퍼의 확률로
    else
    {
        // 사과를 maxNum개 추가 합니다.
        fruits->SethavFruits(maxNum);
        count = maxNum;
    }

    cout << "오렌지 " << count << "개를 획득하였습니다." << endl;
    _sleep(1000);
}

//초기화
void Orange::InitializeTree(int num, int y, int m, int d, int h)
{
    tree[num]->year = y;
    tree[num]->month = m;
    tree[num]->day = d;
    tree[num]->hour = h;
    tree[num]->level = 0;
}

// Set
void Orange::SethavFruits(int i)
{
    havFruits = havFruits + i;
}

void Orange::SetTree(int i, int y, int m, int d, int h)
{
    tree[i - 1] = new Tree(y, m, d, h);
}

void Orange::SethavTree(bool tf)
{
    if (tf) havTree++;
    else havTree--;

    if (havTree > 10) havTree = 10;
    if (havTree < 0) havTree = 0;
}

void Orange::SetTreeLevel(int y, int m, int d, int h)
{
    for (int i = 0;i < havTree;i++)
    {
        if (tree[i] != nullptr)
        {
            // 심어진 과일의 성장 시간을 1 올려줍니다.
            tree[i]->growTime++;

            // 성장 시간에 따라 성장레벨을 조정합니다.
            /// 성장시간이 최대성장시간 이상이면 레벨을 3으로 조정해줍니다.
            if (tree[i]->growTime >= maxgrowTime) tree[i]->level = 3;
            /// 성장시간이 최대성장시간 2/3 이상이면 레벨을 2로 조정해줍니다.
            else if (tree[i]->growTime >= (maxgrowTime / 3) * 2) tree[i]->level = 2;
            /// 성장시간이 최대성장시간 1/3 이상이면 레벨을 1로 조정해줍니다.
            else if (tree[i]->growTime >= (maxgrowTime / 3)) tree[i]->level = 1;
        }
    }
}

// Get
string Orange::GetName()
{
    return Name;
}

int Orange::GethavTree()
{
    return havTree;
}

Tree* Orange::GetTree(int i)
{
    return tree[i];
}

int Orange::GettreeLevel(int i)
{
    return tree[i]->level;
}

void Orange::GetInitializeTime(int i)
{
    cout << "(" << tree[i]->year << "년 "
        << tree[i]->month << "월 "
        << tree[i]->day << "일 "
        << tree[i]->hour << "시)";
}

int Orange::GethavFruits()
{
    return havFruits;
}

int Orange::GetmaxLevel()
{
    return maxLevel;
}

int Orange::GetmaxTree()
{
    return maxTree;
}

int Orange::GetPrice()
{
    return price;
}
