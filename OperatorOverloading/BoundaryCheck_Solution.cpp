#include <iostream>
#include <cstdlib>

using namespace std;

class BoundCheckIntArray
{
private:
    int *arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray &ref) {}
    BoundCheckIntArray &operator=(const BoundCheckIntArray &ref) {}

public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }

    int &operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }

    int &operator[](int idx) const
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }

    int GetArrLen() const { return arrlen; }
    ~BoundCheckIntArray() { delete[] arr; }
};

void ShowData(const BoundCheckIntArray &ref)
{
    int len = ref.GetArrLen();
    for (int idx = 0; idx < len; idx++)

        cout << ref[idx] << endl;
}

int main(void)
{
    BoundCheckIntArray arr(5);
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * 11;
    }
    for (int i = 0; i < 6; i++)
    {
        cout << arr.operator[](i) << endl;
    }

    return 0;
}
