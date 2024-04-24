#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    double r = 0;
    double h = 0;
    cin >> r >> h;
    if(r < 1 || r > 1e4 || h < 1 || h > 1e3)
    {
        return 0;
    }
    double angle = acos(r / (r + h));
    double visible_area = 2 * M_PI * pow(r, 2) * (1 - cos(angle));
    cout << fixed << setprecision(6) << visible_area;
}