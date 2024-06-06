#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> images(n);
    int amount = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> images[i];
        if(count(images.begin(), images.end(), images[i]) == 1)
        {
            amount++;
        }
        else if(i >= k)
        {
            amount++;
            for(int y = i - k; y < i; y++)
            {
                if(images[i] == images[y])
                {
                    amount--;
                    break;
                }
            }
        }
    }
    cout << amount;
}