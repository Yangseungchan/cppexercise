#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace AAA
{
    namespace BBB
    {
        namespace CCC
        {
            int num1;
            int num2;
        } // namespace CCC
    }     // namespace BBB
} // namespace AAA

namespace ABC = AAA::BBB::CCC;

int main(void)
{
    AAA::BBB::CCC::num1 = 20;
    AAA::BBB::CCC::num2 = 30;

    cout << ABC::num1 << endl;
    cout << ABC::num2 << endl;

    return 0;
}