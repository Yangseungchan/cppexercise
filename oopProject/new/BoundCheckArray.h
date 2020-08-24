#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include <iostream>

template <typename T>

class BoundCheckArray
{
private:
    T *arr;
    int arr_len;
    BoundCheckArray(const BoundCheckArray &ref);
    BoundCheckArray &operator=(const BoundCheckArray &ref);

public:
    BoundCheckArray(int len = 100);
    T &operator[](int idx);
    T operator[](int idx) const;
    int GetArrLen();
    ~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arr_len(len)
{
    arr = new T[len];
}

template <typename T>
T &BoundCheckArray<T>::operator[](int idx)
{
    if (idx < 0 || idx >= arr_len)
    {
        cout << "Out of range" << endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[](int idx) const
{
    if (idx < 0 || idx >= arr_len)
    {
        cout << "Out of range" << endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen()
{
    return arr_len;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
    delete[] arr;
}

#endif