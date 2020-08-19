#include <iostream>
#include <cstdlib>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    friend ostream &operator<<(ostream &ostm, const Point &ref);
    // friend 함수이기 때문에 private 멤버에 접근이 가능하다
    friend ostream &operator<<(ostream &ostm, const Point *ref);
};

ostream &operator<<(ostream &ostm, const Point &ref)
//Point 레퍼런스의 멤버를 출력하는 연산자
{
    cout << '[' << ref.xpos << ", " << ref.ypos << ']' << endl;
    return ostm;
}

ostream &operator<<(ostream &ostm, const Point *ref)
//Point 포인터의 멤버를 출력하는 연산자
{
    cout << '[' << ref->xpos << ", " << ref->ypos << ']' << endl;
    return ostm;
}

class PointArr
{
private:
    Point *parr;
    int arr_len;
    PointArr(const PointArr &ref);            // copy constructor
    PointArr &operator=(const PointArr &ref); // = opeartor

public:
    PointArr(int len) : arr_len(len)
    {
        parr = new Point[arr_len];
    }
    Point &operator[](int idx) // [] operator
    {
        if (idx < 0 || idx >= arr_len)
        {
            cout << "Out of range" << endl;
            exit(1);
        }
        return parr[idx];
    }

    Point operator[](int idx) const // [] operator for the const  PointArr object
    {
        if (idx < 0 || idx >= arr_len)
        {
            cout << "Out of range" << endl;
            exit(1);
        }
        return parr[idx];
    }

    int GetArrLen() const
    {
        return arr_len;
    }
};

typedef Point *POINT_PTR; // POINT_PTR = Point *

class PointPTRArr
{
private:
    POINT_PTR *ptrarr;
    int arr_len;
    PointPTRArr(const PointArr &ref);            // copy constructor
    PointPTRArr &operator=(const PointArr &ref); // = opeartor

public:
    PointPTRArr(int len) : arr_len(len)
    {
        ptrarr = new POINT_PTR[len];
    }

    POINT_PTR &operator[](int idx)
    {
        if (idx < 0 || idx >= arr_len)
        {
            cout << "Out of range" << endl;
            exit(1);
        }
        return ptrarr[idx];
    }

    POINT_PTR operator[](int idx) const
    {
        if (idx < 0 || idx >= arr_len)
        {
            cout << "Out of range" << endl;
            exit(1);
        }
        return ptrarr[idx];
    }

    int GetArrLen() const
    {
        return arr_len;
    }
};

void ShowData(const PointArr &ref)
{
    for (int i = 0; i < ref.GetArrLen(); i++)
    {
        cout << ref[i] << endl;
    }
}

void ShowData(const PointPTRArr &ref)
{
    for (int i = 0; i < ref.GetArrLen(); i++)
    {
        cout << *ref[i] << endl;
    }
}

int main(void)
{
    Point pt1(3, 4);
    Point pt2(4, 5);
    Point pt3(1, 7);

    PointArr ptrarr(3);
    PointPTRArr ptr_ptrarr(3);

    ptrarr[0] = pt1;
    ptrarr[1] = pt2;
    ptrarr[2] = pt3;

    ShowData(ptrarr);

    cout << "****************" << endl
         << endl;

    ptr_ptrarr[0] = new Point(3, 4);
    ptr_ptrarr[1] = new Point(4, 5);
    ptr_ptrarr[2] = new Point(5, 6);

    //ShowData(ptr_ptrarr);

    for (int i = 0; i < ptr_ptrarr.GetArrLen(); i++)
        cout << ptr_ptrarr[i];

    delete ptr_ptrarr[0];
    delete ptr_ptrarr[1];
    delete ptr_ptrarr[2];

    return 0;
}
