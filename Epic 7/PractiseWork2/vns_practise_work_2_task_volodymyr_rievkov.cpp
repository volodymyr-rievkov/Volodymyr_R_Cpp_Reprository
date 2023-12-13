#include<iostream>
#include<cmath>
using namespace std;

double calculate_function(double x)
{
    double z = abs(start_x) + pow(start_x, 2);
    return z * pow(sin(2 + x), 2) / (2 + x);
}

void print_function_results(double start_x, double end_X, double step)
{
    for(start_x; start_x <= end_X; start_x + step)
    {

        cout << "x = " << start_x << ":" << endl;
        cout << "y = " << calculate_function(start_x) << endl;
    }
}

int main()
{
    double start_x = -2.5;
    double end_x = 2;
    double step = 0.5;
    print_function_results(start_x, end_x, z, step);
}