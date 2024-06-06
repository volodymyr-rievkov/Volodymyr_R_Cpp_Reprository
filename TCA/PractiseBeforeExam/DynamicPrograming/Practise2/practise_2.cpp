#include<iostream>
#include<vector>
using namespace std;

//1: Fence painting Either 1 or 0, cant be 000 or 111
// int get_amount_of_painting_options(const int n)
// {
//     vector<vector<int>> dp(n + 1, vector<int>(2));
//     dp[1][0] = 1;
//     dp[1][1] = 1;
//     dp[2][0] = 2;
//     dp[2][1] = 2;
//     for(int i = 3; i <= n; i++)
//     {
//         for(int j = 0; j <= 1; j++)
//         {
//             dp[i][j] = dp[i - 1][1 - j] + dp[i - 2][1 - j];
//         }
//     }
//     return dp[n][0] + dp[n][1];
// }

//2: Coin Change
// int get_amount_of_change_options(int n)
// {
//     vector<int> coins = {1, 2, 5, 10, 25, 50};
//     vector<int> dp(n + 1);
//     dp[0] = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         for(int coin : coins)
//         {
//             if(i >= coin)
//             {
//                 dp[i] += dp[i - coin];
//             }
//         }
//     }
//     return dp[n];
// }



int main()
{
    const int n = 4;
    //1
    // cout << get_amount_of_painting_options(n);

    //2
    // cout << get_amount_of_change_options(n);

    

}