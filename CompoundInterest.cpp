#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    string name;
    double startAmount = 0;
    double rate;
    int years;
    int compound;
    double result;
    // cout << "Enter your name: ";
    // cin >> name;
    // cout << "Enter the principal amount: ";
    // cin >> startAmount;
    // cout << "Enter the rate of interest: ";
    // cin >> rate;
    // cout << "Enter number of years: ";
    // cin >> years;
    // result = (startAmount * pow((1 + rate/compound), compound * years)) - startAmount;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the principal amount: ");
    scanf("%lf", startAmount);
    printf("Enter the rate of interest: ");
    scanf("%lf", rate);
    printf("Enter number of years: ");
    scanf("%d", years);
    result = (startAmount * pow((1 + rate/compound), compound * years)) - startAmount;
    
}