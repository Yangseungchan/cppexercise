#include <iostream>

using namespace std;

class SortRule
{
public:
    virtual bool operator()(int num1, int num2) const = 0; /* virtual function */
};                                                         // abstract class

class AscendingSort : public SortRule // 오름차순
{
public:
    bool operator()(int num1, int num2) const
    {
        if (num1 > num2)
            return true;
        else
            return false;
    }
};

class DescendingSort : public SortRule // 내림차순
{
public:
    bool operator()(int num1, int num2) const
    {
        if (num1 < num2)
            return true;
        else
            return false;
    }
};

class DataStorage
{
private:
    int *arr;
    int idx;
    const int MAX_LEN;

public:
    DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen)
    {
        arr = new int[arrlen];
    }

    void SortData(const SortRule &functor)
    {
        int temp;
        for (int i = 0; i < idx - 1; i++)
        {
            for (int j = 0; j < idx - (i + 1); j++)
            {
                if (functor(arr[j], arr[j + 1]))
                {
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void AddData(int num)
    {
        if (idx >= MAX_LEN)
        {
            cout << "Not Enough Space to Save" << endl;
            exit(1);
        }
        arr[idx++] = num;
    }

    void ShowAllData()
    {
        for (int i = 0; i < idx; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
};

int main(void)
{
    AscendingSort asc;
    DescendingSort dsc;

    DataStorage storage(5);

    storage.AddData(10);
    storage.AddData(5);
    storage.AddData(14);
    storage.AddData(7);
    storage.AddData(9);

    storage.ShowAllData();

    storage.SortData(asc);
    storage.ShowAllData();

    storage.SortData(dsc);
    storage.ShowAllData();

    return 0;
}