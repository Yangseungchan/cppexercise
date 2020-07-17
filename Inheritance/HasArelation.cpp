#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class Gun
{
private:
    int bullet;

public:
    Gun(int bnum) : bullet(bnum) {}
    void Shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
    int returnBullet()
    {
        return bullet;
    }
};

class Police : public Gun
{
private:
    int handcuffs;

public:
    Police(int bnum, int bcuff) : Gun(bnum), handcuffs(bcuff) {}
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void ShowEquips()
    {
        cout << "bullets : " << returnBullet() << endl;
        cout << "handcuffs : " << handcuffs << endl;
    }
};

int main(void)
{
    Police pman(5, 3);
    pman.Shot();
    pman.PutHandcuff();
    pman.ShowEquips();

    return 0;
}