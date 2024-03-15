#include<iostream>
using namespace std;

int main()
{
    int x = 0;
    int y = 0;
    string comands;
    cin >> comands;
    if(comands.size() < 1 || comands.size() > 1000)
    {
        return 0;
    }
    int x1;
    int y1;
    cin >> x1 >> y1;
    if(x1 < 0 || x1 > 1000 || y1 < 0 || y1 > 1000)
    {
        return 0;
    }
    for(int i = 0; i < comands.size(); i++)
    {
        if(comands[i] == 'R')
        {
            x++;
        }
        else
        {
            y++;
        }
        if(x1 <= x && y1 <= y)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}