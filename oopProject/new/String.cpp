#include "String.h"

ostream &operator<<(ostream &ostm, const String &ref)
{
    ostm << ref.str << endl;
    return ostm;
}

istream &operator>>(istream &istm, String &ref)
{
    char input[100];
    istm >> input;
    ref = String(input);

    return istm;
}

String::String()
{
    str = NULL;
    length = 0;
}

String::String(const char *input)
{
    length = strlen(input) + 1;
    str = new char[length];
    strcpy(str, input);
}

String::String(const String &ref)
{
    length = ref.length;
    str = new char[length];
    strcpy(str, ref.str);
}

String &String::operator=(const String &ref) // opearator= overloading
{
    length = ref.length;
    if (str != NULL)
    {
        delete[] str;
    }
    str = new char[length];
    strcpy(str, ref.str);

    return *this;
}

String String::operator+(const String &ref) // operator+ overloading
{
    char *temp = new char[length + ref.length - 1];
    strcpy(temp, str);
    strcat(temp, ref.str);
    String tmp_string(temp);

    delete[] temp;
    return tmp_string;
}

String &String::operator+=(const String &ref) // operator+= overloading
{
    length += ref.length - 1;
    char *result = new char[length];

    strcpy(result, str);
    strcat(result, ref.str);

    if (str != NULL)
        delete[] str;
    str = result;
    return *this;
}

bool String::operator==(const String &ref) // operator == overloading
{
    return strcmp(str, ref.str) == 0 ? true : false;
}

String::~String() // destructor
{
    delete[] str;
}
