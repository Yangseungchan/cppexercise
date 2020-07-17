#include <iostream>
#include <cstring>

using namespace std;

class First
{
public:
    void FirstFunc() { cout << "FirstFunc()" << endl; }
    virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
    void SecondFunc() { cout << "SecondFunc()" << endl; }
    virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
    void ThirdFunc() { cout << "ThirdFunc()" << endl; }
    virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
    Third obj;
    obj.FirstFunc(); /* obj는 Third형 객체이므로 직/간접 상속관계에 있는 객체의 멤버함수를 호출할 수 있다 */
    obj.SecondFunc();
    obj.ThirdFunc();
    obj.SimpleFunc();

    Second &sref = obj;
    sref.FirstFunc(); /* Second형인 참조자는 기본클래스 First의 FirstFunc()을 호출할 수 있다. */
    sref.SecondFunc();
    sref.SimpleFunc(); /* SimpleFunc()은 가상함수이기 때문에 Second형 참조자 이더라도 
                        실제로 가리키는 객체가 Third형 객체이므로 Third의 멤버함수가 호출된다 */

    First &fref = obj;
    fref.FirstFunc();
    fref.SimpleFunc();

    return 0;
}
