#include<iostream>
#include<cmath>
using namespace std;
//Lab1
//
//Task1
// void PrintTask(int a, double b)
// {
//     cout << "a: " << a << endl;
//     cout << "b: " << b << endl;
//     cout << "(a+b)^2-(a^2+2ab)" << endl;
//     cout << "—————————————————" << endl;
//     cout << "       b^2       " << endl;
// }
// double GetResult(int a, double b)
// {
//     double result = (pow(a+b, 2)-(pow(a, 2)+2*a*b))/pow(b, 2);
//     return result;
// }
// int main()
// {
//     const int a = 1000;
//     const double b = 0.0001;
//     double result;
//     PrintTask(a, b);
//     cout << "Result: " << round(GetResult(a, b)) << endl;
// }
//
//Task2
// int main()
// {
//     int n;
//     int m;
//     cout << "Enter n: ";
//     cin >> n;
//     cout << "Enter m: ";
//     cin >> m;
//     cout << "n+++m: " << n+++m << endl;
//     cout << "n-->m: " << (n-->m) << endl;
//     cout << "m-->n: " << (m-->n) << endl;
// }

//Lab2
//
//Task1
// double GetElementOfRowByNum(int num)
// {
//     double result = pow(num, 2)*exp(-sqrt(num));
//     return result;
// }
// double GetSumOfRowNums(int amountOfnums)
// {
//     double sum = 0;
//     for(int i = 1; i <= amountOfnums; i++)
//     {
//         sum += GetElementOfRowByNum(i);
//     }
//     return sum;
// }
// void PrintSumOf(int amountOfsum)
// {
//     cout << "Sum of 7 elements" << GetSumOfRowNums(amountOfsum);
// }
// int main()
// {
//     PrintSumOf(7);
// }
