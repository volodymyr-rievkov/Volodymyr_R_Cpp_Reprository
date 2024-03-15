#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n < 1 || n > 34)
    {
        return 0;
    }
    vector<int> weights(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> weights[i];
        if(weights[i] < 1 || weights[i] > 47474747)
        {
            return 0;
        }
    }
    
}