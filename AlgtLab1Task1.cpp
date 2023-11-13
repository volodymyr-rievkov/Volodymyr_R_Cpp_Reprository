#include<iostream>
using namespace std;
int main()
{
    bool fail = false;
    int H;
    int M;
    int h;
    int m;
    cin >> H;
    cin >> M;
    for (int i = 0; i < 3; i++)
    {   
        cin >> h;
        cin >> m;
        if(h != 0 && m != 0) 
        {
            fail = true;
        }
        H -= h;
        M -= m;
    }
    if(fail)
    {
        cout << "NO";
    } 
    else
    {
        if(H > 0 && M > 0)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    } 
}