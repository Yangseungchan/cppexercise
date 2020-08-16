#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Point
{
  private:
    int xpos, ypos;
  public:
    Point(int x=0, int y=0) : xpos(x), ypos(y){}
    friend ostream& operator<<(ostream &os, const Point &pos);
};

class PointAddr
{
  private:
    Point **pa_arr;
    int arr_len;

    PointAddr(const PointAddr &ref){}
    PointAddr &operator=(const PointAddr &ref){}

  public: 
    PointAddr(int len):arr_len(len)
    {
      pa_arr = new Point*[arr_len];
    }

    Point*& operator[](int idx) const
    {
      if(idx < 0 || idx >= arr_len)
      {
        cout << "Out of border of array" << endl;
        exit(1);
      }
      return pa_arr[idx];
    }

    int get_len() const
    {
      return arr_len;
    }

    ~PointAddr()
    {
      delete []pa_arr;
    } 

};

class PointArr
{
  private:
    Point *parr;
    int arr_len;
    PointArr(const PointArr &ref){}
    PointArr &operator=(const PointArr &ref){}

  public:
    PointArr(int len):arr_len(len)
    {
      parr = new Point[arr_len];
    }

    Point &operator[](int idx) const
    {
      if(idx < 0 || idx >= arr_len)
      {
        cout << "Out of border of array" << endl;
        exit(1);
      }
      return parr[idx];
    }

    int get_len() const
    {
      return arr_len;
    }

    ~PointArr()
    {
      delete []parr;
    }


};

void ShowData(const PointArr &ref)
{
  for(int i=0; i < ref.get_len(); i++)
  {
    cout << ref[i] << endl;
  }
}

void ShowData(const PointAddr &addrref) 
{
  for(int i=0; i< addrref.get_len(); i++)
  {
    cout << *addrref[i] << endl; 
  }
}

ostream& operator<<(ostream &os, const Point &pos)
{
  os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
  return os;
}


int main(void)
{

  PointAddr addr_arr(5);
  PointArr arr(5);

  arr[0] = Point(3, 4);
  arr[1] = Point(2, 5);
  arr[2] = Point(1, 6);
  arr[3] = Point(5, 4);
  arr[4] = Point(7, 12);

  ShowData(arr);

  addr_arr[0] = &arr[0];
  addr_arr[1] = &arr[1];
  addr_arr[2] = &arr[2];
  addr_arr[3] = &arr[3];
  addr_arr[4] = &arr[4];

  ShowData(addr_arr);

  return 0;
}

