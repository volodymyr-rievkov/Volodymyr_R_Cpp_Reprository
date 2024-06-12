#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    const int MOD = pow(10, 9) + 7;
    int N, M;
    cin >> N >> M;
    vector<int> B(M);
    for(int i = 0; i < M; i++)
    {
        cin >> B[i];
    }
    vector<int> dp(N + 1);
    int index = 0;
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            index = i - B[j];
            if (index < 0)
            {
                dp[i] += 0;
            }
            else if(index == 0)
            {
                dp[i] += 1;
            }
            else if (index > 0)
            {
                dp[i] += dp[index];
            }
            dp[i] %= MOD;
        }
    }
    cout << dp[N];
}