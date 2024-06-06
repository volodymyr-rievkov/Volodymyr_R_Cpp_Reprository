#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> field(N);
    for(int i = 0; i < N; i++)
    {
        cin >> field[i];
    }
    // if((N < 4 && M < 4))
    // {
    //     cout << 0;
    //     return 0;
    // }
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
            }
        }
    }
    int result = dp[N - 1][M - 1] % (10^9 + 7);
    cout << result;
}