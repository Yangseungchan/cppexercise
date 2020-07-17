#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class Book
{
private:
    char *title;
    char *isbn;
    int price;

public:
    Book(const char *btitle, const char *bisbn, const int bprice) : price(bprice)
    {
        title = new char[strlen(btitle) + 1];
        isbn = new char[strlen(bisbn) + 1];
        strcpy(title, btitle);
        strcpy(isbn, bisbn);
    }
    void ShowBookInfo()
    {
        cout << "제목 : " << title << endl;
        cout << "ISBN : " << isbn << endl;
        cout << "가격 : " << price << endl;
    }
};

class EBook : public Book
{
private:
    char *DRMKey;

public:
    EBook(const char *btitle, const char *bisbn, const int bprice, const char *bDRMKey) : Book(btitle, bisbn, bprice)
    {
        DRMKey = new char[strlen(bDRMKey) + 1];
        strcpy(DRMKey, bDRMKey);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키 :" << DRMKey << endl;
    }
};

int main(void)
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "apsdna0");
    ebook.ShowEBookInfo();
}