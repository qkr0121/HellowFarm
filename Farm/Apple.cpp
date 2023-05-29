#include "Apple.h"

Apple::Apple()
{
    Name = "���";
    price = 50;

    maxLevel = 3;
    maxSize = 300;
    havFruits = 3;
    maxTree = 10;
    havTree = 0;
    maxNum = 5;
    maxgrowTime = 15;

    for (int i = 0;i < maxTree;i++)
    {
        tree[i] = nullptr;
    }
}

Apple::~Apple()
{
    for (int i = 0; i < maxTree; i++)
    {
        delete tree[i];
    }
}

// �������� ����� ����ϴ�.
void Apple::PickFruits(Fruits* fruits, int num)
{
    // 0 ~ 99 ������ ������ ���� ����
    int per = rand() % 100;
    // ��Ȯ�� ���� ����
    int count = 0;

    // 40�� �� Ȯ����
    if (per < 40)
    {
        // ����� maxNum-2�� �߰� �մϴ�.
        fruits->SethavFruits(maxNum - 2);
        count = maxNum - 2;
    }
    // 40 ���� Ȯ����
    else if (per < 80)
    {
        // ����� maxNum-1�� �߰� �մϴ�.
        fruits->SethavFruits(maxNum - 1);
        count = maxNum - 1;
    }
    // ������ 20 ���� Ȯ����
    else
    {
        // ����� maxNum�� �߰� �մϴ�.
        fruits->SethavFruits(maxNum);
        count = maxNum;
    }

    cout << "��� " << count << "���� ȹ���Ͽ����ϴ�." << endl;
    _sleep(1000);
}

// �ʱ�ȭ
void Apple::InitializeTree(int num, int y, int m, int d, int h)
{
    tree[num]->year = y;
    tree[num]->month = m;
    tree[num]->day = d;
    tree[num]->hour = h;
    tree[num]->level = 0;
}

// Set
void Apple::SethavFruits(int i)
{
    havFruits = havFruits + i;
}

void Apple::SetTree(int i, int y, int m, int d, int h)
{
    tree[i - 1] = new Tree(y, m, d, h);
}

void Apple::SethavTree(bool tf)
{
    if (tf) havTree++;
    else havTree--;

    if (havTree> 10) havTree = 10;
    if (havTree< 0) havTree = 0;
}

void Apple::SetTreeLevel(int y, int m, int d, int h)
{
    for (int i = 0;i < havTree;i++)
    {
        if (tree[i] != nullptr)
        {
            // �ɾ��� ������ ���� �ð��� 1 �÷��ݴϴ�.
            tree[i]->growTime++;

            // ���� �ð��� ���� ���巹���� �����մϴ�.
            /// ����ð��� �ִ뼺��ð� �̻��̸� ������ 3���� �������ݴϴ�.
            if (tree[i]->growTime >= maxgrowTime) tree[i]->level = 3;
            /// ����ð��� �ִ뼺��ð� 2/3 �̻��̸� ������ 2�� �������ݴϴ�.
            else if (tree[i]->growTime >= (maxgrowTime / 3) * 2) tree[i]->level = 2;
            /// ����ð��� �ִ뼺��ð� 1/3 �̻��̸� ������ 1�� �������ݴϴ�.
            else if (tree[i]->growTime >= (maxgrowTime / 3)) tree[i]->level = 1;
        }
    }
}

// Get
string Apple::GetName()
{
    return Name;
}

int Apple::GethavTree()
{
    return havTree;
}

Tree* Apple::GetTree(int i)
{
    return tree[i];
}

int Apple::GettreeLevel(int i)
{
    return tree[i]->level;
}

void Apple::GetInitializeTime(int i)
{
    cout << "(" << tree[i]->year << "�� "
        << tree[i]->month << "�� "
        << tree[i]->day << "�� "
        << tree[i]->hour << "��)";
}

int Apple::GethavFruits()
{
    return havFruits;
}

int Apple::GetmaxLevel()
{
    return maxLevel;
}

int Apple::GetmaxTree()
{
    return maxTree;
}

int Apple::GetPrice()
{
    return price;
}


