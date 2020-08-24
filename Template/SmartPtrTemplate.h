#ifndef __SMARTPTR_TEMPLATE_H__
#define __SMARTPTR_TEMPLATE_H__

#include <iostream>

template <typename T>

class SmartPtr
{
private:
    T *posptr;

public:
    SmartPtr(T *ptr);
    T &operator*() const;
    T *operator->() const;
    ~SmartPtr();
};

template <typename T>
SmartPtr<T>::SmartPtr(T *ptr) : posptr(ptr)
{
}

template <typename T>
T &SmartPtr<T>::operator*() const
{
    return *posptr;
}

template <typename T>
T *SmartPtr<T>::operator->() const
{
    return posptr;
}

template <typename T>
SmartPtr<T>::~SmartPtr()
{
    delete posptr;
}

#endif