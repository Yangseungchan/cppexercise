#include "BankingCommonDecl.h"
#include "AccountArray.h"

AccountArray::AccountArray(int len) : arr_len(len)
{
    accarr = new ACC_PTR[len];
}

ACC_PTR &AccountArray::operator[](int idx)
{
    if (idx < 0 || idx >= arr_len)
    {
        cout << "Out of range" << endl;
        exit(1);
    }
    return accarr[idx];
}

ACC_PTR AccountArray::operator[](int idx) const
{
    if (idx < 0 || idx >= arr_len)
    {
        cout << "Out of range" << endl;
        exit(1);
    }
    return accarr[idx];
}

int AccountArray::GetArrLen()
{
    return arr_len;
}

AccountArray::~AccountArray()
{
    delete[] accarr;
}
