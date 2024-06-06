#include<iostream>
#include<vector>
using namespace std;

//1: Sum
// int get_sum_of_n(const int n)
// {
//     vector<int> dp(n + 1);
//     dp[0] = 1
//     for(int i = 1; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + i;
//     }
//     return dp[n];
// }

//2: Climb Stairs
// int get_count_of_climb_options(const int n)
// {
//     vector<int> dp(n + 1);
//     dp[0] = 1;
//     dp[1] = 1;
//     for(int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }
//     return  dp[n];
// }

//3: Climb Stairs Mem Opt
// int get_count_of_climb_options(const int n)
// {
//     int a = 1;
//     int b = 1;
//     int c = 0;
//     for(int i = 2; i <= n; i++)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//     }
//     return c;
// }

//4: Climb Stairs with 3 step options
// int get_count_of_climb_options(const int n)
// {
//     int a = 1;
//     int b = 1;
//     int c = 2;
//     int d = 0;
//     for(int i = 3; i <= n; i++)
//     {
//         d = a + b + c;
//         a = b;
//         b = c;
//         c = d;
//     }
//     return d;
// }

//5: Climb Stairs with k step options
// int get_count_of_climb_options(const int n)
// {
//     const int k = 3;
//     vector<int> dp(n + 1);
//     dp[0] = 1;
//     dp[1] = 1;
//     for(int i = 2; i <= n; i++)
//     {
//         for(int j = 1; j <= k; j++)
//         {
//             if((i - j) < 0)
//             {
//                 continue;
//             }
//             dp[i] += dp[i - j];
//         }
//     }
//     return dp[n];
// }

//6: Climb Stairs with k step options Opt
// int get_count_of_climb_options(const int n)
// {
//     const int k = 3;
//     vector<int> dp(k);
//     dp[0] = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j < k; j++)
//         {
//             if((i - j) < 0)
//             {
//                 continue;
//             }
//             dp[i % k] += dp[(i - j) % k];
//         }
//     }
//     return dp[n % k];
// }

//7: Climb Stairs with k step options and red stairs
// int get_count_of_climb_options(const int n)
// {
//     const int k = 3;
//     vector<bool> stairs = {true, true, false, false, true, true, false, true, true, false};
//     vector<int> dp(k);
//     dp[0] = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j < k; j++)
//         {
//             if((i - j) < 0)
//             {
//                 continue;
//             }
//             if(stairs[i - 1])
//             {
//                 dp[i % k] = 0;
//             }
//             else
//             {
//                 dp[i % k] += dp[(i - j) % k];
//             }
//         }
//     }
//     return dp[n % k];
// }

//8: Paid Stairs Case
// int get_price_of_stairs_climb(const int n)
// {
//     vector<int> dp(n + 1);
//     vector<int> p(n + 1);
//     p = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     dp[0] = 0;
//     dp[1] = p[1];
//     for(int i = 2; i <= n; i++)
//     {
//         dp[i] = min(dp[i - 1], dp[i - 2]) + p[i];
//     }
//     return dp[n];
// }

//9: Fibonacci numbers
// int fibonacci_number_of(const int n)
// {
//     vector<int> dp(n + 1);
//     dp[0] = 0;
//     dp[1] = 1;
//     for(int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }
//     return dp[n];
// }

int main()
{
    const int n = 10;
    
    //1
    // cout << get_sum_of_n(n);
  
    //2
    // cout << get_count_of_climb_options(n);

    //3
    // cout << get_count_of_climb_options(n);

    //4
    // cout << get_count_of_climb_options(n);

    //5
    // cout << get_count_of_climb_options(n);

    //6
    // cout << get_count_of_climb_options(n);

    //7
    // cout << get_count_of_climb_options(n);

    //8
    // cout << get_price_of_stairs_climb(n);

    //9
    // cout << fibonacci_number_of(n);

}