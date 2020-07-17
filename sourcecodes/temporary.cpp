#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Temporary
{
private:
    int num;

public:
    Temporary(int n) : num(n)
    {
        cout << "create obj : " << num << endl;
    }
    ~Temporary()
    {
        cout << "destroy obj" << num << endl;
    }
    void ShowTempInfo() const
    {
        cout << "My num is " << num << endl;
    }
};

int main(void)
{
    Temporary(100);
    cout << "AFTER MAKE!" << endl
         << endl;

    Temporary(200).ShowTempInfo();
    cout << "AFTER MAKE!" << endl
         << endl;

    const Temporary &ref = Temporary(300);

    ref.ShowTempInfo();

    cout << "END OF MAIN!" << endl
         << endl;

    return 0;
}