#include<iostream>
using namespace std;

int main()
{
    int n, battery_capicity;
    cin >> n >> battery_capicity;
    long long min_sum = 0;
    long long max_sum = 0;
    pair<int, int> battery;
    for(int i = 0; i < n; i++)
    {
        cin >> battery.first >> battery.second;
        min_sum += battery.first;
        max_sum += battery.second;
    }    
    if(min_sum >= battery_capicity)
    {
        cout << "Certainly";
    }
    else if(max_sum < battery_capicity)
    {
        cout << "Impossible";
    }
    else
    {
        cout << "Possibly";
    }
}