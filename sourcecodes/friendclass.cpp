#include <iostream>
#include <cstring>

using namespace std;

class Boy
{
private:
    int height;
    friend class Girl;

public:
    Boy(int len) : height(len){};
};

class Girl
{
private:
    char phNum[20];

public:
    Girl(const char *num)
    {
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(const Boy &ref)
    {
        cout << "height : " << ref.height << endl;
    }
};

int main(void)
{
    Boy boy1(183);
    Girl girl1("Jenny");
    girl1.ShowYourFriendInfo(boy1);
    return 0;
}