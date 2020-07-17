#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class Person
{

private:
    char *name;
    int age;

public:
    Person(const char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    void showPersonInfo() const
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }

    ~Person()
    {
        delete[] name;
        cout << "call destructor" << endl;
    }
};

int main(void)
{
    Person man1("yangseungchan", 23);
    Person man2 = man1;
    man1.showPersonInfo();
    man2.showPersonInfo();

    return 0;
}