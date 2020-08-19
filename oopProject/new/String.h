#ifndef __STRING_H__
#define __STRING_H__

#include "BankingCommonDecl.h"

class String
{
private:
    char *str;
    int length;

public:
    String();                              // basic constructor
    String(const char *input);             // constructor
    String(const String &ref);             // copy constructor
    String &operator=(const String &ref);  // opearator= overloading
    String operator+(const String &str);   // operator+ overloading
    String &operator+=(const String &ref); // operator+= overloading
    bool operator==(const String &ref);    // operator == overloading
    ~String();                             // destructor

    friend ostream &operator<<(ostream &ostm, const String &ref);
    friend istream &operator>>(istream &istm, String &ref);
};

#endif