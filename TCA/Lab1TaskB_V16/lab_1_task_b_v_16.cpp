#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n < 1 || n > 100000)
    {
        return 0;
    }
    string points;
    cin >> points;
    if(points.length() != n)
    {
        return 0;
    }
    int k_points = 0;
    int v_points = 0;
    int k_win = 0;
    int v_win = 0;
    for(int i = 0; i < n; i++)
    {
        if(points[i] == 'K')
        {
            k_points++;
        }
        else
        {
            v_points++;
        }
        int diff = abs(k_points - v_points);
        if ((k_points >= 11 || v_points >= 11) && diff >= 2) 
        {
            if (k_points > v_points)
            {
                k_win++;
            }  
            else
            {
                v_win++;
            }
            k_points = 0;
            v_points = 0;
        }
    }
    cout << k_win << ":" << v_win << endl;
    if(k_points != 0 || v_points != 0)
    {
        cout << k_points << ":" << v_points;
    }
}
