#include<iostream>
#include<cmath>
using namespace std;
double GetElementOfRowByNum(int num)
{
    double result = pow(num, 2)*exp(-sqrt(num));
    return result;
}
double GetSumOfRowNums(int amountOfnums)
{
    double sum = 0;
    for(int i = 1; i <= amountOfnums; i++)
    {
        sum += GetElementOfRowByNum(i);
    }
    return sum;
}
void PrintSumOf(int amountOfsum)
{
    cout << "Sum of "<< amountOfsum << " elements is " << GetSumOfRowNums(amountOfsum);
}
int main()
{
    PrintSumOf(7);
}