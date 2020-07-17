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
        bullet--;
    }
    int &returnBullet()
    {
        return bullet;
    }
};

class Police
{
private:
    int handcuffs;
    Gun pistol;

public:
    Police(int bnum, int bcuff) : pistol(bnum), handcuffs(bcuff)
    {
    }
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shot()
    {
        cout << "BBANG!" << endl;
        pistol.Shot();
    }
    void ShowEquips()
    {
        cout << "bullets : " << pistol.returnBullet() << endl;
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