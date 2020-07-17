#include <iostream>

using namespace std;

class SoBase
{
private:
    int baseNum;

public:
    SoBase() : baseNum(20)
    {
        cout << "SoBase()" << endl;
    }

    SoBase(int n) : baseNum(n)
    {
        cout << "SoBase(" << n << ")" << endl;
    }

    ~SoBase()
    {
        cout << "~SoBase(" << baseNum << ")" << endl;
    }

    void ShowBaseData()
    {
        cout << baseNum << endl;
    }
};

class SoDerived : public SoBase /* 클래스 SoBase를 상속 */
{
private:
    int derivNum;

public:
    SoDerived() : derivNum(30)
    {
        cout << "SoDerived()" << endl;
    }

    SoDerived(int n) : SoBase(n), derivNum(n)
    {
        cout << "SoDerived(" << n << ")" << endl;
    }

    SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
    {
        cout << "SoDerived(int n1, int n2)" << endl;
    }

    ~SoDerived()
    {
        cout << "~SoDerive(" << derivNum << ")" << endl;
    }

    void ShowDerivData()
    {
        ShowBaseData();
        cout << derivNum << endl;
    }
};

int main(void)
{
    SoDerived drv1(15);
    SoDerived drv2(27);
    return 0;
}
