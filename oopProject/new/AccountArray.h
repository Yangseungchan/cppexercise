#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"

typedef Account *ACC_PTR;

class AccountArray
{
private:
    ACC_PTR *accarr; // Account의 주소값을 담는 포인터들의 배열
    int arr_len;
    AccountArray(const AccountArray &ref);
    AccountArray &operator=(const AccountArray &ref);

public:
    AccountArray(int len = 100);       // constructor
    ACC_PTR &operator[](int idx);      // [] opeartor
    ACC_PTR operator[](int idx) const; // [] opeartor const ver
    int GetArrLen();
    ~AccountArray(); // destructor
};

#endif