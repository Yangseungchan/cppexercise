#include <iostream>
#include <cstring>

class string
{
    char *str;
    int len;

public:
    string(char c, int n); // 문자 c 가 n 개 있는 문자열로 정의
    string(const char *s);
    string(const string &s);
    ~string();

    void add_string(const string &s);  // str 뒤에 s 를 붙인다.
    void copy_string(const string &s); // str 에 s 를 복사한다.
    void print_string();
    int strlen(); // 문자열 길이 리턴
};

int main(void)
{
    string s1('c', 10);
    string s2("string");
    string s3("176th");

    s1.print_string();
    s2.print_string();
    s3.print_string();

    s1.add_string(s2);
    s1.print_string();

    s3.copy_string(s2);
    s3.print_string();

    return 0;
}

string::string(char c, int n)
{
    int i;
    str = new char[n + 1];
    len = n;
    for (i = 0; i < n; i++)
    {
        str[i] = c;
    }
    str[i] = '\0'; /* i = n */
}

string::string(const char *s)
{
    int i;
    int length = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        length++;
    }
    len = length;
    str = new char[len + 1];
    for (i = 0; i < length; i++)
    {
        str[i] = s[i];
    }
    str[i] = '\0'; /* i = length */
}

string::string(const string &s)
{
    int i;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
}

string::~string()
{
    delete[] str;
}

void string::add_string(const string &s) // str 뒤에 s 를 붙인다.
{
    char *tmp;
    int l1 = len;
    int l2 = 0;
    for (int i = 0; s.str[i] != '\0'; i++)
    {
        l2++;
    }
    tmp = new char[l1 + 1];
    strcpy(tmp, str);

    delete[] str;
    len = l1 + l2;
    str = new char[len + 1];
    strcpy(str, tmp);
    strcat(str, s.str);
    delete[] tmp;
}

void string::copy_string(const string &s) // str 에 s 를 복사한다.
{
    if (len < s.len)
    {
        len = s.len;
    }
    delete[] str;
    str = new char[len + 1];
    strcpy(str, s.str);
}

void string::print_string()
{
    std::cout << str << "/length : " << len << std::endl;
}

int string::strlen()
{
    return len;
}