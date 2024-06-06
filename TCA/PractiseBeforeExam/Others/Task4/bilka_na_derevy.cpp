#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    double h, H, s;
    cin >> h >> H >> s;
    double distance = (H / h) * (sqrt(pow(h, 2) + pow(s, 2)));
    cout << fixed << setprecision(4) << distance;
}
