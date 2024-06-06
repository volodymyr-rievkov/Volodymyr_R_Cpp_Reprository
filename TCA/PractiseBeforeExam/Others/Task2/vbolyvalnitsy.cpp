#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> prices(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(z >= 2 * prices[i])
        {
            z -= 2 * prices[i];
            count++;
            if(count >= k)
            {
                break;
            }
        }
        else
        {
            break;
        }    
    }
    cout << count;
}