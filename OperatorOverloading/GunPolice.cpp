#include <iostream>
#include <cstring>

using namespace std;

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
    void ShowData()
    {
        cout << "bullet : " << bullet << endl;
    }
};

class Police
{
private:
    int handcuffs;
    Gun *pistol;

public:
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }

    Police(const Police &ref) : handcuffs(ref.handcuffs)
    {
        pistol = new Gun(*(ref.pistol));
    }

    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }

    void Shot()
    {
        if (pistol == NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol->Shot();
    }

    Police &operator=(const Police &ref)
    {
        handcuffs = ref.handcuffs;
        pistol = new Gun(*(ref.pistol));

        return *this;
    }

    void ShowData()
    {
        cout << "handcuffs : " << handcuffs << endl;
        pistol->ShowData();
    }

    ~Police()
    {
        if (pistol != NULL)
            delete pistol;
    }
};

int main(void)
{
    Police p1(12, 3);
    Police p2(0, 0);

    p2 = p1;
    p2.ShowData();

    Police p3 = p1;
    p3.ShowData();

    return 0;
}