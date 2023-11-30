#include<iostream>
#include<cmath>
using namespace std;
double sum = 0;
double GetSum(int n)
{
    if(n == 0)
    {
        return 0;
    }
    sum += pow(n, 2)*exp(-sqrt(n));
    GetSum(n-1);
    return sum;
}
int main()
{
    int n = 7;
    cout << "Sum of " << n << " elements is: " << GetSum(n);
}