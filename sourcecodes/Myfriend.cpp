#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class MyFriendInfo
{
private:
    char *name;
    const int age;

public:
    MyFriendInfo(const char *fname, int fage) : age(fage)
    {
        name = new char[strlen(fname) + 1];
        strcpy(name, fname);
    }
    ~MyFriendInfo()
    {
        delete[] name;
    }
    void ShowMyFriendInfo()
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char *addr;
    char *phone;

public:
    MyFriendDetailInfo(const char *fname, const int fage, const char *faddr, const char *fphone) : MyFriendInfo(fname, fage)
    {
        addr = new char[strlen(faddr) + 1];
        strcpy(addr, faddr);

        phone = new char[strlen(fphone) + 1];
        strcpy(phone, fphone);
    }

    ~MyFriendDetailInfo()
    {
        delete[] addr;
        delete[] phone;
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소 : " << addr << endl;
        cout << "전화 : " << phone << endl
             << endl;
    }
};

int main(void)
{
    MyFriendDetailInfo frd = MyFriendDetailInfo("seungchan", 23, "cp humphreys, rok", "010-7388-5289");

    frd.ShowMyFriendDetailInfo();

    return 0;
}