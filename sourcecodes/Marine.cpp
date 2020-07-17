#include <iostream>
#include <cstring>

using namespace std;

class Marine
{
    char *name;
    int hp;               // 마린 체력
    int coord_x, coord_y; // 마린 위치
    int damage;           // 공격력
    bool is_dead;

public:
    Marine();                               // 기본 생성자
    Marine(const char *name, int x, int y); // x, y 좌표에 마린 생성
    ~Marine();                              /* 소멸자(destructor)는 객체가 delete될시 자동으로 호출된다 */

    int attack();                      // 데미지를 리턴한다.
    void be_attacked(int damage_earn); // 입는 데미지
    void move(int x, int y);           // 새로운 위치

    void show_status(); // 상태를 보여준다.
};

int main(void)
{
    char name[20] = "mike";

    Marine *marine_list[3];

    marine_list[0] = new Marine("Mike", 2, 3);
    marine_list[1] = new Marine("Philips", 3, 4);
    marine_list[2] = new Marine("Bale", 0, 0);

    for (int i = 0; i < 3; i++)
    {
        marine_list[i]->show_status();
    }

    for (int i = 0; i < 3; i++)
    {
        delete marine_list[i];
    }

    return 0;
}

Marine::Marine()
{
    name = NULL;
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(const char *name, int x, int y)
{
    this->name = new char[20];
    strcpy(this->name, name);
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
}

Marine::~Marine()
{
    cout << "call destructor" << endl;
    if (name != NULL)
    {
        delete[] name;
    }
}

int Marine::attack()
{
    return damage;
} // 데미지를 리턴한다.

void Marine::be_attacked(int damage_earn)
{
    hp -= damage_earn;
    if (hp <= 0)
        is_dead = true;
} // 입는 데미지

void Marine::move(int x, int y)
{
    coord_x = x;
    coord_y = y;
} // 새로운 위치

void Marine::show_status()
{
    printf("*** %s ***\n", name);
    printf("* HP : %3d *\n", hp);
    printf("* status : ");
    is_dead == true ? printf("dead *\n") : printf("alive *\n");
    printf("* pos : %3d,%3d *\n", coord_x, coord_y);
    printf("**************\n\n\n");
} // 상태를 보여준다.