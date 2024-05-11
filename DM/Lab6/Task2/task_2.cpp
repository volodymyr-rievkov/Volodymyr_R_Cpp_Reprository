#include<iostream>
using namespace std;

void set_func(string &function_s)
{
    string func_format = "(x + y)^n";
    cout << "Enter function in format " << func_format << " : ";
    getline(cin, function_s);  
}

int fact(int number)
{
    if(number == 0)
    {
        return 1;
    }
    return number * fact(number - 1);
}

int C(int n, int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

void build_func(const string &function_s)
{
    char x = function_s[1];
    char action = function_s[3];
    char y = function_s[5];
    int power = atoi(&function_s[8]);
    for(int i = 0; i <= power; i++)
    {
        cout << C(power, i) << x << '^' << power - i << y << '^' << i;
        if(i != power)
        {
            cout << ' ' << action << ' ';
        }
    }
}

int main()
{
    string function_s;
    set_func(function_s);
    build_func(function_s);
}