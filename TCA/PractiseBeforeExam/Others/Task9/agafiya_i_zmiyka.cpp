#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    pair<int, int> H, G;
    cin >> H.first >> H.second >> G.first >> G.second;
    cout << abs(H.first - G.first) + abs(H.second - G.second);
}