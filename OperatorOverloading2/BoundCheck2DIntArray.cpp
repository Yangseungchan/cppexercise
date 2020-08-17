#include <iostream>
#include <cstdlib>

using namespace std;

class BoundCheckIntArray
{
private:
    int *arr;
    int col_len;

public:
    BoundCheckIntArray()
    {
        arr = NULL;
        col_len = 0;
    }
    BoundCheckIntArray(int col) : col_len(col)
    {
        arr = new int[col_len];
    }

    int &operator[](int col)
    {
        if (col < 0 || col >= col_len)
        {
            cout << "Out of range" << endl;
            exit(1);
        }
        return arr[col];
    }

    void SetArrInfo(int col)
    {
        arr = new int[col];
        col_len = col;
    }

    ~BoundCheckIntArray()
    {
        delete[] arr;
    }
};

class BoundCheck2DIntArray
{
private:
    BoundCheckIntArray *BCArr;
    int row_len;

public:
    BoundCheck2DIntArray(int row, int col) : row_len(row)
    {
        BCArr = new BoundCheckIntArray[col];
        for (int i = 0; i < col; i++)
        {
            BCArr[i].SetArrInfo(col);
        }
    }

    BoundCheckIntArray &operator[](int row)
    {
        if (row < 0 || row >= row_len)
        {
            cout << "Out of range" << endl;
            exit(1);
        }
        return BCArr[row];
    }
    ~BoundCheck2DIntArray()
    {
        delete[] BCArr;
    }
};

int main(void)
{
    int n, m;
    BoundCheck2DIntArray arr2d(3, 4);

    for (n = 0; n < 3; n++)
    {
        for (m = 0; m < 4; m++)
        {
            arr2d[n][m] = (n + m);
        }
    }

    for (int n = 0; n < 3; n++)
    {
        for (int m = 0; m < 4; m++)
        {
            cout << arr2d[n][m] << ' ';
        }
        cout << endl;
    }

    return 0;
}