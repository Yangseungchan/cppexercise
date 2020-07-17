#include <iostream>
#include <string.h>
class MyString
{
    char *str;
    int len;

public:
    MyString(char c);
    MyString(const char *arr);
    MyString(const MyString &mystr);
    int str_len();
    void str_cat(const MyString &target);
    int str_str(const MyString &str_part);
    int str_cmp(const MyString &s2);
    int str_dic(const MyString &s2);
    ~MyString() { delete[] str; }
    void printstr();
};

int main(void)
{
    char ch = 'a';
    char string[100] = "USFK is U.S Forces in Korea";
    MyString s1("U.S Forces");
    std::cout << "s1 : ";
    s1.printstr();

    MyString s2 = MyString(string);
    std::cout << "s2 : ";
    s2.printstr();

    MyString s3 = MyString(s2);
    std::cout << "s3 : ";
    s3.printstr();

    std::cout << "s1's length : " << s1.str_len() << std::endl;
    std::cout << "s2's length : " << s2.str_len() << std::endl;

    std::cout << "s1 and s2 comp : " << s2.str_cmp(s1) << std::endl;
    std::cout << "s2 and s3 comp : " << s2.str_cmp(s3) << std::endl;

    s3.str_cat(s1);
    std::cout << "strcat s3 with s1 : ";
    s3.printstr();
    std::cout << "finding s1 in s3 : " << s3.str_str(s1) << std::endl;
    std::cout << "str_dic between s1 and s2 : " << s1.str_dic(s2) << std::endl;

    return 0;
}

MyString::MyString(char c)
{
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
    len = 1;
}
MyString::MyString(const char *arr)
{
    len = strlen(arr);
    str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        str[i] = arr[i];
    }
    str[len] = '\0';
}
MyString::MyString(const MyString &mystr)
{
    len = mystr.len;
    str = new char[len];
    for (int i = 0; i < len; i++)
    {
        str[i] = mystr.str[i];
    }
    str[len] = '\0';
}
int MyString::str_len()
{
    return len;
}
void MyString::str_cat(const MyString &target)
{
    int i;
    int sum_len = len + target.len;
    char *str_copy = new char[len + 1];
    for (i = 0; i < len; i++)
    {
        str_copy[i] = str[i];
    }
    str_copy[len] = '\0';
    if (str != NULL)
    {
        delete[] str;
    }

    str = new char[sum_len + 1];
    for (i = 0; i < len; i++)
    {
        str[i] = str_copy[i];
    }
    for (i = len; i < sum_len; i++)
    {
        str[i] = target.str[i - len];
    }
    str[sum_len] = '\0';
    delete[] str_copy;
}
int MyString::str_str(const MyString &str_part)
{
    int i, j, flag;
    int part_len = str_part.len;
    flag = -1;
    for (i = 0; i < len; i++)
    {
        if (str[i] == str_part.str[0])
        {
            flag = i;
            for (j = i; j < i + part_len; j++)
            {
                if (str[j] != str_part.str[j - i])
                {
                    flag = -1;
                    break;
                }
            }
        }
        if (flag > -1)
        {
            return flag;
        }
    }
    return -1;
}
/* not same -> return -1; same -> return 1; */
int MyString::str_cmp(const MyString &s2)
{
    int l1 = len;
    int l2 = s2.len;
    int len_short = (l1 < l2) ? l1 : l2;
    if (l1 != l2)
    {
        return -1;
    }
    for (int i = 0; i < len_short; i++)
    {
        if (str[i] == s2.str[i])
        {
            continue;
        }
        else
        {
            return -1;
        }
    }
    return 1;
}
int MyString::str_dic(const MyString &s2)
{
    int l1 = len;
    int l2 = s2.len;
    for (int i = 0; i < l1 < l2 ? l1 : l2; i++)
    {
        if (str[i] == s2.str[i])
        {
            continue;
        }
        else if (str[i] < s2.str[i])
        {
            return (str[i] - s2.str[i]);
        }
        else
        {
            return (str[i] - s2.str[i]);
        }
    }
    return 0;
}
void MyString::printstr()
{
    std::cout << str << std::endl;
}
