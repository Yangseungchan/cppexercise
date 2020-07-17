#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    int age;
    char name[50];

public:
    Person(int myage, char *myname) : age(myage)
    {
        strcpy(name, myname);
    }
    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }
    void HowOldAreYou() const
    {
        cout << "I'm " << age << " years old" << endl;
    }
};

class UnivStudent : public Person // Person 클래스와의 상속관계 선언
{
private:
    char major[50];

public:
    UnivStudent(char *myname, int myage, char *mymajor) : Person(myage, myname)
    {
        strcpy(major, mymajor);
    }
    void WhoAreYou() const
    {
        WhatYourName();
        HowOldAreYou();
        cout << "My major is " << major << endl
             << endl;
    }
};
