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
    double endAmount;
    double generalAmount;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the principal amount: ";
    cin >> startAmount;
    cout << "Enter the rate of interest: ";
    cin >> rate;
    cout << "Enter number of years: ";
    cin >> years;
    cout << "Enter the number of times interest compounded per year: ";
    cin >> compound;
    endAmount = (startAmount * pow((1 + rate/compound), compound * years)) - startAmount; 
    generalAmount = startAmount + endAmount;
    cout << "Hello " << name << "!" << endl;
    cout << "The compounf of interest for a principal of " << startAmount << " at a rate of " << rate << "%" << " compounded " << compound << " times a year for " << years << " years is: " << endAmount << endl;
    cout << "The general amount after " << years << " years is: "<< generalAmount << endl; 
}