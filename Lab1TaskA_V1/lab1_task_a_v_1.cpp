#include<iostream>
using namespace std;

struct Point
{
    double x;
    double y;
};

void set_coords(Point& P)
{
    cin >> P.x >> P.y;
}

bool check_coord(Point P)
{
    return (P.x >= 0 && P.x <= 100000) && (P.y >= 0 && P.y <= 100000);
}

int main()
{
    Point A;
    Point B;
    Point C;
    int k;
    string steps;
    set_coords(A);
    if(!check_coord(A))
    {
        return 0;
    }
    set_coords(B);
    if(!check_coord(B))
    {
        return 0;
    }
    set_coords(C);
    if(!check_coord(C))
    {
        return 0;
    }
    cin >> k;
    if((k <= 0) || (k >= 20))
    {
        return 0;
    }
    cin >> steps;
}