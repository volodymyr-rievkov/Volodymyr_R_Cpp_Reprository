#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    int n, m;
    long long x;
    cin >> n >> m >> x;
    if ((n < 1 || n > 1e5) || (m < 1 || m > 1e5) || (x < 1 || x > 1e18))
    {
        return 0;
    }
    vector<long long> a(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] < 1 || a[i] > 1e18)
        {
            return 0;
        }
    }
    sort(a.begin(), a.end());
    vector<long long> b(m, 0);
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
        if(b[i] < 1 || b[i] > 1e18)
        {
            return 0;
        }
    }
    sort(b.begin(), b.end());
    long long min_diff = LLONG_MAX;
    for(int i = 0; i < n; i++)
    {
        auto number = lower_bound(b.begin(), b.end(), x - a[i]);
        if(number != b.end())
        {
            long long sum = *number + a[i];
            min_diff = min(min_diff, abs(sum - x));
        }
        if(number != b.begin())
        {
            --number;
            long long sum = *number + a[i];
            min_diff = min(min_diff, abs(sum - x));
        }
    }
    cout << min_diff;
}