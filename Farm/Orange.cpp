#include "Orange.h"

Orange::Orange()
{
    Name = "������";
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

// �������� �������� ����ϴ�.
void Orange::PickFruits(Fruits* fruits, int num)
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

    cout << "������ " << count << "���� ȹ���Ͽ����ϴ�." << endl;
    _sleep(1000);
}

//�ʱ�ȭ
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
    cout << "(" << tree[i]->year << "�� "
        << tree[i]->month << "�� "
        << tree[i]->day << "�� "
        << tree[i]->hour << "��)";
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
