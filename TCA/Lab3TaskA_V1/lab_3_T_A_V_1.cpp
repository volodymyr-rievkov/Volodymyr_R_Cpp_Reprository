#include<iostream>
#include<cmath>
using namespace std;

long long get_pow_two_of(int x)
{
    long long result = 1;
    while(result < x)
    {
        result *= 2;
    }
    if((result - x) > (abs((result / 2) - x)))
    {
        result /= 2;
    }
    return result;
}

int main()
{
    long long current_position = 0;
    long long x;
    cin >> x;
    if(x < 1 || x > 1e9)
    {
        return 0;
    }
    int time = 0;
    while(x != 0)
    {
        current_position = get_pow_two_of(x);
        x = abs(x - current_position);
        time++;
    }
    cout << time;
}