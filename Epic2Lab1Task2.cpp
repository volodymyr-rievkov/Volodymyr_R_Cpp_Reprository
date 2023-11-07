#include<iostream>
using namespace std;
int main()
{
    double n1;
    double m1;
    cout << "Enter n: ";
    cin >> n1;
    cout << "Enter m: ";
    cin >> m1;
    float n2 = n1;
    float m2 = m1;
    cout << "---------Double Result---------" << endl;
    cout << "n+++m: " << n1+++m1 << endl;
    cout << "n-->m: " << (n1-->m1) << endl;
    cout << "m-->n: " << (m1-->n1) << endl;
    cout << "---------Float Result---------" << endl;
    cout << "n+++m: " << n2+++m2 << endl;
    cout << "n-->m: " << (n2-->m2) << endl;
    cout << "m-->n: " << (m2-->n2) << endl;
}