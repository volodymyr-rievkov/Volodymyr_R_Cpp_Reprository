#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    double x, k, r;
    cin >> x >> k >> r;
    double distance = (2 * M_PI * r) * k * x;
    cout << fixed << setprecision(7) << distance;
}