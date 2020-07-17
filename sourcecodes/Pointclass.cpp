#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class Point
{
    int x; /* 기본적으로 private으로 설정된다 */
    int y;

public:
    Point();
    Point(int pos_x, int pos_y);
    int GetPointX();
    int GetPointY();
};

class Geometry
{
    // 점 100 개를 보관하는 배열.

private:
    Point *point_array[100];
    int point_num;

public:
    Geometry(Point **point_list, int num);
    Geometry();

    void AddPoint(Point &point);
    int GetPointNum();

    // 모든 점들 간의 거리를 출력하는 함수 입니다.
    void PrintDistance();

    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
    void PrintNumMeets();
};

int main(void)
{
    int i, j;
    Point *list_1[3]; /* 클래스 Point 객체를 가리키는 주소들의 배열 */
    Point *list_2[3];
    Point p1;

    srand(time(NULL));

    for (i = 0; i < 3; i++)
    {
        list_1[i] = new Point();
        list_2[i] = new Point();
    }

    Geometry g1 = Geometry(list_1, 3);
    Geometry g2 = Geometry(list_2, 3);

    g1.AddPoint(p1);
    g1.PrintDistance();
    /*for (i = 0; i < g1.GetPointNum(); i++)
    {
        g1.PrintDistance();
        //cout << (*list_1[i]).GetPointX() << " " << (*list_1[i]).GetPointY() << endl;
        //cout << (*list_2[i]).GetPointX() << " " << (*list_2[i]).GetPointY() << endl;
    }*/

    return 0;
}

Point::Point()
{
    x = rand() % 10;
    y = rand() % 10;
}

Point::Point(int pos_x, int pos_y)
{
    x = pos_x;
    y = pos_y;
}

int Point::GetPointX()
{
    return x;
}

int Point::GetPointY()
{
    return y;
}

Geometry::Geometry(Point **point_list, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        point_array[i] = point_list[i];
    }
    point_num = num;
}

Geometry::Geometry()
{
    for (int i = 0; i < 5; i++)
    {
        point_array[i] = new Point(rand() % 10, rand() % 10);
    }
    point_num = 5;
}

void Geometry::AddPoint(Point &point) /* 매개변수 point의 멤버로 왜 접근이 안될까? */
{
    //cout << "point_num : " << point_num << endl;
    if (point_num < 100)
    {
        point_array[point_num++] = new Point(point.GetPointX(), point.GetPointY());
    }
}

int Geometry::GetPointNum()
{
    return point_num;
}

void Geometry::PrintDistance()
{
    int x, y;
    for (int i = 0; i < point_num; i++)
    {
        for (int j = 0; j < point_num; j++)
        {
            if (j == i)
                continue;
            x = abs((*point_array[i]).GetPointX() - (*point_array[j]).GetPointX());
            y = abs((*point_array[i]).GetPointY() - (*point_array[j]).GetPointY());
            cout << "Distance between point " << i << " and " << j << " : " << (int)(sqrt(pow(x, 2) + pow(y, 2))) << endl;
        }
    }
}

void Geometry::PrintNumMeets()
{
}