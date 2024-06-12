#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    const int MOD = pow(10, 9) + 7;
    int N, M;
    cin >> N >> M;
    vector<string> field(N);
    for(int i = 0; i < N; i++)
    {
        cin >> field[i];
    }
    vector<vector<int>> dp(N, vector<int>(M, 0));
    dp[0][0] = 1;
    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j < M; j++)
        {
            if(field[i][j] == '#')
            {
                dp[i][j] == 0;
            }
            else
            {
                if(i >= 2 && j >= 1)
                {
                    dp[i][j] += dp[i - 2][j - 1];
                }
                if(i >= 1 && j >= 2)
                {
                    dp[i][j] += dp[i - 1][j - 2];
                }
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[N - 1][M - 1];
}