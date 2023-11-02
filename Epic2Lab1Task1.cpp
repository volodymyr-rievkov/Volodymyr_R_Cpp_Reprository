#include<iostream>
#include<cmath>
using namespace std;
void PrintTask(int a, double b)
{
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "(a+b)^2-(a^2+2ab)" << endl;
    cout << "—————————————————" << endl;
    cout << "       b^2       " << endl;
}
double GetResult(int a, double b)
{
    double result = (pow(a+b, 2)-(pow(a, 2)+2*a*b))/pow(b, 2);
    return result;
}
int main()
{
    const int a = 1000;
    const double b = 0.0001;
    double result;
    PrintTask(a, b);
    cout << "Result: " << round(GetResult(a, b)) << endl;
}
