#include<iostream>
#include<cmath>
using namespace std;

struct Side
{
    double a;
    double b;
    double c;
};

double find_triangle_height(Side s, int side)
{
    double p = (s.a + s.b + s.c) / 2;
    return  (sqrt(p * (p - s.a) * (p - s.b) * (p - s.c)));
}

int main()
{
    Side s;
    s.a = 10;
    s.b = 5; 
    s.c = 5;
    cout << "Height of a: " << find_triangle_height(s, s.a) << endl;
    cout << "Height of b: " << find_triangle_height(s, s.b) << endl;
    cout << "Height of c: " << find_triangle_height(s, s.c) << endl;
}