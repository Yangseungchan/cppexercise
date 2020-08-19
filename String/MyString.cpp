#include <iostream>
#include <cstring>

using namespace std;

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

int main(void)
{
    String str1 = "I like ";
    String str2 = "string class";
    String str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if (str1 == str3)
        cout << "Same String" << endl;
    else
        cout << "Not Same String" << endl;

    String str4;
    cout << "Input String : ";
    cin >> str4;
    cout << "String that you input : " << str4 << endl;

    return 0;
}
