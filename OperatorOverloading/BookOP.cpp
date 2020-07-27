#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private:
    char *title;
    char *isbn;
    int price;

public:
    Book(const char *B_title, const char *B_isbn, int B_price) : price(B_price)
    {
        title = new char[strlen(B_title) + 1];
        strcpy(title, B_title);
        isbn = new char[strlen(B_isbn) + 1];
        strcpy(isbn, B_isbn);
    }

    Book(const Book &ref) : price(ref.price)
    {
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
    }

    Book &operator=(const Book &ref)
    {
        if (title != NULL)
            delete[] title;
        if (isbn != NULL)
            delete[] isbn;

        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
        price = ref.price;

        return *this;
    }

    void ShowData() const
    {
        cout << "title : " << title << endl;
        cout << "isbn : " << isbn << endl;
        cout << "price : " << price << endl;
    }
};

class EBook : public Book
{
private:
    char *DRMKey;

public:
    EBook(const char *E_title, const char *E_isbn, int E_price, const char *E_DRMKey) : Book(E_title, E_isbn, E_price)
    {
        DRMKey = new char[strlen(E_DRMKey) + 1];
        strcpy(DRMKey, E_DRMKey);
    }

    EBook(const EBook &ref) : Book(ref)
    {
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
    }

    EBook &operator=(const EBook &ref)
    {
        if (DRMKey != NULL)
            delete[] DRMKey;

        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);

        Book::operator=(ref);
        return *this;
    }

    void ShowData() const
    {
        Book::ShowData();
        cout << "DRMKey : " << DRMKey << endl;
    }
};

int main(void)
{
    EBook eb1("helloworld", "1234-5678", 30000, "12313");

    EBook eb2 = eb1;

    eb2.ShowData();
    cout << endl
         << endl;

    EBook eb3("xxxx", "xxxx", 0, "xxxx");
    eb3.ShowData();
    cout << endl
         << endl;
    eb3 = eb1;
    eb3.ShowData();

    return 0;
}
