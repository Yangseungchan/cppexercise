#ifndef __ARRAY_TEMPLATE_H__
#define __ARRAY_TEMPLATE_H__

#include <iostream>

using namespace std;

template <typename T>

class BoundCheckArray
{
private:
    T *arr;
    int arrlen;
    BoundCheckArray(const BoundCheckArray &ref);
    BoundCheckArray &operator=(const BoundCheckArray &ref);

public:
    BoundCheckArray(int len);

    T &operator[](int idx);

    T operator[](int idx) const;

    int GetArrLen() const;

    ~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
    arr = new T[arrlen];
}

template <typename T>
T &BoundCheckArray<T>::operator[](int idx)
{
    if (idx < 0 || idx >= arrlen)
    {
        cout << "Out of Range" << endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[](int idx) const
{
    if (idx < 0 || idx >= arrlen)
    {
        cout << "Out of Range" << endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const
{
    return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
    delete[] arr;
}

#endif